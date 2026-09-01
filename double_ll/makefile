FLAGS = -Wall -c
FILE1 = list
EXEC = dll

fold: 
	mkdir -p madefiles/

exec: madefiles/$(FILE1).o madefiles/client.o
	gcc madefiles/$(FILE1).o madefiles/client.o -o $(EXEC)

madefiles/$(FILE1).o: $(FILE1).c $(FILE1).h
	gcc $(FLAGS) $(FILE1).c -o madefiles/$(FILE1).o

madefiles/client.o: client.c $(FILE1).h
	gcc $(FLAGS) client.c -o madefiles/client.o

