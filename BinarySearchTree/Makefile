CC=clang
OBJ=BstTester.o MyBst.o

BstTester: $(OBJ)
	$(CC) -o BstTester $(OBJ)

BstTester.o: BstTester.c MyBst.h
	$(CC) -c BstTester.c

MyBst.o: MyBst.c MyBst.h
	$(CC) -c MyBst.c

.PHONY: clean
clean:
	rm $(OBJ) BstTester
