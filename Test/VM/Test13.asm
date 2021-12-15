@256                 D=A
@0                   M=D
@1                   M=D
@2                   M=D
@3                   M=D
@4                   M=D
@1                   D=A
@0                   M=M+1
                     A=M-1
                     M=D
@2                   D=A
@0                   M=M+1
                     A=M-1
                     M=D
@0                   M=M-1
                     A=M
                     D=M
                     A=A-1
                     D=M-D
@L541                D;JLT
                     D=0
@L441                0;JMP
(L541)
                     D=-1
(L441)
@0                   A=M-1
                     M=D
@3                   D=A
@1                   D=D+M
@15                  M=D
@0                   M=M-1
                     A=M
                     D=M
@15                  A=M
                     M=D
@2                   D=A
@0                   M=M+1
                     A=M-1
                     M=D
@1                   D=A
@0                   M=M+1
                     A=M-1
                     M=D
@0                   M=M-1
                     A=M
                     D=M
                     A=A-1
                     D=M-D
@L542                D;JGT
                     D=0
@L442                0;JMP
(L542)
                     D=-1
(L442)
@0                   A=M-1
                     M=D
@4                   D=A
@1                   D=D+M
@15                  M=D
@0                   M=M-1
                     A=M
                     D=M
@15                  A=M
                     M=D
@3                   D=A
@0                   M=M+1
                     A=M-1
                     M=D
@3                   D=A
@0                   M=M+1
                     A=M-1
                     M=D
@0                   M=M-1
                     A=M
                     D=M
                     A=A-1
                     D=M-D
@L543                D;JEQ
                     D=0
@L443                0;JMP
(L543)
                     D=-1
(L443)
@0                   A=M-1
                     M=D
@5                   D=A
@1                   D=D+M
@15                  M=D
@0                   M=M-1
                     A=M
                     D=M
@15                  A=M
                     M=D
@1                   D=A
@0                   M=M+1
                     A=M-1
                     M=D
@3                   D=A
@0                   M=M+1
                     A=M-1
                     M=D
@0                   M=M-1
                     A=M
                     D=M
                     A=A-1
                     D=M-D
@L544                D;JEQ
                     D=0
@L444                0;JMP
(L544)
                     D=-1
(L444)
@0                   A=M-1
                     M=D
@0                   A=M-1
                     M=!M
@6                   D=A
@1                   D=D+M
@15                  M=D
@0                   M=M-1
                     A=M
                     D=M
@15                  A=M
                     M=D
