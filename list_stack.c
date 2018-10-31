//
//  list_stack.c
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/20.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//

#include "list_stack.h"



void list_stack_ini(list_stack_pstack s)//链栈初始化
{
    s->top=s->bottom=(list_stack_pnod)malloc(sizeof(list_stack_nod));
    s->top->next=NULL;
}

void list_stack_push(list_stack_pstack s,int k)//入栈
{
    list_stack_pnod p;
    p=(list_stack_pnod)malloc(sizeof(list_stack_nod));
    p->data=k;
    p->next=s->top;
    s->top=p;
}

void list_stack_pop(list_stack_pstack s)//出栈
{
    if(s->top==s->bottom)
    {
        printf("NULL\n");
        return;
    }
    else
    {
        s->top=s->top->next;
    }
}


void list_stack_print(list_stack_pstack s)//打印
{
    list_stack_pnod p;
    p=s->top;
    while(p!=s->bottom)
    {
        printf("%3d",p->data);
        p=p->next;
    }
    printf("\n");
}

void list_stack_initial_document()//源代码打印
{
    FILE*fp;
    char ch;
    fp=fopen(__FILE__,"r");
    while((ch=fgetc(fp))!=EOF)
        putchar(ch);
    fclose(fp);
}
