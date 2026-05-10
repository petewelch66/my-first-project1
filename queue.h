typedef struct
{
	QueueElementType element[MAXSIZE];
	int front;
	int rear;
}SeqQueue;

void InitQueue(SeqQueue *Q)
{
	Q->front=Q->rear=0;
}//初始化 

int IsQueueEmpty(SeqQueue *Q){
	if(Q->rear==Q->front)
		return 1;
	else 
		return 0;
}//判空 
int IsQueueFull(SeqQueue *Q){
	if((Q->rear+1)%MAXSIZE==Q->front)
		return 1;
	else 
		return 0;
}//判满 
int EnterQueue(SeqQueue *Q,QueueElementType x)
{
	if((Q->rear+1)%MAXSIZE==Q->front)
		return 0;
	Q->element[Q->rear]=x;
	Q->rear=(Q->rear+1)%MAXSIZE;
	return 1;
}//入队 
int DeleteQueue(SeqQueue *Q,QueueElementType *x)
{
	if(Q->rear==Q->front)
		return 0;
	*x=Q->element[Q->front];
	Q->front=(Q->front+1)%MAXSIZE;
	return 1;
}//出队 
int GetHead(SeqQueue *Q,QueueElementType *x)
{
	if(Q->rear==Q->front){
		printf("循环队列为空！\n");
		return 0;
	}
	else{
		*x=Q->element[Q->front];
		return 1;
	}
}//读队头 
int GetTail(SeqQueue *Q,QueueElementType *x)
{
	if(Q->rear==Q->front){
		printf("循环队列为空！\n");
		return 0;
	}
	else{
		*x=Q->element[(Q->rear-1+MAXSIZE)%MAXSIZE];
		return 1;
	}
}//读队尾 


