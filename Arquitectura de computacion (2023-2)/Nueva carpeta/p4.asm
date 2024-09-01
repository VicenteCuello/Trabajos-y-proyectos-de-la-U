# NOMBRE (MATRICULA) 
# Maximiliano Esteban Lopez Becerra (2021450327)
# Iván Ignacio Zapatá Ávila (2021432469)
# Vicente Javier Cuello Diban (2021438998)
# Eduardo Ignacio Parra Roldan (2021439579)


.pos 0
    irmovq stack, %rsp       # Establece el puntero de pila

    irmovq $11, %rdi           # Define el valor de n (en este caso, n = 7)
    call calcularFibonacci    # Llama a la función que calcula Fibonacci con el argumento n
    halt                     # Detiene la ejecución del programa

calcularFibonacci:           # Cambia el nombre de la función
    irmovq $1, %rax           # Inicializa el resultado en 1
    irmovq $1, %r8            # Inicializa n-1 en %r8
    irmovq $1, %r9            # Inicializa n-2 en %r9

    irmovq $1, %r10           # Carga el valor 1 en un registro temporal
    subq %r10, %rdi           # Decrementa n
    jle .FinFibonacci         # Salta a .FinFibonacci si n <= 1

    irmovq $1, %r10           # Carga el valor 1 en un registro temporal
    subq %r10, %rdi           # Decrementa n
    jle .FinFibonacci         # Salta a .FinFibonacci si n <= 2
    irmovq $2, %r9            # Inicializa n-2 en %r9

calculoFibonacciLoop:       # Cambia el nombre de la etiqueta
    rrmovq %rax, %r10        # Copia el valor actual de %rax a %r10
    addq %r8, %rax            # Suma n-1 al resultado actual
    rrmovq %r8, %r9           # Mueve n-1 a n-2
    rrmovq %r10, %r8          # Mueve el resultado a n-1

    irmovq $1, %r10           # Inicializa el contador en 1
    subq %r10, %rdi           # Decrementa n
    jg calculoFibonacciLoop   # Salta a calculoFibonacciLoop si n > 0
    jmp .FinFibonacci

.FinFibonacci:
    ret                       # Retorna del procedimiento calcularFibonacci

    .pos 0x2000
stack:
