(Start)
@R0   
M=0
@8192 
D=A
@R1   
M=D

(fillTop)
@R0  
M=0
@R3  
M=!M

(loopTop)
//; Move Screen start to R2
@SCREEN  
D=A
@R2      
M=D
@R0     
D=M
//; Store  Screen Address + iteration
//; In R4
@R4      
M=D
@R2      
D=M
@R4      
M=D+M
//;Go to R4 and place the value in R3
@R3      
D=M
@R4      
A=M
M=D
//; Increment R0
@R0     
M=M+1
D=M
//; Calculate exit condition
@R1      
D=M
@R0      
D=D-M
@fillTop 
D;JEQ
@loopTop 
0;JMP
