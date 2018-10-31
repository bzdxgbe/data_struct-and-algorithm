//
//  sort_circle_quene.c
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/20.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//

#include "sort_circle_quene.h"



void circle_quene_ini(sort_circle_quene_pquene p)//初始化
{
    p->top=p->bottom=0;
}

void circle_quene_push(sort_circle_quene_pquene p,int k)//入队，注意循环操作
{
    if(p->top==(p->bottom+1)%sort_circle_quene_len)
    {
        p->top=(p->top+1)%sort_circle_quene_len;
    }
    p->arr[p->bottom%sort_circle_quene_len]=k;
    p->bottom=(p->bottom+1)%sort_circle_quene_len;
}

void circle_quene_pop(sort_circle_quene_pquene p)//出队
{
    if(p->top==p->bottom)
    {
        printf("NULL!\n");
        return;
    }
    else
    {
        p->top=(p->top+1)%sort_circle_quene_len;
    }
}


void circle_quene_print(sort_circle_quene_pquene p)//打印
{
    int i;
    i=p->top;
    while(i%sort_circle_quene_len!=(p->bottom)%sort_circle_quene_len)
    {
        printf("%3d",p->arr[i]);
        i=(i+1)%sort_circle_quene_len;
    }
    printf("\n");
}

void sort_circle_quene_initial_document()//源代码打印
{
    FILE*fp;
    char ch;
    fp=fopen(__FILE__,"r");
    while((ch=fgetc(fp))!=EOF)
        putchar(ch);
    fclose(fp);
}

