INCLUDE Irvine32.inc

.data
msg1 BYTE " and ",0
msg2 BYTE " have GCD by loop of: ",0
msg3 BYTE " and GCD by recursion of: ",0

val1 DWORD  5           ;initialize values
val2 DWORD  20

val3 DWORD  24
val4 DWORD  18

val5 DWORD  11
val6 DWORD  7

val7 DWORD  432
val8 DWORD  226

val9 DWORD  26
val10 DWORD  13

.code

main PROC
    push val1           ;push values to access in gcd and gcd_rec
    push val2           
   call print_LOOP      
   call gcd             
   call print_REC
   call gcd_rec

   push val3
   push val4
   call print_LOOP
   call gcd
   call print_REC
   call gcd_rec

   push val5
   push val6
   call print_LOOP
   call gcd
   call print_REC
   call gcd_rec

   push val7
   push val8
   call print_LOOP
   call gcd
   call print_REC
   call gcd_rec

   push val9
   push val10
   call print_LOOP
   call gcd
   call print_REC
   call gcd_rec


exit
main ENDP


print_LOOP PROC     ;print out message preceding GCD

   mov eax,dword ptr[esp+8]     ;val 1
   call WriteDec
   mov edx,OFFSET msg1
   call WriteString
   mov eax,dword ptr[esp+4]     ;val 2
   call WriteDec
   mov edx,OFFSET msg2
   call WriteString
   call crlf
   ret

print_LOOP ENDP

print_REC PROC     ;print out message preceding recursive GCD

   mov edx, OFFSET msg3
   call WriteString
   call crlf
   ret

print_REC ENDP


gcd PROC        ;calculate gcd by loop

mov eax,dword ptr[esp+4]      ;move dividend to eax
cdq
mov ebx,dword ptr[esp+8]      ;move divisor to ebx
div ebx                       

L1:
   mov eax,ebx              ;divisor to eax
   mov ebx,edx              ;remainder to ebx
   cmp ebx,0                ;if remainder = 0, print GCD
   je L2
   mov dword ptr[esp+8],edx
   cdq
   div ebx                  
   loop L1

L2:
   call WriteDec
   call crlf
   ret 

gcd ENDP

gcd_REC PROC     ;calculate gcd by recursion

xor edx, edx                ;clear edx
mov eax,dword ptr[esp+4]    ;move dividend to eax
mov ebx,dword ptr[esp+8]    ;move divisor to ebx
div ebx
cmp edx,0                   ;if remainder not 0, call recursively
je L1
call gcd_REC

L1:
   mov eax,ebx              ;move divisor to eax for printing
   call WriteDec
   call crlf
   ret 8                    ;clear 8 bytes on the stack

gcd_REC ENDP

END main




