OBJ = Queue.o Stack.o Tree.o main.o

DS: $(OBJ)
	cc -o $@ $(OBJ)
Queue.o: Queue.c Node/QNode.h Queue.h Common.h
	cc -c $^
Stack.o: Stack.c Node/SNode.h Stack.h Common.h
	cc -c $^
Tree.o: Tree.c Node/TNode.h Tree.h Common.h
	cc -c $^
main.o: main.c Tree.h
	cc -c $^

.PHONY: clean
clean:
	rm -rf *.o Node/*.o *.gch Node/*.gch DS