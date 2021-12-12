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
(L461)
         D=-1
@L441    D;JMP
(L541)
         D=0
(L441)
@0       A=M
         M=D
@top1    D;JEQ
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
