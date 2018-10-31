//
//  sort_quene.h
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/20.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//

#ifndef sort_quene_h
#define sort_quene_h


# include <stdio.h>
# define sort_quene_len 20


typedef struct sort_quene_nod
{
    int arr[sort_quene_len];
    int top;
    int count;
    int rear;
}sort_quene_quene,*sort_quene_pquene;


void sort_quene_ini(sort_quene_pquene p);//初始化
void sort_quene_push(sort_quene_pquene p,int k);//入队
int sort_quene_pop(sort_quene_pquene p);//出队
void sort_quene_print(sort_quene_pquene p);//打印队
void sort_quene_initial_document(void);//源代码打印


#endif /* sort_quene_h */
