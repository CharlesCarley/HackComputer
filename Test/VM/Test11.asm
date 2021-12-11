// push constant 555
@555     D=A
@0       M=M+1
         A=M-1
         M=D
// pop temp 0
@0       D=A
@5       D=D+A
@15      M=D
@0       M=M-1
         A=M
         D=M
@15      A=M
         M=D
// push temp 0
@0       D=A
@5       A=D+A
         D=M
@0       M=M+1
         A=M-1
         M=D
// pop temp 1
@1       D=A
@5       D=D+A
@15      M=D
@0       M=M-1
         A=M
         D=M
@15      A=M
         M=D
// push temp 1
@1       D=A
@5       A=D+A
         D=M
@0       M=M+1
         A=M-1
         M=D
// pop temp 2
@2       D=A
@5       D=D+A
@15      M=D
@0       M=M-1
         A=M
         D=M
@15      A=M
         M=D
// push temp 2
@2       D=A
@5       A=D+A
         D=M
@0       M=M+1
         A=M-1
         M=D
// pop temp 3
@3       D=A
@5       D=D+A
@15      M=D
@0       M=M-1
         A=M
         D=M
@15      A=M
         M=D
// push temp 3
@3       D=A
@5       A=D+A
         D=M
@0       M=M+1
         A=M-1
         M=D
// pop temp 4
@4       D=A
@5       D=D+A
@15      M=D
@0       M=M-1
         A=M
         D=M
@15      A=M
         M=D
// push temp 4
@4       D=A
@5       A=D+A
         D=M
@0       M=M+1
         A=M-1
         M=D
// pop temp 5
@5       D=A
@5       D=D+A
@15      M=D
@0       M=M-1
         A=M
         D=M
@15      A=M
         M=D
// push temp 5
@5       D=A
@5       A=D+A
         D=M
@0       M=M+1
         A=M-1
         M=D
// pop temp 6
@6       D=A
@5       D=D+A
@15      M=D
@0       M=M-1
         A=M
         D=M
@15      A=M
         M=D
// push temp 6
@6       D=A
@5       A=D+A
         D=M
@0       M=M+1
         A=M-1
         M=D
// pop temp 7
@7       D=A
@5       D=D+A
@15      M=D
@0       M=M-1
         A=M
         D=M
@15      A=M
         M=D
// push temp 7
@7       D=A
@5       A=D+A
         D=M
@0       M=M+1
         A=M-1
         M=D
