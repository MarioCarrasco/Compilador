.data
    num1:     .word 5         # Primer número a sumar
    num2:     .word 10        # Segundo número a sumar
    resultSuma:   .word 0         # Variable para almacenar el resultado
    resultMult:   .word 0         #Variable resultado de la mult
    msg1:      .asciiz "El resultado de la suma es: "  # Mensaje a imprimir
    msg2:      .asciiz "El resultado de la multiplicacion es: "  # Mensaje a imprimir
    newline:  .asciiz "\n"   # Secuencia de escape para nueva línea

.text
.globl main
main:
    lw $t0, num1          # Carga el primer número en el registro $t0
    lw $t1, num2          # Carga el segundo número en el registro $t1

    add $t2, $t0, $t1     # Suma los registros $t0 y $t1 y almacena el resultado en $t2
    sw $t2, resultSuma        # Almacena el resultado en la variable result
    
    
    mul $t3, $t0, $t1     # Multiplica los registros $t0 y $t1 y almacena el resultado en $t3
    sw $t3, resultMult        # Almacena el resultado en la variable result


	## RESULTADO SUMA
    # Mostrar mensaje "El resultado es: "
    la $a0, msg1           # Carga la dirección de memoria de msg en $a0
    li $v0, 4             # Código de llamada al sistema para imprimir una cadena
    syscall              

    # Mostrar el valor almacenado en result
    lw $a0, resultSuma        # Carga el valor almacenado en result en $a0
    li $v0, 1             # Código de llamada al sistema para imprimir un entero
    syscall
    
    # Mostrar una nueva línea
    la $a0, newline       # Carga la dirección de memoria de newline en $a0
    li $v0, 4             # Código de llamada al sistema para imprimir una cadena
    syscall

    
    ##RESULTADO MULTIPLICACION
    # Mostrar mensaje y resultado de la multiplicación
    la $a0, msg2          # Carga la dirección de memoria de msg2 en $a0
    li $v0, 4             # Código de llamada al sistema para imprimir una cadena
    syscall              

    lw $a0, resultMult      # Carga el valor almacenado en result2 en $a0
    li $v0, 1             # Código de llamada al sistema para imprimir un entero
    syscall

    # Mostrar una nueva línea
    la $a0, newline       # Carga la dirección de memoria de newline en $a0
    li $v0, 4             # Código de llamada al sistema para imprimir una cadena
    syscall              

    li $v0, 10            # Código de salida del programa
    syscall               # Termina el programa
