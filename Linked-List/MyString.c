#include "MyString.h"
#include <stdio.h>
#include <stdlib.h>

int Initialize(String *S)
{
    S->head = NULL;
}
//Calculates the length of String S
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

//Inserts character X, at position Pos in String S
int InsertChar(char X, int Pos, String *S)
{
    int length = Length(S); 

    if(Pos < 1 || Pos > length + 1){
        fprintf(stderr, "The position does not exist\n");
        return 0;
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

    return 1;
}
//Inserts String X into String S, String X is  unchanged
int InsertString(String *X, int Pos, String *S)
{
    if(Pos < 1 || Pos > Length(S)+1) {
        fprintf(stderr,"Invalid position");
        return 0;
    }
    int i;
    for(i = 0; i < Length(X);++i) {
        char c;
        GetChar(&c,i+1,X);
        InsertChar(c,Pos+i,S);
    }
    return 1;
}

//Puts the character found at position Pos in String S into C
int GetChar(char *C, int Pos, String *S)
{
    int length = Length(S);
    if(Pos < 1 || Pos > length) {
        fprintf(stderr,"No letter at that position\n");
        return 0;
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
    return 1;
}
//Copies a substring of S into position Pos of string X. The substring is the substring of S from position start
//to position end inclusive. S is unchanced.
int CopyString(String *X, int Pos, int start, int end, String *S)
{
    int lengthS = Length(S);
    int lengthX = Length(X)+1;

    if(Pos < 1 || Pos > lengthX) {
        fprintf(stderr, "Invalid position");
        return 0;
    } else if(start < 1 || start > lengthS) {
        fprintf(stderr, "Invalid start position");
        return 0;
    } else if(end > lengthS || end < 1) {
        fprintf(stderr, "Invalid end position");
        return 0;
    } else if(start > end) {
        fprintf(stderr, "end cannot be greater then start");
        return 0;
    }
    int i;
    //+1 for 1 based indexing
    for(i = 0; i < end - start + 1 ; ++i) {
        char c;
        GetChar(&c,start+i,S);
        InsertChar(c,Pos+i,X);
    }
    return 1;
}
//Deletes character at position Pos in String S
int DeleteChar(int Pos, String *S)
{
    int length = Length(S);
    if(Pos < 1 || Pos > length) {
        fprintf(stderr,"No letter at that position\n");
        return 0;
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
        tmp = middle->next;
        free(middle->next);
        middle->next = tmp->next;
    } 
    return 1;
}
//Deletes from character first to last in String S (inclusive)
int DeleteString(int first, int last, String *S)
{
    int lengthS = Length(S);

    if(first > lengthS || first < 1) {
        fprintf(stderr, "Invalid first position");
        return 0;
    } else if(last < 1 || last > lengthS) {
        fprintf(stderr, "Invalid last position");
        return 0;
    } else if(first > last) {
        fprintf(stderr, "First position cannot be greater than last position");
        return 0;
    }
    int i;

    for(i = first; i <= last; ++i) {
        DeleteChar(first,S);
        //printf("%d\n",i);
    } 
    return 1;
    
}

//prints string S
int PrintString(String *S)
{
    StringNode *tmp = S->head;
    while(tmp != NULL) {
        printf("%c", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
    return 1;
}
