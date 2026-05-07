//创建链表函数，结点包括学号和成绩,创建两个链表后，再将这两个链表合并，按学号升序排序。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct student) //一个结点的内存大小 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct student  //定义结构体，包含学号和成绩 
{
	char id[20];
	int grade;
	struct student*next;
}SSS,*list; //起别名:SSS，定义一个结构体指针 
SSS* create(void) //创建链表函数 
{
	SSS*head=NULL,*tail=NULL,*neww=NULL; //定义头指针、尾指针、新指针 
	printf("请输入学生的学号和成绩(输入#停止)： \n");
	while(1){
	neww=(SSS*)malloc(LEN); //给新指针分配内存空间 
	scanf("%s",neww->id);  
	if (!strcmp(neww->id,"#")) //输入#结束 
	{
		free(neww); //释放新结点，防止内存泄露 
		break;
	}
	scanf("%d",&neww->grade);
	neww->next=NULL;
	
	if (head == NULL){ //空链表，头尾指向新结点 
            head = neww;
            tail = neww;
        }
        else { //尾指针的next指向新结点，尾指针后移 
            tail->next = neww;
            tail = neww;
        }
    }
	return head;
}
SSS* neipaixu(SSS* head) //先对每一个链表进行内部排序 
{
    if (head == NULL || head->next == NULL) {
        return head; //空结点或只有一个结点直接返回 
    }

    SSS* p, * q;
    char temp_id[20];
    int temp_grade;
    
    for (p = head; p != NULL; p = p->next) {//外层：多少轮 
        for (q = head; q->next != NULL; q = q->next) { //内层：相邻结点比较 
            if (strcmp(q->id, q->next->id) > 0) { //前面的学号大 
                strcpy(temp_id, q->id);  //id是char类型，用strcpy实现交换 
                strcpy(q->id, q->next->id);
                strcpy(q->next->id, temp_id);
        
                temp_grade = q->grade; //交换成绩 
                q->grade = q->next->grade;
                q->next->grade = temp_grade;
            }
        }
    }
    return head;
}
void print(SSS* head) //打印链表函数 
{
	SSS* p=head;
	if (head==NULL){  //空链表 
		printf("list is empty\n");
	}
	else{
		printf("学生的学号和成绩如下:\n");
		while(p!=NULL){ //遍历链表 
			printf("%s %d\n",p->id,p->grade);
			p=p->next;
		}
	}
}
SSS* hb(SSS* listA, SSS* listB)  //两个链表合并 排序 
{
    SSS head;
    SSS* current = &head;
    head.next = NULL;
    
    while (listA != NULL && listB != NULL) {  //需满足两个链表都有结点未处理 
        if (strcmp(listA->id, listB->id) < 0) {
            current->next = listA; //谁小接入谁，并且该链表指针后移 
            listA = listA->next;
        } else {
            current->next = listB;
            listB = listB->next;
        }
        current = current->next; //新指针后移 
    }
    if (listA != NULL) { //拼接剩余链表 
        current->next = listA;
    } else {
        current->next = listB;
    }
    return head.next;
}



int main(int argc, char *argv[]) {
	printf("===== 创建链表a =====\n");
    list a = create();
    printf("\n===== 创建链表b =====\n");
    list b = create();

    a = neipaixu(a);  //两个链表先内排序 
    b = neipaixu(b);
    
    printf("\n===== 链表a的内容 =====\n");
    print(a);
    printf("=====链表b的内容 =====\n");
    print(b);
    
    list pxh = hb(a, b); //两个链表合并排序 

    printf("\n===== 合并排序后的链表 =====\n");
    print(pxh);
    
    
	return 0;
}
