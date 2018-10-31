//
//  sort_tree.c
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/17.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//
#include "sort_tree.h"


void sort_tree_insert(sort_tree_pnode*root,int k)//排序二叉树插入
{
    sort_tree_pnode p;
    p=(sort_tree_pnode)malloc(sizeof(sort_tree_node));
    p->data=k;
    p->lchild=p->rchild=p->parent=NULL;
    if((*root)==NULL)
    {
        (*root)=p;
    }
    else if((*root)->lchild==NULL&&k<(*root)->data)
    {
        p->parent=(*root);
        (*root)->lchild=p;
    }
    else if((*root)->rchild==NULL&&k>(*root)->data)
    {
        p->parent=(*root);
        (*root)->rchild=p;
    }
    if((*root)->data>k)
        sort_tree_insert(&(*root)->lchild,k);
    else if((*root)->data<k)
        sort_tree_insert(&(*root)->rchild,k);
}


void sort_tree_creat(sort_tree_pnode *root,int a[],int n)//排序二叉树创建
{
    int i=0;
    while(i<n)
    {
        sort_tree_insert(root,a[i]);
        i++;
    }
}


sort_tree_pnode sort_tree_search(sort_tree_pnode root,int k)//排序二叉树搜索
{
    if(root==NULL||root->data==k)
        return root;
    else if(root->data>k)
        return sort_tree_search(root->lchild,k);
    else
        return sort_tree_search(root->rchild,k);
}


void sort_tree_print(sort_tree_pnode root)//排序二叉树打印
{
    if(root)
    {
        sort_tree_print(root->lchild);
        printf("%3d",root->data);
        sort_tree_print(root->rchild);
    }
}


sort_tree_pnode sort_tree_min(sort_tree_pnode root)//寻找最小节点
{
    if(root==NULL||root->lchild==NULL)
        return root;
    else
        return sort_tree_min(root->lchild);
}


sort_tree_pnode sort_tree_max(sort_tree_pnode root)//寻找最大节点
{
    if(root==NULL||root->rchild==NULL)
        return root;
    else
        return sort_tree_max(root->rchild);
}


sort_tree_pnode sort_tree_pre(sort_tree_pnode root)//寻找前驱节点
{
    if(root==NULL)
        return root;
    if(root->lchild)
        return sort_tree_max(root->lchild);
    else
    {
        if(root->parent==NULL)
            return NULL;
        while(root)
        {
            if(root->parent->rchild==root)
                break;
            root=root->parent;
        }
        return root->parent;
    }
}


sort_tree_pnode sort_tree_aft(sort_tree_pnode root)//寻找后继节点
{
    if(root==NULL)
        return root;
    if(root->rchild)
        return sort_tree_min(root->rchild);
    else
    {
        if(root->parent==NULL)
            return NULL;
        while(root)
        {
            if(root->parent->lchild==root)
                break;
            root=root->parent;
        }
        return root->parent;
    }
}


void sort_tree_del(sort_tree_pnode *root,int k)//删除节点
{
    sort_tree_pnode p,q;
    int t;
    p=sort_tree_search((*root),k);
    if(p==NULL)
    {
        printf("error!\n");
        return ;
    }
    
    if(p->lchild==NULL&&p->rchild==NULL)
    {
        if(p->parent==NULL)
            (*root)=NULL;
        else if(p->parent->lchild==p)
            p->parent->lchild=NULL;
        else if(p->parent->rchild==p)
            p->parent->rchild=NULL;
        free(p);
    }

    else if(p->lchild&&!p->rchild)
    {
        p->lchild->parent=p->parent;
        if(p->parent==NULL)
            (*root)=p->lchild;
        else if(p->parent->lchild==p)
            p->parent->lchild=p->lchild;
        else if(p->parent->rchild==p)
            p->parent->rchild=p->lchild;
        free(p);
    }

    else if(p->rchild&&!p->lchild)
    {
        p->rchild->parent=p->parent;
        if(p->parent==NULL)
            (*root)=p->rchild;
        else if(p->parent->lchild==p)
            p->parent->lchild=p->rchild;
        else if(p->parent->rchild==p)
            p->parent->rchild=p->rchild;
        free(p);
    }
    
    else
    {
        q=sort_tree_aft(p);
        t=q->data;
        sort_tree_del(root,q->data);
        p->data=t;
    }
}


