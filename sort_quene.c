//
//  sort_quene.c
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/20.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//

#include "sort_quene.h"



void sort_quene_ini(sort_quene_pquene p)//初始化
{
    p->top=p->rear=0;
    p->count=0;
}

void sort_quene_push(sort_quene_pquene p,int k)//入队
{
    if(p->rear>=sort_quene_len)
    {
        printf("FULL!\n");
        return ;
    }
    else
    {
        p->arr[p->rear]=k;
        p->rear++;
        p->count++;
    }
}

int sort_quene_pop(sort_quene_pquene p)//出队
{
    int i,j;
    if(p->count==0)
    {
        printf("NULL!\n");
        return -1;
    }
    else
    {
        i=p->arr[p->top];
        p->count--;
        p->rear--;
        for(j=0;j<p->count;j++)
            p->arr[j]=p->arr[j+1];
        p->arr[j]=0;
        return i;
    }
}

void sort_quene_print(sort_quene_pquene p)//打印
{
    int i;
    i=p->top;
    while(i!=sort_quene_len)
    {
        printf("%3d",p->arr[i]);
        i++;
    }
    printf("\n");
}


void sort_quene_initial_document()//源代码打印
{
    FILE*fp;
    char ch;
    fp=fopen(__FILE__,"r");
    while((ch=fgetc(fp))!=EOF)
        putchar(ch);
    fclose(fp);
}
