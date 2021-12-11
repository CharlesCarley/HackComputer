// push constant 2
@2       D=A
@0       M=M+1
         A=M-1
         M=D
// push constant 2
@2       D=A
@0       M=M+1
         A=M-1
         M=D
// add 
@0       M=M-1
         A=M
         D=M
         A=A-1
         M=D+M
// pop argument 0
@0       D=A
@2       D=D+M
@15      M=D
@0       M=M-1
         A=M
         D=M
@15      A=M
         M=D
