# Compilador
actividad del compilador en lenguaje Latino

## Instrucciones de compilación:
bison -d -v compilador.y<br>
flex -o compilador.lex.c compilador.flex<br>
gcc -o compiladorexe compilador.tab.c compilador.lex.c<br>

## Ejecución del fichero de entrada
compiladorexe.exe < CodigoEntrada/in.txt
