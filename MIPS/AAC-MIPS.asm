.data
msg: .asciiz "Escoge una de las siguientes operaciones. Introducir solo el número.\n"
msgari: .asciiz "1. Operación aritmética.\n"
msgrel: .asciiz "2. Operación relacional.\n"
msgexit: .asciiz "3. Salir del programa.\n"
msgfin: .asciiz "3. Programa terminado.\n"

msgariadd: .asciiz "1. suma.\n"
msgarisub: .asciiz "2. resta.\n"
msgarimul: .asciiz "3. multiplicación.\n"
msgaridiv: .asciiz "4. division.\n"
msgarivol: .asciiz "5. Volver.\n"

msgrelbgt: .asciiz "1. Es mayor.\n"
msgrelblt: .asciiz "2. Es menor.\n"
msgrelbeq: .asciiz "3. Son iguales.\n"
msgrelbne: .asciiz "4. No son iguales.\n"
msgrelbge: .asciiz "5. Es mayor o igual.\n"
msgrelble: .asciiz "6. Es menor o igual.\n"
msgrelvol: .asciiz "7. Volver.\n"

msgreltrue: .asciiz "Correcto\n####################\n"
msgrelfalse: .asciiz "Incorrecto\n####################\n"

msgope: .asciiz "Elegir la operacion.\n"
msgnum1: .asciiz "Introducir un numero.\n"
msgnum2: .asciiz "Introducir otro numero.\n"
msgerrop: .asciiz "Opcion no encontrada.\n"

linea: .asciiz "\n####################\n" # Salto de linea
.text

addi $s0, $zero, 1
addi $s1, $zero, 2
addi $s2, $zero, 3
addi $s3, $zero, 4
addi $s4, $zero, 5
addi $s5, $zero, 6
addi $s6, $zero, 7

main:
    li $v0, 4
    la, $a0, msg
    syscall
    li $v0, 4
    la, $a0, msgari
    syscall
    li $v0, 4
    la, $a0, msgrel
    syscall
    li $v0, 4
    la, $a0, msgexit
    syscall
    
    # Get the user's input
    li $v0, 5
    syscall
    
    move $t0, $v0
    
    beq $t0, $s0, aritmetica
    beq $t0, $s1, relacional
    beq $t0, $s2, end
    li $v0, 4
    la, $a0, msgerrop
    syscall
    j main
    
    aritmetica:
         li $v0, 4
         la, $a0, msgariadd
         syscall
         li $v0, 4
         la, $a0, msgarisub
         syscall
         li $v0, 4
         la, $a0, msgarimul
         syscall
         li $v0, 4
         la, $a0, msgaridiv
         syscall
         li $v0, 4
         la, $a0, msgarivol
         syscall
         
         # Get the operator
         li $v0, 4
         la, $a0, msgope
         syscall
         li $v0, 5
         syscall
         
         move $t0, $v0
         
         beq $t0, $s4, main
         
         # Get the number 1
         li $v0, 4
         la, $a0, msgnum1
         syscall
         li $v0, 5
         syscall
         
         move $t1, $v0
         
         # Get the number 2
         li $v0, 4
         la, $a0, msgnum2
         syscall
         li $v0, 5
         syscall
         
         move $t2, $v0
         
         # Realizar operaciones
         beq $t0, $s0, suma
         beq $t0, $s1, resta
         beq $t0, $s2, multiplicacion
         beq $t0, $s3, division
         
         suma:
              add $t3, $t1, $t2
              li $v0, 1
              move $a0, $t3
              syscall
              j resultari
         resta:
              sub $t3, $t1, $t2
              li $v0, 1
              move $a0, $t3
              syscall
              j resultari
         multiplicacion:
              mul $t3, $t1, $t2
              li $v0, 1
              move $a0, $t3
              syscall
              j resultari
         division:
              div $t3, $t1, $t2
              li $v0, 1
              move $a0, $t3
              syscall
              j resultari
         
         resultari:
              li $v0, 4
              la $a0, linea
              syscall
              j aritmetica
    relacional:
         li $v0, 4
         la, $a0, msgrelbgt
         syscall
         la, $a0, msgrelblt
         syscall
         la, $a0, msgrelbeq
         syscall
         la, $a0, msgrelbne
         syscall
         la, $a0, msgrelbge
         syscall
         la, $a0, msgrelble
         syscall
         la, $a0, msgrelvol
         syscall
         
         # Get the operator
         li $v0, 4
         la, $a0, msgope
         syscall
         li $v0, 5
         syscall
         
         move $t0, $v0
         
         beq $t0, $s6, main
         
         # Get the number 1
         li $v0, 4
         la, $a0, msgnum1
         syscall
         li $v0, 5
         syscall
         
         move $t1, $v0
         
         # Get the number 2
         li $v0, 4
         la, $a0, msgnum2
         syscall
         li $v0, 5
         syscall
         
         move $t2, $v0
         
         # Realizar operaciones
         beq $t0, $s0, mayor
         beq $t0, $s1, menor
         beq $t0, $s2, igual
         beq $t0, $s3, nigual
         beq $t0, $s4, mayorigual
         beq $t0, $s5, menorigual
         mayor:
              bgt $t1, $t2, correcto
              j incorrecto
         menor:
              blt $t1, $t2, correcto
              j incorrecto
         igual:
              beq $t1, $t2, correcto
              j incorrecto
         nigual:
              bne $t1, $t2, correcto
              j incorrecto
         mayorigual:
              bge $t1, $t2, correcto
              j incorrecto
         menorigual:
              ble $t1, $t2, correcto
              j incorrecto
         
         correcto:
              li $v0, 4
              la, $a0, msgreltrue
              syscall
              j relacional
         
         incorrecto:
              li $v0, 4
              la, $a0, msgrelfalse
              syscall
              j relacional
end: