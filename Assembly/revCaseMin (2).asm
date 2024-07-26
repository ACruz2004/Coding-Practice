# Starter code for reversing the case of a 30 character input.
# Put in comments your name and date please.  You will be
# revising this code.
#
# Created by Anthony Cruz
# Students should modify this code
# 
# This code displays the authors name (you must change
# outpAuth to display YourFirstName and YourLastName".
#
# The code then prompts the user for input
# stores the user input into memory "varStr"
# then displays the users input that is stored in"varStr" 
#
# You will need to write code per the specs for 
# procedures main, revCase and function findMin.
#
# revCase will to reverse the case of the characters
# in varStr.  You must use a loop to do this.  Another buffer
# varStrRev is created to hold the reversed case string.
# 
# Please refer to the specs for this project, this is just starter code.
#
# In MARS, make certain in "Settings" to check
# "popup dialog for input syscalls 5,6,7,8,12"
#
            .data      # data segment
	    .align 2   # align the next string on a word boundary
outpAuth:   .asciiz  "This is Anthony Cruz presenting revCaseMin.\n"
outpPrompt: .asciiz  "Please enter 30 characters (upper/lower case mixed):\n"
	    .align 2   #align next prompt on a word boundary 
outpStr:    .asciiz  "You entered the string: "
            .align 2   # align users input on a word boundary
varStr:     .space 32  # will hold the user's input string thestring of 20 bytes 
                       # last two chars are \n\0  (a new line and null char)
                       # If user enters 31 characters then clicks "enter" or hits the
                       # enter key, the \n will not be inserted into the 21st element
                       # (the actual users character is placed in 31st element).  the 
                       # 32nd element will hold the \0 character.
                       # .byte 32 will also work instead of .space 32
            .align 2   # align next prompt on word boundary
outpStrRev: .asciiz   "\n Your string in reverse case is: "
            .align 2   # align the output on word boundary
varStrRev:  .space 32  # reserve 32 characters for the reverse case string
	    .align 2   # align  on a word boundary
outpStrMin: .asciiz    "The min ASCII character after reversal is: "


endl:       .asciiz   "\n"
	    .align 2   # align  on a word boundary
#
            .text      # code section begins
            .globl	main 
main:  
#
# system call to display the author of this code
#
	 la $a0,outpAuth	# system call 4 for print string needs address of string in $a0
	 li $v0,4		# system call 4 for print string needs 4 in $v0
	 syscall	

#
# system call to prompt user for input
#
	 la $a0,outpPrompt	# system call 4 for print string needs address of string in $a0
	 li $v0,4		# system call 4 for print string needs 4 in $v0
	 syscall	
#
# system call to store user input into string thestring
#
	li $v0,8		# system call 8 for read string needs its call number 8 in $v0
        			# get return values
	la $a0,varStr    	# put the address of thestring buffer in $t0
	li $a1,32 	        # maximum length of string to load, null char always at end
				# but note, the \n is also included providing total len < 22
        syscall
        #move $t0,$v0		# save string to address in $t0; i.e. into "thestring"
#
# system call to display "You entered the string: "
#
	 la $a0,outpStr 	# system call 4 for print string needs address of string in $a0
	 li $v0,4		# system call 4 for print string needs 4 in $v0
	 syscall  	
#
# system call to display user input that is saved in "varStr" buffer
#
	 la $a0,varStr  	# system call 4 for print string needs address of string in $a0
	 li $v0,4		# system call 4 for print string needs 4 in $v0
	 syscall	
#
# Your code to invoke revCase goes next	 
#
	jal revCase              # Jump and link invokes a function

# Exit gracefully from main()
         li   $v0, 10       # system call for exit
         syscall            # close file
         
         
################################################################
# revCase() procedure can go next
################################################################
#  Write code to reverse the case of the string.  The base address of the
# string should be in $a0 and placed there by main().  main() should also place into
# $a1 the number of characters in the string.
# You will want to have a label that main() will use in its jal 
# instruction to invoke revCase, perhaps revCase:
#
revCase:
# Going to use two loops
# These loops will jump to the functions lower and upper depending on if the input is in 
# Uppercase or lowercase
	li $t3, 0               # Loop counter
	la $t0, varStr		# $t0 to varStr
	la $t2, varStrRev       # $t2 to varStrRev
	j Loop1
	
