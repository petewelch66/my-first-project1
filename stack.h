typedef struct
{
	ElemType elem[Stack_Size];
	int top;
}SeqStack;

void InitStack(SeqStack *S)
{
	S->top=-1;
}
int IsStackEmpty(SeqStack *S)
{
	if(S->top==-1)
		return 1;
	else{
		return 0;
	}
}
int IsStackFull(SeqStack *S)
{
	if(S->top==Stack_Size-1)
		return 1;
	else{
		return 0;
	}
}
int Push(SeqStack *S,ElemType x)
{
	if(S->top==Stack_Size-1)
		return 0;
	S->top++;
	S->elem[S->top]=x;
	return 1;
}
int Pop(SeqStack *S,ElemType *x)
{
	if(S->top==-1)
		return 0;
	else{
		*x=S->elem[S->top];
		S->top--;
		return 1;
	}
}
int GetTop(SeqStack *S,ElemType *x)
{
	if(S->top==-1)
		return 0;
	else{
		*x=S->elem[S->top];
		return 1;
	}
}

