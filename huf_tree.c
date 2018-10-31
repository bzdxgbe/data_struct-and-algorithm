//
//  huf_tree.c
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/18.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//

#include "huf_tree.h"
 

void huf_tree_min_select(huf hf,int n,int *s1,int *s2)//寻找权重数组中最小的两个
{
    int tem=max,temi=0,i;
    for(i=1;i<=n;i++)
    {
        if(!hf[i].parent)
        {
            if(tem>hf[i].weight)
            {
                tem=hf[i].weight;
                temi=i;
            }
        }
    }
    *s1=temi;
    tem=max;
    temi=0;
    for(i=1;i<=n;i++)
    {
        if(!hf[i].parent&&i!=*s1)
        {
            if(tem>hf[i].weight)
            {
                tem=hf[i].weight;
                temi=i;
            }
        }
    }
    *s2=temi;
}


void huf_tree_creat(huf hf,int w[])//构建M个节点的信息，包括父节点，左孩子，右孩子
{
    int i;
    for(i=1;i<=N;i++)
    {
        hf[i].parent=0;
        hf[i].weight=w[i];
        hf[i].lchild=0;
        hf[i].rchild=0;
    }
    for(i=N+1;i<=M;i++)
    {
        hf[i].parent=0;
        hf[i].weight=0;
        hf[i].lchild=0;
        hf[i].rchild=0;
    }
    for(i=N+1;i<=M;i++)
    {
        int s1,s2;
        huf_tree_min_select(hf,i-1,&s1,&s2);
        hf[s1].parent=i;
        hf[s2].parent=i;
        hf[i].lchild=s1;
        hf[i].rchild=s2;
        hf[i].weight=hf[s1].weight+hf[s2].weight;
    }
}


void huf_tree_print_intocode(huf hf,char c[])//打印M个节点信息
{
    int i;
    printf("字符  权重  父节点  左孩子  右孩子\n");
    for(i=1;i<=M;i++)
    {
        if(i<=N)
            printf("%2c %4d %5d %6d %6d\n",c[i],hf[i].weight,hf[i].parent,hf[i].lchild,hf[i].rchild);
        else
            printf("%2d %4d %5d %6d %6d\n",0,hf[i].weight,hf[i].parent,hf[i].lchild,hf[i].rchild);
    }
}


void huf_tree_into_code(huf hf,hufchar ch)//生成N个字符的哈夫曼编码
{
    char tem[N];
    tem[N-1]='\0';
    int c,f,start,i;
    for(i=1;i<=N;i++)
    {
        start=N-1;
        c=i;
        f=hf[i].parent;
        while(f)
        {
            if(hf[f].lchild==c)
                tem[--start]='0';
            else if(hf[f].rchild==c)
                tem[--start]='1';
            c=f;
            f=hf[f].parent;
        }
        ch[i]=(char*)malloc((N-start)*sizeof(char));
        strcpy(ch[i],&tem[start]);
    }
}


void huf_tree_print_outcode(hufchar ch,char c[])//打印N个字符的哈夫曼编码
{
    int i;
    printf("字符  编码\n");
    for(i=1;i<=N;i++)
        printf("%2c   %s\n",c[i],ch[i]);
}


void huf_tree_code_out(huf hf,char c[],char test[],int len,char result[])//输入一串数据，将数据反向解码未字符串
{
    int i,j,p;
    i=0;
    j=0;
    p=M;
    while(i<len)
    {
        if(test[i]=='0')
            p=hf[p].lchild;
        else if(test[i]=='1')
            p=hf[p].rchild;
        if(p<=N)
        {
            result[j]=c[p];
            p=M;
            j++;
        }
        i++;
    }
    result[j]='\0';
}


void huf_tree_initial_document()//源代码打印
{
    FILE*fp;
    char ch;
    fp=fopen(__FILE__,"r");
    while((ch=fgetc(fp))!=EOF)
        putchar(ch);
    fclose(fp);
}
