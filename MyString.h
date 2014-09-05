typedef struct StringTag {
    char data; 
    struct StringTag *next;    
} StringNode;

typedef struct {
    StringNode *head;
} String;

extern int Initialize(String *S);
extern int Length(String *S);
extern int InsertChar(char X, int Pos, String *S);
extern int InsertString(String *X, int Pos, String *S);
extern int GetChar(char *C, int Pos, String *S);
extern int CopyString(String *X, int Pos, int start, int end, String *S);
extern int DeleteChar(int Pos, String *S);
extern int DeleteString(int first, int last, String *S);
extern int PrintString(String *S);
