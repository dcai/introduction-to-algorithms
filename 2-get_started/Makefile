CFLAG=-Wall -g
OBJS = common.o

all: merge_sort insertion_sort

merge_sort: $(OBJS)
	cc -c 2-3_merge_sort.c
	cc -o merge_sort $(OBJS) 2-3_merge_sort.o

insertion_sort: $(OBJS)
	cc -c 2-1_insertion_sort.c
	cc -o insertion_sort $(OBJS) 2-1_insertion_sort.o

clean:
	rm -f *.out
	rm -f *.o
	rm -f insertion_sort
	rm -f merge_sort
