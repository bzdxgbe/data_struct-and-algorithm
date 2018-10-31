//
//  list_hash.c
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/21.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//

#include "list_hash.h"




void list_hash_ini(list_hash_arr array)//哈希表初始化
{
    int i;
    for(i=0;i<list_hash_len;i++)
    {
        array[i]=(list_hash_pnode)malloc(sizeof(list_hash_node));
        array[i]->next=NULL;
    }
}


void list_hash_top_creat(list_hash_arr array,int k)//头插法创建
{
    int address=k%list_hash_key;
    list_hash_pnode p;
    p=(list_hash_pnode)malloc(sizeof(list_hash_node));
    p->data=k;
    p->next=array[address]->next;
    array[address]->next=p;
}

void list_hash_bottom_creat(list_hash_arr array,int k)//尾插法创建
{
    int address=k%list_hash_key;
    list_hash_pnode p;
    p=(list_hash_pnode)malloc(sizeof(list_hash_node));
    p->data=k;
    p->next=NULL;
    list_hash_pnode q=array[address];
    while(q->next)
        q=q->next;
    q->next=p;
    q=p;
    q->next=NULL;
}

void list_hash_del(list_hash_arr array,int k)//按数值删除
{
    int address=k%list_hash_key;
    list_hash_pnode p=array[address]->next;
    list_hash_pnode q=array[address];
    list_hash_pnode x;
    while(p&&p->data!=k)
    {
        q=p;
        p=p->next;
    }
    if(p==NULL)
    {
        if(list_hash_flag==0)
        {
            printf("删除的数值%4d不存在!\n",k);
        }
        else
        {
            printf("删除成功!\n");
            list_hash_flag=0;
        }
        return;
    }
    else
    {
        if(p->next==NULL)
        {
            q->next=NULL;
        }
        else
        {
            x=q->next;
            q->next=x->next;
            free(x);
        }
        list_hash_flag=1;
        return list_hash_del(array,k);
    }

}


void list_hash_search(list_hash_arr array ,int k)//按数值搜索
{
    int address=k%list_hash_key;
    list_hash_pnode p=array[address]->next;
    int pos=0;
    while(p!=NULL&&p->data!=k)
    {
        p=p->next;
        pos++;
    }
    if(p==NULL)
    {
        printf("数值%4d不存在!\n",k);
        return;
    }
    else
    {
        printf("数值存在于第%3d行第%3d位\n",address+1,pos);
    }
}


void list_hash_print(list_hash_arr array)//哈希打印
{
    list_hash_pnode p;
    int i;
    for(i=0;i<list_hash_len;i++)
    {
        p=array[i]->next;
        while(p)
        {
            printf("%4d",p->data);
            p=p->next;
        }
        printf("\n");
    }
}

void list_hash_initial_document()//源代码打印
{
    FILE*fp;
    char ch;
    fp=fopen(__FILE__,"r");
    while((ch=fgetc(fp))!=EOF)
        putchar(ch);
    fclose(fp);
}
