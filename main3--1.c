#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node,*LinkList;
void InitList(LinkList *L){
	*L=(LinkList)malloc(sizeof(Node));
	if(*L==NULL){ 
        printf("内存分配失败！\n");
        exit(1);}
	(*L)->next=NULL;
}//初始化 
void dayin()
{
	printf("欢迎来到单链表管理系统\n");
	printf("输入数字实现以下功能：\n");
	printf("1:单链表的初始化\n"); 
	printf("2:数据的录入\n"); 
	printf("3:数据的插入\n"); 
	printf("4:数据的删除\n"); 
	printf("5:数据的遍历\n"); 
	printf("6:单链表的长度\n"); 
	printf("7:单链表数据的按值排序\n"); 
	printf("8:单链表的逆置\n"); 
	printf("9:删除数据中的最大或最小值\n"); 
	printf("10:合并两个有序的单链表\n");
	printf("11:单链表的按值拆分或按序拆分\n");
	printf("12:删除有序单链表中大小位于某个区间的值\n");
	printf("13:将两个升序单链表合并为降序新单链表\n");
	printf("14:查找链表中倒数第k个结点\n");
	printf("0:退出单链表\n\n"); 
}
void CreateFromHead(LinkList L)
{
	Node *s,*r;
	r=L;
	int num;
	int flag=1;
	printf("请输入您的数据(输入-1结束)：\n");
	while(flag)
	{
		scanf("%d", &num); 
        if(num==-1){ 
            flag=0;  
            r->next=NULL;
            break;}
		s=(Node*)malloc(sizeof(Node));
		s->data=num;
		r->next=s;
		r=s;
	}
	getchar();
}//尾插法建表 
int InsList(LinkList L,int i,ElemType e)
{
	Node *pre,*s;
	int k;
	if(i<=0)
		return 0;
	pre=L;
	k=0;
	while(pre!=NULL&&k<i-1){
		pre=pre->next;
		k=k+1;}
	if(pre==NULL){
		printf("插入位置不合理！\n");
		return 0;}
	s=(Node*)malloc(sizeof(Node));
	s->data=e;
	s->next=pre->next;
	pre->next=s;
	return 1;
}//插入 
int DelList(LinkList L,int i,ElemType *e) 
{
	Node *pre,*r;
	int k;
	pre=L;
	k=0;
	while(pre->next!=NULL&&k<i-1){
		pre=pre->next;
		k=k+1;}
	if(pre->next==NULL){
		printf("删除的结点的位置i不合理！\n");
		return 0; }
	r=pre->next;
	pre->next=r->next;
	*e=r->data;
	free(r);
	return 1;
}//删除
void shuchu(LinkList L)
{
	Node *pre;
	pre=L;
	if(pre->next==NULL){
		printf("该链表为空！\n");
			return;}
	while(pre->next!=NULL){
		printf("%d ",pre->next->data);
		pre=pre->next;}
	printf("\n");
}//输出
void sortzhijie(LinkList L) 
{
	Node *pre,*p,*temp;
	Node *s=L->next;
	L->next=NULL;
	while(s!=NULL){
		pre=L;
		p=L->next;
		while(p&&s->data>p->data){
			pre=p;
			p=p->next;}
		temp=s->next;
		pre->next=s;
		s->next=p;
		s=temp;}
}//直接插入排序 
void sortjiandan(LinkList L) 
{
	Node *p,*q,*minNode;
    Node *pre,*minPre;
    
    for (p=L->next; p!=NULL; p=p->next) {
        minPre=L;      
        minNode=p;      
        
        pre=p;
        for (q=p->next;q!=NULL;q=q->next) {
            if (q->data<minNode->data) {
                minNode=q;    
                minPre=pre;   }
            pre=q;
        }
        
        if(minNode!=p) {
            int temp=p->data;
            p->data=minNode->data;
            minNode->data=temp;}
    }
}//简单选择排序 
int DeleteMax(LinkList L)
{
    if (L->next==NULL){
    	printf("该链表为空！\n");
        return 0;}
    Node *pre=L, *p=L->next;
    Node *maxPre=pre, *maxNode=p;

    while(p!=NULL)
    {
        if (p->data>maxNode->data){
            maxNode=p;
            maxPre=pre;}
        pre=p;
        p=p->next;
    }
    maxPre->next=maxNode->next;
    free(maxNode);
    return 1;
}//删除最大值 
int DeleteMin(LinkList L)
{
    if(L->next==NULL){
    	printf("该链表为空！\n");
        return 0; }

    Node *pre=L, *p=L->next;
    Node *minPre=pre, *minNode=p;

    while(p!=NULL)
    {
        if(p->data<minNode->data){
            minNode=p;
            minPre=pre;}
        pre=p;
        p=p->next;}
    minPre->next=minNode->next;
    free(minNode);
    return 1;
}//删除最小值 
void ListLength(LinkList L) 
{
	Node *p;
	p=L->next;
	int j=0;
	while(p!=NULL){
		p=p->next;
		j++;}
	printf("单链表的长度为：%d\n",j);
}//求长度 
int Reverse_List(LinkList L)
{
	if(!L->next||!(L->next->next)){
		printf("链表为空或只有一个节点，无需逆置！\n");
		return 0;}
	Node *p=L->next->next;
	Node *temp;
	L->next->next=NULL;
	while(p){
		temp=p->next;
		p->next=L->next;
		L->next=p;
		p=temp;}
	printf("逆置成功！\n");
	return 1;
}//就地逆置 
void MergeList(LinkList a,LinkList b)
{
    Node *pa=a->next;  
    Node *pb=b->next;  
    Node *p=a;         

    while(pa&&pb){
        if(pa->data<=pb->data){
            p->next=pa;
            p=pa;
            pa=pa->next;
        }
        else{
            p->next=pb;
            p=pb;
            pb=pb->next;
        }
    }
    p->next=pa?pa:pb;
    b->next=NULL;
}//单链表升序合并 
void MergeListDesc(LinkList a,LinkList b)
{
    Node *pa=a->next;
    Node *pb=b->next;
    Node *temp, *tail = NULL;

    while (pa&& pb){
        if(pa->data<=pb->data){
            temp=pa->next;
            pa->next=tail;
            tail=pa;
            pa=temp;}
        else{
            temp=pb->next;
            pb->next=tail;
            tail=pb;
            pb=temp;}
    }
    while (pa){
        temp=pa->next;
        pa->next=tail;
        tail=pa;
        pa=temp;}
    while (pb){
        temp=pb->next;
        pb->next=tail;
        tail=pb;
        pb=temp;}
    a->next=tail;
    b->next=NULL;
}//单链表逆序合并 
void SplitByValue(LinkList L,LinkList A,LinkList B)
{
	A->next=NULL; 
    B->next=NULL;
    Node *p=L->next;
    Node *pa=A, *pb=B;

    while (p!=NULL){
        if (p->data%2==0){
            pa->next=p;
            pa=p;}
        else{
            pb->next=p;
            pb=p;}
        p=p->next;}
    pa->next=NULL;
    pb->next=NULL;
    L->next=NULL;
}//奇偶拆分
void SplitByOrder(LinkList L,LinkList A,LinkList B)
{
	A->next=NULL; 
    B->next=NULL;
    Node *p=L->next;
    Node *pa=A, *pb=B;
    int flag=1;

    while (p!=NULL){
        Node *q=p->next;
        if(flag==1){
            pa->next=p;
            pa=p;
            flag=2;}
        else{
            pb->next=p;
            pb=p;
            flag=1;}
        p=q;}
    pa->next=NULL;
    pb->next=NULL;
    L->next=NULL;
}//奇偶位拆分 
int DeleteRange(LinkList L,int min,int max) {
	if(min>max){
        printf("输入错误：最小值不能大于最大值！\n");
        return 0;
    }
    if(L->next==NULL) {
        printf("链表为空！\n");
        return 0;
    }
    Node *pre=L,*p=L->next;
    while(p!=NULL&&p->data<min) {
        pre=p;
        p=p->next;
    }
    while(p!=NULL&&p->data<=max) {
        Node *temp=p;
        p=p->next;
        free(temp); 
    }
    pre->next=p;
    return 1;
}
int FindFromEnd(LinkList L,int k) {
    if(L->next==NULL||k<=0) {
        printf("链表为空或k值非法！\n");
        return 0;
    }
    Node *fast=L->next;
    Node *slow=L->next;
    int count=0;

    while(fast!=NULL&&count<k) {
        fast=fast->next;
        count++;
    }
    if(count<k) {
        printf("k值超出链表长度！\n");
        return 0;
    }
    while(fast!=NULL) {
        slow=slow->next;
        fast=fast->next;
    }
    printf("倒数第%d个节点的值为：%d\n",k,slow->data);
    return 1;
}
int main(int argc, char *argv[]) {
	LinkList L,L1,L2;
	InitList(&L);
	InitList(&L1);
	InitList(&L2);
	int a;
	int i,b,e,jieguo;
	int min,max,k;
	dayin();
	while(1){
		printf("\n请输入一个数字：");
		scanf("%d",&a);
		switch(a){
			case 1:
				InitList(&L);
				printf("链表L已初始化成功！\n");
				break;
			case 2:
				CreateFromHead(L);
				break;
			case 3:
				printf("请输入插入元素的位置：");
				scanf("%d",&i);
				printf("\n请输入插入元素的值： ");
				scanf("%d",&e);
				jieguo=InsList(L,i,e);
				if(jieguo){
					printf("插入元素后存储的数据为：");
					shuchu(L);
				}
				break;
			case 4:
				printf("请输入删除元素的位置：");
				scanf("%d",&i);
				jieguo=DelList(L,i,&e);
				if(jieguo){
					printf("删除元素的值为：%d\n",e);
					printf("删除元素后存储的数据为：");
					shuchu(L);
				}
				break;
			case 5:
				shuchu(L);
				break;
			case 6:
				ListLength(L);
				break;
			case 7:
				printf("请输入一个数字(1:直接插入排序 2:简单选择排序): ");
				scanf("%d",&b);
				if(b==1){
					sortzhijie(L);
					shuchu(L);
				}
				else if(b==2){
					sortjiandan(L);
					shuchu(L);
				}
				else{
					printf("输入数字错误！\n");
				}
				break; 
			case 8:
				jieguo=Reverse_List(L);
				if(jieguo){
					shuchu(L);
				}
				break;
			case 9:
				printf("请输入一个数字(1:删除最大值 2:删除最小值)：");
				scanf("%d",&b);
				if(b==1){
					jieguo=DeleteMax(L);
					if(jieguo){
					shuchu(L);}
				}
				else if(b==2){
					jieguo=DeleteMin(L);
					if(jieguo){
					shuchu(L);}
				}
				else{
					printf("输入数字错误！\n");
				}
				break; 
			case 10:
				printf("创建一个新链表L1\n");
				CreateFromHead(L1);
				printf("\n");
				printf("原链表L：");
				shuchu(L);
				printf("新链表L1：");
				shuchu(L1);
				sortzhijie(L);
				sortzhijie(L1);
				printf("\n请输入一个数字(1:升序合并 2:降序合并)：");
				scanf("%d",&b);
				if(b==1){
					MergeList(L,L1);
					printf("合并后的链表为：");
					shuchu(L);}
				else if(b==2){
					MergeListDesc(L,L1);
					printf("合并后的链表为：");
					shuchu(L);}
				else{
					printf("输入数字错误！\n");}
				break; 
			case 11:
				printf("请输入一个数字(1:奇偶拆分 2:奇偶位拆分)：");
				scanf("%d",&b);
				if(b==1){
					SplitByValue(L,L1,L2);
					printf("已拆分完毕！\n");
					shuchu(L1);
					shuchu(L2);}
				else if(b==2){
					SplitByOrder(L,L1,L2);
					printf("已拆分完毕！\n");
					shuchu(L1);
					shuchu(L2);}
				else{
					printf("输入数字错误！\n");}
				break; 
			case 12:
				printf("请输入区间最小值：");
				scanf("%d",&min);
				printf("请输入区间最大值：");
				scanf("%d",&max);
				DeleteRange(L,min,max);
				printf("删除后链表：");
				shuchu(L);
				break;
			case 13:
				printf("创建一个新链表L1\n");
				CreateFromHead(L1);
				printf("\n");
				printf("原链表L：");
				shuchu(L);
				printf("新链表L1：");
				shuchu(L1);
				sortzhijie(L);
				sortzhijie(L1);
				MergeListDesc(L,L1);
				printf("合并为降序链表：");
				shuchu(L);
				break;
			case 14:
				printf("请输入k值：");
				scanf("%d",&k);
				FindFromEnd(L,k);
				break;
			case 0:
				printf("您已成功退出单链表管理系统！");
				return 0;
			default:
				printf("输入无效！请输入0-14之间的数字！\n");
				break;	
		}
	}
	return 0;
}


