OBJ = Stack.o main.o

main: $(OBJ)
	cc -o $@ $(OBJ)
Stack.o: Stack.c Stack.h Node.h Common.h
	cc -c $^
main.o: main.c Common.h
	cc -c $<

.PHONY: clean
clean:
	rm -rf *.o *.gch main