# Compilador
actividad del compilador en lenguaje Latino

##Instrucciones de compilación:
bison -d -v compilador.y
flex -o compilador.lex.c compilador.flex
gcc -o compiladorexe compilador.tab.c compilador.lex.c

##Ejecución del fichero de entrada
compiladorexe.exe < CodigoEntrada/in.txt
