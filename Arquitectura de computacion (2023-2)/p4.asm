# Funcion Fibonacci
# Entrada: %rdi = n
# Salida: %rax = resultado

    .pos 0
    irmovq stack, %rsp      # Set up stack pointer
    irmovq $7, %rdi
    call fibonacci
    halt
     
fibonacci:
    irmovq $1, %rax        # Inicializar el resultado en 1
    irmovq $1, %r8         # Inicializar n-1 en %r8
    irmovq $1, %r9         # Inicializar n-2 en %r9

    irmovq $1, %r10        # Cargar el valor 1 en un registro temporal
    subq %r10, %rdi        # Decrementar n
    jle .L1_end            # Saltar a .L1_end si n <= 1

    irmovq $1, %r10        # Cargar el valor 1 en un registro temporal
    subq %r10, %rdi        # Decrementar n
    jle .L1_end            # Saltar a .L1_end si n <= 2
    irmovq $2, %r9         # Inicializar n-2 en %r9

fib_loop:    
    rrmovq %rax, %r10
    addq %r8, %rax         # Sumar n-1 al resultado actual
    rrmovq %r8, %r9        # Mover n-1 a n-2
    rrmovq %r10, %r8       # Mover el resultado a n-1
    #rrmovq %r9, %rax       # Mover n-2 al resultado
    

    irmovq $1, %r10        # Inicializar el contador en 1
    subq %r10, %rdi        # Decrementar n
    jg fib_loop            # Saltar a fib_loop si n > 0
    jmp .L1_end

.L1_end:
    ret
    
    .pos 0x2000
stack: