FLAGS = -Wall -c
FILE1 = term
FILE2 = list
EXEC = poly

fold: 
	mkdir -p madefiles/

exec: madefiles/$(FILE1).o madefiles/$(FILE2).o madefiles/client.o
	gcc madefiles/$(FILE1).o madefiles/$(FILE2).o madefiles/client.o -o $(EXEC)

madefiles/$(FILE1).o: $(FILE1).c $(FILE1).h
	gcc $(FLAGS) $(FILE1).c -o madefiles/$(FILE1).o

madefiles/$(FILE2).o: $(FILE2).c $(FILE2).h $(FILE1).h
	gcc $(FLAGS) $(FILE2).c -o madefiles/$(FILE2).o

madefiles/client.o: client.c $(FILE2).h $(FILE1).h
	gcc $(FLAGS) client.c -o madefiles/client.o

