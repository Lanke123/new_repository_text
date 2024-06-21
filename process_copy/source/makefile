app:main.o process_wait.o process_create.o check_pram.o blocksize_cur.o
	gcc *.o -o app

main.o:main.c
	gcc -I../include -c main.c

process_wait.o:process_wait.c
	gcc -I../include -c process_wait.c

process_create.o:process_create.c
	gcc -I../include -c process_create.c

blocksize_cur.o:blocksize_cur.c
	gcc -I../include -c blocksize_cur.c

check_pram.o:check_pram.c
	gcc -I../include -c check_pram.c
