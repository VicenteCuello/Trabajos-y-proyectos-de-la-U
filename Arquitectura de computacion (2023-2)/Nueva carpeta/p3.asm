# NOMBRE (MATRICULA) 
# Maximiliano Esteban Lopez Becerra (2021450327)
# Iván Ignacio Zapatá Ávila (2021432469)
# Vicente Javier Cuello Diban (2021438998)
# Eduardo Ignacio Parra Roldan (2021439579)

.pos 0

inicio:
	irmovq $32, %rdi   # Inicializar x
	irmovq $10, %rsi      # Inicializar divisor y multiplicador base
	irmovq $0, %rsp       # Inicializar mod
	irmovq $0, %rbx       # Inicializar inverso de x
	irmovq $0, %r14       # Inicializar copia de x
	jmp Pal
	
	halt
	
Pal: 
    rrmovq %rdi, %r14     # r14 = x
    

    %rdi,%rax
    jge .siMayorIgualCero # Salta a .siMayorIgualCero si x es mayor o igual a 0

    irmovq $0, %r10       # Inicializa r10 a 0
    subq %rdi, %r10       # r10 = -x
    rrmovq %r10, %rdi     # x = -x
    rrmovq %r10, %r14     # r14 = -x
    
    .siMayorIgualCero:
    
	jmp division           # Salta a la sección de división
	.flag:
    rrmovq %rdx, %rdi      # rdi = resto de la división
    rrmovq %rcx, %rbp      # rbp = cociente de la división
    
    rrmovq %rbx, %r8       # r8 = inverso de x
    rrmovq %rsi, %r9       # r9 = divisor
    
    jmp multiplicacion     # Salta a la sección de multiplicación
    .flag2:
    rrmovq %rax, %rbx      # rbx = resultado de la multiplicación
    addq %rbp, %rbx        # rbx = rbx + cociente de la división
    
    irmovq $0, %r10        # Inicializa r10 a 0
    subq %r10, %rdi        # rdi = rdi - 0
    jg .siMayorIgualCero   # Salta a .siMayorIgualCero si rdi es mayor a 0
    
    subq %rbx, %r14        # r14 = r14 - rbx
   je .finalSi             # Salta a .finalSi si r14 es igual a 0

   jmp .finalNo            # Salta a .finalNo en otros casos

.finalSi:
   irmovq $1, %rax         # rax = 1 (indicando verdadero)
   ret

.finalNo:
   irmovq $0, %rax         # rax = 0 (indicando falso)
ret

multiplicacion: 
    irmovq $0, %rax        # Declaración de acumulador
    irmovq $0, %rcx        # Declaración de contador

    irmovq $0, %r11
    addq %r8, %r11         # r11 = r8 (inverso de x)
    %r11, %rax
    jge .multiplicar1

.multiplicar1:


    irmovq $0, %r12
    addq %r9, %r12         # r12 = r9 (divisor)
    %r12, %r12
    jge .bucleMultiplicacion

 
.bucleMultiplicacion:

    irmovq $0, %r11
    subq %r11, %r8
    jle .finMultiplicacion  # Salta a .finMultiplicacion si r8 es menor o igual a 0
    addq %r8, %r11
    addq %r9, %rax
    irmovq $1, %r10
    addq %r10, %rcx

    subq %rcx, %r11
    jg .bucleMultiplicacion # Salta a .bucleMultiplicacion si r11 es mayor a 0

    .finMultiplicacion:


jmp .flag2                # Salta a .flag2 para finalizar la multiplicación


division:
	irmovq $0, %rdx         # Inicializa el cociente a 0
	irmovq $0, %rcx         # Inicializa el resto a 0

	
	irmovq $0, %r11
    addq %rdi, %r11         # r11 = rdi (dividendo)
    %r11, %rax
    jge .dividir1           # Salta a .dividir1 si r11 es mayor o igual a 0

    .dividir1:
        irmovq $0, %r12
        addq %rsi, %r12       # r12 = rsi (divisor)
        %r12, %r12
        jge .dividir2         # Salta a .dividir2

    .dividir2:
	    %rsi
	    jne .dividir3          # Salta a .dividir3 si rsi no es igual a 0
	    jmp .dividir4          # Salta a .dividir4 en otros casos


    .dividir3:
	    rrmovq %rdi, %rcx      # rcx = rdi (dividendo)
	    %rcx, %rsi
	    jge .bucleDivision    # Salta a .bucleDivision


.dividir4:
	irmovq $2147483647, %rdx # Establece el cociente a un valor grande por defecto
	subq %rsp, %r14          # r14 = r14 - rsp
	je .divisionFinSi        # Salta a .divisionFinSi si r14 es igual a 0
	jne .divisionFinNo       # Salta a .divisionFinNo en otros casos
	
	
	
    .bucleDivision:
	   
	    irmovq $1, %r13
	    addq %r13, %rdx        # Incrementa el cociente en 1

	    subq %rsi, %rcx
	    jge .bucleDivision     # Salta a .bucleDivision si rcx es mayor o igual a 0

        addq %rsi, %rcx
        subq %r13, %rdx
	   subq %rsp, %r9
        jne .divisionFinNo     # Salta a .divisionFinNo si el divisor es diferente de 0
        je .divisionFinSi      # Salta a .divisionFinSi si el divisor es igual a 0


.divisionFinNo:
	rrmovq %rcx, %rax        # rax = rcx (resto de la división)
	jmp .flag                # Retorna el resto
.divisionFinSi:
rrmovq %rdx, %rax          # rax = rdx (cociente)
jmp .flag                   # Retorna el cociente


# La pila comienza aquí y crece hacia direcciones más bajas
    .pos 0x2000
pila:
