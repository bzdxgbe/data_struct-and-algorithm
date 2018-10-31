//
//  sort_stack.h
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/20.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//

#ifndef sort_stack_h
#define sort_stack_h

# include <stdio.h>
# include<stdlib.h>
# define sort_stack_len 20

typedef struct sort_stack_nod
{
    int arr[sort_stack_len];
    int top;
}sort_stack_stack,*sort_stack_pstack;


void sort_stack_ini(sort_stack_pstack s);//初始化
void sort_stack_push(sort_stack_pstack s,int k);//入栈
int sort_stack_pop(sort_stack_pstack s);//出栈
void sort_stack_print(sort_stack_pstack s);//打印栈
void sort_stack_initial_document(void);//源代码打印


#endif /* sort_stack_h */
