.data
values: .word 3, 0
.text

.global main

main:
	mov r2, r0
	movi r3, 1
	movia r10, values
	ldw r4, 0(r10)

label:
	bgt r3, r4, label3
	
	div r1, r4, r3
	mul r1, r1, r3
	sub r1, r4, r1
	
	bne r1, r0, label2
	addi r2, r2, 1
	addi r3, r3, 1
	br label

label2:
	addi r3, r3, 1
	br label

label3:
	movi r1, 2
	bne r2, r1, end
	movi r1, 1
	stw r1, 4(r10)
end:
	br end
	.end
