//
//  rb_tree.h
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/7/10.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//

#ifndef rb_tree_h
#define rb_tree_h

# include<stdio.h>
# include<stdlib.h>
# define r 1
# define b 2

typedef struct rb_tree_nod
{
    int weight;
    int color;
    struct rb_tree_nod*lchild;
    struct rb_tree_nod*rchild;
    struct rb_tree_nod*parent;
}rb_tree_node,*rb_tree_pnode;

void rb_tree_file(void);
void rb_tree_print(rb_tree_pnode root,int key,int dec);
rb_tree_pnode rb_tree_insert3(rb_tree_pnode root,rb_tree_pnode p);
rb_tree_pnode rb_tree_insert2(rb_tree_pnode root,rb_tree_pnode p);
rb_tree_pnode rb_tree_insert1(rb_tree_pnode root,int k);
rb_tree_pnode rb_tree_ll(rb_tree_pnode root,rb_tree_pnode y);
rb_tree_pnode rb_tree_rr(rb_tree_pnode root,rb_tree_pnode y);
rb_tree_pnode rb_tree_search(rb_tree_pnode root,int key);
rb_tree_pnode rb_tree_del1(rb_tree_pnode root,int key);
rb_tree_pnode rb_tree_del2(rb_tree_pnode root,rb_tree_pnode p);
rb_tree_pnode rb_tree_del3(rb_tree_pnode root,rb_tree_pnode p,rb_tree_pnode parent);

#endif /* rb_tree_h */
