//
//  list_quene.c
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/20.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//

#include "list_quene.h"



void list_quene_ini(list_quene_pquene p)//链队初始化
{
    p->top=p->bottom=(list_quene_pnod)malloc(sizeof(list_quene_nod));
    p->top->next=NULL;
}

void list_quene_push(list_quene_pquene p,int k)//入队
{
    list_quene_pnod s;
    s=(list_quene_pnod)malloc(sizeof(list_quene_nod));
    s->data=k;
    s->next=NULL;
    p->bottom->next=s;
    p->bottom=s;
}

void list_quene_pop(list_quene_pquene p)//出队
{
    if(p->top==p->bottom)
    {
        printf("NULL\n");
        return;
    }
    else
    {
        p->top=p->top->next;
    }
}


void list_quene_print(list_quene_pquene p)//打印
{
    list_quene_pnod s;
    s=p->top->next;
    while(s!=p->bottom->next)
    {
        printf("%3d",s->data);
        s=s->next;
    }
    printf("\n");
}

void list_quene_initial_document()//源代码打印
{
    FILE*fp;
    char ch;
    fp=fopen(__FILE__,"r");
    while((ch=fgetc(fp))!=EOF)
        putchar(ch);
    fclose(fp);
}

