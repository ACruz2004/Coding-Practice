# Starter code for threeTimes.asm
# Anthony Cruz
# 6/4/2024

# The code then prompts the user for 3 integer values.
# The code outputs the summation of these 3 values multiplied by 3.


            .data      # data segment
	    .align 2   # align the next string on a word boundary
outpAuth:   .asciiz  "This is Anthony Cruz presenting threeTimes.\n"
            
  
outpPrompt: .asciiz  "Please enter an integer: "
	    .align 2   #align next prompt on a word boundary
outpStr:    .asciiz  "The sum of your numbers multiplied by 3 is: "
            .align 2   # align users input on a word boundary
outpAside:  .asciiz  "\n Aside: "
            .align 2   # align users input on a word boundary
inBrack:  .asciiz  "( "
            .align 2   # align users input on a word boundary
outBrack:  .asciiz  " )"
            .align 2   # align users input on a word boundary
plusSign:  .asciiz  " + "
            .align 2   # align users input on a word boundary
timesSign:  .asciiz  " * "
            .align 2   # align users input on a word boundary
#
# main begins
            .text      # code section begins
            .globl	main 
main:  
###############################################################
# system call to display the author of this code
	 la $a0,outpAuth	# system call 4 for print string needs address of string in $a0
	 li $v0,4		# system call 4 for print string needs 4 in $v0
	 syscall	

#
# system call to prompt user for input
# write a system call to read the user's integer value
# First Prompt
	 la $a0,outpPrompt	# system call 4 for print string needs address of string in $a0
	 li $v0,4		# system call 4 for print string needs 4 in $v0
	 syscall	
	 
	 li $v0, 5              # This system call reads the integer the user inputs
	 syscall 
	 move $t0, $v0          # Stores the integer into $t0
# Second Prompt 
	 la $a0,outpPrompt	# system call 4 for print string needs address of string in $a0
	 li $v0,4		# system call 4 for print string needs 4 in $v0
	 syscall	
	 
	 li $v0, 5              # This system call reads the integer the user inputs
	 syscall 
	 move $t1, $v0          # Stores the integer into $t1
# Third Prompt
	 la $a0,outpPrompt	# system call 4 for print string needs address of string in $a0
	 li $v0,4		# system call 4 for print string needs 4 in $v0
	 syscall	
	 
	 li $v0, 5              # This system call reads the integer the user inputs
	 syscall 
	 move $t2, $v0          # Stores the integer into $t2
	 
###############################################################



# We have not studied looping, so you will need to repeat the prompt for input
# and do the calculation as you see fit

	#ADDITION
	 add $t3,$t0,$t1        # Stores the sum of t0 and t1 into t3
	 add $t3,$t3,$t2        # Stores the sum of t3 and t2 into t3
	 
	#MULTIPLICATION
	 li $t4, 3              # Loads 3 into t4 
	 mul $t5,$t4,$t3
	 


# system call to display "The sum of your numbers multiplied by 3 is: "
	 la $a0,outpStr 	# system call 4 for print string needs address of string in $a0
	 li $v0,4		# system call 4 for print string needs 4 in $v0
	 syscall  	
################################################################
# write a system call to display the calculation
	 move $a0, $t5
	 li $v0, 1 
	 syscall

# writing the Aside (I think this is required)
    la $a0, outpAside              
    li $v0, 4                      
    syscall

# Moving the input ints into different temps
    move $t6, $t0   
    move $t7, $t1
    move $t8, $t2  
    move $t9, $t4                   # THIS IS THE TEMP ADD FOR 3       
# Printing Bracket Number 1 
    la $a0, inBrack                
    li $v0, 4                      
    syscall
    
# Printing the integers
# Uno
    move $a0, $t6                  # Move the integer to $a0 (It worked above for outputting the product)
    li $v0, 1                      # System call for print integer
    syscall
    
    la $a0, plusSign               # Adds the plus sign             
    li $v0, 4                      
    syscall
    
# Dos
    move $a0, $t7                  # Move the integer to $a0
    li $v0, 1                      # System call for print integer
    syscall
    
    la $a0, plusSign               # Adds the second plus sign             
    li $v0, 4                      
    syscall
    
# Tres
     move $a0, $t8                  # Move the integer to $a0
     li $v0, 1                      # System call for print integer
     syscall
    
# Printing Bracket Number 2
    la $a0, outBrack                
    li $v0, 4                      
    syscall
    
    la $a0, timesSign               # Adds the times sign             
    li $v0, 4                      
    syscall
             
    move $a0, $t9                  # Move the integer to $a0
    li $v0, 1                      # System call for print integer
    syscall
	
# Exit gracefully
         li   $v0, 10       # system call for exit
         syscall            # close file
###############################################################
