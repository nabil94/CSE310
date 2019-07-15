flex -o lex.yy.c 1505094_scanner.l
g++ lex.yy.c -lfl -o a.out
./a.out input.txt
