all :
	gcc helper.c sort.c main.c

clean :
	rm a.out

test :
	gcc sort.c test.c
