//  sort_tree.h
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/17.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//
#ifndef avl_tree_h
#define avl_tree_h
# include<stdio.h>
# include<stdlib.h>

typedef struct avl_tree_nod
{
    int weight;
    int height;
    struct avl_tree_nod*lchild;
    struct avl_tree_nod*rchild;
}avl_tree_node,*avl_tree_pnode;


int avl_tree_high(avl_tree_pnode root);//平衡二叉树高度计算
int avl_tree_max(int a,int b);//两者寻找最大值
avl_tree_pnode avl_tree_ll(avl_tree_pnode k);//左旋
avl_tree_pnode avl_tree_rr(avl_tree_pnode k);//右旋
avl_tree_pnode avl_tree_rl(avl_tree_pnode k);//右左旋
avl_tree_pnode avl_tree_lr(avl_tree_pnode k);//左右旋
avl_tree_pnode avl_tree_search(avl_tree_pnode root,int k);//搜索
avl_tree_pnode avl_tree_min_search(avl_tree_pnode root);//最小节点的搜索
avl_tree_pnode avl_tree_max_search(avl_tree_pnode root);//最大节点的节点
void avl_tree_print(avl_tree_pnode root);//打印
avl_tree_pnode avl_tree_insert(avl_tree_pnode root,int k);//数据插入，注意平衡操作
avl_tree_pnode avl_tree_del(avl_tree_pnode root,int k);//删除数据，注意平衡操作
void avl_tree_print_AVL(avl_tree_pnode tree, int key, int direction);//特例打印
void avl_tree_initial_document(void);//源代码打印


# endif
