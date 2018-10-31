//
//  signal_list.h
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/21.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//

#ifndef signal_list_h
#define signal_list_h

# include <stdio.h>
# include<stdlib.h>


typedef struct single_list
{
    int data;
    struct single_list*next;
}single_list_node,*single_list_pnode;


single_list_pnode single_list_creat1(single_list_pnode head);//头插法创建
single_list_pnode single_list_creat2(single_list_pnode head);//尾插法创建
single_list_pnode single_list_insert1(single_list_pnode head,int pos,int k);//按位置插入数值
single_list_pnode single_list_insert2(single_list_pnode head,int num,int k);//按数值插入数值
single_list_pnode single_list_del1(single_list_pnode head,int pos);//按位置删除数值
single_list_pnode single_list_del2(single_list_pnode head,int num);//按数值删除数值
void single_list_find(single_list_pnode head,int num);//按数值搜索数值
void single_list_print(single_list_pnode head);//打印链表
single_list_pnode single_list_oppo(single_list_pnode head);//链表反转
single_list_pnode single_list_sort(single_list_pnode head);//对链表进行插入排序
void signal_list_initial_document(void);//打印链表源代码

#endif /* signal_list_h */
