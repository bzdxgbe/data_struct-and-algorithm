//
//  rb_tree.c
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/7/10.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//

#include "rb_tree.h"


rb_tree_pnode rb_tree_ll(rb_tree_pnode root,rb_tree_pnode y)
{
    rb_tree_pnode x=y->lchild;
    y->lchild=x->rchild;
    if(x->rchild)
        x->rchild->parent=y;
    x->parent=y->parent;
    if(y->parent==NULL)
        root=x;
    else
    {
        if(y->parent->lchild==y)
            y->parent->lchild=x;
        else
            y->parent->rchild=x;
    }
    x->rchild=y;
    y->parent=x;
    return root;
}


rb_tree_pnode rb_tree_rr(rb_tree_pnode root,rb_tree_pnode y)
{
    rb_tree_pnode x=y->rchild;
    y->rchild=x->lchild;
    if(x->lchild)
        x->lchild->parent=y;
    x->parent=y->parent;
    if(y->parent==NULL)
        root=x;
    else
    {
        if(y->parent->lchild==y)
            y->parent->lchild=x;
        else
            y->parent->rchild=x;
    }
    x->lchild=y;
    y->parent=x;
    return root;
}

rb_tree_pnode rb_tree_insert1(rb_tree_pnode root,int k)
{
    rb_tree_pnode p=(rb_tree_pnode)malloc(sizeof(rb_tree_node));
    p->weight=k;
    p->color=r;
    p->parent=p->lchild=p->rchild=NULL;
    if(rb_tree_search(root,k))
        return root;
    root=rb_tree_insert2(root,p);
    return root;
}

rb_tree_pnode rb_tree_insert2(rb_tree_pnode root,rb_tree_pnode p)
{
    rb_tree_pnode y=NULL;
    rb_tree_pnode x=root;
    while(x)
    {
        y=x;
        if(x->weight>p->weight)
            x=x->lchild;
        else
            x=x->rchild;
    }
    p->parent=y;
    if(y)
    {
        if(y->weight>p->weight)
            y->lchild=p;
        else
            y->rchild=p;
    }
    else
        root=p;
    root=rb_tree_insert3(root,p);
    return root;
}

rb_tree_pnode rb_tree_insert3(rb_tree_pnode root,rb_tree_pnode p)
{
    rb_tree_pnode parent,gparent;
    while((parent=p->parent)&&parent->color==r)
    {
        gparent=parent->parent;
        if(parent==gparent->lchild)
        {
            rb_tree_pnode uncle=gparent->rchild;
            if(uncle&&uncle->color==r)
            {
                uncle->color=b;
                parent->color=b;
                gparent->color=r;
                p=gparent;
                continue;
            }
            if(parent->rchild==p)
            {
                rb_tree_pnode temp;
                root=rb_tree_rr(root,parent);
                temp=parent;
                parent=p;
                p=temp;
            }
            parent->color=b;
            gparent->color=r;
            root=rb_tree_ll(root,gparent);
        }
        else
        {
            rb_tree_pnode uncle=gparent->lchild;
            if(uncle&&uncle->color==r)
            {
                uncle->color=b;
                parent->color=b;
                gparent->color=r;
                p=gparent;
                continue;
            }
            if(parent->lchild==p)
            {
                rb_tree_pnode temp;
                root=rb_tree_ll(root,parent);
                temp=parent;
                parent=p;
                p=temp;
            }
            parent->color=b;
            gparent->color=r;
            root=rb_tree_rr(root,gparent);
        }
    }
    root->color=b;
    return root;
}


void rb_tree_print(rb_tree_pnode root,int key,int dec)
{
    if(root)
    {
        if(dec==0)
            printf("%3d%3c is root\n",root->weight,root->color==1?'R':'B');
        else
            printf("%3d%3c is %3d %5s child\n",root->weight,root->color==1?'R':'B',key,dec==1?"left":"rght");
        rb_tree_print(root->rchild,root->weight,2);
        rb_tree_print(root->lchild,root->weight,1);
    }
}

