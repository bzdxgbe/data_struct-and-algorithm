//
//  bs_dui.h
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/20.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//

#ifndef bs_dui_h
#define bs_dui_h

#include <stdio.h>
#include <stdlib.h>
# define dui_len 10


void dui_print(int a[],int n);
void dui_max_creat(int a[],int n);
void dui_fix_down(int a[],int i,int n);
void dui_bs_sort(int a[],int b[],int n);
void dui_swap(int *x,int *y);
void dui_fix_up(int a[],int i);
void dui_min_creat(int a[],int n);
void bs_dui_initial_document(void);

#endif /* bs_dui_h */
