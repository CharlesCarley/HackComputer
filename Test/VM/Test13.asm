// push constant 0
@0       D=A
@0       M=M+1
         A=M-1
         M=D
(top1)
// push constant 1
@1       D=A
@0       M=M+1
         A=M-1
         M=D
// add 
@0       M=M-1
         A=M
         D=M
         A=A-1
         M=D+M
// push constant 2
@2       D=A
@0       M=M+1
         A=M-1
         M=D
// lt 
@0       M=M-1
         A=M
         D=M
         A=A-1
         D=M-D
@false1  D;JLT
(true1)
         D=-1
@done1   0;JMP
(false1)
         D=0
(done1)
@0       A=M
         M=D
// if-goto top1
@top1    D;JEQ
// pop local 0
@0       D=A
@1       D=D+M
@15      M=D
@0       M=M-1
         A=M
         D=M
@15      A=M
         M=D
// push local 0
@0       D=A
@1       A=D+M
         D=M
@0       M=M+1
         A=M-1
         M=D
(top2)
// push constant 1
@1       D=A
@0       M=M+1
         A=M-1
         M=D
// sub 
@0       M=M-1
         A=M
         D=M
         A=A-1
         M=M-D
// push constant 0
@0       D=A
@0       M=M+1
         A=M-1
         M=D
// eq 
@0       M=M-1
         A=M
         D=M
         A=A-1
         D=M-D
@false2  D;JNE
(true2)
         D=-1
@done2   0;JMP
(false2)
         D=0
(done2)
@0       A=M
         M=D
// not 
@0       A=M
         M=!M
// if-goto top2
@top2    D;JEQ
// push local 0
@0       D=A
@1       A=D+M
         D=M
@0       M=M+1
         A=M-1
         M=D
// pop argument 0
@0       D=A
@2       D=D+M
@15      M=D
@0       M=M-1
         A=M
         D=M
@15      A=M
         M=D
