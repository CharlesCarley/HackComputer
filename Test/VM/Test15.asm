@256     D=A
@0       M=D
@1       M=D
@2       M=D
@3       M=D
@4       M=D
@1       D=A
@0       M=M+1
         A=M-1
         M=D
@L1      
         D=A
         0;JMP
(L2)
@4       D=A
@0       M=M+1
         A=M-1
         M=D
@0       M=M-1
         A=M
         D=M
         A=A-1
         M=D+M
@L3      
         D=A
         0;JMP
(L4)
@5       D=A
@0       M=M+1
         A=M-1
         M=D
@0       M=M-1
         A=M
         D=M
         A=A-1
         M=M-D
@L5      
         D=A
         0;JMP
(L1)
@5       D=A
@0       M=M+1
         A=M-1
         M=D
@0       M=M-1
         A=M
         D=M
         A=A-1
         M=D+M
@L2      
         D=A
         0;JMP
(L3)
@20      D=A
@0       M=M+1
         A=M-1
         M=D
@0       M=M-1
         A=M
         D=M
         A=A-1
         M=D+M
@L4      
         D=A
         0;JMP
(L5)
@0       D=A
@1       D=D+M
@15      M=D
@0       M=M-1
         A=M
         D=M
@15      A=M
         M=D