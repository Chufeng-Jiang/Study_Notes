.data
    prompt_s0: .asciiz "Enter value for $s0: "
    prompt_s1: .asciiz "Enter value for $s1: "
    prompt_s2: .asciiz "Enter value for $s2: "
    result_prompt: .asciiz "Result: "
    newline: .asciiz "\n"
.text
.globl main

main:
    # Prompt user to enter $s0
    li $v0, 4           # syscall code for print string
    la $a0, prompt_s0   # load address of prompt_s0
    syscall             # print prompt_s0

    # Read integer input for $s0
    li $v0, 5           # syscall code for read integer
    syscall             # read integer input
    move $s0, $v0       # move input value to $s0

    # Prompt user to enter $s1
    li $v0, 4           # syscall code for print string
    la $a0, prompt_s1   # load address of prompt_s1
    syscall             # print prompt_s1

    # Read integer input for $s1
    li $v0, 5           # syscall code for read integer
    syscall             # read integer input
    move $s1, $v0       # move input value to $s1

    # Prompt user to enter $s2
    li $v0, 4           # syscall code for print string
    la $a0, prompt_s2   # load address of prompt_s2
    syscall             # print prompt_s2

    # Read integer input for $s2
    li $v0, 5           # syscall code for read integer
    syscall             # read integer input
    move $s2, $v0       # move input value to $s2

    # Calculate $t0 = $s0 / 8 - 2 * $s1 + $s2
    srl $t1, $s0, 3     # $t1 = $s0 >> 3 (divide $s0 by 8)
    sll $t2, $s1, 1     # $t2 = $s1 << 1 (multiply $s1 by 2)
    sub $t3, $t1, $t2   # $t3 = $t1 - $t2
    add $t0, $t3, $s2   # $t0 = $t3 + $s2

    # Print the result
    li $v0, 4           # syscall code for print string
    la $a0, result_prompt   # load address of result_prompt
    syscall             # print result_prompt

    # Print $t0 (the result)
    li $v0, 1           # syscall code for print integer
    move $a0, $t0       # load $t0 into $a0
    syscall             # print $t0

    # Print newline
    li $v0, 4           # syscall code for print string
    la $a0, newline     # load address of newline
    syscall             # print newline

    # Exit program
    li $v0, 10          # syscall code for exit
    syscall             # exit program
