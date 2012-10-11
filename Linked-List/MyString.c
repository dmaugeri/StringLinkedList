#include "MyString.h"
#include <stdio.h>
#include <stdlib.h>

int Initialize(String *S)
{
    S->head = NULL;
}

int Length(String *S)
{
    int length=0;
    if(S->head == NULL)
        return 0;

    StringNode *A = S->head->next;
    length++;
    while(A != NULL){
        length++;
        A = A->next; 
    }    
    return length;
}

int InsertChar(char X, int Pos, String *S)
{
    int length = Length(S); 

    if(Pos < 1 || Pos > length + 1){
        fprintf(stderr, "The position does not exist\n");
        return 1;
    }
    //alocates memory for new node 
    StringNode *new = (StringNode *)malloc(sizeof(StringNode));
    new->data = X;
    
    if(Pos == 1) {
        new->next = S->head;
        S->head = new; 
   } else {
        StringNode *middle = S->head;
        int i;

        for(i = 0; i < Pos-2; ++i) {
            middle = middle->next;
        }

        new->next = middle->next;
        middle->next = new;
    }

    return 0;
}

int InsertString(String *X, int Pos, String *S)
{


}

int GetChar(char *C, int Pos, String *S)
{
    int length = Length(S);
    if(Pos < 1 || Pos > length) {
        fprintf(stderr,"No letter at that position\n");
        return 1;
    }

    if(Pos == 1) {
        *C = S->head->data;
   } else {
        StringNode *middle = S->head;
        int i;
        for(i = 0; i < Pos-1; ++i) {
            middle = middle->next;
        }
        *C = middle->data;
    }
    return 0;
}

int CopyString(String *X, int Pos, int start, int end, String *S)
{

}

int DeleteChar(int Pos, String *S)
{
    int length = Length(S);
    if(Pos < 1 || Pos > length) {
        fprintf(stderr,"No letter at that position\n");
        return 1;
    }
    StringNode *tmp = S->head;

    if(Pos == 1) {
        tmp = tmp->next;
        free(S->head);
        S->head = tmp; 
    }else{
        StringNode *middle = S->head;
        int i;
        for(i = 0; i < Pos-2; ++i) {
            middle = middle->next;
        }
    } 
}

int DeteString(int first, int last, String *S)
{

}

int PrintString(String *S)
{
    StringNode *tmp = S->head;
    while(tmp != NULL) {
        printf("%c", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
    return 0;
}
