@0       D=A
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
         M=D+M
@2       D=A
@0       M=M+1
         A=M-1
         M=D
@0       M=M-1
         A=M
         D=M
         A=A-1
         D=M-D
@L461    D;JLT
(L541)
         D=-1
@L441    0;JMP
(L461)
         D=0
(L441)
@0       A=M
         M=D
@top1    D;JEQ
@0       D=A
@1       D=D+M
@15      M=D
@0       M=M-1
         A=M
         D=M
@15      A=M
         M=D
@0       D=A
@1       A=D+M
         D=M
@0       M=M+1
         A=M-1
         M=D
(top2)
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
@L462    D;JNE
(L542)
         D=-1
@L442    0;JMP
(L462)
         D=0
(L442)
@0       A=M
         M=D
@0       A=M
         M=!M
@top2    D;JEQ
@0       D=A
@1       A=D+M
         D=M
@0       M=M+1
         A=M-1
         M=D
@0       D=A
@2       D=D+M
@15      M=D
@0       M=M-1
         A=M
         D=M
@15      A=M
         M=D
