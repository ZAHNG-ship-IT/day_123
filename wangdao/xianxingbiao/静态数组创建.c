 #define MaxSize 50

#include <stdio.h>





typedef struct 
{
//    ElemType data[MaxSize];   ElemType这个数据类型是任意的，例如int，double等等
    int data[MaxSize];
    int length;

}SqList;
//定义的静态数组的结构
void InitList(SqList *L);

int main()
{
    SqList L;
    InitList(&L);
}







void InitList(SqList *L)
{
    L->length = 0;
}

