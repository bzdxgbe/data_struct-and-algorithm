//
//  double_list.c
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/21.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//

#include "double_list.h"


double_list_pquene double_list_creat1(double_list_pquene head)//尾插法创建
{
    double_list_pquene p,q;
    p=head;
    while(p->next)
        p=p->next;
    printf("请输入一组数据(0截止):\n");
    q=(double_list_pquene)malloc(sizeof(double_list_quene));
    q->front=q->next=NULL;
    scanf("%d",&q->data);
    while(q->data!=0)
    {
        p->next=q;
        q->front=p;
        p=q;
        q=(double_list_pquene)malloc(sizeof(double_list_quene));
        q->front=q->next=NULL;
        scanf("%d",&q->data);
    }
    p->next=NULL;
    return head;
}

double_list_pquene double_list_creat2(double_list_pquene head)//头插法创建
{
    double_list_pquene p;
    p=(double_list_pquene)malloc(sizeof(double_list_quene));
    p->next=p->front=NULL;
    printf("请输入数值(0截止):\n");
    scanf("%d",&p->data);
    while(p->data!=0)
    {
        p->next=head->next;
        head->next=p;
        p->front=head;
        p=(double_list_pquene)malloc(sizeof(double_list_quene));
        p->next=p->front=NULL;
        scanf("%d",&p->data);
    }
    return head;
}


double_list_pquene double_list_insert1(double_list_pquene head,int pos,int k)//按位置插入
{
    double_list_pquene p,q;
    int j=0;
    p=head;
    q=(double_list_pquene)malloc(sizeof(double_list_quene));
    q->next=q->front=NULL;
    q->data=k;
    while(p->next&&j<pos)
    {
        p=p->next;
        j++;
    }
    if(p->next==NULL&&j<pos)
    {
        p->next=q;
        q->front=p;
        p=q;
        p->next=NULL;
    }
    else
    {
        q->front=p->front;
        p->front->next=q;
        q->next=p;
        p->front=q;
    }
    return head;
}

double_list_pquene double_list_insert2(double_list_pquene head,int key,int num)//按数值插入
{
    double_list_pquene p=head->next;
    double_list_pquene q=(double_list_pquene)malloc(sizeof(double_list_quene));
    q->next=q->front=NULL;
    q->data=num;
    while(p&&p->data!=key)
    {
        p=p->next;
    }
    if(p==NULL)
        printf("insert num error!\n");
    else if(p->next==NULL&&p->data==num)
    {
        p->next=q;
        q->front=p;
        p=q;
        p->next=NULL;
    }
    else
    {
        q->front=p->front;
        p->front->next=q;
        q->next=p;
        p->front=q;
    }
    return head;
}

double_list_pquene double_list_del1(double_list_pquene head,int pos)//按位置删除
{
    double_list_pquene p,q;
    int j=0;
    p=q=head;
    while(p->next&&j<pos)
    {
        q=p;
        p=p->next;
        j++;
    }
    if(p->next==NULL&&j<=pos)
    {
        q->next=NULL;
    }
    else
    {
        p->front->next=p->next;
        p->next->front=p->front;
    }
    return head;
}

double_list_pquene double_list_del2(double_list_pquene head,int num)//按数值删除
{
    double_list_pquene p=head->next;
    double_list_pquene q=p;
    while(p&&p->data!=num)
    {
        q=p;
        p=p->next;
    }
    if(p==NULL)
    {
        return head;
    }
    else if(p->next==NULL)
    {
        q->next=NULL;
    }
    else
    {
        p->front->next=p->next;
        p->next->front=p->front;
    }
    return double_list_del2(head,num);
}



void double_list_search(double_list_pquene head,int num)//按数值搜索
{
    double_list_pquene p;
    int j=0;
    p=head;
    while(p->next&&p->next->data!=num)
    {
        j++;
        p=p->next;
    }
    if(p->next==NULL&&p->data!=num)
    {
        printf("can not find!\n");
        return ;
    }
    printf("the pos is:%3d\n",j);
}


void double_list_print(double_list_pquene head)//双向链表打印
{
    double_list_pquene p;
    p=head->next;
    while(p!=NULL)
    {
        printf("%3d",p->data);
        p=p->next;
    }
    printf("\n");
}


void double_list_initial_document()//双向链表源代码打印
{
    FILE*fp;
    char ch;
    fp=fopen(__FILE__,"r");
    while((ch=fgetc(fp))!=EOF)
        putchar(ch);
    fclose(fp);
}
