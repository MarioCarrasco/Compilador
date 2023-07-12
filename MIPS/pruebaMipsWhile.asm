.data
var0: .float 0.000000
var1: .float 0.000000
var2: .float 0.000000
var3: .float 1.000000
var4: .float 1.000000
newLine: .asciiz "\n"
zero_f: .float 0.0

.text
lwc1 $f31, zero_f
lwc1 $f0, var0
lwc1 $f2, var1
lwc1 $f3, var2
c.lt.s $f3, $f2
bc1f etiq0
lwc1 $f5, var3
etiq0:
lwc1 $f7, var4
lwc1 $f7, var4
li $v0, 2
add.s $f12, $f31, $f7
syscall
li $v0, 4
la $a0, newLine
syscall
