//
//  bs_dui.c
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/20.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//

#include "bs_dui.h"


void dui_fix_down(int a[],int i,int n)
{
    int j,tem;
    tem=a[i];
    j=2*i+1;
    while(j<n)
    {
        if(j+1<n&&a[j+1]<a[j])
            j++;
        if(tem<=a[j])
            break;
        a[i]=a[j];
        i=j;
        j=2*i+1;
    }
    a[i]=tem;
}

void dui_fix_up(int a[],int i)
{
    int j,tem;
    tem=a[i];
    j=(i-1)/2;
    while(i>0)
    {
        if(a[j]<=tem)
            break;
        a[i]=a[j];
        i=j;
        j=(i-1)/2;
    }
    a[i]=tem;
}

void dui_max_creat(int a[],int n)
{
    int i;
    for(i=n/2-1;i>=0;i--)
        dui_fix_up(a,i);
}

void dui_min_creat(int a[],int n)
{
    int i;
    for(i=n/2-1;i>=0;i--)
        dui_fix_down(a,i,n);
}
void dui_swap(int *x,int *y)
{
    int i;
    i=*x;
    *x=*y;
    *y=i;
}
void dui_bs_sort(int a[],int b[],int n)
{
    int i;
    for(i=0;i<dui_len;i++)
        b[i]=a[i];
    for(i=n-1;i>=1;i--)
    {
        dui_swap(&b[0],&b[i]);
        dui_fix_down(b,0,i);
    }
}

void dui_print(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%3d",a[i]);
    printf("\n");
}

void bs_dui_initial_document()
{
    FILE*fp;
    char ch;
    fp=fopen(__FILE__,"r");
    while((ch=fgetc(fp))!=EOF)
        putchar(ch);
    fclose(fp);
}