rb_tree_pnode rb_tree_search(rb_tree_pnode root,int key)
{
    if(root==NULL||root->weight==key)
        return root;
    else if(root->weight>key)
        return rb_tree_search(root->lchild,key);
    else
        return rb_tree_search(root->rchild,key);
}

rb_tree_pnode rb_tree_del1(rb_tree_pnode root,int key)
{
    rb_tree_pnode p=rb_tree_search(root,key);
    if(p==NULL)
    {
        printf("do't exist!\n");
        return root;
    }
    root=rb_tree_del2(root,p);
    return root;
}

rb_tree_pnode rb_tree_del2(rb_tree_pnode root,rb_tree_pnode p)
{
    rb_tree_pnode parent,child,replace;
    int color;
    if(p->lchild&&p->rchild)
    {
        replace=p->rchild;
        while(replace->lchild)
            replace=replace->lchild;
        if(p->parent)
        {
            if(p->parent->lchild==p)
                p->parent->lchild=replace;
            else
                p->parent->rchild=replace;
        }
        else
            root=replace;
        parent=replace->parent;
        color=replace->color;
        child=replace->rchild;
        if(parent==p)
            parent=replace;
        else
        {
            if(child)
                child->parent=parent;
            parent->lchild=child;
            replace->rchild=p->rchild;
            p->rchild->parent=parent;
        }
        replace->parent=p->parent;
        replace->color=p->color;
        replace->lchild=p->lchild;
        p->lchild->parent=replace;
        if(color==b)
            root=rb_tree_del3(root,child,parent);
        return root;
    }
    if(p->lchild)
        child=p->lchild;
    else
        child=p->rchild;
    parent=p->parent;
    color=p->color;
    if(child)
        child->parent=parent;
    if(parent)
    {
        if(parent->lchild==p)
            parent->lchild=child;
        else
            parent->rchild=child;
    }
    else
        root=child;
    if(color==b)
        root=rb_tree_del3(root,child,parent);
    return root;
}

rb_tree_pnode rb_tree_del3(rb_tree_pnode root,rb_tree_pnode p,rb_tree_pnode parent)
{
    rb_tree_pnode other;
    while((p==NULL||p->color==b)&&p!=root)
    {
        if(p==parent->lchild)
        {
            other=parent->rchild;
            if(other&&other->color==r)
            {
                other->color=b;
                parent->color=r;
                root=rb_tree_rr(root,parent);
                other=parent->rchild;
            }
            if((other->lchild==NULL||other->lchild->color==b)&&(other->rchild==NULL||other->rchild->color==b))
            {
                other->color=r;
                p=parent;
                parent=p->parent;
            }
            else
            {
                if(other->rchild==NULL||other->rchild->color==b)
                {
                    other->lchild->color=b;
                    other->color=r;
                    root=rb_tree_ll(root,other);
                    other=parent->rchild;
                }
                other->color=parent->color;
                parent->color=b;
                other->rchild->color=b;
                root=rb_tree_rr(root,parent);
                p=root;
                break;
            }
        }
        else
        {
            other=parent->lchild;
            if(other&&other->color==r)
            {
                other->color=b;
                parent->color=r;
                root=rb_tree_ll(root,parent);
                other=parent->lchild;
            }
            if((other->lchild==NULL||other->lchild->color==b)&&(other->rchild==NULL||other->rchild->color==b))
            {
                other->color=r;
                p=parent;
                parent=p->parent;
            }
            else
            {
                if(other->lchild==NULL||other->lchild->color==b)
                {
                    other->rchild->color=b;
                    other->color=r;
                    root=rb_tree_rr(root,other);
                    other=parent->lchild;
                }
                other->color=parent->color;
                parent->color=b;
                other->lchild->color=b;
                root=rb_tree_ll(root,parent);
                p=root;
                break;
            }
        }
    }
    if(p)
        p->color=b;
    return root;
}

void rb_tree_file(void)
{
    FILE*fp;
    fp=fopen(__FILE__,"r");
    char ch;
    while((ch=getc(fp))!=EOF)
        putchar(ch);
}
