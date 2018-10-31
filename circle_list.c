//
//  circle_list.c
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/21.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//

#include "circle_list.h"

static int circle_list_count=0;

circle_list_pnode circle_list_creat1(circle_list_pnode head)   //尾插法创建链表，头结点为空
{
    circle_list_pnode p,q;
    p=head;
    while(p->next)
        p=p->next;
    printf("请输入一组数据(0截止):\n");
    q=(circle_list_pnode)malloc(sizeof(circle_list_node));
    scanf("%d",&q->data);
    q->next=NULL;
    while(q->data!=0)
    {
        p->next=q;
        p=q;
        q=(circle_list_pnode)malloc(sizeof(circle_list_node));
        scanf("%d",&q->data);
        circle_list_count++;
        q->next=NULL;
    }
    p->next=head->next;
    return head;
}

circle_list_pnode circle_list_creat2(circle_list_pnode head)//头插法创建
{
    circle_list_pnode q;
    printf("请输入一组数据(0截止):\n");
    q=(circle_list_pnode)malloc(sizeof(circle_list_node));
    scanf("%d",&q->data);
    q->next=NULL;
    while(q->data!=0)
    {
        q->next=head->next;
        head->next=q;
        q=(circle_list_pnode)malloc(sizeof(circle_list_node));
        scanf("%d",&q->data);
        circle_list_count++;
    }
    return head;
}

void circle_list_insert1(circle_list_pnode head,int pos,int k)//按位置插入
{
    int i=0;
    circle_list_pnode p,q;
    q=(circle_list_pnode)malloc(sizeof(circle_list_node));
    q->data=k;
    q->next=NULL;
    p=head;
    while(p->next&&i<pos%circle_list_count-1)
    {
        i++;
        p=p->next;
    }
    q->next=p->next;
    p->next=q;
    circle_list_count++;
}

void circle_list_insert2(circle_list_pnode head,int num,int key)//按数值插入
{
    circle_list_pnode p=head;
    int i=0;
    circle_list_pnode q=(circle_list_pnode)malloc(sizeof(circle_list_node));
    q->next=NULL;
    q->data=key;
    while(p->next&&p->next->data!=num&&i<circle_list_count)
    {
        i++;
        p=p->next;
    }
    if(i>=circle_list_count)
    {
        printf("can not find!\n");
        return;
    }
    else
    {
        q->next=p->next;
        p->next=q;
        circle_list_count++;
    }
}


void circle_list_del1(circle_list_pnode head,int pos)//按位置删除
{
    int i=0;
    circle_list_pnode p,q;
    p=head;
    if(circle_list_count==0)
    {
        printf("NULL\n");
        return ;
    }
    while(p->next&&i<pos%circle_list_count-1)
    {
        i++;
        p=p->next;
    }
    q=p->next;
    p->next=q->next;
    circle_list_count--;
}

void circle_list_del2(circle_list_pnode head,int num)//按数值删除
{
    circle_list_pnode p=head;
    circle_list_pnode q;
    int i=0;
    while(p->next&&p->next->data!=num&&i<circle_list_count)
    {
        i++;
        p=p->next;
    }
    if(i>=circle_list_count)
    {
        return;
    }
    else
    {
        q=p->next;
        p->next=q->next;
        free(q);
        circle_list_count--;
    }
    return circle_list_del2(head,num);
}

void circle_list_search(circle_list_pnode head,int num)//按数值搜索
{
    circle_list_pnode p=head;
    int i=0;
    while(p->next&&p->next->data!=num&&i<circle_list_count)
    {
        i++;
        p=p->next;
    }
    if(i>=circle_list_count)
    {
        printf("not exist!\n");
        return;
    }
    else
        printf("exist pos:%3d\n",i);
}

void circle_list_print(circle_list_pnode head)//链表打印
{
    circle_list_pnode p=head->next;
    int i=0;
    while(i<circle_list_count)
    {
        printf("%3d",p->data);
        p=p->next;
        i++;
    }
    printf("\n");
}

void circle_list_initial_document()
{
    FILE*fp;
    char ch;
    fp=fopen(__FILE__,"r");
    while((ch=fgetc(fp))!=EOF)
        putchar(ch);
    fclose(fp);
}
