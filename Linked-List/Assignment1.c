#include <stdio.h>
#include <stdlib.h>
#include "MyString.h"

int main(int argc, char *argv[])
{
    String S1, S2;
    char X;
    Initialize(&S1);
    Initialize(&S2);

    printf("%d\n",Length(&S1));
    InsertChar('A', 1, &S1);    //A
    PrintString(&S1);
    InsertChar('B', 2, &S1);    //AB
    PrintString(&S1);
    InsertChar('C', 2, &S1);    //ACB
    PrintString(&S1);
    InsertChar('D', 4, &S1);    //ACBD
    PrintString(&S1);           //Should print ACBD
    DeleteChar(1, &S1);         //Should delete A

    PrintString(&S1);           //should print CBD
    InsertChar('E', 0, &S1);    //Fails
    InsertChar('E', 6, &S1);    //Fails
    GetChar(&X, 3, &S1);         //S1 is unchanged
    printf("%c\n",X);           //prints D
    InsertString(&S1, 1, &S2);  //S2: is CBD and S1 is unchanged
    PrintString(&S2);           //Should print CBD
    CopyString(&S1, 2,1,3, &S2);    //S1: is CCBDBD and S2 is unchanged
    PrintString(&S1);           //Should print CCBDBD
}
