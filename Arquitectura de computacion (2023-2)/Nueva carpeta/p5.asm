# NOMBRE (MATRICULA) 
# Maximiliano Esteban Lopez Becerra (2021450327)
# Iván Ignacio Zapatá Ávila (2021432469)
# Vicente Javier Cuello Diban (2021438998)
# Eduardo Ignacio Parra Roldan (2021439579)


.pos 0
    irmovq Stack, %rsp

    irmovq $444, %rdi    # Inicializa x 
    irmovq $0, %r8       # Inicializa la bandera de paridad en 0
    rrmovq %rdi, %r9     # Inicializa la variable de trabajo r9 con el valor de x
    call Par             # Llama a la función Par

    halt                 

Par:
    xorq %r9, %r8        # Realiza una operación XOR entre r8 y r9
    je .EsPar            # Salta a .EsPar si el resultado de la operación XOR es 0
    irmovq $0, %r10      # Inicializa una variable temporal con 0
    rrmovq %r10, %r8     # Asigna 0 a la bandera de paridad
    irmovq $1, %r11      # Inicializa una variable temporal con 1
    subq %r11, %r9       # Resta 1 a r9 
    call Impar           # Llama a la función Impar
    jmp .FinPar          # Salta a .FinPar después de la llamada a Impar

.EsPar:
    irmovq $1, %rax       # Si la bandera de paridad es 1, establece rax en 1

.FinPar:
    rrmovq %rbp, %rsp    # Restaura el puntero de pila
    popq %rbp            # Desapila el valor de rbp
    ret                  # Retorna de la función Par

Impar:
    xorq %r9, %r8        # Realiza una operación XOR entre r8 y r9 
    je .EsImpar          # Salta a .EsImpar si el resultado de la operación XOR es 0
    irmovq $0, %r10      # Inicializa una variable temporal con 0
    rrmovq %r10, %r8     # Asigna 0 a la bandera de paridad
    irmovq $1, %r11      # Inicializa una variable temporal con 1
    subq %r11, %r9       # Resta 1 a r9
    call Par             # Llama a la función Par
    jmp .FinImpar        # Salta a .FinImpar después de la llamada a Par

.EsImpar:
    irmovq $0, %rax       # Si la bandera de paridad es 0, establece rax en 0

.FinImpar:
    rrmovq %rbp, %rsp    # Restaura el puntero de pila
    popq %rbp            # Desapila el valor de rbp
    ret                  # Retorna de la función Impar

.pos 0x1900
Stack:
    .quad 0x0             # Inicializa la pila con 0
