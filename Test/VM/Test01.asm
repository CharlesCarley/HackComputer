// RAM[0] = 256
@256
D=A  
@0
M=D  
// RAM[1] = 300
@300
D=A  
@1
M=D  
// RAM[2] = 400
@400
D=A  
@2
M=D  
// RAM[3] = 3000
@3000
D=A  
@3
M=D  
// RAM[4] = 3010
@3010
D=A  
@4
M=D  
// push constant 10
@10
D=A  
@SP
M=M+1
A=M-1
M=D  
