.386
.model flat,stdcall
.stack 4096
ExitProcess PROTO, dwExitCode:DWORD


;BYTE               8-bit unsigned integer;
;SBYTE              8-bit signed integer;
;WORD               16-bit unsigned integer;
;SWORD              16-bit signed integer;
;DWORD              32-bit unsigned integer;
;SDWORD             32-bit signed integer;
;FWORD              48-bit integer;
;QWORD              64-bit integer;
;TBYTE              80-bit (10 byte) integer;
;REAL4              32-bit (4 byte) IEEE short real;
;REAL8              64-bit (8 byte) IEEE long real;
;REAL10             80-bit (10 byte) IEEE extended real;


SUN=0
MON=1
TUE=2
WED=3
THU=4
FRI=5
SAT=6

str1 EQU <"Apple",0>
str2 EQU <"Banana",0>
str3 EQU <"Citrus",0>


.data

byte1 BYTE 12
sbyte1 SBYTE -12
word1 WORD 1248
sword1 SWORD -1248
dword1 DWORD 12412412
sdword1 SDWORD -12412412
fword1 FWORD 10
qword1 QWORD 10
tbyte1 TYBTE 10
real41 REAL4 2.1
real81 REAL8 -15.4e-2
real101 REAL10 -2800.5e+2

first BYTE str1
second BYTE str2
third BYTE str3

daysArray BYTE SUN,MON,TUE,WED,THU,FRI,SAT

.code
main PROC

	mov eax, 1h
	mov ebx, 2h
	mov ecx, 3h
	mov edx, 4h

	add eax, ebx
	add ecx, edx
	sub eax, ecx


INVOKE ExitProcess,0 

main endp
end main


