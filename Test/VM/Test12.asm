// push constant 3030
@3030    D=A
@0       M=M+1
         A=M-1
         M=D
// pop pointer 0
@0       D=A
@3       D=D+A
@15      M=D
@0       M=M-1
         A=M
         D=M
@15      A=M
         M=D
// push constant 3040
@3040    D=A
@0       M=M+1
         A=M-1
         M=D
// pop pointer 1
@1       D=A
@3       D=D+A
@15      M=D
@0       M=M-1
         A=M
         D=M
@15      A=M
         M=D
// push constant 32
@32      D=A
@0       M=M+1
         A=M-1
         M=D
// pop this 2
@2       D=A
@3       D=D+M
@15      M=D
@0       M=M-1
         A=M
         D=M
@15      A=M
         M=D
// push constant 46
@46      D=A
@0       M=M+1
         A=M-1
         M=D
// pop that 6
@6       D=A
@4       D=D+M
@15      M=D
@0       M=M-1
         A=M
         D=M
@15      A=M
         M=D
// push pointer0
@0       D=A
@3       A=D+A
         D=M
@0       M=M+1
         A=M-1
         M=D
// push pointer1
@1       D=A
@3       A=D+A
         D=M
@0       M=M+1
         A=M-1
         M=D
// add 
@0       M=M-1
         A=M
         D=M
         A=A-1
         M=D+M
// push this 2
@2       D=A
@3       A=D+M
         D=M
@0       M=M+1
         A=M-1
         M=D
// sub 
@0       M=M-1
         A=M
         D=M
         A=A-1
         M=M-D
// push that 6
@6       D=A
@4       A=D+M
         D=M
@0       M=M+1
         A=M-1
         M=D
// add 
@0       M=M-1
         A=M
         D=M
         A=A-1
         M=D+M