Loop1:  beq $t3, $a1, Exit      # The loop that will be counted, goes to a1 due to a1 being the maximum number
	lbu $t1, 0($t0)         # Load bit unassigned
	blt $t1, 64, Loop2  	# Go to loop two if $t1 is less than 64
	blt $t1, 95, upper      # Go to upper if $t1 is higher than 64 but less than 95
	j lower
	
Loop2:
	sb $t1, 0($t2)
	addi $t0, $t0, 1
	addi $t2, $t2, 1
	addi $t3, $t3, 1
	j Loop1
upper:
	add $t1, $t1, $a1  
	j Loop2
lower:
	sub $t1, $t1, $a1
	j Loop2

#
################################################################
# system call to display "Your string in reverse case is: "
Exit:

# After reversing the string, you may print it with the following code.
# This is the system call to display "Your string in reverse case is: "
	 la $a0,outpStrRev 	# system call 4 for print string needs address of string in $a0
	 li $v0,4		# system call 4 for print string needs 4 in $v0
	 syscall  	
	# system call to display the user input that is in reverse case saved in the varRevStr buffer
	 la $a0,varStrRev  	# system call 4 for print string needs address of string in $a0
	 li $v0,4		# system call 4 for print string needs 4 in $v0
	 syscall
	
#
# Your code to invoke findMin() can go next
	addiu $sp, $sp, -8	#putting the two words into the stack (found fixes my previous error)
	sw   $ra, 4($sp)
	jal findMin 
	lw   $v0, ($sp)
	lw $ra, 4($sp)
	
# Your code to return to the caller main() can go next
 	move $t9, $v0		# Gets the min value stored to $v0
 	
 	la $a0,outpStrMin	# system call 4 for print string needs address of string in $a0
	li $v0,4		# system call 4 for print string needs 4 in $v0
	syscall
 	
 	move $a0, $t9
 	li $v0,11		# system call 4 for print string needs 4 in $v0
	syscall 
	
	jr $ra 


################################################################
# findMin() function can go next
################################################################
#  Write code to find the minimum character in the string.  The base address of the
# string should be in $a0 and placed there by revCase.  revCase() should also place into
# $a1 the number of characters in the string.
#  You will want to have a label that revCase() will use in its jal 
# instruction to invoke revCase, perhaps findMin:
#
findMin:
	
	li $t3, 0		# loop counter just like in the first loops
	la $t2, varStrRev	
	lb $t1, 0($t2)
	move $t9, $t1
	j checkLoop
	
	
checkLoop :	
	beq $t3, $a1, exitMin
	lb $t1, 0($t2)
	blt $t1, 64, next 
	blt  $t1, $t9, lessChar 
	j next
	
next: 
	addi $t2, $t2, 1
	addi $t3, $t3, 1
	j checkLoop
lessChar:
	move $t9, $t1
	j next

exitMin:

# write use a loop and find the minimum character
# system call to display "The min ASCII character after reversal is:  "
 	move $v0, $t9	#moving min value to $v0	 
	sw   $v0, ($sp)  #saving minimum value to the stack
	jr $ra		

#
# After reversing the string, you may print it with the following code.
# This is the system call to display "Your string in reverse case is: "
	 la $a0,outpStrRev 	# system call 4 for print string needs address of string in $a0
	 li $v0,4		# system call 4 for print string needs 4 in $v0
	 syscall  	
# The endl afterwards
# Just adds an endl that wasn't showing up so I just did it manually
	 la $a0,endl
	 li $v0,4
	 syscall
# system call to display the user input that is in reverse case saved in the varRevStr buffer
	 la $a0,varStrRev  	# system call 4 for print string needs address of string in $a0
	 li $v0,4		# system call 4 for print string needs 4 in $v0
	 syscall	


