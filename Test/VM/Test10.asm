// push constant 111
@111     D=A
@0       M=M+1
         A=M-1
         M=D
// push constant 333
@333     D=A
@0       M=M+1
         A=M-1
         M=D
// push constant 888
@888     D=A
@0       M=M+1
         A=M-1
         M=D
// pop static 8
@Test10.8
         D=A
@13      M=D
@0       M=M-1
         A=M
         D=M
@13      A=M
         M=D
// pop static 3
@Test10.3
         D=A
@13      M=D
@0       M=M-1
         A=M
         D=M
@13      A=M
         M=D
// pop static 1
@Test10.1
         D=A
@13      M=D
@0       M=M-1
         A=M
         D=M
@13      A=M
         M=D
// push static3
@Test10.3
         D=M
@0       M=M+1
         A=M-1
         M=D
// push static1
@Test10.1
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
// push static8
@Test10.8
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
