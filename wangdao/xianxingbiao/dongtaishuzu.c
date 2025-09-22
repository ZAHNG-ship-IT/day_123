#define InitSize 100
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
//线性表的顺序存储结构

typedef struct 
{
  int *data;
  int MaxSize,length;  
}SeqList;
//线性表要完成的基本操作



void InitList(SeqList *L);//初始化
int length(int* );//求表长
void LocateElem(L,e);//按值查找
GetElem(L,i);//按位查找
bool ListInsert(L,i,e);//插入操作
ListDelete(L,i,e);//插入操作
Print(L);//遍历操作
empty(L);//判空操作
DestoryList(l);//销毁操作，释放空间



int main()
{
  SeqList l;
  InitList(&l);

  printf("hello");
}



void InitList(SeqList *L)
{
    L->data = (int *)malloc(InitSize * sizeof(int));
    L->length = 0;
    L->MaxSize = InitSize;

}

int length(int arr[])
{
    int len = 0;
    while (arr[len] != '\0') {
        len++;
    }
    return len;
}

void LocateElem(SeqList *L, int e)
{

  int i;
  for (i = 0; i < L->length; i++) {
      if (L->data[i] == e) {
          return i;
      }
  }
  return -1;
}

int GetElem(SeqList *L, int i)
{
    if (i < 0 || i >= L->length) {
        // Handle invalid index
        return -1;
    }
    return L->data[i];
}


bool ListInsert(SeqList *L, int i, int e)
{
    if (i < 0 || i > L->length) {
        return false; //判断i的合法性
    }
    if (L->length >= L->MaxSize) {//扩容
        // Reallocate memory if needed
        int *newData = (int *)realloc(L->data, (L->MaxSize + InitSize) * sizeof(int));
        if (!newData) {
            return false; // Memory allocation failed
        }
        L->data = newData;
        L->MaxSize += InitSize;
    }
    for (int j = L->length; j > i; j--) {
        L->data[j] = L->data[j - 1];
    }
    L->data[i] = e;
    L->length++;//需要反复打磨，不然根本写不出来
    //经典的几行代码
    return true;
}