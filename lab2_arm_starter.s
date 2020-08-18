@@@ PRINT STRINGS, CHARACTERS, INTEGERS TO STDOUT
.equ Stdout,      0x01  @ Set output mode to be Output View
.equ SWI_PrStr,   0x69  @ Write a null-ending string
.equ SWI_PrInt,   0x6b  @ Write a null-ending string
.equ SWI_Exit,    0x11  @ Stop execution

.text

.align 8
.global get_max_ARM
.type get_max_ARM, %function 

get_max_ARM:
    @ YOUR CODE GOES HERE (list *ls is in r0)
    @-----------------------

    @ (your code)

    @ put your return value in r0 here:    

	@ if( ls->size != 0)
	LDR r1, [r0] @ls->sortedList
	LDR r2, [r0, #4] @ls->size
	
	
	CMP r2, #0
	BEQ else_max
	
	SUB r3, r2, #1
	LDR r4, [r1, r3, LSL #2] @ls->sortedList[(ls->size) - 1]
	
	MOV r0, r4
	BX lr
	
else_max:
	BAL return_negOne
	
    @-----------------------

    @ ARM equivalent of return
    BX lr

	
	
	
.align 8
.global get_min_ARM
.type get_min_ARM, %function

get_min_ARM:

    @ YOUR CODE GOES HERE (list *ls is in r0)
    @-----------------------

    @ (your code)

    @ put your return value in r0 here:    

	@ if( ls->size != 0)
	LDR r1, [r0] @ls->sortedList
	LDR r2, [r0, #4] @ls->size
	
	
	CMP r2, #0
	BEQ else_min
	
	LDR r4, [r1] @ls->sortedList[0]
	
	MOV r0, r4
	BX lr
	
else_min:
	BAL return_negOne
	
    @-----------------------

    @ ARM equivalent of return
    BX lr

	
	
	
	
.align 8
.global pop_min_ARM
.type pop_min_ARM, %function

pop_min_ARM:

    @ YOUR CODE GOES HERE (list *ls is in r0)
    @-----------------------

    LDR r1, [r0,#4]	@ls->size
	
	
	@if ls->size != 0
	
	CMP r1, #0
	BEQ return_negOne
	
	@decrement size
	SUB r1, r1, #1
	STR r1, [r0, #4]
	
	LDR r2, [r0] @ls->sortedList
	LDR r7, [r2] @ls->sortedList[0] (minVal)
	
	MOV r3, #0 @counter (i)
	BAL test_pop_min_loop

pop_min_loop:
	
    ADD r4, r3, #1 @ i+1
    LDR r5, [r2, r4, LSL #2] @ ls->sortedList[i+1]
    STR r5, [r2, r3, LSL #2] @ ls->sortedList[i]
		
	ADD r3, r3, #1 @++i
test_pop_min_loop:
	CMP r3, r1
	BLT pop_min_loop
	
	
	@ put your return value in r0 here:
	MOV r0, r7
    @-----------------------


    @ ARM equivalent of return
    BX lr

	
	
	
	
.align 8
.global remove_val_ARM
.type remove_val_ARM, %function

remove_val_ARM:

    @ YOUR CODE GOES HERE (list *ls is in r0, int val is in r1)
    @-----------------------
	MOV r8, #0 @number of values deleted
	
	@begin outer loop
	@for (i = 0; i < ls->size; ++i)
    LDR r9, [r0, #4] @ls->size
	MOV r2, #0 @counter (i)
	
	BAL test_remove_val_loop
remove_val_loop:
	
	@if (val == ls->sortedList[i])
	LDR r3, [r0] @ls->sortedList
	LDR r4, [r3, r2, LSL #2] @ls->sortedList[i]
	
	CMP r1, r4
	BNE end_if
	
	@decrement size
	SUB r9, r9, #1
	STR r9, [r0, #4] @(ls->size)--;
	
	
	
	@begin inner loop
	MOV r5, r2 @r5 = counter (j)
	
	BAL test_remove_val_inner_loop
remove_val_inner_loop:	
	
    ADD r6, r5, #1 @j+1
	LDR r7, [r3, r6, LSL #2] @ ls->sortedList[j+1]
	STR r7, [r3, r5, LSL #2] @ ls->sortedList[j]
	
	@increment inner loop counter (j)
	ADD r5, r5, #1
test_remove_val_inner_loop:
	CMP r5, r9
	BLT remove_val_inner_loop
	@end inner loop

	
	
	
	ADD r8, r8, #1 @number of deleted values
	
	@Decrement i for any potential duplicates to be retested
	SUB r2, r2, #1 
		
end_if:
	
	@increment counter (i) for outer loop
    ADD r2, r2, #1
test_remove_val_loop:
	CMP r2, r9
	BLT remove_val_loop
	@end outer loop
	
	
	
    @ put your return value in r0 here:

	MOV r0, r8
    @-----------------------

    @ ARM equivalent of return
    BX lr

	
	
	
	
.align 8
.global search_ARM
.type search_ARM, %function

search_ARM:
    @ YOUR CODE GOES HERE (list *ls is in r0, int val is in r1)
    @-----------------------

    @begin for loop
	MOV r2, #0 @counter (i)
	LDR r3, [r0, #4] @ls->size
	
	BAL test_search_loop
search_loop:
    
	@begin if statement
	
	LDR r4, [r0]
	LDR r5, [r4, r2, LSL #2] @ls->sortedList[i]
	
	CMP r1, r5
	BNE end_search_if
	
	BAL search_return
    @end if statement

end_search_if:
	@increment counter (i)
    ADD r2, r2, #1
test_search_loop:
	CMP r2, r3
	BLT search_loop
	@end for loop

	BAL return_negOne
	
    @ put your return value in r0 here:
search_return:
	MOV r0, r2
    @-----------------------

    @ ARM equivalent of return
    BX lr

	
	
	
	
.align 8
.global insert_ARM
.type insert_ARM, %function

insert_ARM:
    @ YOUR CODE GOES HERE (list *ls is in r0, int val in r1)
    @-----------------------

    @ (your code)

	
	
	/** 1) find index where insert is required for val **/
	/** 	
	* for (i = 0; i < ls->size; ++i) {
	*     if (val < ls->sortedList[i]) {
	*         break;
	*     }
	* }
	*/
	
	@for( i=0; i < ls->size; ++i)
	LDR	r2, [r0, #4]        @ r2 = ls->size
	MOV	r3, #0              @ for loop counter (i)
	LDR	r4, [r0]            @ r4 = ls->sortedList

		
	@if( ls->size == ls->maxSize)
	@ return -1
	
	LDR r9, [r0, #8] 		@ls->maxSize
	CMP r2, r9 
	BEQ return_negOne
	
	
	BAL test_insert_size_array
loop_insert_size_array:
	
	
	@ if(val < ls->sortedList[i])
	LDR	r5, [r4, r3, LSL #2] @ ls->sortedList[i]
	
	CMP	r1, r5 
	BLE break_loop
	
	ADD r3, r3, #1 @ increment counter (i++)

test_insert_size_array:
	CMP	r3, r2 @ Have we reached size of array?
	BLT loop_insert_size_array @ if not, loop again
	
break_loop:
	
	
	/** 2) Insert val into correct index of array**/
	/**
	* for (j = ls->size; j > i; --j) {
	*	ls->sortedList[j] = ls->sortedList[j-1];
	* }
	*/
	
	MOV r6, r2	@ loop counter (j) = ls->size
	BAL test_insert_into_array
	
loop_insert_into_array:
	SUB r8, r6, #1 @ j-1
	LDR r7, [r4, r8, LSL #2] @ ls->sortedList[j-1]
	STR r7, [r4, r6, LSL #2] @ ls->sortedList[j]
	
	SUB r6, r6, #1	@ --j

test_insert_into_array:
	CMP r6, r3
	BGT loop_insert_into_array
	
	
	@increment size
	ADD r2, r2, #1
	STR r2, [r0,#4]
	
	@insert into array
	STR r1, [r4, r3, LSL #2] @ls->sortedList[i]
	

    @ put your return value in r0 here:
	MOV r0, r3
    @-----------------------

    @ ARM equivalent of return
    BX lr
	
return_negOne:	
	MOV r0, #-1
	BX lr

.align 8
.global print_ARM

.type print_ARM, %function

print_ARM:
    @ Save caller's registers on the stack
    @push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE (list *ls is in r0)
    @-----------------------
    MOV r4, r0 @ r4 = ls
    LDR r6, [r4] @ r6 = ls->sortedList
    LDR r7, [r4, #4] @ r7 = ls->size
    MOV r5, #-1 @ r5 = -1 (i)
    
loop:
    ADD r5, r5, #1
    CMP r5, r7
    BGE continued 
    MOV r0, #Stdout         @ mode is Stdout
    LDR r1,[r6, r5, LSL #2]
    SWI SWI_PrInt
    B loop

continued:
    MOV r0, #Stdout         @ mode is Stdout
    LDR r1, =nl          @ new line
    SWI SWI_PrStr

    @ put your return value in r0 here:

    @-----------------------

    @ restore caller's registers
    @pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr


.align 8
.global _start
.type _start, %function

_start:
    LDR R0, =sorted_list
    LDR R2, =sorted_array
    STR R2, [R0]

    LDR R0, =sorted_list
    MOV R1, #1
    BL insert_ARM

    LDR R0, =sorted_list
    MOV R1, #2
    BL insert_ARM

    LDR R0, =sorted_list
    MOV R1, #3
    BL insert_ARM

    LDR R0, =sorted_list
    MOV R1, #4
    BL insert_ARM
	
    LDR R0, =sorted_list
    BL print_ARM


.data
nl: .asciz "\n"
.align 4
sorted_list: .word 0
size: .word 0
maxSize: .word 100
sorted_array: .skip 400
.align 4
.end