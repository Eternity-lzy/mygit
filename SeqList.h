#ifndef SEQLIST_H_INCLUDED
#define SEQLIST_H_INCLUDED
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef void SeqList;
typedef void SeqListNode;
typedef struct _tag_SeqList
{
    int capacity;   //表容量
    int length;       //表长度
    int *node;     //数组指针

}TSeqList;
//创建链表
SeqList *SeqList_Create(int capacity)
{
    int ret;
    TSeqList *temp=NULL;
    temp=(TSeqList *)malloc(sizeof(TSeqList));
    if (temp==NULL)
    {
        ret=1;
        printf("func SeqList_Create() error:%d\n",ret);
        return NULL;
    }
    memset(temp,0,sizeof(TSeqList));
    temp->capacity=capacity;
    temp->length=0;
    temp->node=(int *) malloc(sizeof(void *)*capacity);      //分配一个指针数组
    if (temp->node==NULL)
    {
        ret=2;
        printf("func SeqList_Create() error:%d",ret);
        return NULL;

    }
    return temp;

}
//获取表容量
int SeqList_Capacity(SeqList * list)
{
    TSeqList *temp=NULL;
    if (list==NULL)
    {
        return 0;
    }
    temp=(TSeqList *)list;
    return temp->capacity;
}
//获取顺序表长度
int SeqList_Length(SeqList * list)
{
    TSeqList *temp=NULL;
    if (list==NULL)
    {
        return 0;
    }
    temp=(TSeqList *)list;
    return temp->length;
}
//插入元素
int SeqList_Insert(SeqList *list,SeqListNode *node,int pos)
//参数list：顺序表地址  *node：插入元素地址  POS：插入位置
{
    int i;
    TSeqList *temp=NULL;
    //判断顺序表是否为空
    if (list==NULL||node==NULL)
    {
        return -1;
    }
    temp=(TSeqList *)list;
    //判断顺序表是否满
    if (temp->length>=temp->capacity)
    {
        return -2;
    }
    //容错
    if (pos>temp->length)   //如果参数pos在长度后即中间有空余
    {
        pos=temp->length;    //修正到最后一个元素后边
    }
    //将插插入位置之后元素依次向后移动
    for (i=temp->length;i>pos;i--)
    {
        temp->node[i]=temp->node[i-1];
    }
    temp->node[i]=(int)node;
    temp->length++;
    return  0;
}
//删除元素
SeqList *Seqlist_Delete(SeqList *list,int pos)
{
    int i;
    //健壮判断
    TSeqList *tlist=NULL;
    SeqListNode *temp=NULL;
    tlist=(TSeqList *) list;
    if (list==NULL||pos<0||pos>=tlist->capacity)
    {
        printf("SeqList_Delete() error!\n");
        return NULL;
    }
    temp=(SeqListNode *)tlist->node[pos];  //要删除的元素
    for (i=pos+1;i<tlist->length;i++)   //将要删除元素之后元素前移
    {
        tlist->node[i-1]=tlist->node[i];
    }
    tlist->length--;
    return temp;

}
//查找某个位置上的元素
SeqList * SeqList_Get(SeqList * list,int pos)
{
    //健壮判断
    TSeqList * tlist=NULL;
    SeqListNode * temp=NULL;
    tlist=(TSeqList *)list;
    if (list==NULL||pos<0||pos>=tlist->capacity)
    {
        printf("SeqLsit_Get() error!\n");
        return NULL;
    }
    temp=(SeqList *)tlist->node[pos];
    return temp;
}
//清空顺序表
void SeqList_Clear(SeqList * list)
{
    TSeqList * temp=NULL;
    if (list==NULL)
    {
        return ;
    }
    temp=(TSeqList *)list;
    temp->length=0;
    memset(temp->node,0,(temp->capacity*sizeof(void *)));//将顺序表全部归0
    return ;
}
//销毁表
void SeqList_Destory(SeqList * list )
{
    TSeqList *temp=NULL;
    if (list==NULL)  //如果顺序表为空
        return ;
    temp=(TSeqList *)list;
    if(temp->node!=NULL)  //如果顺序表不为空
        free(temp->node);  //限时房头结点中的指针数组
    free(temp);  //在释放头结点
    return ;
}



























#endif // SEQLIST_H_INCLUDED
