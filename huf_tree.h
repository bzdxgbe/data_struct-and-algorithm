//
//  huf_tree.h
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/18.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//

#ifndef huf_tree_h
#define huf_tree_h

#include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define N 5
# define M 2*N-1
# define max 20000

typedef struct huf_tree_node
{
    int weight;
    int parent;
    int lchild;
    int rchild;
}huf[M+1];//N个字符串可以对应M个哈弗曼树的节点
typedef char *hufchar[N+1];// N个指针，指向N个字符的哈夫曼编码，记住字符串及其权值从1开始

void huf_tree_min_select(huf hf,int n,int *s1,int *s2);//寻找剩余权值中前两小的数值
void huf_tree_creat(huf hf,int w[]);//创建哈弗曼树
void huf_tree_print_intocode(huf hf,char c[]);//打印哈夫曼编码
void huf_tree_into_code(huf hf,hufchar ch);//哈夫曼编码
void huf_tree_print_outcode(hufchar ch,char c[]);//打印哈夫曼解码
void huf_tree_code_out(huf hf,char c[],char test[],int len,char result[]);//哈夫曼解码
void huf_tree_initial_document(void);//源代码打印

#endif /* huf_tree_h */
