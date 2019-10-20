    .data                               #global data
    input:                              #input array
        .word   13, 43, 16, 23, 9, 2, 15, 19, 8, 28, 30, 4, 48, 24, 10, 18, 29, 35, 6, 35
    input_length:                       #length of input
        .word   20
    buffer:
        .space 80                       #(4*20) array of 20 integers

    .text
main:
    add $sp, $sp, -4			#save $ra on stack
    sw $ra, 0($sp)
    li $a0, 0                           #initial value for left = 0
    la $t0, input_length
    lw $a1, 0($t0)                      #initial value for right = len-1
    add $a1, $a1, -1
    jal mergesort
    jal print_output
    lw $ra, 0($sp)
    add $sp, $sp, 4			#restore $ra and stack pointer position
    jr $ra				#returns to spim base code for exiting

mergesort:
    add $sp, $sp, -16
    sw $ra, 0($sp)                      #save return address and
    sw $s0, 4($sp)                      #"saved" registers on stack
    sw $s1, 8($sp)
    sw $s2, 12($sp)
    move $s0, $a0                       #left in $s0
    move $s1, $a1                       #right in $s1
    add $t0, $s0, $s1
    srl $s2, $t0, 1                     #mid=(left+right)/2 in $s2
    bge $s0, $s1, mergesort_finish	#base case
    move $a0, $s0			#arguments for recursive call
    move $a1, $s2			#left, mid
    jal mergesort			#first recursive call
    add $t0, $s2, 1
    move $a0, $t0			#arguments for second call
    move $a1, $s1			#mid+1 and right
    jal mergesort			#second recursive call
    move $a0, $s0			#arguents for merge function
    move $a1, $s1			#left, mid, right
    move $a2, $s2
    jal merge				#call to merge
mergesort_finish:
    lw $ra, 0($sp)                      #restore return address and
    lw $s0, 4($sp)                      #"saved" registers from stack
    lw $s1, 8($sp)
    lw $s2, 12($sp)
    add $sp, $sp, 16			#restore stack position
    jr $ra				#return to previous position before being called

merge:
    addi $sp, $sp, -32			#reserve $s0~$s7
    sw $s0, 0($sp)
    sw $s1, 4($sp)
    sw $s2, 8($sp)
    sw $s3, 12($sp)
    sw $s4, 16($sp)
    sw $s5, 20($sp)
    sw $s6, 24($sp)
    sw $s7, 28($sp)
    move $s0, $a0                       #left
    move $s1, $a1                       #right
    move $s2, $a2                       #mid
    la $s3, input                       #A
    la $s4, buffer                      #buf
    move $s5, $s0                       #i = left
merge_for:				#code for the for loop
    sll $t1, $s5, 2			#index = 4*i
    add $t2, $s3, $t1			#address of A[i]
    lw $t3, 0($t2)                      #load A[i]
    add $t2, $s4, $t1			#address for buf[i]
    sw $t3, 0($t2)                      #save buf[i]
    add $s5, $s5, 1                     #i++
    ble $s5, $s1, merge_for		#looping condition
    move $s5, $s0                       #i = left
    move $s6, $s0                       #left_i = left
    add $t0, $s2, 1
    move $s7, $t0                       #right_i = mid+1
merge_while1:				#code for first while loop
    slt $t0, $s2, $s6                   #mid<left_i ? 1:0
    slt $t1, $s1, $s7                   #right<right_i ? 1:0
    or $t2, $t1, $t0                    #$t0 or $t1 is true?
    bgtz $t2, merge_while2
    sll $t0, $s6, 2                     #index = 4*left_i
    add $t0, $s4, $t0                   #buf[left_i] address
    lw $t0, 0($t0)                      #load buf[left_i]
    sll $t1, $s7, 2                     #index = 4*right_i
    add $t1, $s4, $t1                   #buf[right_i] address
    lw $t1, 0($t1)                      #load buf[right_i]
    slt $t2, $t0, $t1			# (buf[left_i] < buf[right_i]) ? 1:0
    sll $t3, $s5, 2                     #index = 4*i
    add $t3, $s3, $t3                   #address of A[i]
    beqz $t2, while1_right		#if (buf[right_i] >= buf[left_i])
    b while1_left			#otherwise
while1_right:
    sw $t1, 0($t3)			#store into A
    add $s7, $s7, 1                     #right_i++
    b while1_finish
while1_left:
    sw $t0, 0($t3)			#store into A
    add $s6, $s6, 1                     #left_i++
while1_finish:
    add $s5, $s5, 1                     #i++
    b merge_while1

merge_while2:
    bgt $s6, $s2, merge_while3		#loop exit condition
    sll $t0, $s5, 2                     #index = 4*i
    add $t0, $s3, $t0                   #address of A[i]
    sll $t1, $s6, 2                     #index = 4*left_i
    add $t1, $s4, $t1                   #address of buf[left_i]
    lw  $t2, 0($t1)			#load buf element and save to A
    sw  $t2, 0($t0)
    add $s5, $s5, 1			#i++
    add $s6, $s6, 1			#left_i++
    b merge_while2			#loop
merge_while3:
    bgt $s7, $s1, merge_finish		#loop end condition
    sll $t0, $s5, 2                     #index = 4*i
    add $t0, $s3, $t0                   #address of A[i]
    sll $t1, $s7, 2                     #index = 4*right_i
    add $t1, $s4, $t1                   #address of buf[right_i]
    lw  $t2, 0($t1)			#move buf element to A
    sw  $t2, 0($t0)
    add $s5, $s5, 1			#i++
    add $s7, $s7, 1			#right_i++
    b merge_while3			#loop
merge_finish:
    lw $s0, 0($sp)			#restore $s0~$s7
    lw $s1, 4($sp)
    lw $s2, 8($sp)
    lw $s3, 12($sp)
    lw $s4, 16($sp)
    lw $s5, 20($sp)
    lw $s6, 24($sp)
    lw $s6, 28($sp)
    add $sp, $sp, 32
    jr $ra				#return to caller

print_output:
    li $t0, 0                           #i
    la $t1, input                       #A
    la $t2, input_length
    lw $t2, 0($t2)                      #input length
print:
    sll $t3, $t0, 2                     #index = 4*i
    add $t3, $t1, $t3                   #address of A[i]
    lw  $a0, 0($t3)                     #A[i]
    li $v0, 1				#print_int (A[i])
    syscall
    li $a0, ' '
    li $v0, 11				#print_char (' ')
    syscall
    add $t0, $t0, 1			#i++
    blt $t0, $t2, print			#i<length ? loop
    jr $ra				#return to caller (main)
