all: bal
CC = gcc
FLAGS = -Wall -c
FILE1 = bal
FILE2 = stack

bal: $(FILE1).o $(FILE2).o client.o
	$(CC) $(FILE1).o $(FILE2).o client.o -o bal
	rm -f *.o

$(FILE1).o: $(FILE1).c $(FILE1).h
	$(CC) $(FLAGS) $(FILE1).c -o $(FILE1).o

$(FILE2).o: $(FILE2).c $(FILE2).h $(FILE1).h
	$(CC) $(FLAGS) $(FILE2).c -o $(FILE2).o

client.o: client.c $(FILE2).h $(FILE1).h
	$(CC) $(FLAGS) client.c -o client.o
