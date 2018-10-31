//
//  sort_circle_quene.h
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/20.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//

#ifndef sort_circle_quene_h
#define sort_circle_quene_h

# include <stdio.h>
# define sort_circle_quene_len 5


typedef struct sort_circle_quene_node
{
    int arr[sort_circle_quene_len];
    int top;
    int bottom;
}sort_circle_quene_quene,*sort_circle_quene_pquene;


void circle_quene_ini(sort_circle_quene_pquene p);//初始化
void circle_quene_push(sort_circle_quene_pquene p,int k);//入队
void circle_quene_pop(sort_circle_quene_pquene p);//出队
void circle_quene_print(sort_circle_quene_pquene p);//打印队
void sort_circle_quene_initial_document(void);//源代码打印
#endif /* sort_circle_quene_h */
