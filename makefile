build: paku.y paku.lex
	bison -d paku.y
	flex -o paku.l.c paku.lex
	gcc -o paku paku.l.c paku.tab.c -ll -lm 

clean:
	rm -f *.c *.h paku