include Irvine32.inc

Str_find PROTO, pSource:PTR BYTE, pTarget:PTR BYTE

.data

target BYTE 32 DUP(?)	;initalize strings
source BYTE 32 DUP(?)

str1 BYTE "Source string found at position ",0		
str2 BYTE " in Target string (counting from zero).",0,0ah
str3 BYTE "Unable to find Source string in Target string.",0,0ah

msg1 BYTE "Enter the source string: ", 0,0ah
msg2 BYTE "Enter the target substring: ", 0,0ah
msg3 BYTE "Repeat program? [Y/N]: ", 0
msg4 BYTE "Error, reenter choice please", 0

stop DWORD ?
lenTarget DWORD ?
lenSource DWORD ?
position DWORD ?

.code

main PROC

repeat_program:

	mov EDX, OFFSET msg1	;get input of source
	call WriteString
	mov ecx, SIZEOF source - 1 
	mov edx, offset target
	call ReadString

	mov EDX, OFFSET msg2	;get input of target
	call WriteString
	 mov ecx, SIZEOF target - 1 
	mov edx, offset source
	call ReadString


  INVOKE Str_find , ADDR source, ADDR target
  mov position,eax
  jz wasfound           ; if ZF=0, string not found
  mov edx,OFFSET str3   
  call WriteString
  jmp   quit
  

wasfound:                  
  mov edx,OFFSET str1
  call WriteString
  mov eax,position       
  call WriteDec
  mov edx,OFFSET str2
  call WriteString


quit:							;ask user to repeat program
	mov EDX, OFFSET msg3
	call WriteString
	call ReadChar
	call Crlf

	cmp AL, 'y'
	je repeat_program
	cmp AL, 'Y'
	je repeat_program
	cmp AL, 'N'
	je end_program
	cmp AL, 'n'
	je end_program

	mov EDX, OFFSET msg4		;if not 'n','N','Y',or'y' jump to quit
	call WriteString
	call ReadChar
	call Crlf
	jmp quit

end_program:

call WaitMsg
  exit

main ENDP


Str_find PROC, pSource:PTR BYTE, pTarget:PTR BYTE

  INVOKE Str_length,pTarget   ; get length of target
  mov lenTarget,eax
  INVOKE Str_length,pSource   ; get length of source
  mov lenSource,eax
  mov edi,OFFSET target       
  mov esi,OFFSET source       
   

  mov eax,edi    ; compute where to stop search
  add eax,lenTarget    
  sub eax,lenSource    
  inc eax   
  mov stop,eax           

  cld
  mov ecx, lenSource    

L1:
  pushad
  repe cmpsb            ; compare all bytes
  popad
  je found				; if found, exit
  inc edi               ; move to next target position
  cmp edi,stop          ;if edi reached target, exit
  jae notfound          ;else, loop back to L1
  jmp L1               

notfound:                 
  or eax,1           
  jmp done

found:                  
  mov eax,edi           ; compute position in target of find
  sub eax,pTarget
  cmp eax,eax   

done:
  ret

Str_find ENDP
END 

