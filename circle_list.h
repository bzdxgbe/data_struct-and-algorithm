//
//  circle_list.h
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/21.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//

#ifndef circle_list_h
#define circle_list_h

# include <stdio.h>
# include <stdlib.h>

typedef struct circle_list_nod
{
    int data;
    struct circle_list_nod*next;
}circle_list_node,*circle_list_pnode;


circle_list_pnode circle_list_creat1(circle_list_pnode head);//尾插法创建
circle_list_pnode circle_list_creat2(circle_list_pnode head);//头插法创建
void circle_list_insert1(circle_list_pnode head,int pos,int k);//按位置插入
void circle_list_insert2(circle_list_pnode head,int num,int key);//按数值插入
void circle_list_print(circle_list_pnode head);//链表打印
void circle_list_del1(circle_list_pnode head,int pos);//按位置删除
void circle_list_del2(circle_list_pnode head,int num);//按数值删除
void circle_list_search(circle_list_pnode head,int num);//按数值搜索
void double_list_initial_document(void);//源文件打印

#endif /* circle_list_h */
