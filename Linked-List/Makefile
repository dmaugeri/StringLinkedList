OBJ=Assignment1.o MyString.o

Assignment1: $(OBJ)
	gcc -o Assignment1 $(OBJ)

Assignment1.o: Assignment1.c MyString.h
	gcc -c Assignment1.c

MyString.o: MyString.c MyString.h
	gcc -c MyString.c

clean:
	rm $(OBJ) Assignment1
