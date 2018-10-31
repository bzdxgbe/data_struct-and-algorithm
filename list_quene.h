//
//  list_quene.h
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/20.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//

#ifndef list_quene_h
#define list_quene_h
#include <stdio.h>
#include<stdlib.h>

typedef struct list_quene_no
{
    int data;
    struct list_quene_no*next;
}list_quene_nod,*list_quene_pnod;

typedef struct list_quene_node
{
    list_quene_pnod top;
    list_quene_pnod bottom;
}list_quene_quene,*list_quene_pquene;

void list_quene_ini(list_quene_pquene p);//初始化
void list_quene_push(list_quene_pquene p,int k);//入队
void list_quene_pop(list_quene_pquene p);//出队
void list_quene_print(list_quene_pquene p);//打印
void list_quene_initial_document(void);//源代码打印

#endif /* list_quene_h */
