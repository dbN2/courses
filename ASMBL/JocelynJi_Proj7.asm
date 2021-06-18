include Irvine32.inc


.data
choice BYTE ?
msg1 BYTE "Enter the multiplicant: ", 0
msg2 BYTE "Enter the multiplier: ", 0
msg3 BYTE "The product is : ", 0
msg4 BYTE "Repeat program? [Y/N]: ", 0

.code

main PROC
repeat_program:
	mov EDX, OFFSET msg2
	call WriteString
	call ReadInt
	mov EBX, EAX

	mov EDX, OFFSET msg1
	call WriteString
	call ReadInt
	call Crlf

	call Multiply
	mov EDX, OFFSET msg3
	call WriteString
	call WriteDec			;print result of multiply
	call Crlf

	mov EDX, OFFSET msg4
	call WriteString
	call ReadChar
	call Crlf

	cmp AL, 'y'
	je repeat_program
	cmp AL, 'Y'
	je repeat_program

	call WaitMsg
	exit

main ENDP


Multiply PROC
	push EDX
	push EBX
	push ECX

	mov EDX, EAX		; EDX is multiplicand
	mov ECX, 16			; number of loops is  16
	mov EAX, 0			; set sum to 0

L1:
	test EBX, 00000001h	; if last bit in EBX is 0. add EDX to EAX
	jz ZERO				; else jump to ZERO
	add EAX, EDX

ZERO:
	shl EDX, 1			; shift multiplicand left
	shr EBX, 1			; shift multiplier right
	loop L1

	pop ECX				;preserve values of registers
	pop EBX
	pop EDX
	ret

Multiply ENDP

END
