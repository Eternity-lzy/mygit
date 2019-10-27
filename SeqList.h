#ifndef SEQLIST_H_INCLUDED
#define SEQLIST_H_INCLUDED
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef void SeqList;
typedef void SeqListNode;
typedef struct _tag_SeqList
{
    int capacity;   //������
    int length;       //����
    int *node;     //����ָ��

}TSeqList;
//��������
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
    temp->node=(int *) malloc(sizeof(void *)*capacity);      //����һ��ָ������
    if (temp->node==NULL)
    {
        ret=2;
        printf("func SeqList_Create() error:%d",ret);
        return NULL;

    }
    return temp;

}
//��ȡ������
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
//��ȡ˳�����
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
//����Ԫ��
int SeqList_Insert(SeqList *list,SeqListNode *node,int pos)
//����list��˳����ַ  *node������Ԫ�ص�ַ  POS������λ��
{
    int i;
    TSeqList *temp=NULL;
    //�ж�˳����Ƿ�Ϊ��
    if (list==NULL||node==NULL)
    {
        return -1;
    }
    temp=(TSeqList *)list;
    //�ж�˳����Ƿ���
    if (temp->length>=temp->capacity)
    {
        return -2;
    }
    //�ݴ�
    if (pos>temp->length)   //�������pos�ڳ��Ⱥ��м��п���
    {
        pos=temp->length;    //���������һ��Ԫ�غ��
    }
    //�������λ��֮��Ԫ����������ƶ�
    for (i=temp->length;i>pos;i--)
    {
        temp->node[i]=temp->node[i-1];
    }
    temp->node[i]=(int)node;
    temp->length++;
    return  0;
}
//ɾ��Ԫ��
SeqList *Seqlist_Delete(SeqList *list,int pos)
{
    int i;
    //��׳�ж�
    TSeqList *tlist=NULL;
    SeqListNode *temp=NULL;
    tlist=(TSeqList *) list;
    if (list==NULL||pos<0||pos>=tlist->capacity)
    {
        printf("SeqList_Delete() error!\n");
        return NULL;
    }
    temp=(SeqListNode *)tlist->node[pos];  //Ҫɾ����Ԫ��
    for (i=pos+1;i<tlist->length;i++)   //��Ҫɾ��Ԫ��֮��Ԫ��ǰ��
    {
        tlist->node[i-1]=tlist->node[i];
    }
    tlist->length--;
    return temp;

}
//����ĳ��λ���ϵ�Ԫ��
SeqList * SeqList_Get(SeqList * list,int pos)
{
    //��׳�ж�
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
//���˳���
void SeqList_Clear(SeqList * list)
{
    TSeqList * temp=NULL;
    if (list==NULL)
    {
        return ;
    }
    temp=(TSeqList *)list;
    temp->length=0;
    memset(temp->node,0,(temp->capacity*sizeof(void *)));//��˳���ȫ����0
    return ;
}
//���ٱ�
void SeqList_Destory(SeqList * list )
{
    TSeqList *temp=NULL;
    if (list==NULL)  //���˳���Ϊ��
        return ;
    temp=(TSeqList *)list;
    if(temp->node!=NULL)  //���˳���Ϊ��
        free(temp->node);  //��ʱ��ͷ����е�ָ������
    free(temp);  //���ͷ�ͷ���
    return ;
}



























#endif // SEQLIST_H_INCLUDED
