OBJ = Queue.o main.o

main: $(OBJ)
	cc -o $@ $(OBJ)
Queue.o: Queue.c Queue.h Node.h Common.h
	cc -c $^
main.o: main.c Common.h
	cc -c $<

.PHONY: clean
clean:
	rm -rf *.o *.gch main