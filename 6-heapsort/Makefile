CFLAG=-Wall -g
OBJS = common.o

all: heap_sort

heap_sort: $(OBJS)
	cc -c 6-1_heapsort.c
	cc -o heap_sort $(OBJS) 6-1_heapsort.o

clean:
	rm -f *.out
	rm -f *.o
	rm -f heap_sort
