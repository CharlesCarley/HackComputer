@256     D=A
@0       M=D
@1       M=D
@2       M=D
@3       M=D
@4       M=D
@256     D=A
@0       M=D
@300     D=A
@1       M=D
@400     D=A
@2       M=D
@6       D=A
@400     M=D
@3000    D=A
@401     M=D
@1       D=A
@2       A=D+M
         D=M
@0       M=M+1
         A=M-1
         M=D
@1       D=A
@3       D=D+A
@15      M=D
@0       M=M-1
         A=M
         D=M
@15      A=M
         M=D
@0       D=A
@0       M=M+1
         A=M-1
         M=D
@0       D=A
@4       D=D+M
@15      M=D
@0       M=M-1
         A=M
         D=M
@15      A=M
         M=D
@1       D=A
@0       M=M+1
         A=M-1
         M=D
@1       D=A
@4       D=D+M
@15      M=D
@0       M=M-1
         A=M
         D=M
@15      A=M
         M=D
@0       D=A
@2       A=D+M
         D=M
@0       M=M+1
         A=M-1
         M=D
@2       D=A
@0       M=M+1
         A=M-1
         M=D
@0       M=M-1
         A=M
         D=M
         A=A-1
         M=M-D
@0       D=A
@2       D=D+M
@15      M=D
@0       M=M-1
         A=M
         D=M
@15      A=M
         M=D
(MAIN_LOOP_START)
@0       D=A
@2       A=D+M
         D=M
@0       M=M+1
         A=M-1
         M=D
@0       M=M-1
         A=M
         D=M
@COMPUTE_ELEMENT
         D;JNE
@END_PROGRAM
         D=A
         0;JMP
(COMPUTE_ELEMENT)
@0       D=A
@4       A=D+M
         D=M
@0       M=M+1
         A=M-1
         M=D
@1       D=A
@4       A=D+M
         D=M
@0       M=M+1
         A=M-1
         M=D
@0       M=M-1
         A=M
         D=M
         A=A-1
         M=D+M
@2       D=A
@4       D=D+M
@15      M=D
@0       M=M-1
         A=M
         D=M
@15      A=M
         M=D
@1       D=A
@3       A=D+A
         D=M
@0       M=M+1
         A=M-1
         M=D
@1       D=A
@0       M=M+1
         A=M-1
         M=D
@0       M=M-1
         A=M
         D=M
         A=A-1
         M=D+M
@1       D=A
@3       D=D+A
@15      M=D
@0       M=M-1
         A=M
         D=M
@15      A=M
         M=D
@0       D=A
@2       A=D+M
         D=M
@0       M=M+1
         A=M-1
         M=D
@1       D=A
@0       M=M+1
         A=M-1
         M=D
@0       M=M-1
         A=M
         D=M
         A=A-1
         M=M-D
@0       D=A
@2       D=D+M
@15      M=D
@0       M=M-1
         A=M
         D=M
@15      A=M
         M=D
@MAIN_LOOP_START
         D=A
         0;JMP
(END_PROGRAM)