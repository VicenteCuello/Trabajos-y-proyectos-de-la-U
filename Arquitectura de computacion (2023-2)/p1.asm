main:
    .pos 0
    irmovq stack, %rsp      # Set up stack pointer
    irmovq $0 , %rdi    #Declaramos x
    irmovq $2 , %rsi    #Declaramos y
    irmovq $0, %rax #declaracion de acum
    irmovq $0,  %rcx #declaracion de count
    irmovq $0,  %r8  #bandera de x si es negativo
    irmovq $0,  %r9  #bandera de y si es negativo

    irmovq $0, %r11
    addq %rdi, %r11
    %r11,%rax
    jge .L1

    irmovq $0, %r10
    subq %rdi,%r10
    irmovq $1,%r8
    rrmovq %r10, %rdi

.L1:


    irmovq $0, %r12
    addq %rsi, %r12
    %r12, %r12
    jge .L2

    irmovq $0, %r10
    subq %rsi,%r10
    irmovq $1,%r9
    rrmovq %r10, %rsi

.L2:
 
.loop:

    irmovq $0, %r11
    subq %r11, %rdi
    jle .L3
    addq %rdi,%r11
    addq %rsi,%rax
    irmovq $1,%r10
    addq %r10,%rcx

    subq %rcx,%r11
    jg .loop



    xorq %r8,%r9
    jne .L3

    halt



.L3:
    irmovq $0, %r10
    subq %rax,%r10

    rrmovq %r10, %rax


#Stack starts here and grows to lower addresses
    .pos 0x2000
stack: