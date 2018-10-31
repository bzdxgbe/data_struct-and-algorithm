//
//  bmp_kmp_search.c
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/18.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//

#include "bmp_kmp_search.h"


void bmp_search(char str1[],char str2[])
{
    int i,j,k,count=0;
    for(i=0;str1[i]!='\0';i++)
    {
        for(j=i,k=0;str2[k]!='\0'&&str1[j]==str2[k];j++,k++)
        {
            ;
        }
        if(k>0&&str2[k]=='\0')
        {
            count++;
        }
    }
    if(count>0)
        printf("出现次数:%3d\n",count);
    else
        printf("can not find!\n");
}


void kmp_search(char str1[],char str2[])
{
    int i=0,j=0;
    int len1,len2;
    int count=0;
    len1=(int)strlen(str1);
    len2=(int)strlen(str2);
    int tem[string_len];
    get_line(str2,tem);
    while(i<len1)
    {
        if(j==-1||str1[i]==str2[j])
        {
            j++;
            i++;
        }
        else
        {
            j=tem[j];
        }
        if(j==len2)
            count++;
    }
    if(count>0)
        printf("出现次数:%3d\n",count);
    else
        printf("can not find!\n");
}


void get_line(char str[],int tem[])
{
    int j=0;
    int k=-1;
    tem[0]=-1;
    while(j<strlen(str)-1)
    {
        if(k==-1||str[k]==str[j])
        {
            k++;
            j++;
            tem[j]=k;
        }
        else
            k=tem[k];
    }
}

void bmp_kmp_initial_document()
{
    FILE*fp;
    char ch;
    fp=fopen(__FILE__,"r");
    while((ch=fgetc(fp))!=EOF)
        putchar(ch);
    fclose(fp);
}

