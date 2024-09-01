
.pos 0
    irmovq Stack, %rsp


    irmovq $2, %rdi 
    irmovq $0, %r8
    rrmovq %rdi, %r9
    call Par        

    

    halt


Par:
    xorq %r9, %r8
    je .L1
    irmovq $0, %r10
    rrmovq %r10, %r8
    irmovq $1, %r11
    subq %r11, %r9
    call Impar
    jmp .L2

.L1:
    irmovq $1, %rax  

.L2:
    rrmovq %rbp, %rsp  
    popq %rbp          
    ret


Impar:
    xorq %r9, %r8
    je .L3
    irmovq $0, %r10
    rrmovq %r10, %r8
    irmovq $1, %r11
    subq %r11, %r9
    call Par
    jmp .L4

.L3:
    irmovq $0, %rax  

.L4:
    rrmovq %rbp, %rsp  
    popq %rbp          
    ret


.pos 0x1900
Stack:
    .quad 0x0  