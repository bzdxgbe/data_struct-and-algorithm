//
//  main.c
//  avl_tree
//
//  Created by 暴走的小钢镚儿 on 2018/3/17.
//  Copyright © 2017年 暴走的小钢镚儿. All rights reserved.
//
# include"avl_tree.h"


int avl_tree_high(avl_tree_pnode root)//二叉树高度计算
{
    return (root==NULL?-1:root->height);
}


int avl_tree_max(int a,int b)//寻找两者最大者
{
    return (a>b?a:b);
}

avl_tree_pnode avl_tree_ll(avl_tree_pnode k)//左旋
{
    avl_tree_pnode k1=k->lchild;
    k->lchild=k1->rchild;
    k1->rchild=k;
    k->height=avl_tree_max(avl_tree_high(k->lchild),avl_tree_high(k->rchild))+1;
    k1->height=avl_tree_max(avl_tree_high(k1->lchild),k->height)+1;
    return k1;
}

avl_tree_pnode avl_tree_rr(avl_tree_pnode k)//右旋
{
    avl_tree_pnode k1=k->rchild;
    k->rchild=k1->lchild;
    k1->lchild=k;
    k->height=avl_tree_max(avl_tree_high(k->lchild),avl_tree_high(k->rchild))+1;
    k1->height=avl_tree_max(avl_tree_high(k1->rchild),k->height)+1;
    return k1;
}

avl_tree_pnode avl_tree_rl(avl_tree_pnode k)//右左旋
{
    k->rchild=avl_tree_ll(k->rchild);
    return avl_tree_rr(k);
}

avl_tree_pnode avl_tree_lr(avl_tree_pnode k)//左右旋
{
    k->lchild=avl_tree_rr(k->lchild);
    return avl_tree_ll(k);
}


avl_tree_pnode avl_tree_search(avl_tree_pnode root,int k)//数值搜索
{
    if(root==NULL||root->weight==k)
        return root;
    else if(k<root->weight)
        return avl_tree_search(root->lchild,k);
    else
        return avl_tree_search(root->rchild,k);
}

avl_tree_pnode avl_tree_min_search(avl_tree_pnode root)//最小节点搜索
{
    if(root==NULL||root->lchild==NULL)
        return root;
    else
        return avl_tree_min_search(root->lchild);
}


avl_tree_pnode avl_tree_max_search(avl_tree_pnode root)//最大节点搜索
{
    if(root==NULL||root->rchild==NULL)
        return root;
    else
        return avl_tree_min_search(root->rchild);
}


void avl_tree_print(avl_tree_pnode root)//打印二叉树信息
{
    if(root!=NULL)
    {
        avl_tree_print(root->lchild);
        printf("%5d",root->weight);
        avl_tree_print(root->rchild);
    }
}

avl_tree_pnode avl_tree_insert(avl_tree_pnode root,int k)//平衡二叉树插入
{
    avl_tree_pnode p;
    p=(avl_tree_pnode)malloc(sizeof(avl_tree_node));
    p->weight=k;
    p->height=0;
    p->lchild=p->rchild=NULL;
    if(root==NULL)
    {
        root=p;
    }
    else if(k<root->weight)
    {
        root->lchild=avl_tree_insert(root->lchild,k);
        if(avl_tree_high(root->lchild)-avl_tree_high(root->rchild)==2)
        {
            if(k<root->lchild->weight)
                root=avl_tree_ll(root);
            else
                root=avl_tree_lr(root);
        }
    }
    else if(k>root->weight)
    {
        root->rchild=avl_tree_insert(root->rchild,k);
        if(avl_tree_high(root->rchild)-avl_tree_high(root->lchild)==2)
        {
            if(k>root->rchild->weight)
                root=avl_tree_rr(root);
            else
                root=avl_tree_rl(root);
        }
    }
    else
        printf("不能插入相同数值%5d!\n",k);
    root->height=avl_tree_max(avl_tree_high(root->rchild),avl_tree_high(root->lchild))+1;
    return root;
}



avl_tree_pnode avl_tree_del(avl_tree_pnode root,int k)//平衡二叉树删除
{
    if(root==NULL||avl_tree_search(root,k)==NULL)
    {
        printf("do not exist!\n");
        return root;
    }
    if(k<root->weight)
    {
        root->lchild=avl_tree_del(root->lchild,k);
        if(avl_tree_high(root->rchild)-avl_tree_high(root->lchild)==2)
        {
            avl_tree_pnode x=root->rchild;
            if(avl_tree_high(x->lchild)>avl_tree_high(x->rchild))
                root=avl_tree_rl(root);
            else
                root=avl_tree_rr(root);
        }
    }
    else if(k>root->weight)
    {
        root->rchild=avl_tree_del(root->rchild,k);
        if(avl_tree_high(root->lchild)-avl_tree_high(root->rchild)==2)
        {
            avl_tree_pnode x=root->lchild;
            if(avl_tree_high(x->rchild)>avl_tree_high(x->lchild))
                root=avl_tree_lr(root);
            else
                root=avl_tree_ll(root);
        }
    }
    else
    {
        if(root->lchild&&root->rchild)
        {
            if(avl_tree_high(root->lchild)>avl_tree_high(root->rchild))
            {
                avl_tree_pnode x=avl_tree_max_search(root->lchild);
                root->weight=x->weight;
                root->lchild=avl_tree_del(root->lchild,x->weight);
            }
            else
            {
                avl_tree_pnode y=avl_tree_min_search(root->rchild);
                root->weight=y->weight;
                root->rchild=avl_tree_del(root->rchild,y->weight);
            }
        }
        else
        {
            avl_tree_pnode z=root;
            root=root->lchild?root->lchild:root->rchild;
            free(z);
        }
    }
    return root;
}


void avl_tree_print_AVL(avl_tree_pnode tree, int key, int direction)//特例打印
{
    char *s;
    if(tree!=NULL)
    {
        if(direction==0)    // tree是根节点
            printf("%5d is root\n", tree->weight);
        else                // tree是分支节点
            printf("%5d is %2d's %6schild\n", tree->weight, key, s=(direction==1?"right" : "left"));
        avl_tree_print_AVL(tree->lchild,tree->weight, 2);
        avl_tree_print_AVL(tree->rchild,tree->weight,  1);
    }
}


void avl_tree_initial_document()//源代码打印
{
    FILE*fp;
    char ch;
    fp=fopen(__FILE__,"r");
    while((ch=fgetc(fp))!=EOF)
        putchar(ch);
    fclose(fp);
}