int sort_tree_leaf(sort_tree_pnode root)//根节点结算
{
    int leaf;
    if(root==NULL)
        leaf=0;
    else if(root->rchild==NULL&&root->lchild==NULL)
        leaf=1;
    else
        leaf=sort_tree_leaf(root->rchild)+sort_tree_leaf(root->lchild);
    return leaf;
}


void sort_tree_special_print(sort_tree_pnode root,int key,int dec)//特例节点信息打印
{
    char *s;
    if(root!=NULL)
    {
        if(dec==0)
            printf("%3d is root\n",root->data);
        else
            printf("%3d is %3d %5s child\n",root->data,key,s=(dec==1?"right":"left"));
        sort_tree_special_print(root->lchild,root->data,3);
        sort_tree_special_print(root->rchild,root->data,1);
    }
}


void sort_tree_initial_document()//源代码打印
{
    FILE*fp;
    char ch;
    fp=fopen(__FILE__,"r");
    while((ch=fgetc(fp))!=EOF)
        putchar(ch);
    fclose(fp);
}




//************************************/
/******一级指针可以不必返回指针直接创建****/
/************************************/
/*
 # include <stdio.h>
 # include <stdlib.h>
 
 typedef struct nod
 {
 int data;
 struct nod*lchild;
 struct nod*rchild;
 struct nod*parent;
 }node,*pnode;
 
 
 pnode sort_tree_insert(pnode root,int k);             //二叉树数值插入，二级指针                   ！！！ 插入为二级指针，使用时加&
 pnode sort_tree_creat(pnode root,int a[],int n);      //二叉树创建是在插入的基础上实现的             ！！！创建也为二级指针，使用时加&
 pnode sort_tree_search(pnode root,int k);             //二叉树寻找的递归实现
 void sort_tree_print(pnode root);                     //二叉树的中序遍历是有序的
 pnode sort_tree_min(pnode root);                      //寻找二叉树中数值最小的节点
 pnode sort_tree_max(pnode root);                      //寻找二叉树中数值最大的节点
 pnode sort_tree_pre(pnode root);                      //寻找当前节点的前驱节点，以左孩子为基准
 pnode sort_tree_aft(pnode root);                      //寻找当前节点的后继节点，以右孩子为基准
 pnode sort_tree_del(pnode root,int k);                //删除指定值对应的节点                       ！！！删除也为二级指针，使用时加&
 int sort_tree_leaf(pnode root);                       //计算二叉树的叶子节点数目
 
 
 int main()
 {
 pnode root=NULL;                                  //必须指定初始值为NULL，不然会出现野指针！！！！！！！！！！！！！！！！！！！！！！！！！
 int choice;
 int a[100],i,num;
 while(1)
 {
 printf("1:创建  2:插入  3:搜索  4:遍历  5:最小节点  6:最大节点  7:删除节点  8:计算叶子节点数目  9:退出\n");
 scanf("%d",&choice);
 switch(choice)
 {
 
 case 1:
 {
 i=0;
 printf("请输入一组数据(0截止):\n");
 scanf("%d",&a[i]);
 while(a[i]!=0&&i<100)
 {
 i++;
 scanf("%d",&a[i]);
 }
 i=0;
 while(a[i]!=0)
 {
 root=sort_tree_insert(root,a[i]);
 i++;
 }
 sort_tree_print(root);
 printf("\n");
 }
 break;
 
 case 2:
 {
 printf("请输入插入的数值:\n");
 scanf("%d",&num);
 root=sort_tree_insert(root,num);
 sort_tree_print(root);
 printf("\n");
 }
 break;
 
 case 3:
 {
 printf("请输入要搜索的数值:\n");
 scanf("%d",&num);
 if(sort_tree_search(root,num)==NULL)
 printf("not exist!\n");
 else
 printf("exist! %3d\n",(sort_tree_search(root,num))->data);
 }
 break;
 
 case 4:
 sort_tree_print(root);
 printf("\n");
 break;
 
 case 5:
 {
 if(sort_tree_min(root)==NULL)
 printf("not exist!\n");
 else
 printf("exist! %3d\n",(sort_tree_min(root))->data);
 }
 break;
 
 case 6:
 {
 if(sort_tree_max(root)==NULL)
 printf("not exist!\n");
 else
 printf("exist! %3d\n",(sort_tree_max(root))->data);
 }
 break;
 
 case 7:
 {
 printf("请输入要删除的节点值:\n");
 scanf("%d",&num);
 root=sort_tree_del(root,num);
 sort_tree_print(root);
 printf("\n");
 }
 break;
 
 case 8:
 {
 printf("叶子节点数目为:%3d\n",sort_tree_leaf(root));
 }
 break;
 
 case 9:
 exit(0);
 break;
 
 default:
 printf("error!\n");
 break;
 }
 }
 return 0;
 }
 
 
 
 
 
 pnode sort_tree_insert(pnode root,int k)
 {
 pnode p;
 p=(pnode)malloc(sizeof(node));
 p->data=k;
 p->lchild=p->rchild=p->parent=NULL;
 if(root==NULL)
 {
 root=p;
 }
 else if(root->lchild==NULL&&k<root->data)
 {
 p->parent=root;
 root->lchild=p;
 }
 else if(root->rchild==NULL&&k>root->data)
 {
 p->parent=root;
 root->rchild=p;
 }
 if(root->data>k)
 sort_tree_insert(root->lchild,k);
 else if(root->data<k)
 sort_tree_insert(root->rchild,k);
 return root;
 }
 
 pnode sort_tree_creat(pnode root,int a[],int n)
 {
 int i=0;
 while(i<n)
 {
 sort_tree_insert(root,a[i]);
 i++;
 }
 return root;
 }
 
 pnode sort_tree_search(pnode root,int k)
 {
 if(root==NULL)
 return NULL;
 else if(root->data>k)
 return sort_tree_search(root->lchild,k);
 else if(root->data<k)
 return sort_tree_search(root->rchild,k);
 else
 return root;
 }
 
 
 void sort_tree_print(pnode root)
 {
 if(root==NULL)
 return;
 else
 {
 sort_tree_print(root->lchild);
 printf("%3d",root->data);
 sort_tree_print(root->rchild);
 }
 }
 
 
 pnode sort_tree_min(pnode root)
 {
 if(root==NULL)
 return NULL;
 else if(root->lchild==NULL)
 return root;
 else
 return sort_tree_min(root->lchild);
 }
 
 
 pnode sort_tree_max(pnode root)
 {
 if(root==NULL)
 return NULL;
 else if(root->rchild==NULL)
 return root;
 else
 return sort_tree_max(root->rchild);
 }
 
 pnode sort_tree_pre(pnode root)
 {
 if(root==NULL)
 return NULL;
 if(root->lchild)
 return sort_tree_max(root->lchild);
 else
 {
 if(root->parent==NULL)
 return NULL;
 while(root)
 {
 if(root->parent->rchild==root)
 break;
 root=root->parent;
 }
 return root->parent;
 }
 }
 
 
 pnode sort_tree_aft(pnode root)
 {
 if(root==NULL)
 return NULL;
 if(root->rchild)
 return sort_tree_min(root->rchild);
 else
 {
 if(root->parent==NULL)
 return NULL;
 while(root)
 {
 if(root->parent->lchild==root)
 break;
 root=root->parent;
 }
 return root->parent;
 }
 }
 
 pnode sort_tree_del(pnode root,int k)
 {
 pnode p,q;
 int t;
 p=sort_tree_search(root,k);
 if(p==NULL||root==NULL)
 {
 printf("error!\n");
 return root ;
 }
 
 if(p->lchild==NULL&&p->rchild==NULL)
 {
 if(p->parent==NULL)
 root=NULL;
 else if(p->parent->lchild==p)
 p->parent->lchild=NULL;
 else if(p->parent->rchild==p)
 p->parent->rchild=NULL;
 free(p);
 }
 
 
 else if(p->lchild&&!p->rchild)
 {
 p->lchild->parent=p->parent;
 if(p->parent==NULL)
 root=p->lchild;
 else if(p->parent->lchild==p)
 p->parent->lchild=p->lchild;
 else if(p->parent->rchild==p)
 p->parent->rchild=p->lchild;
 free(p);
 }
 
 
 else if(p->rchild&&!p->lchild)
 {
 p->rchild->parent=p->parent;
 if(p->parent==NULL)
 root=p->rchild;
 else if(p->parent->lchild==p)
 p->parent->lchild=p->rchild;
 else if(p->parent->rchild==p)
 p->parent->rchild=p->rchild;
 free(p);
 }
 
 else
 {
 q=sort_tree_aft(p);
 t=q->data;
 sort_tree_del(root,q->data);
 p->data=t;
 }
 return root;
 }
 
 int sort_tree_leaf(pnode root)
 {
 int leaf;
 if(root==NULL)
 leaf=0;
 else if(root->rchild==NULL&&root->lchild==NULL)
 leaf=1;
 else
 leaf=sort_tree_leaf(root->rchild)+sort_tree_leaf(root->lchild);
 return leaf;
 }
 */
