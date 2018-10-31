//
//  eight_methods_of_sort.h
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/18.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//

#ifndef eight_methods_of_sort_h
#define eight_methods_of_sort_h

#include <stdio.h>
# include<stdlib.h>
# include<time.h>

# define data_len 20                                                         //数组长度
# define data_max 500                                                        //随机生成数组元素的最大值
void swap(int *a,int *b);                                               //数值交换
void insert_sort(int a[],int n);                                        //插入排序
void chose_sort(int a[],int n);                                         //选择排序
void blue_sort(int a[],int n);                                          //冒泡排序
void quick_sort(int a[],int left,int right);                            //快速排序
void xier_sort(int a[],int n);                                          //希尔排序
void combine_sort(int a[],int first,int last,int tem[]);                //归并排序
void combine(int a[],int first,int mid,int last,int tem[]);

void dui_dowm(int a[],int i,int n);                                     //堆排序
void dui_creat(int a[],int n);
void dui_sort(int a[],int n);

void buck_sort(int a[],int n,int m);                                    //桶排序
void eight_methods_of_sort_initial_document(void);

#endif /* eight_methods_of_sort_h */
