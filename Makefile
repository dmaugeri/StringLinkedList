OBJ=MyStringTester.o MyString.o

Assignment1: $(OBJ)
	gcc -o MyStringTester $(OBJ)

Assignment1.o: MyStringTester.c MyString.h
	gcc -c MyStringTester.c

MyString.o: MyString.c MyString.h
	gcc -c MyString.c

clean:
	rm $(OBJ) MyStringTester
