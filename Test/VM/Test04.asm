// push constant 41
@41      D=A
@0       M=M+1
         A=M-1
         M=D
// push constant 31
@31      D=A
@0       M=M+1
         A=M-1
         M=D
// and 
@0       M=M-1
         A=M
         D=M
         A=A-1
         M=D&M
// pop local 0
@0       D=A
@1       D=D+M
@15      M=D
@0       M=M-1
         A=M
         D=M
@15      A=M
         M=D
