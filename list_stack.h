//
//  list_stack.h
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/20.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//

#ifndef list_stack_h
#define list_stack_h


# include <stdio.h>
# include<stdlib.h>
typedef struct list_stack_no
{
    int data;
    struct list_stack_nod *next;
}list_stack_nod,*list_stack_pnod;

typedef struct list_stack_node
{
    list_stack_pnod top;
    list_stack_pnod bottom;
}list_stack_stack,*list_stack_pstack;


void list_stack_ini(list_stack_pstack s);//初始化
void list_stack_push(list_stack_pstack s,int k);//入栈
void list_stack_pop(list_stack_pstack s);//出栈
void list_stack_print(list_stack_pstack s);//打印
void list_stack_initial_document(void);//打印源代码


#endif /* list_stack_h */
