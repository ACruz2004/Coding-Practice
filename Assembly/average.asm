# 7/2/2024 
# Anthony Cruz
# Average.asm
# Prompt the user for the number of floating point values that the user will enter. You MUST
# save this number as in integer or 10 points are deducted from the assignment. Later you
# will need to convert it to a float.


.data      
howmany:      .asciiz  "How Many Numbers Would You Like To Average? "
	      .align 2 #align next prompt on a word boundary
	      
digdecimal:   .asciiz  "\n Please enter a 3 digit decimal d.dd: "
	      .align 2 #align next prompt on a word boundary
	      
avgprompt:    .asciiz  "\n The Average is: "
	      .align 2 #align next prompt on a word boundary

constzero:    .float 0.0
	      
.text
.globl main 
main: 
	########## Prompting the user with howmany ##########
	li $v0,4		# system call 4 for print string needs 4 in $v0
	la $a0,howmany		# system call 4 for print string needs address of string in $a0
	syscall	
	
	########## Reading the number of values ##########
	li $v0, 5               # reading the int
	syscall
	move $t0, $v0           # $t0 is now the number of values
	
	########## Converting int value to float ##########
	mtc1 $t0, $f2
	cvt.s.w $f2, $f2
	
	########## Loop for floating point numbers ##########
	li $t1, 0               # the loop counter
	l.s $f0, constzero      # the sum will be stored here originally I didn't have it set to l.s

loop:
	########## Start of loop for prompting decimals ##########

	li $v0, 4 
	la $a0, digdecimal      # digdecimal address is loaded into $a0
	syscall
	
	########## Reading the given decimals ##########
	li $v0, 6               # reading the decimal 6 is for reading a float
	syscall 
	
	########## Moving the input ##########
	mov.s  $f12, $f0       # moves the input to f12
	
	add.s  $f4, $f12, $f4   # get the sum of f12 and f4 and store it into f4
	    
	addi $t1, $t1, 1        # increment the loop counter 
	
	blt $t1, $t0, loop      # repeats the loop if the loop counter is less than the number of values


	########## Calculating and loading the average prompt ##########
	div.s $f0, $f4, $f2

	
	li $v0, 4
	la $a0, avgprompt       # avgprompt address is loaded into $a0    
	syscall
	
	########## Displaying the average #########
	mov.s $f12, $f0
	li $v0, 2               # prints what is in $f12
	syscall
	
	########## Exit the program ##########
         li   $v0, 10           # system call for exit
         syscall                # close file
         
	########## Done with program ##########
   
