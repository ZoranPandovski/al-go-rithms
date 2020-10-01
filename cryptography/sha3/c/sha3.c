#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

#define KECCAFK_ROUNDS 24

struct shaInfo {
    union {
        uint8_t buf8[200];
        uint64_t buf64[25];
    };
    uint32_t arg1;
    uint32_t arg2;
    uint32_t arg3;
};

uint64_t ROTL64(uint64_t x, uint64_t y) {
    return (((x) << (y)) | ((x) >> (64 - (y))));
}

uint64_t keccakf_rndc[] = {
    0x0000000000000001, 0x0000000000008082, 0x800000000000808a,
    0x8000000080008000, 0x000000000000808b, 0x0000000080000001,
    0x8000000080008081, 0x8000000000008009, 0x000000000000008a,
    0x0000000000000088, 0x0000000080008009, 0x000000008000000a,
    0x000000008000808b, 0x800000000000008b, 0x8000000000008089,
    0x8000000000008003, 0x8000000000008002, 0x8000000000000080,
    0x000000000000800a, 0x800000008000000a, 0x8000000080008081,
    0x8000000000008080, 0x0000000080000001, 0x8000000080008008
};
uint64_t keccakf_rotc[] = {
    1,  3,  6,  10, 15, 21, 28, 36, 45, 55, 2,  14,
    27, 41, 56, 8,  25, 43, 62, 18, 39, 61, 20, 44
};
uint64_t keccakf_piln[] = {
    10, 7,  11, 17, 18, 3, 5,  16, 8,  21, 24, 4,
    15, 23, 19, 13, 12, 2, 20, 14, 22, 9,  6,  1
};

void sha3_keccakf(uint64_t * st) {
    uint32_t i,j;
    uint64_t t;
    uint64_t bc[5] = {0,0,0,0,0};

    uint32_t r;
    for (r = 0; r < KECCAFK_ROUNDS; r++) {
        for (i = 0; i < 5; i++) {
            bc[i] = st[i] ^ st[i + 5] ^ st[i + 10] ^ st[i + 15] ^ st[i + 20];
        }
        for (i = 0; i < 5; i++) {
            t = bc[(i + 4) % 5] ^ ROTL64(bc[(i + 1) % 5], 1);
            for (j = 0; j < 25; j += 5) {
                st[j + i] ^= t;
            }
        }

        t = st[1];

        for (i = 0; i < 24; i++) {
            j = keccakf_piln[i];
            bc[0] = st[j];
            st[j] = ROTL64(t, keccakf_rotc[i]);
            t = bc[0];
        }

        for (j = 0; j < 25; j += 5) {
            for (i = 0; i < 5; i++) {
                bc[i] = st[j + i];
            }
            for (i = 0; i < 5; i++) {
                st[j + i] ^= (~bc[(i + 1) % 5]) & bc[(i + 2) % 5];
            }
        }

        st[0] ^= keccakf_rndc[r];
    }
}

void sha3_init(struct shaInfo * s, uint32_t mdlen) {
    memset(s -> buf8, 0, 200);
    s -> arg3 = mdlen;
    s -> arg2 = 200 - 2 * mdlen;
    s -> arg1 = 0;
}

void sha3_update( struct shaInfo * s, uint8_t * data, uint32_t l) {
    uint32_t i,j;

    j = s -> arg1;
    for (i = 0; i < l; i++) {
        s -> buf8[j] ^= data[i];
        j++;
        if (j >= s -> arg2) {
            sha3_keccakf(s -> buf64);
            j = 0;
        }
    }
    s -> arg1 = j;
}

void sha3_final(uint8_t * md, struct shaInfo * s) {
    s -> buf8[s -> arg1] ^= 0x06;
    s -> buf8[s -> arg2 - 1] ^= 0x80;

    sha3_keccakf(s -> buf64);

    uint32_t i;
    for (i = 0; i < s -> arg3; i++) {
        md[i] = s -> buf8[i];
    }
}

uint8_t * sha3(uint8_t * message, uint32_t messageLength, uint32_t shaLength) {
    shaLength >>= 3;
    uint8_t * buffer = (uint8_t*)malloc(shaLength);
    memset(buffer, 0, shaLength);
    struct shaInfo s;

    sha3_init(&s, shaLength);
    sha3_update(&s, message, messageLength);
    sha3_final(buffer, &s);

    return buffer;
}

void printHash(uint8_t * buf, uint32_t len) {
    uint32_t i;
    for (i = 0; i < len; i++) {
        uint8_t low = buf[i] & 0xF;
        uint8_t high = (buf[i] >> 4) & 0xF;
        if (low >= 10) { low += 'A' - 10; } else {low += '0';}
        if (high >= 10) { high += 'A' - 10; } else {high += '0';}

        printf("%c", high);
        printf("%c", low);
    }
}


// perfroms tests
int main(int argc, char ** args) {
    char test[] = "test";

    printf("Tests:\n\n");
    printf("sha3 224 of \"test\":\n");
    printHash(sha3((uint8_t*)test, strlen(test), 224), 224/8);
    printf("\n\n");
    printf("sha3 224 of \"test\":\n");
    printHash(sha3((uint8_t*)test, strlen(test), 256), 256/8);
    printf("\n\n");
    printf("sha3 224 of \"test\":\n");
    printHash(sha3((uint8_t*)test, strlen(test), 384), 384/8);
    printf("\n\n");
    printf("sha3 224 of \"test\":\n");
    printHash(sha3((uint8_t*)test, strlen(test), 512), 512/8);
    printf("\n");

    return 0;
}
