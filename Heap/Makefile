OBJ = Heap.o main.o

main: $(OBJ)
	cc -o $@ $(OBJ)
Heap.o: Heap.c Heap.h Node.h Common.h
	cc -c $^
main.o: main.c Common.h
	cc -c $<

.PHONY: clean
clean:
	rm -rf *.o *.gch main