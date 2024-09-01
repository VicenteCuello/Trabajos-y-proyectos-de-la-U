# NOMBRE (MATRICULA) 
# Maximiliano Esteban Lopez Becerra (2021450327)
# Iván Ignacio Zapatá Ávila (2021432469)
# Vicente Javier Cuello Diban (2021438998)
# Eduardo Ignacio Parra Roldan (2021439579)

main:
    .pos 0
    irmovq stack, %rsp     
    irmovq $2, %rdi         # Inicializa x
    irmovq $2, %rsi         # Inicializa y
    irmovq $0, %rax         # Acumulador (resultado final)
    irmovq $0, %rcx         # Contador
    irmovq $0, %r8          # Bandera de signo para x
    irmovq $0, %r9          # Bandera de signo para y

    irmovq $0, %r11         # Variable temporal para procesar x
    addq %rdi, %r11        # Suma x a la variable temporal
    %r11, %rax             # Mueve el valor de la variable temporal a %rax
    jge .Loop_check_y      # Salta a .Loop_check_y para ver su signo

    irmovq $0, %r10         # Variable temporal para almacenar el negativo de x
    subq %rdi, %r10         # Resta x a la variable temporal
    irmovq $1, %r8          # Establece la bandera de signo para x en 1
    rrmovq %r10, %rdi       # Reemplaza %rdi con el negativo de x

.Loop_check_y:

    irmovq $0, %r12         # Variable temporal para procesar y
    addq %rsi, %r12        # Suma y a la variable temporal
    %r12, %r12             # Mueve el valor de la variable temporal a %r12 (podría ser un error)
    jge .Loop_check_x      # Salta a .Loop_check_x para ver su signo

    irmovq $0, %r10         # Variable temporal para almacenar el negativo de y
    subq %rsi, %r10         # Resta y a la variable temporal
    irmovq $1, %r9          # Establece la bandera de signo para y en 1
    rrmovq %r10, %rsi       # Reemplaza %rsi con el negativo de y

.Loop_check_x:

.Loop_multiplicacion:

    irmovq $0, %r11         # Variable temporal para procesar x en el bucle de multiplicación
    subq %r11, %rdi         # Resta 0 a %rdi (podría no ser necesario)
    jle .Loop_resultadoFinal    # Salta a .Loop_resultadoFinal si el resultado es menor o igual a 0
    addq %rdi, %r11         # Suma el valor original de %rdi a la variable temporal
    addq %rsi, %rax         # Suma el valor original de %rsi a %rax
    irmovq $1, %r10          # Variable temporal para el valor 1
    addq %r10, %rcx         # Incrementa %rcx en 1

    subq %rcx, %r11         # Resta %rcx a la variable temporal
    jg .Loop_multiplicacion # Salta de nuevo al loop si la variable temporal es mayor que 0

    xorq %r8, %r9           # Realiza una operación XOR entre las banderas de signo de x e y
    jne .Loop_resultadoFinal     # Salta a .Loop_resultadoFinal si las banderas de signo son diferentes

    halt

.Loop_resultadoFinal:

    irmovq $0, %r10         # Variable temporal para almacenar el negativo del resultado
    subq %rax, %r10         # Resta %rax a la variable temporal
    rrmovq %r10, %rax       # Reemplaza %rax con el negativo del resultado

    .pos 0x2000
stack:
