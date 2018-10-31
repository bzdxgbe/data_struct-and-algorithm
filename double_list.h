//
//  double_list.h
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/21.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//

#ifndef double_list_h
#define double_list_h


# include <stdio.h>
# include<stdlib.h>

typedef struct double_list_node
{
    int data;
    struct double_list_node *next;
    struct double_list_node *front;
}double_list_quene,*double_list_pquene;


double_list_pquene double_list_creat1(double_list_pquene head);//尾插法
double_list_pquene double_list_creat2(double_list_pquene head);//头插法
double_list_pquene double_list_insert1(double_list_pquene head,int pos,int k);//按位置插入
double_list_pquene double_list_insert2(double_list_pquene head,int key,int num);//按数值插入
double_list_pquene double_list_del1(double_list_pquene head,int pos);//按位置删除
double_list_pquene double_list_del2(double_list_pquene head,int pos);//按数值删除
void double_list_search(double_list_pquene head,int num);//按数值搜索
void double_list_print(double_list_pquene head);//双向链表打印
void double_list_initial_document(void);//双向链表源代码打印


#endif /* double_list_h */
