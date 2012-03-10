CFLAG=-Wall -g
OBJS = common.o

all: quick_sort

quick_sort: $(OBJS)
	cc -c 7-1_quicksort.c
	cc -o quick_sort $(OBJS) 7-1_quicksort.o

clean:
	rm -f *.out
	rm -f *.o
	rm -f quick_sort
