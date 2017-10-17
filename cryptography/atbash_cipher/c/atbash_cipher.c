#include <stdio.h>
#include <string.h>

char cipher (char c){
	if(c >= 65 && c<= 90){ // 65 is "A" on ASCII table, 90 is Z 
		c = c - 65;
		c = 90 - c;
	}else if( c >= 97 && c<= 122){ // 97 is "a" on ASCII table, 122 is "z"
		c = c-97;
		c = 122 - c;
	}
	return c;
}

int main(int argc, char *argv[]){
	int b = 0;
	if (argc == 2){
		for (b=0; b<strlen(argv[1]);b++){
			printf("%c", cipher(argv[1][b]));
		}
	printf("\n");
	}
	return 0;
}
