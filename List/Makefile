OBJ = List.o main.o

main: $(OBJ)
	cc -o $@ $(OBJ)
List.o: List.c List.h Node.h Common.h
	cc -c $^
main.o: main.c Common.h
	cc -c $<

.PHONY: clean
clean:
	rm -rf *.o *.gch main