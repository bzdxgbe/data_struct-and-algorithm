//
//  eight_methods_of_sort.c
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/18.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//

#include "eight_methods_of_sort.h"

//数值交换
void swap(int *a,int *b)
{
    int tem;
    tem=*a;
    *a=*b;
    *b=tem;
}

//插入排序
void insert_sort(int a[],int n)
{
    int i,tem,j;
    for(i=1;i<n;i++)
    {
        tem=a[i];
        for(j=i-1;j>=0&&tem<a[j];j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=tem;
    }
}

//选择排序
void chose_sort(int a[],int n)
{
    int i,k,j;
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[k])
                k=j;
        }
        if(i!=k)
            swap(&a[i],&a[k]);
    }
}

//冒泡排序
void blue_sort(int a[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j+1]<a[j])
                swap(&a[j],&a[j+1]);
        }
    }
}

//快速排序
void quick_sort(int a[],int left,int right)
{
    int low,high,x;
    if(left<right)
    {
        low=left;
        high=right;
        x=a[low];
        while(low<high)
        {
            while(low<high&&a[high]>x)
                high--;
            if(low<high)
                a[low++]=a[high];
            while(low<high&&a[low]<x)
                low++;
            if(low<high)
                a[high--]=a[low];
            a[low]=x;
            quick_sort(a,left,low-1);
            quick_sort(a,low+1,right);
        }
    }
}

//希尔排序
void xier_sort(int a[],int n)
{
    int gap,i,j;
    for(gap=n/2;gap>0;gap=gap/2)
    {
        for(j=gap;j<n;j++)
        {
            for(i=j-gap;i>=0&&a[i+gap]<a[i];i=i-gap)
                swap(&a[i+gap],&a[i]);
        }
    }
}

//归并排序
void combine_sort(int a[],int first,int last,int tem[])
{
    int mid;
    if(first<last)
    {
        mid=(first+last)/2;
        combine_sort(a,first,mid,tem);
        combine_sort(a,mid+1,last,tem);
        combine(a,first,mid,last,tem);
    }
}

void combine(int a[],int first,int mid,int last,int tem[])
{
    int i=first,n=mid,j=mid+1,m=last,k=0;
    while(i<=n&&j<=m)
    {
        if(a[i]<a[j])
            tem[k++]=a[i++];
        else
            tem[k++]=a[j++];
    }
    while(i<=n)
        tem[k++]=a[i++];
    while(j<=m)
        tem[k++]=a[j++];
    for(i=0;i<k;i++)
        a[first+i]=tem[i];
}

//堆排序
void dui_down(int a[],int i,int n)
{
    int tem,j;
    tem=a[i];
    j=2*i+1;
    while(j<n)
    {
        if(j+1<n&&a[j+1]>a[j])
            j++;
        if(tem>=a[j])
            break;
        a[i]=a[j];
        i=j;
        j=2*i+1;
    }
    a[i]=tem;
}

void dui_creat(int a[],int n)
{
    int i;
    for(i=n/2-1;i>=0;i--)
        dui_down(a,i,n);
}

void dui_sort(int a[],int n)
{
    int i;
    for(i=n-1;i>=1;i--)
    {
        swap(&a[i],&a[0]);
        dui_down(a,0,i);
    }
}


//桶排序
void buck_sort(int a[],int n,int m)
{
    int *array;
    int i,j;
    array=(int *)malloc(data_max*sizeof(int));
    for(i=0;i<data_max;i++)
        array[i]=0;
    for(i=0;i<data_len;i++)
        array[a[i]]++;
    for(i=0,j=0;i<data_max;i++)
    {
        while(array[i]-->0)
            a[j++]=i;
    }
}

void eight_methods_of_sort_initial_document()
{
    FILE*fp;
    char ch;
    fp=fopen(__FILE__,"r");
    while((ch=fgetc(fp))!=EOF)
        putchar(ch);
    fclose(fp);
}

