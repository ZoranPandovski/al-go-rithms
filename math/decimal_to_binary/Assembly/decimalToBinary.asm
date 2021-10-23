title decimal_to_binary
.model small
.stack 100h
.data
    msg db 'Entry a decimal number:$'
    msg1 db 0dh, 0ah, 'Invalid entry $'
    msg2 db 0dh, 0ah, 'Its binary equivalent: $'
.code
main proc
    mov ax, @data
    mov ds, ax

    lea dx, msg
    mov ah, 9
    int 21h

    mov ah, 1
    int 21h

    cmp al, 30h
    jnge invalid

    cmp al, 39h
    jnle invalid

    lea dx, msg2
    mov ah, 9
    int 21h

    and al, 0fh
    mov cl, 3

    mov bl, al
    mov bh, bl

    shr bh, cl
    add bh, 30h

    mov ah, 2
    mov dl, bh 
    int 21h

    xor bh, bh
    mov bh, bl

    mov cl, 2
    and bh, 04h

    shr bh, cl
    add bh, 30h

    mov ah, 2
    mov dl, bh 
    int 21h

    xor bh, bh
    mov bh, bl

    and bh, 02h
    shr bh, 1

    add bh, 30h

    mov ah, 2
    mov dl, bh
    int 21h

    xor bh, bh
    mov bh, bl

    and bh, 01h
    add bh, 30h

    mov ah, 2
    mov dl, bh
    int 21h

    jmp exit

   invalid:

    lea dx, msg1
    mov ah, 9
    int 21h

   exit:

    mov ah, 4ch
    int 21h

   main endp
        end main