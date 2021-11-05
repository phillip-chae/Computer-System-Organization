#Makefile for projcet 4

CC		= gcc
CFLAGS		= -g  -Og  -Wall  -std=c99

p4: project4.c
	$(CC) $(CFLAGS) -o project4 project4.c

rp4: project4
	./project4 < Project4Input.txt

clean:
	rm -f *~ *.o a.out core project4
