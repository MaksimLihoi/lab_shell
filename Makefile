shell: main.o libexec.so
	gcc -Wall main.o -L. -lexec -Wl,-rpath -Wl,'$$ORIGIN' -o shell

main.o: main.c
	gcc -Wall -c -o main.o main.c

exec.o: exec.c
	gcc -Wall -c -o exec.o exec.c

libexec.so: exec.o 
	gcc -Wall -shared -o libexec.so exec.o
