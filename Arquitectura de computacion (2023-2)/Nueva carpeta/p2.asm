# NOMBRE (MATRICULA) 
# Maximiliano Esteban Lopez Becerra (2021450327)
# Iván Ignacio Zapatá Ávila (2021432469)
# Vicente Javier Cuello Diban (2021438998)
# Eduardo Ignacio Parra Roldan (2021439579)


.pos 0
main:
    irmovq $-169, %rdi    # x
    irmovq $13, %rsi     # y
    irmovq $0, %rsp     # mod
    jmp div             # Salta a la función 'div'

    halt                # Fin del programa

div:
    irmovq $0, %rdx     # Cociente
    irmovq $0, %rcx     # Resto
    irmovq $0, %r8      # Bandera de x
    irmovq $0, %r9      # Bandera de y

    irmovq $0, %r11
    addq %rdi, %r11
    %r11, %rax          # Mueve el valor de la variable temporal a %rax
    jge .Loop_NegativoX      # Salta a .Loop_NegativoX si x es negativo

    irmovq $0, %r10
    subq %rdi, %r10
    irmovq $1, %r8
    rrmovq %r10, %rdi   # Reemplaza %rdi con el negativo de x

.Loop_NegativoX:
    irmovq $0, %r12
    addq %rsi, %r12
    %r12, %r12
    jge .Loop_NegativoY      # Salta a .Loop_NegativoY si y es negativo

    irmovq $0, %r10
    subq %rsi, %r10
    irmovq $1, %r9
    rrmovq %r10, %rsi   # Reemplaza %rsi con el negativo de y

.Loop_NegativoY:
    %rsi
    jne .Loop_NoEsCero       # Salta a .Loop_NoEsCero
    jmp .Loop_EsCero         # Si y == 0, salta a .Loop_EsCero

.Loop_NoEsCero:
    rrmovq %rdi, %rcx   # Resto = x
    %rcx, %rsi
    jge .Loop_Division           # Salta a .Loop_Division si el resto es negativo

.Loop_EsCero:
    irmovq $2147483647, %rdx  # Valor máximo de 32 bits para el cociente inicial
    subq %rsp, %r14            # Sección de código que podría ser un error (etiquetas .Loop_RamaCociente y .Loop_RamaResto)
    je .Loop_RamaCociente
    jne .Loop_RamaResto

.Loop_Division:
    # División
    irmovq $1, %r13
    addq %r13, %rdx

    subq %rsi, %rcx
    jge .Loop_Division

    addq %rsi, %rcx
    subq %r13, %rdx
    xorq %r8, %r9
    jne .Loop_AjusteNegativo  # Salta a .Loop_AjusteNegativo si las banderas de signo son diferentes

    subq %rsp, %r14
    jne .Loop_RamaResto
    je .Loop_RamaCociente

.Loop_AjusteNegativo:
    # Factor de negativo
    irmovq $0, %r10
    subq %rdx, %r10
    rrmovq %r10, %rdx

    irmovq $0, %r14
    subq %rsp, %r14
    jne .Loop_RamaResto
    je .Loop_RamaCociente

.Loop_RamaResto:
    rrmovq %rcx, %rax
    ret                 # Retorna el resto

.Loop_RamaCociente:
    rrmovq %rdx, %rax
    ret                 # Retorna el cociente

# Stack empieza aquí y crece hacia direcciones más bajas
.pos 0x2000
stack:
