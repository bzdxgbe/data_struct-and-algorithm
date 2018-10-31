//
//  signal_list.c
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/21.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//

#include "signal_list.h"




single_list_pnode single_list_creat1(single_list_pnode head)                   //头插法创建
{
    single_list_pnode p;
    p=(single_list_pnode)malloc(sizeof(single_list_node));
    p->next=NULL;
    printf("请输入一组数据(0截止):\n");
    scanf("%d",&p->data);
    while(p->data!=0)
    {
        p->next=head->next;
        head->next=p;
        p=(single_list_pnode)malloc(sizeof(single_list_node));
        p->next=NULL;
        scanf("%d",&p->data);
    }
    return head;
}


single_list_pnode single_list_creat2(single_list_pnode head)                       //尾插法创建
{
    single_list_pnode p,q;
    q=head;
    while(q->next)
        q=q->next;
    p=(single_list_pnode)malloc(sizeof(single_list_node));
    p->next=NULL;
    printf("请输入一组数据(0截止):\n");
    scanf("%d",&p->data);
    while(p->data!=0)
    {
        q->next=p;
        q=p;
        p=(single_list_pnode)malloc(sizeof(single_list_node));
        p->next=NULL;
        scanf("%d",&p->data);
    }
    q->next=NULL;
    return head;
}


single_list_pnode single_list_insert1(single_list_pnode head,int pos,int k)//按位置插入
{
    single_list_pnode p,q;
    int j=0;
    q=(single_list_pnode)malloc(sizeof(single_list_node));
    q->data=k;
    q->next=NULL;
    p=head;
    while(p->next&&j<pos-1)
    {
        p=p->next;
        j++;
    }
    if(p->next==NULL&&j<=pos-1)
    {
        p->next=q;
        p=q;
        p->next=NULL;
    }
    else
    {
        q->next=p->next;
        p->next=q;
    }
    return head;
}


single_list_pnode single_list_insert2(single_list_pnode head,int num,int k)//按数值插入
{
    single_list_pnode p,q;
    p=head;
    q=(single_list_pnode)malloc(sizeof(single_list_node));
    q->data=k;
    q->next=NULL;
    while(p->next&&p->next->data!=num)
        p=p->next;
    if(p->next==NULL&&p->data!=num)
    {
        printf("insert_number error!\n");
    }
    else if(p->next==NULL&&p->data==num)
    {
        p->next=q;
        p=q;
        p->next=NULL;
    }
    else
    {
        q->next=p->next;
        p->next=q;
    }
    return head;
}


single_list_pnode single_list_del1(single_list_pnode head,int pos)//按位置删除
{
    single_list_pnode p,q,x;
    p=head;
    x=head;
    int j=0;
    while(p->next&&j<pos-1)
    {
        x=p;
        p=p->next;
        j++;
    }
    if(p->next==NULL&&j<=pos-1)
    {
        x->next=NULL;
    }
    else
    {
        q=p->next;
        p->next=q->next;
        free(q);
    }
    return head;
}


single_list_pnode single_list_del2(single_list_pnode head,int num)//按数值删除
{
    single_list_pnode p,q,x;
    p=q=head->next;
    while(p&&p->data!=num)
    {
        q=p;
        p=p->next;
    }
    if(p==NULL)
    {
        return head;
    }
    else
    {
        if(p->next==NULL&&p->data==num)
            q->next=NULL;
        else
        {
            x=q->next;
            q->next=x->next;
            free(x);
        }
        return single_list_del2(head,num);
    }
}


void single_list_find(single_list_pnode head,int num)//按数值搜索
{
    single_list_pnode p;
    int i=0;
    p=head->next;
    while(p&&p->data!=num)
    {
        p=p->next;
        i++;
    }
    if(p==NULL)
        printf("not exist!\n");
    else
        printf("pos:%d\n",i+1);
}


void single_list_print(single_list_pnode head)//链表打印
{
    single_list_pnode p;
    p=head->next;
    while(p)
    {
        printf("%5d",p->data);
        p=p->next;
    }
    printf("\n");
}

single_list_pnode single_list_oppo(single_list_pnode head)//带头结点的链表反转
{
    single_list_pnode p=head;
    single_list_pnode q=head->next;
    single_list_pnode r;
    while(q)
    {
        r=q->next;
        q->next=p;
        p=q;
        q=r;
    }
    head->next->next=NULL;
    q=(single_list_pnode)malloc(sizeof(single_list_node));
    q->next=p;
    head=q;
    return head;
}


single_list_pnode single_list_sort(single_list_pnode head)//带头结点的链表插入排序
{
    single_list_pnode newhead=NULL,toinsert=head;
    single_list_pnode current,last,next;
    while(toinsert)
    {
        current=newhead;
        last=NULL;
        next=toinsert->next;
        while(current&&current->data<=toinsert->data)
        {
            last=current;
            current=current->next;
        }
        if(last==NULL)
        {
            toinsert->next=newhead;
            newhead=toinsert;
        }
        else
        {
            toinsert->next=last->next;
            last->next=toinsert;
        }
        toinsert=next;
    }
    return newhead;
}


void signal_list_initial_document()//单向链表源代码打印
{
    FILE*fp;
    char ch;
    fp=fopen(__FILE__,"r");
    while((ch=fgetc(fp))!=EOF)
        putchar(ch);
    fclose(fp);
}

