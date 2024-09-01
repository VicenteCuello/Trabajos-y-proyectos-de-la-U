.pos 0
main:
	irmovq $20,%rdi #x
	irmovq $5, %rsi #y
	irmovq $0, %rsp #mod
	jmp div

	halt



div:
	irmovq $0, %rdx #couciente
	irmovq $0, %rcx #resto
	irmovq $0, %r8	#bandera de x
	irmovq $0, %r9 #bandera de y

	
	irmovq $0, %r11
    addq %rdi, %r11
    %r11,%rax
    jge .L1

    irmovq $0, %r10
    subq %rdi,%r10
    irmovq $1,%r8
    rrmovq %r10, %rdi

    .L1:
	    #cambios de valores negativos

        irmovq $0, %r12
        addq %rsi, %r12
        %r12, %r12
        jge .L2

        irmovq $0, %r10
        subq %rsi,%r10
        irmovq $1,%r9
        rrmovq %r10, %rsi

    .L2:

	    #if((y != 0))
	    %rsi
	    jne .L3
	    #else
	    jmp .L4


    .L3:
	    rrmovq %rdi,%rcx
	    %rcx,%rsi
	    jge .loop
	    #detector while


.L4:
	#caso else
	irmovq $2147483647, %rdx
	subq %rsp, %r14
	je .L8
	jne .L7
	
	
	
    .loop:
	    #division
	   
	    irmovq $1,%r13
	    addq %r13,%rdx

	    subq %rsi,%rcx
	    jge .loop

        addq %rsi, %rcx
        subq %r13 ,%rdx
	    xorq %r8,%r9
	    jne .L6
	   subq %rsp, %r14
        jne .L7
        je .L8




.L6:
	#factor de negativo
    irmovq $0, %r10
    subq %rdx,%r10
	rrmovq %r10, %rdx
	     irmovq $0,%r14
        subq %rsp, %r14
        jne .L7
        je .L8

.L7:
	rrmovq %rcx,%rax
	ret #retorna resto
.L8:
rrmovq %rdx,%rax
ret #retorna coucioente


#Stack starts here and grows to lower addresses
    .pos 0x2000
stack:


#Stack starts here and grows to lower addresses
    .pos 0x2000
stack: