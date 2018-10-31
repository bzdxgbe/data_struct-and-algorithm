//
//  sort_tree.h
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/17.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//
#ifndef sort_tree_h
#define sort_tree_h

# include <stdio.h>
# include <stdlib.h>

typedef struct sort_tree_nod
{
    int data;
    struct sort_tree_nod*lchild;
    struct sort_tree_nod*rchild;
    struct sort_tree_nod*parent;
}sort_tree_node,*sort_tree_pnode;


void sort_tree_insert(sort_tree_pnode *root,int k);//二叉树数值插入，！！！ 插入为二级指针，使用时加&
void sort_tree_creat(sort_tree_pnode *root,int a[],int n);//创建是在插入的基础上实现的，！！！创建也为二级指针，使用时加&
sort_tree_pnode sort_tree_search(sort_tree_pnode root,int k);//二叉树寻找的递归实现
void sort_tree_print(sort_tree_pnode root);//二叉树的中序遍历是有序的
sort_tree_pnode sort_tree_min(sort_tree_pnode root);//寻找二叉树中数值最小的节点
sort_tree_pnode sort_tree_max(sort_tree_pnode root);//寻找二叉树中数值最大的节点
sort_tree_pnode sort_tree_pre(sort_tree_pnode root);//寻找当前节点的前驱节点，以左孩子为基准
sort_tree_pnode sort_tree_aft(sort_tree_pnode root);//寻找当前节点的后继节点，以右孩子为基准
void sort_tree_del(sort_tree_pnode *root,int k);//删除指定值对应的节点！！！删除也为二级指针，使用时加&
int sort_tree_leaf(sort_tree_pnode root);//计算二叉树的叶子节点数目
void sort_tree_special_print(sort_tree_pnode root,int key,int dec);//具体特例打印
void sort_tree_initial_document(void);//源代码打印

#endif /* sort_tree_h */
