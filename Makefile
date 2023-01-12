playlife: lifefunc.o playlife.o
	gcc lifefunc.o playlife.o -o playlife

lifefunc.o: lifefunc.c lifefunc.h
	gcc -c lifefunc.c -o lifefunc.o -std=c11 -D_XOPEN_SOURCE=600 -D_POSIX_C_SOURCE=200112L

playlife.o: playlife.c lifefunc.h
	gcc -c playlife.c -o playlife.o -std=c11

clean:
	rm *.o
	rm playlife
