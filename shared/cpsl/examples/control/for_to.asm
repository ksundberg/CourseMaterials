.text
.globl main
main:	la $gp, GA
	ori $fp, $sp, 0
BB1:	
	li $8, 0
	addi $9, $gp, 0 # Load a global
	sw $8, 0($9) #store memory
	j BB2
BB2:	
	li $8, 5
	addi $9, $gp, 0 # Load a global
	lw $9, 0($9)
	slt $8, $8, $9
	bne $8, $zero, BB3
	j BB4
BB3:	
	li $v0, 10
	syscall
BB4:	
	addi $8, $gp, 0 # Load a global
	lw $8, 0($8)
	li $v0, 1
	move $a0, $8
	syscall    # writing an integer
	li $v0, 4
	la $a0, SL0
	syscall    # writing a string
	addi $8, $gp, 0 # Load a global
	lw $8, 0($8)
	addi $8, $8, 1
	addi $9, $gp, 0 # Load a global
	sw $8, 0($9) #store memory
	j BB2
.data
SL0: 	.asciiz " \n"
.align 2
GA:
