//
//  sort_stack.c
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/20.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//

#include "sort_stack.h"



void sort_stack_ini(sort_stack_pstack s)//初始化
{
    s->top=-1;
}


void sort_stack_push(sort_stack_pstack s,int k)//入栈
{
    if(s->top>=sort_stack_len)
    {
        printf("FULL!\n");
        return;
    }
    else
    {
        s->top++;
        s->arr[s->top]=k;
    }
}

int sort_stack_pop(sort_stack_pstack s)//出栈
{
    int i;
    if(s->top<0)
    {
        printf("NULL!\n");
        return -1;
    }
    else
    {
        i=s->arr[s->top];
        s->top--;
        return i;
    }
}

void sort_stack_print(sort_stack_pstack s)//打印栈
{
    int i;
    i=s->top;
    while(i>=0)
    {
        printf("%3d",s->arr[i]);
        i--;
    }
    printf("\n");
}

void sort_stack_initial_document()//源代码打印
{
    FILE*fp;
    char ch;
    fp=fopen(__FILE__,"r");
    while((ch=fgetc(fp))!=EOF)
        putchar(ch);
    fclose(fp);
}
