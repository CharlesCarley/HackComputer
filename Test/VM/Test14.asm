@256     D=A
@0       M=D
@1       M=D
@2       M=D
@3       M=D
@4       M=D
@7       D=A
@0       M=M+1
         A=M-1
         M=D
(top1)
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
@0       M=M+1
         A=M-1
         M=D
@0       M=M-1
         A=M
         D=M
         A=A-1
         D=M-D
@L541    D;JGT
         D=0
@L441    0;JMP
(L541)
         D=-1
(L441)
@0       A=M-1
         M=D
@0       M=M-1
         A=M
         D=M
@top1    
         D;JNE
@987     D=A
@0       M=M+1
         A=M-1
         M=D
@0       D=A
@1       D=D+M
@15      M=D
@0       M=M-1
         A=M
         D=M
@15      A=M
         M=D
