.data
var0: .float 11.000000
var1: .float 11.000000
var2: .float 10.000000
var3: .float 1.000000
var4: .float 11.000000
var5: .float 12.000000
var6: .float 12.000000
newLine: .asciiz "\n"
zero_f: .float 0.0

.text
lwc1 $f31, zero_f
lwc1 $f0, var0
etiqueta0:
lwc1 $f2, var1
lwc1 $f3, var2
c.le.s $f2, $f3
bc1f etiqueta1
lwc1 $f5, var3
lwc1 $f6, var4
add.s $f7, $f5, $f6
mov.s $f8, $f7
lwc1 $f10, var5
lwc1 $f10, var5
li $v0, 2
add.s $f12, $f31, $f10
syscall
li $v0, 4
la $a0, newLine
syscall
j etiqueta0
etiqueta1:
lwc1 $f11, var6
lwc1 $f11, var6
li $v0, 2
add.s $f12, $f31, $f11
syscall
li $v0, 4
la $a0, newLine
syscall
