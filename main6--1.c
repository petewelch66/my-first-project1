#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
#define MAXSIZE 1000

typedef struct{
    int row,col;
    ElementType e;
}Triple;

typedef struct{
    Triple data[MAXSIZE+1];
    int m,n,len;
}TSMatrix;

void CreateTS(TSMatrix *t){
    int m,n,x,i,j;
    printf("请输入矩阵的行数和列数：");
    scanf("%d%d",&t->m,&t->n);
    t->len=0;
    printf("请按行输入矩阵元素：\n");
    for(i=0;i<t->m;i++){
        for(j=0;j<t->n;j++){
            scanf("%d",&x);
            if(x!=0){
                t->len++;
                t->data[t->len].row=i;
                t->data[t->len].col=j;
                t->data[t->len].e=x;
            }
        }
    }
}

void PrintMatrix(TSMatrix *t){
    int i,j,k;
    int mat[100][100]={0};
    for(k=1;k<=t->len;k++){
        mat[t->data[k].row][t->data[k].col]=t->data[k].e;
    }
    printf("=====矩阵=====\n");
    for(i=0;i<t->m;i++){
        for(j=0;j<t->n;j++){
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
}

void GetRowElements(TSMatrix *t,int i){
	int j=0; int k=0;
    i--;
    if(i<0||i>=t->m){
        printf("行号越界！\n");
        return;
    }
    printf("第%d行元素：",i+1);
    for(j=0;j<t->n;j++){
        int val=0;
        for(k=1;k<=t->len;k++){
            if(t->data[k].row==i&&t->data[k].col==j){
                val=t->data[k].e;
                break;
            }
        }
        printf("%d ",val);
    }
    printf("\n");
}

ElementType GetElement(TSMatrix *t,int i,int j){
	int k=0;
    i--;j--;
    if(i<0||i>=t->m||j<0||j>=t->n){
        printf("行/列号越界！\n");
        return 0;
    }
    for(k=1;k<=t->len;k++){
        if(t->data[k].row==i&&t->data[k].col==j){
            return t->data[k].e;
        }
    }
    return 0;
}

void SimpleTranspose(TSMatrix A,TSMatrix *B){
	int col=0; int i=0;
    B->m=A.n;
    B->n=A.m;
    B->len=0;
    if(A.len==0)return;
    for(col=0;col<A.n;col++){
        for(i=1;i<=A.len;i++){
            if(A.data[i].col==col){
                B->len++;
                B->data[B->len].row=A.data[i].col;
                B->data[B->len].col=A.data[i].row;
                B->data[B->len].e=A.data[i].e;
            }
        }
    }
}

void FastTransposeTSMatrix(TSMatrix A,TSMatrix *B){
    int col,t,p,q;
    int num[MAXSIZE]={0};
    int position[MAXSIZE]={0};
    B->len=A.len;
    B->m=A.n;
    B->n=A.m;
    if(B->len==0)return;
    for(t=1;t<=A.len;t++){
        num[A.data[t].col]++;
    }
    position[0]=1;
    for(col=1;col<A.n;col++){
        position[col]=position[col-1]+num[col-1];
    }
    for(p=1;p<=A.len;p++){
        col=A.data[p].col;
        q=position[col];
        B->data[q].row=A.data[p].col;
        B->data[q].col=A.data[p].row;
        B->data[q].e=A.data[p].e;
        position[col]++;
    }
}

int AddMatrix(TSMatrix A,TSMatrix B,TSMatrix *C){
    if(A.m!=B.m||A.n!=B.n){
        printf("矩阵行列数不同，无法相加！\n");
        return 0;
    }
    C->m=A.m;
    C->n=A.n;
    C->len=0;
    int i=1,j=1;
    while(i<=A.len&&j<=B.len){
        int ra=A.data[i].row,ca=A.data[i].col;
        int rb=B.data[j].row,cb=B.data[j].col;
        if(ra<rb||(ra==rb&&ca<cb)){
            C->len++;
            C->data[C->len]=A.data[i++];
        }else if(ra>rb||(ra==rb&&ca>cb)){
            C->len++;
            C->data[C->len]=B.data[j++];
        }else{
            int sum=A.data[i].e+B.data[j].e;
            if(sum!=0){
                C->len++;
                C->data[C->len].row=ra;
                C->data[C->len].col=ca;
                C->data[C->len].e=sum;
            }
            i++;j++;
        }
    }
    while(i<=A.len){
        C->len++;
        C->data[C->len]=A.data[i++];
    }
    while(j<=B.len){
        C->len++;
        C->data[C->len]=B.data[j++];
    }
    return 1;
}

int main(){
    TSMatrix A,B,transA,C;
    int choice,i,j;
    printf("=====稀疏矩阵三元组运算=====\n");
    CreateTS(&A);
    printf("\n=====功能菜单=====\n");
    printf("1.输出矩阵A\n2.读取第i行元素\n3.读取i行j列元素\n");
    printf("4.简单转置\n5.快速转置\n6.矩阵A+B\n7.退出\n");
    while(1){
        printf("\n请输入选择：");
        scanf("%d",&choice);
        switch(choice){
            case 1:PrintMatrix(&A);break;
            case 2:
                printf("输入行号(从1开始)：");
                scanf("%d",&i);
                GetRowElements(&A,i);break;
            case 3:
                printf("输入行号列号(从1开始)：");
                scanf("%d%d",&i,&j);
                printf("值为：%d\n",GetElement(&A,i,j));break;
            case 4:
                SimpleTranspose(A,&transA);
                PrintMatrix(&transA);break;
            case 5:
                FastTransposeTSMatrix(A,&transA);
                PrintMatrix(&transA);break;
            case 6:
                CreateTS(&B);
                if(AddMatrix(A,B,&C))PrintMatrix(&C);break;
            case 7:printf("退出\n");return 0;
            default:printf("输入错误\n");
        }
    }
    return 0;
}
