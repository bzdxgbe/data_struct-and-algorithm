//
//  open_hash.c
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/21.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//

#include "open_hash.h"



//哈希表初始化
void hash_ini(open_hash_arr p)
{
    int i;
    for(i=0;i<open_hash_len;i++)
    {
        p[i].null=0;
    }
}


//哈希表数据插入
void hash_push(open_hash_arr p,int k)
{
    int i=k%open_hash_key;
    while(p[i].null!=0&&i<open_hash_len)
    {
        i++;
    }
    if(i>=open_hash_len)
    {
        printf("FULL!\n");
        return;
    }
    else
    {
        p[i].null=1;
        p[i].data=k;
    }
}


//哈希表数据查询
void hash_search(open_hash_arr p,int k)
{
    int i=k%open_hash_key;
    while(p[i].data!=k&&i<open_hash_len)
    {
        i++;
    }
    if(i>=open_hash_len)
    {
        printf("not exist!\n");
        return;
    }
    else
    {
        printf("pos:%3d\n",i);
    }
}


//哈希表数据删除
void hash_del(open_hash_arr p,int k)
{
    int i=k%open_hash_key;
    while(p[i].data!=k&&i<open_hash_len)
    {
        i++;
    }
    if(i>=open_hash_len)
    {
        if(open_hash_flag==1)
        {
            printf("删除成功!\n");
            open_hash_flag=0;
        }
        else
            printf("数值不存在，无法删除!\n");
        return;
    }
    else
    {
        p[i].data=0;
        p[i].null=0;
        open_hash_flag=1;
        return hash_del(p,k);
    }
}


//哈希表打印
void hash_print(open_hash_arr p)
{
    int i;
    printf("哈希表如下:\n");
    for(i=0;i<open_hash_len;i++)
    {
        if(i%20==0)
            printf("\n");
        printf("%4d",p[i].data);
    }
    printf("\n");
}

//打印源代码
void open_hash_initial_document()
{
    FILE*fp;
    char ch;
    fp=fopen(__FILE__,"r");
    while((ch=fgetc(fp))!=EOF)
        putchar(ch);
    fclose(fp);
}
