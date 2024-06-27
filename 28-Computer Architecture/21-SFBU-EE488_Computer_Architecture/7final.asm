.data
    prompt1: .asciiz "Enter first number $t4 to add: "
    prompt2: .asciiz "Enter second number $t5 to add: "
    prompt3: .asciiz "Enter number $t6 to subtract: "
    prompt4: .asciiz "Enter $s1 for calculation (s1 - 54321): "
    prompt5: .asciiz "Enter Divisor t2 for t2 / (s1 - 54321): "
    result1: .asciiz "Result of arithmetic operations t3: "
    result2: .asciiz "Result of division s3 = t2 / (s1 - 54321): "
    result3: .asciiz "Value loaded from memory: "
    result4: .asciiz "Stored 32768 at memory address: "
    op_info1: .asciiz "Performed t8 = Mem(a0);"
    op_info2: .asciiz "Performed Mem(a0 + 16) = 32768;"
    addr_info: .asciiz "Address used: "
    hello:   .asciiz "Hello World"
    newline: .asciiz "\n"

.text
.globl main
main:
    # [Original code remains the same up to the "Print Hello World" section]
        # Get input values
    li $v0, 4
    la $a0, prompt1
    syscall
    li $v0, 5
    syscall
    move $t4, $v0

    li $v0, 4
    la $a0, prompt2
    syscall
    li $v0, 5
    syscall
    move $t5, $v0

    li $v0, 4
    la $a0, prompt3
    syscall
    li $v0, 5
    syscall
    move $t6, $v0

    li $v0, 4
    la $a0, prompt4
    syscall
    li $v0, 5
    syscall
    move $s1, $v0

    li $v0, 4
    la $a0, prompt5
    syscall
    li $v0, 5
    syscall
    move $t2, $v0

    # Arithmetic operations
    add $t3, $t4, $t5       # $t3 = $t4 + $t5
    sub $t3, $t3, $t6       # $t3 = $t3 - $t6

    # Print result of arithmetic operations
    li $v0, 4
    la $a0, result1
    syscall
    li $v0, 1
    move $a0, $t3
    syscall
    li $v0, 4
    la $a0, newline
    syscall

    # Calculate s3 = t2 / (s1 - 54321)
    li $t0, 54321           # $t0 = 54321
    sub $t1, $s1, $t0       # $t1 = $s1 - 54321
    div $t2, $t1            # $t2 / $t1 (Note the order change)
    mflo $s3                # $s3 = quotient of division

    # Print result of division
    li $v0, 4
    la $a0, result2
    syscall
    li $v0, 1
    move $a0, $s3
    syscall
    li $v0, 4
    la $a0, newline
    syscall

    # New memory operations with a random stack address
    addi $sp, $sp, -32      # Allocate space on the stack
    la $t7, 0($sp)          # Load address of allocated stack space into $t7
    lw $t8, 0($t7)          # Load word from memory at address in $t7 to $t8

    # Print loaded value
    li $v0, 4
    la $a0, result3
    syscall
    li $v0, 1
    move $a0, $t8
    syscall
    li $v0, 4
    la $a0, newline
    syscall

    # Print operation information for t8 = Mem(a0)
    li $v0, 4
    la $a0, op_info1
    syscall
    li $v0, 4
    la $a0, newline
    syscall

    # Store 32768 at memory address + 16
    li $t0, 32768           # Load immediate value 32768 into $t0
    sw $t0, 16($t7)         # Store $t0 at memory address $t7 + 16

    # Print operation information for Mem(a0 + 16) = 32768
    li $v0, 4
    la $a0, op_info2
    syscall
    li $v0, 4
    la $a0, newline
    syscall

    # Print the address used for memory operations
    li $v0, 4
    la $a0, addr_info
    syscall
    li $v0, 1
    move $a0, $t7
    syscall
    li $v0, 4
    la $a0, newline
    syscall

    # Print confirmation of store operation
    li $v0, 4
    la $a0, result4
    syscall
    li $v0, 1
    move $a0, $t7
    addi $a0, $a0, 16       # Add 16 to the address for display
    syscall
    li $v0, 4
    la $a0, newline
    syscall

    # Print "Hello World"
    li $v0, 4
    la $a0, hello
    syscall
    li $v0, 4
    la $a0, newline
    syscall

    # Exit program
    li $v0, 10
    syscall
