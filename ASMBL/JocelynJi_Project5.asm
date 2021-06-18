INCLUDE Irvine32.inc
strLen=10    ;initialize string length
.data
arr BYTE strLen DUP(?)          ;initalize array of length strLen

.code
    main PROC
        call Clrscr
        mov esi, offset arr     ;move offset of arr to esi
        mov ecx, 20             ;amount of random strings
        L1:
            call RandomString   ;loop the call of RandomString until amount is met
        Loop L1                 ;end loop 1
        call WaitMsg
        exit
    main ENDP

    RandomString PROC USES ecx  ;process creates randomized string
        mov ecx, lengthOf arr
        L2:
            mov eax, 26
            call RandomRange    ;generates random integer
            add eax, 65    
            mov [esi], eax      ;move value at eax to memory address esi
            call WriteChar      ;write character
        loop L2                 ;end loop 2
        call Crlf
        ret                     ;return to start
    RandomString ENDP           ;end RandomString

END main