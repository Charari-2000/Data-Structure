OBJ = DCList.o main.o

main: $(OBJ)
	cc -o $@ $(OBJ)
DCList.o: DCList.c DCList.h Node.h Common.h
	cc -c $^
main.o: main.c Common.h
	cc -c $<

.PHONY: clean
clean:
	rm -rf *.o *.gch main