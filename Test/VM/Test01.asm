# [ set ram ] 

@256     D=A     # CPU.D = 256
@0       M=D     # RAM[0] = 256

# [ set ram ] 

@300     D=A     # CPU.D = 300
@1       M=D     # RAM[1] = 300

# [ set ram ] 

@400     D=A     # CPU.D = 400
@2       M=D     # RAM[2] = 400

# [ set ram ] 

@3000    D=A     # CPU.D = 3000
@3       M=D     # RAM[3] = 3000

# [ set ram ] 

@3010    D=A     # CPU.D = 3010
@4       M=D     # RAM[4] = 3010

# [ push constant ] 

@1       D=A
@0       M=M+1
         A=M-1
         M=D

# [ push constant ] 

@2       D=A
@0       M=M+1
         A=M-1
         M=D

# [ push constant ] 

@3       D=A
@0       M=M+1
         A=M-1
         M=D

# [ push constant ] 

@4       D=A
@0       M=M+1
         A=M-1
         M=D

# [ push constant ] 

@5       D=A
@0       M=M+1
         A=M-1
         M=D

# [ push constant ] 

@6       D=A
@0       M=M+1
         A=M-1
         M=D

# [ push constant ] 

@7       D=A
@0       M=M+1
         A=M-1
         M=D

# [ push constant ] 

@8       D=A
@0       M=M+1
         A=M-1
         M=D

# [ push constant ] 

@9       D=A
@0       M=M+1
         A=M-1
         M=D

# [ pop local ] 

@9       D=A
@1       D=D+M
@15      M=D
@0       M=M-1
         A=M
         D=M
@15      A=M
         M=D

# [ pop local ] 

@8       D=A
@1       D=D+M
@15      M=D
@0       M=M-1
         A=M
         D=M
@15      A=M
         M=D

# [ pop local ] 

@7       D=A
@1       D=D+M
@15      M=D
@0       M=M-1
         A=M
         D=M
@15      A=M
         M=D

# [ pop local ] 

@6       D=A
@1       D=D+M
@15      M=D
@0       M=M-1
         A=M
         D=M
@15      A=M
         M=D

# [ pop local ] 

@5       D=A
@1       D=D+M
@15      M=D
@0       M=M-1
         A=M
         D=M
@15      A=M
         M=D

# [ pop local ] 

@4       D=A
@1       D=D+M
@15      M=D
@0       M=M-1
         A=M
         D=M
@15      A=M
         M=D

# [ pop local ] 

@3       D=A
@1       D=D+M
@15      M=D
@0       M=M-1
         A=M
         D=M
@15      A=M
         M=D

# [ pop local ] 

@2       D=A
@1       D=D+M
@15      M=D
@0       M=M-1
         A=M
         D=M
@15      A=M
         M=D

# [ pop local ] 

@1       D=A
@1       D=D+M
@15      M=D
@0       M=M-1
         A=M
         D=M
@15      A=M
         M=D

