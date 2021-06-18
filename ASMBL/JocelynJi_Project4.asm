includelib irvine32.lib
include irvine32.inc

;.386 
;.model flat, stdcall
;.stack 4096
;ExitProcess PROTO, dwExitCode:DWORD


.data
source BYTE "String string", 0      ;declare string
target BYTE SIZEOF source DUP ('0') ;result string


.code

main PROC

mov ECX, SIZEOF source -1;   ;move loop count to ECX 
mov EDI, OFFSET target - 2   ;move last char in string to EDI
mov ESI, OFFSET target	     ;move first char in target to ESI

L1:

mov AL, [EDI]  ;move element at address EDI to AL 
mov [ESI], AL  ;move AL to element at address ESI
dec EDI        ;dec to get char in string before last loop
inc ESI        ;inc to move target char to next index

LOOP L1        
mov BYTE PTR [ESI], 0    ;replace element at ESI with null char
mov EDX, OFFSET target  ;print reversed string
call WriteString

exit  ; End program
main ENDP
end main


