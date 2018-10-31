//
//  list_hash.h
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/21.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//

#ifndef list_hash_h
#define list_hash_h


# include<stdio.h>
# include<stdlib.h>
# define list_hash_len 5   //表头数组长度
# define list_hash_key 4   //除数留余关键字
static int list_hash_flag=0;

typedef struct list_hash_nod
{
    int data;
    struct list_hash_nod *next;
}list_hash_node,*list_hash_pnode,*list_hash_arr[list_hash_len];


void list_hash_ini(list_hash_arr array);//初始化哈希链表头
void list_hash_top_creat(list_hash_arr array,int k);//哈希头插法
void list_hash_bottom_creat(list_hash_arr array,int k);//哈希表尾插法
void list_hash_print(list_hash_arr array);//哈希打印
void list_hash_del(list_hash_arr array,int k);//哈希表按数值删除
void list_hash_search(list_hash_arr array ,int k);//按数值搜索

void list_hash_initial_document(void);//源代码打印
#endif /* list_hash_h */
