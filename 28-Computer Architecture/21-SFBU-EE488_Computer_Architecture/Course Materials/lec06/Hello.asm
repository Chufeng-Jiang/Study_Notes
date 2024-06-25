.data
prompt1: .asciiz "Enter the first number: "
prompt2: .asciiz "Enter the second number (a prime number): "
result_msg: .asciiz "Result (0 if prime factor, remainder otherwise): "

.text
.globl main

main:
    # Prompt for first number
    li $v0, 4
    la $a0, prompt1
    syscall

    # Read first number
    li $v0, 5
    syscall
    move $t0, $v0  # Store first number in $t0

    # Prompt for second number
    li $v0, 4
    la $a0, prompt2
    syscall

    # Read second number
    li $v0, 5
    syscall
    move $t1, $v0  # Store second number in $t1

    # Perform division
    div $t0, $t1
    mfhi $t2  # Store remainder in $t2

    # Print result message
    li $v0, 4
    la $a0, result_msg
    syscall

    # Print the result (remainder)
    li $v0, 1
    move $a0, $t2
    syscall

    # Exit program
    li $v0, 10
    syscall