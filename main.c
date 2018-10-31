//  main.c
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/17.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.



# include "sort_tree.h"
# include "avl_tree.h"
# include "sort_map.h"
# include "list_map.h"
# include "huf_tree.h"
# include "eight_methods_of_sort.h"
# include "bmp_kmp_search.h"
# include "bit_map.h"
# include "bs_dui.h"
# include "sort_stack.h"
# include "sort_quene.h"
# include "sort_circle_quene.h"
# include "list_quene.h"
# include "list_stack.h"
# include "signal_list.h"
# include "double_list.h"
# include "list_hash.h"
# include "open_hash.h"
# include "circle_list.h"
# include "rb_tree.h"


int main()
{
    int flag=0;
    char chose;
    while(1)
    {
        printf("|a:单向链表|    |b:双向链表|    |c:循环链表|    |d:数组式栈|    |e:链表式栈|    |f:数组式队|    |g:链表式队|    |h:循环队列|\n\n");
        printf("|i:开放哈希|    |j:链式哈希|    |k:哈夫曼树|    |l:排序二叉|    |m:平衡二叉|    |n:邻接矩阵|    |o:邻接链表|    |p:八大排序|\n\n");
        printf("|q:字符匹配|    |r:位图储存|    |s:文件操作|    |t:最大小堆|    |u:红黑二叉|    |v:退出|\n");
        scanf("%c",&chose);
        getchar();
        switch(chose)
        {
            case 'a':
            {
                int i;
                single_list_pnode head;
                head=(single_list_pnode)malloc(sizeof(single_list_node));
                head->next=NULL;
                int pos,number;
                while(1)
                {
                    printf("|1:头部创建|   |2:尾部创建|   |3:位置插入|   |4:数值插入|   |5:位置删除|   |6:数值删除|   |7:数值搜索|   |8:查看源码|   |9:链表反转|   |10:插入排序|   |11:退出|\n");
                    scanf("%d",&i);
                    getchar();
                    switch(i)
                    {
                        case 1:
                        {
                            head=single_list_creat1(head);
                            single_list_print(head);
                        }break;
                        
                        case 2:
                        {
                            head= single_list_creat2(head);
                            single_list_print(head);
                           
                        }break;
                        
                        case 3:
                        {
                            printf("which pos and what data:\n");
                            scanf("%d %d",&pos,&number);
                            head=single_list_insert1(head,pos,number);
                            single_list_print(head);
                        }break;
                        
                        case 4:
                        {
                            printf("which number and what data:\n");
                            scanf("%d %d",&pos,&number);
                            head=single_list_insert2(head,pos,number);
                            single_list_print(head);
                        }break;
                        
                        case 5:
                        {
                            printf("which pos:\n");
                            scanf("%d",&pos);
                            head=single_list_del1(head,pos);
                            single_list_print(head);
                        }break;
                        
                        case 6:
                        {
                            printf("what data:\n");
                            scanf("%d",&number);
                            head=single_list_del2(head,number);
                            single_list_print(head);
                        }break;
                        
                        case 7:
                        {
                            printf("what data:\n");
                            scanf("%d",&number);
                            single_list_find(head,number);
                        }break;
                        
                        case 8:
                        {
                            signal_list_initial_document();
                        }break;
                            
                        case 9:
                        {
                            head=single_list_oppo(head);
                            single_list_print(head);
                        }break;
                        case 10:
                        {
                            head=single_list_sort(head);
                            single_list_print(head);
                        }break;
                        case 11:
                        {
                            flag=1;
                        }break;
                            
                    }
                    if(flag==1)
                    {
                        flag=0;
                        break;
                    }
                }
            }break;
                
            case 'b':
            {
                double_list_pquene head;
                head=(double_list_pquene)malloc(sizeof(double_list_quene));
                head->front=head->next=NULL;
                int i,pos,num;
                while(1)
                {
                    printf("|1:尾插创建|   |2:头插创建|   |3:按位置插入|   |4:按数值插入|   |5:按位置删除|   |6:按数值删除|   |7:查询|   |8:查看源码|   |9:退出|\n");
                    scanf("%d",&i);
                    getchar();
                    switch(i)
                    {
                        case 1:
                        {
                            head=double_list_creat1(head);
                            double_list_print(head);
                        }break;

                        case 2:
                        {
                            head=double_list_creat2(head);
                            double_list_print(head);
                        }break;
                        case 3:
                        {
                            printf("插入的位置及数值:\n");
                            scanf("%d %d",&pos,&num);
                            head=double_list_insert1(head,pos,num);
                            double_list_print(head);
                        }break;
                        case 4:
                        {
                            printf("插入数值位置及数值:\n");
                            scanf("%d %d",&pos,&num);
                            head=double_list_insert2(head,pos,num);
                            double_list_print(head);
                        }break;
                        case 5:
                        {
                            printf("删除哪个位置:\n");
                            scanf("%d",&pos);
                            head=double_list_del1(head,pos);
                            double_list_print(head);
                        }break;
                        case 6:
                        {
                            printf("删除哪个数值:\n");
                            scanf("%d",&pos);
                            head=double_list_del2(head,pos);
                            double_list_print(head);
                        }break;
                        case 7:
                        {
                            printf("查询的数值:\n");
                            scanf("%d",&pos);
                            double_list_search(head,pos);
                        }break;
                        
                        case 8:
                        {
                            double_list_initial_document();
                        }break;
                            
                        case 9:
                        {
                            flag=1;
                        }break;
                    }
                    if(flag==1)
                    {
                        flag=0;
                        break;
                    }
                }
            }break;
                
            case 'c':
            {
                circle_list_pnode head;
                head=(circle_list_pnode)malloc(sizeof(circle_list_node));
                head->next=NULL;
                int i,pos,num;
                while(1)
                {
                    printf("|1:尾插创建|  |2:头插创建|  |3:按位置插入|  |4:按数值插入|  |5:按位置删除|  |6:按数值删除|  |7:按数值搜索|  |8:打印链表|  |9:查看源码|  |10:退出|\n");
                    scanf("%d",&i);
                    getchar();
                    switch(i)
                    {
                        case 1:
                        {
                            head=circle_list_creat1(head);
                            circle_list_print(head);
                        }break;
                        case 2:
                        {
                            head=circle_list_creat2(head);
                            circle_list_print(head);
                        }break;
                        case 3:
                        {
                            printf("请输入插入的位置及数字:\n");
                            scanf("%d %d",&pos,&num);
                            circle_list_insert1(head,pos,num);
                            circle_list_print(head);
                        }break;
                        case 4:
                        {
                            printf("请输入插入的数值及数据:\n");
                            scanf("%d %d",&pos,&num);
                            circle_list_insert2(head,pos,num);
                            circle_list_print(head);
                        }break;
                        case 5:
                        {
                            printf("请输入删除的位置:\n");
                            scanf("%d",&pos);
                            circle_list_del1(head,pos);
                            circle_list_print(head);
                        }break;
                        case 6:
                        {
                            printf("请输入删除的数值\n");
                            scanf("%d",&pos);
                            circle_list_del2(head,pos);
                            circle_list_print(head);
                        }break;
                        case 7:
                        {
                            printf("请输入搜索的数值\n");
                            scanf("%d",&pos);
                            circle_list_search(head,pos);
                        }break;
                        case 8:
                        {
                            circle_list_print(head);
                        }break;
                        
                        case 9:
                        {
                            double_list_initial_document();
                        }break;
                            
                        case 10:
                        {
                            flag=1;
                        }break;
                    }
                    if(flag==1)
                    {
                        flag=0;
                        break;
                    }
                }
            }break;
                
            case 'd':
            {
                flag=0;
                int i,data;
                sort_stack_stack s;                               //顺序栈的申明在全局中申明
                sort_stack_ini(&s);
                while(1)
                {
                    printf("|1:入栈|   |2:出栈|   |3:打印|   |4:查看源码|   |5:退出|\n");
                    scanf("%d",&i);
                    getchar();
                    switch(i)
                    {
                        case 1:
                        {
                            printf("请输入一组入栈数据(0截止)：\n");
                            scanf("%d",&data);
                            while(data!=0)
                            {
                                sort_stack_push(&s,data);
                                scanf("%d",&data);
                            }
                            sort_stack_print(&s);
                        }break;
                            
                        case 2:
                        {
                            printf("%3d\n",sort_stack_pop(&s));
                            sort_stack_print(&s);
                        }break;
                            
                        case 3:
                        {
                            sort_stack_print(&s);
                        }break;
                            
                        case 4:
                        {
                            sort_stack_initial_document();
                        }break;
                            
                        case 5:
                        {
                            flag=1;
                        }break;
                            
                    }
                    if(flag==1)
                    {
                        flag=0;
                        break;
                    }
                }
                
            }break;
                
            case 'e':
            {
                flag=0;
                int i,data;
                list_stack_stack s;
                list_stack_ini(&s);
                while(1)
                {
                    printf("|1:入栈|   |2:出栈|   |3:打印|   |4:查看源码|   |5:退出|\n");
                    scanf("%d",&i);
                    getchar();
                    switch(i)
                    {
                        case 1:
                        {
                            printf("请输入入栈数据(0截止)：\n");
                            scanf("%d",&data);
                            while(data!=0)
                            {
                                list_stack_push(&s,data);
                                scanf("%d",&data);
                            }
                            list_stack_print(&s);
                        }break;
                        
                        case 2:
                        {
                            list_stack_pop(&s);
                            list_stack_print(&s);
                        }break;
                        
                        case 3:
                        {
                            list_stack_print(&s);
                        }break;
                            
                        case 4:
                        {
                            list_stack_initial_document();
                        }break;
                            
                        case 5:
                        {
                            flag=1;
                        }break;
                    }
                    if(flag==1)
                    {
                        flag=0;
                        break;
                    }
                }
            }break;
                
            case 'f':
            {
                flag=0;
                int i,data,tem;
                sort_quene_quene p;
                sort_quene_ini(&p);
                while(1)
                {
                    printf("|1:入队|   |2:出队|   |3:打印|   |4:查看源码|   |5:退出|\n");
                    scanf("%d",&i);
                    getchar();
                    switch(i)
                    {
                        case 1:
                        {
                            printf("请输入一组入队数据(0截止)：\n");
                            scanf("%d",&data);
                            while(data!=0)
                            {
                                sort_quene_push(&p,data);
                                scanf("%d",&data);
                            }
                            sort_quene_print(&p);
                        }break;
                            
                        case 2:
                        {
                            tem=sort_quene_pop(&p);
                            printf("%3d\n",tem);
                            sort_quene_print(&p);
                        }break;
                            
                        case 3:
                        {
                            sort_quene_print(&p);
                        }break;
                            
                        case 4:
                        {
                            sort_quene_initial_document();
                        }break;
                            
                        case 5:
                        {
                            flag=1;
                        }break;
                    }
                    if(flag==1)
                    {
                        flag=0;
                        break;
                    }
                }
            }break;
                
            case 'g':
            {
                flag=0;
                int i,data;
                list_quene_quene p;
                list_quene_ini(&p);
                while(1)
                {
                    printf("|1:入队|   |2:出队|   |3:打印|   |4:查看源码|   |5:退出|\n");
                    scanf("%d",&i);
                    getchar();
                    switch(i)
                    {
                        case 1:
                        {
                            printf("请输入一组入队数据(0截止)：\n");
                            scanf("%d",&data);
                            while(data!=0)
                            {
                                list_quene_push(&p,data);
                                scanf("%d",&data);
                            }
                            list_quene_print(&p);
                        }break;
                            
                        case 2:
                        {
                            list_quene_pop(&p);
                            list_quene_print(&p);
                        }break;
                            
                        case 3:
                        {
                            list_quene_print(&p);
                        }break;
                            
                        case 4:
                        {
                            list_quene_initial_document();
                        }break;
                            
                        case 5:
                        {
                            flag=1;
                        }break;
                    }
                    if(flag==1)
                    {
                        flag=0;
                        break;
                    }
                }
            }break;
                
            case 'h':
            {
                flag=0;
                int i,data;
                sort_circle_quene_quene p;
                circle_quene_ini(&p);
                while(1)
                {
                    printf("|1:入队|   |2:出队|   |3:打印|   |4:查看源码|   |5:退出|\n");
                    scanf("%d",&i);
                    getchar();
                    switch(i)
                    {
                        case 1:
                        {
                            printf("请输入入队数据(0截止)：\n");
                            scanf("%d",&data);
                            while(data!=0)
                            {
                                circle_quene_push(&p,data);
                                scanf("%d",&data);
                            }
                            circle_quene_print(&p);
                        }break;
                            
                        case 2:
                        {
                            circle_quene_pop(&p);
                            circle_quene_print(&p);
                        }break;
                            
                        case 3:
                        {
                            circle_quene_print(&p);
                        }break;
                        case 4:
                        {
                            sort_circle_quene_initial_document();
                        }break;
                        case 5:
                        {
                            flag=1;
                        }break;
                    }
                    if(flag==1)
                    {
                        flag=0;
                        break;
                    }
                }
            }break;
                
            case 'i':
            {
                open_hash_arr array;
                int i,num;
                hash_ini(array);
                while(1)
                {
                    printf("|1:插入数据|   |2:查询数据|   |3:删除数据|   |4:打印哈希表|   |5:初始化|   |6:查看源码|   |7:退出|\n");
                    scanf("%d",&i);
                    getchar();
                    switch(i)
                    {
                        case 1:
                        {
                            printf("输入一组插入的数据(0截止):\n");
                            scanf("%d",&num);
                            while(num!=0)
                            {
                                hash_push(array,num);
                                scanf("%d",&num);
                            }
                            hash_print(array);
                        }break;
                        
                        case 2:
                        {
                            printf("输入查询的数据:\n");
                            scanf("%d",&num);
                            hash_search(array,num);
                        }break;
                        
                        case 3:
                        {
                            printf("输入要删除的数据:\n");
                            scanf("%d",&num);
                            hash_del(array,num);
                            hash_print(array);
                        }break;
                        
                        case 4:
                        {
                            hash_print(array);
                        }break;
                        
                        case 5:
                        {
                            hash_ini(array);
                            printf("初始化成功!\n");
                        }break;
                            
                        case 6:
                        {
                            open_hash_initial_document();
                        }break;
                            
                        case 7:
                        {
                            flag=1;
                        }break;
                    }
                    if(flag==1)
                    {
                        flag=0;
                        break;
                    }
                }
            }break;
                
            case 'j':
            {
                list_hash_arr array;
                int choice;
                int k;
                list_hash_ini(array);
                while(1)
                {
                    printf("|1:初始化|  |2:头插法|  |3:尾插法|  |4:按数值搜索|   |5:按数值删除|  |6:打印|  |7:查看源码|  |8:退出|\n");
                    scanf("%d",&choice);
                    getchar();
                    switch(choice)
                    {
                        case 1:
                        {
                            list_hash_ini(array);
                            printf("初始化成功!\n");
                        }break;
                            
                        case 2:
                        {
                            printf("请输入一组数据(0截止):\n");
                            scanf("%d",&k);
                            while(k!=0)
                            {
                                list_hash_top_creat(array,k);
                                scanf("%d",&k);
                            }
                            printf("链式哈希如下:\n");
                            list_hash_print(array);
                        }break;
                            
                        case 3:
                        {
                            printf("请输入一组数据:\n");
                            scanf("%d",&k);
                            while(k!=0)
                            {
                                list_hash_bottom_creat(array,k);
                                scanf("%d",&k);
                            }
                            printf("链式哈希如下:\n");
                            list_hash_print(array);
                        }break;
                            
                        case 4:
                        {
                            printf("请输入搜索的数字:\n");
                            scanf("%d",&k);
                            list_hash_search(array,k);
                        }break;
                            
                        case 5:
                        {
                            printf("请输入删除的数字:\n");
                            scanf("%d",&k);
                            list_hash_del(array,k);
                            printf("链式哈希如下:\n");
                            list_hash_print(array);
                        }break;
                            
                        case 6:
                        {
                            list_hash_print(array);
                        }break;
                            
                        case 7:
                        {
                            list_hash_initial_document();
                        }break;
                            
                        case 8:
                        {
                            flag=1;
                        }break;
                    }
                    if(flag==1)
                    {
                        flag=0;
                        break;
                    }
                }
            }break;
                
            case 'k':
            {
                int i;
                char c[N+1];                                          //注意是从1——N开始的（0未用），因此要声明N+1个空间
                int w[N+1];
                huf hf;
                hufchar ch;
                int choice;
                while(1)
                {
                    printf("|1:输入字符集及权值集|   |2:哈夫曼编码|   |3:哈夫曼解码|   |4:打印哈夫曼编码|   |5:查看源码|   |6:退出|\n");
                    scanf("%d",&choice);
                    getchar();
                    switch(choice)
                    {
                        case 1:
                        {
                            printf("请输入相应字符及其出现次数(5组)：\n");
                            for(i=1;i<=N;i++)
                            {
                                scanf("%c %d",&c[i],&w[i]);
                                getchar();
                            }
                            huf_tree_creat(hf,w);
                            huf_tree_print_intocode(hf,c);
                        }break;
                            
                        case 2:
                        {
                            huf_tree_into_code(hf,ch);
                            huf_tree_print_outcode(ch,c);
                        }break;
                            
                        case 3:
                        {
                            char test[100];
                            printf("请输入01编码\n");
                            scanf("%s",&test);
                            char result[100];
                            int len=strlen(test);
                            huf_tree_code_out(hf,c,test,len,result);
                            printf("解码后的字符串:\n");
                            printf("%s\n",result);
                        }break;
                            
                        case 4:
                        {
                            huf_tree_print_outcode(ch,c);
                        }break;
                            
                        case 5:
                        {
                            huf_tree_initial_document();
                        }break;
                            
                        case 6:
                        {
                            flag=1;
                        }break;
                    }
                    if(flag==1)
                    {
                        flag=0;
                        break;
                    }
                }
            }break;
                
            case 'l':
            {
                sort_tree_pnode sort_tree_root=NULL;
                int choice;
                int a[100],i,num;
                while(1)
                {
                    printf("|1:创建|   |2:插入|   |3:搜索|   |4:遍历|   |5:最小节点|   |6:最大节点|   |7:删除节点|   |8:计算叶子节点数目|   |9:查看源码|   |10:退出|\n");
                    scanf("%d",&choice);
                    getchar();
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
                                sort_tree_insert(&sort_tree_root,a[i]);
                                i++;
                            }
                            sort_tree_print(sort_tree_root);
                            printf("\n");
                        }break;
                            
                        case 2:
                        {
                            printf("请输入插入的数值:\n");
                            scanf("%d",&num);
                            sort_tree_insert(&sort_tree_root,num);
                            sort_tree_print(sort_tree_root);
                            printf("\n");
                        }break;
                            
                        case 3:
                        {
                            printf("请输入要搜索的数值:\n");
                            scanf("%d",&num);
                            if(sort_tree_search(sort_tree_root,num)==NULL)
                                printf("not exist!\n");
                            else
                                printf("exist! %3d\n",(sort_tree_search(sort_tree_root,num))->data);
                        }break;
                            
                        case 4:
                        {
                            sort_tree_special_print(sort_tree_root,sort_tree_root->data,0);// sort_tree_print(root);
                            printf("\n");
                        }break;
                            
                        case 5:
                        {
                            if(sort_tree_min(sort_tree_root)==NULL)
                                printf("not exist!\n");
                            else
                                printf("exist! %3d\n",(sort_tree_min(sort_tree_root))->data);
                        }break;
                            
                        case 6:
                        {
                            if(sort_tree_max(sort_tree_root)==NULL)
                                printf("not exist!\n");
                            else
                                printf("exist! %3d\n",(sort_tree_max(sort_tree_root))->data);
                        }break;
                            
                        case 7:
                        {
                            printf("请输入要删除的节点值:\n");
                            scanf("%d",&num);
                            sort_tree_del(&sort_tree_root,num);
                            sort_tree_print(sort_tree_root);
                            printf("\n");
                        }break;
                            
                        case 8:
                        {
                            printf("叶子节点数目为:%3d\n",sort_tree_leaf(sort_tree_root));
                        }break;
                            
                        case 9:
                        {
                            sort_tree_initial_document();
                        }break;
                            
                        case 10:
                        {
                            flag=1;
                        }break;
                    }
                    if(flag==1)
                    {
                        flag=0;
                        break;
                    }
                }
            }break;
                
            case 'm':
            {
                avl_tree_pnode avl_tree_root;
                int choice;
                int data;
                avl_tree_root=NULL;
                while(1)
                {
                    printf("|1:创建AVL|   |2:插入数值|   |3:删除数值|   |4: 打印AVL|   |5:搜索|   |6:查看源码|   |7:退出|\n");
                    scanf("%d",&choice);
                    getchar();
                    switch(choice)
                    {
                        case 1:
                        {
                            printf("请输入一组数据:\n");
                            scanf("%d",&data);
                            while(data!=0)
                            {
                                avl_tree_root=avl_tree_insert(avl_tree_root,data);
                                scanf("%d",&data);
                            }
                            avl_tree_print(avl_tree_root);
                            printf("\n");
                        }break;
                            
                        case 2:
                        {
                            printf("请输入插入的数值:\n");
                            scanf("%d",&data);
                            avl_tree_root=avl_tree_insert(avl_tree_root,data);
                            avl_tree_print(avl_tree_root);
                            printf("\n");
                        }break;
                            
                        case 3:
                        {
                            printf("请输入删除的数值:\n");
                            scanf("%d",&data);
                            avl_tree_root=avl_tree_del(avl_tree_root,data);
                            avl_tree_print(avl_tree_root);
                            printf("\n");
                        }break;
                            
                        case 4:
                        {
                            avl_tree_print_AVL(avl_tree_root,avl_tree_root->weight,0);
                            printf("\n");
                        }break;
                            
                        case 5:
                        {
                            printf("请输入要搜索的数值:\n");
                            scanf("%d",&data);
                            if(avl_tree_search(avl_tree_root,data)!=NULL)
                                printf("exist\n");
                            else
                                printf("don't exist!\n");
                        }break;
                            
                        case 6:
                        {
                            avl_tree_initial_document();
                        }break;
                            
                        case 7:
                        {
                            flag=1;
                        }break;
                    }
                    if(flag==1)
                    {
                        flag=0;
                        break;
                    }
                }
            }break;
                
            case 'n':
            {
                sort_map_pmap g;
                g=(sort_map_pmap)malloc(sizeof(sort_map_map));
                int i;
                sort_map_creat(g);
                while(1)
                {
                    printf("|1:打印无向图矩阵|   |2:深度优先遍历|   |3:广度优先遍历|   |4:重建矩阵图|   |5:单源最短路径|   |6:多源最短路径|   |7:最小生成树|   |8:查看源码|   |9:退出|\n");
                    scanf("%d",&i);
                    getchar();
                    switch(i)
                    {
                        case 1:
                        {
                            sort_map_print(g);
                        }break;
                        
                        case 2:
                        {
                            sort_map_dffs(g);
                            printf("\n");
                        }break;
                        
                        case 3:
                        {
                            sort_map_bfs(g);
                            printf("\n");
                        }break;
                        
                        case 4:
                        {
                            sort_map_creat(g);
                        }break;
                        
                        case 5:
                        {
                            int sort_map_pre[sort_map_len];
                            int sort_map_dis[sort_map_len];
                            int v;
                            printf("请输入起始点:\n");
                            scanf("%d",&v);
                            sort_map_dijkstra(g, v, sort_map_pre, sort_map_dis);
                        }break;
                        
                        case 6:
                        {
                            int sort_map_dist[sort_map_len][sort_map_len],sort_map_path[sort_map_len][sort_map_len];
                            sort_map_flod(g,sort_map_dist,sort_map_path);
                        }break;

                        case 7:
                        {
                            int v;
                            printf("最小生成树起点:\n");
                            scanf("%d",&v);
                            sort_map_primm(g,v);
                        }break;
                            
                        case 8:
                        {
                            sort_map_initial_document();
                        }break;
                        
                        case 9:
                        {
                            flag=1;
                        }break;
                    }
                    if(flag==1)
                    {
                        flag=0;
                        break;
                    }
                }
            }break;
                
            case 'o':
            {
                list_map_pmap g;
                int vs,list_map_pre[list_map_len],list_map_dis[list_map_len];
                int list_map_dis1[list_map_len][list_map_len],list_map_path[list_map_len][list_map_len];
                g=(list_map_pmap)malloc(sizeof(list_map_map));
                list_map_creat(g);
                int choice;
                while(1)
                {
                    printf("|1:创建链式图|   |2:深度优先|   |3:广度优先|   |4:单源最短路径|   |5:多源最短路径|   |6:拓扑排序|   |7:最小生成树|   |8:查看源码|   |9:退出|\n");
                    scanf("%d",&choice);
                    getchar();
                    switch(choice)
                    {
                        case 1:
                        {
                            list_map_creat(g);
                            printf("创建成功！\n");
                        }break;
                        
                        case 2:
                        {
                            list_map_dfs(g);
                        }break;
                        
                        case 3:
                        {
                            list_map_bfs(g);
                        }break;
                        
                        case 4:
                        {
                            printf("请指定起始节点:\n");
                            scanf("%d",&vs);
                            list_map_dijkstra(g,vs,list_map_pre,list_map_dis);
                        }break;
                        
                        case 5:
                        {
                            list_map_flod(g,list_map_dis1,list_map_path);
                        }break;
                        
                        case 6:
                        {
                            list_map_tuopo(g);
                        }break;
                        case 7:
                        {
                            int v;
                            printf("最小生成树起点:\n");
                            scanf("%d",&v);
                            list_map_primm(g,v);
                        }break;
                        
                        case 8:
                        {
                            list_map_initial_document();
                        }break;
                            
                        case 9:
                        {
                            flag=1;
                        }break;
                    }
                    if(flag==1)
                    {
                        flag=0;
                        break;
                    }
                }
            }break;
                
            case 'p':
            {
                int data[data_len],i;
                clock_t start,end;                                                  //计时声明
                int style;
                for(i=0;i<data_len;i++)
                    data[i]=arc4random_uniform(data_max)+1;                   //真随机数生成
                printf("随机数组已生成!\n");
                for(i=0;i<data_len;i++)
                    printf("%5d",data[i]);
                while(1)
                {
                    printf("\n");
                    printf("|1:插入排序|   |2:选择排序|   |3:冒泡排序|   |4:快速排序|   |5:希尔排序|   |6:归并排序|   |7:堆排序|   |8:桶排序|   |9:查看源码|    |10:退出|\n");
                    scanf("%d",&style);
                    getchar();
                    switch(style)
                    {
                        case 1:
                        {
                            int data1[data_len];
                            for(i=0;i<data_len;i++)
                                data1[i]=data[i];
                            start=clock();                                           //计时标志
                            insert_sort(data1,data_len);
                            end=clock();
                            printf("排序后的数组:");
                            for(i=0;i<data_len;i++)
                                printf("%4d",data1[i]);
                            printf("\n");
                            printf("所用时间:");
                            printf("%5f\n",(double)(end-start));
                        }break;
                        
                        case 2:
                        {
                            int data2[data_len];
                            for(i=0;i<data_len;i++)
                                data2[i]=data[i];
                            start=clock();
                            chose_sort(data2,data_len);
                            end=clock();
                            printf("排序后的数组:");
                            for(i=0;i<data_len;i++)
                                printf("%4d",data2[i]);
                            printf("\n");
                            printf("所用时间:");
                            printf("%5f\n",(double)(end-start));
                        }break;
                        
                        case 3:
                        {
                            int data3[data_len];
                            for(i=0;i<data_len;i++)
                                data3[i]=data[i];
                            start=clock();
                            chose_sort(data3,data_len);
                            end=clock();
                            printf("排序后的数组:");
                            for(i=0;i<data_len;i++)
                                printf("%4d",data3[i]);
                            printf("\n");
                            printf("所用时间:");
                            printf("%5f\n",(double)(end-start));
                        }break;
                        
                        case 4:
                        {
                            int data4[data_len];
                            for(i=0;i<data_len;i++)
                                data4[i]=data[i];
                            start=clock();
                            chose_sort(data4,data_len);
                            end=clock();
                            printf("排序后的数组:");
                            for(i=0;i<data_len;i++)
                                printf("%4d",data4[i]);
                            printf("\n");
                            printf("所用时间:");
                            printf("%5f\n",(double)(end-start));
                        }break;
                        
                        case 5:
                        {
                            int data5[data_len];
                            for(i=0;i<data_len;i++)
                                data5[i]=data[i];
                            start=clock();
                            chose_sort(data5,data_len);
                            end=clock();
                            printf("排序后的数组:");
                            for(i=0;i<data_len;i++)
                                printf("%4d",data5[i]);
                            printf("\n");
                            printf("所用时间:");
                            printf("%5f\n",(double)(end-start));
                        }break;
                        
                        case 6:
                        {
                            int data6[data_len];
                            for(i=0;i<data_len;i++)
                                data6[i]=data[i];
                            start=clock();
                            chose_sort(data6,data_len);
                            end=clock();
                            printf("排序后的数组:");
                            for(i=0;i<data_len;i++)
                                printf("%4d",data6[i]);
                            printf("\n");
                            printf("所用时间:");
                            printf("%5f\n",(double)(end-start));
                        }break;
                        
                        case 7:
                        {
                            int data7[data_len];
                            for(i=0;i<data_len;i++)
                                data7[i]=data[i];
                            start=clock();
                            chose_sort(data7,data_len);
                            end=clock();
                            printf("排序后的数组:");
                            for(i=0;i<data_len;i++)
                                printf("%4d",data7[i]);
                            printf("\n");
                            printf("所用时间:\n");
                            printf("%5f\n",(double)(end-start));
                        }break;
                        
                        case 8:
                        {
                            int data8[data_len];
                            for(i=0;i<data_len;i++)
                                data8[i]=data[i];
                            start=clock();
                            buck_sort(data8,data_len,data_max);
                            end=clock();
                            printf("排序后的数组:");
                            for(i=0;i<data_len;i++)
                                printf("%4d",data8[i]);
                            printf("\n");
                            printf("所用时间:\n");
                            printf("%5f\n",(double)(end-start));
                        }break;
                        
                        case 9:
                        {
                            eight_methods_of_sort_initial_document();
                        }break;
                        case 10:
                        {
                            flag=1;
                        }break;
                    }
                    if(flag==1)
                    {
                        flag=0;
                        break;
                    }
                }
            }break;
                
            case 'q':
            {
                char str1[string_len],str2[string_len];
                while(1)
                {
                    printf("|1:BMP_search|   |2:KMP_search|   |3:document|   |4:exit|\n");
                    int i;
                    scanf("%d",&i);
                    getchar();
                    switch(i)
                    {
                        case 1:
                        {
                            printf("请输入第一组字符:\n");
                            gets(str1);
                            printf("请输入第二组字符:\n");
                            gets(str2);
                            bmp_search(str1,str2);
                        }break;
                        
                        case 2:
                        {
                            printf("请输入第一组字符:\n");
                            scanf("%s",str1);
                            printf("请输入第二组字符:\n");
                            scanf("%s",str2);
                            kmp_search(str1,str2);
                        }break;
                        
                        case 3:
                        {
                            bmp_kmp_initial_document();
                        }break;
                            
                        case 4:
                        {
                            flag=1;
                        }break;
                    }
                    if(flag==1)
                    {
                        flag=0;
                        break;
                    }
                }
            }break;
                
            case 'r':
            {
                int i;
                int choice;
                while(1)
                {
                    printf("|1:清空位|   |2:设置位|   |3:查询位|   |4:查看源码|   |5:退出|\n");
                    scanf("%d",&choice);
                    getchar();
                    switch(choice)
                    {
                        case 1:
                        {
                            for(i=0;i<bit_map_max;i++)
                                clr(i);
                            printf("初始化位成功！\n");
                        }break;
                            
                        case 2:
                        {
                            int data;
                            printf("请输入要储存的数据(0截止):\n");
                            scanf("%d",&data);
                            while(data)
                            {
                                set(data);
                                scanf("%d",&data);
                            }
                        }break;
                            
                        case 3:
                        {
                            int data;
                            for(i=0;i<bit_map_max;i++)
                                if(test(i))
                                    printf("%3d",i);
                            printf("\n请输入查询的数值:\n");
                            scanf("%d",&data);
                            if(test(data))
                                printf("exist!\n");
                            else
                                printf("do't exist!\n");

                        }break;
                            
                        case 4:
                        {
                            bit_map_initial_document();
                        }break;
                            
                        case 5:
                        {
                            flag=1;
                        }break;
                    }
                    if(flag==1)
                    {
                        flag=0;
                        break;
                    }
                }
            }break;
                
            case 's':
            {
                flag=0;
            }break;
                
            case 't':
            {
                int choice,i,a[dui_len],bb[dui_len];
                while(1)
                {
                    printf("|1:创建最大堆|   |2:创建最小堆|   |3:堆排序|   |4:打印堆|   |5:查看源码|   |6:退出|!\n");
                    scanf("%d",&choice);
                    getchar();
                    switch(choice)
                    {
                        case 1:
                        {
                            printf("请输入一组%d个数据:\n",dui_len);
                            for(i=0;i<dui_len;i++)
                                scanf("%d",&a[i]);
                            dui_max_creat(a,dui_len);
                            dui_print(a,dui_len);
                        }break;
                        
                        case 2:
                        {
                            printf("请输入一组%d个数据:\n",dui_len);
                            for(i=0;i<dui_len;i++)
                                scanf("%d",&a[i]);
                            dui_min_creat(a,dui_len);
                            dui_print(a,dui_len);
                        }break;
                        
                        case 3:
                        {
                            printf("排序后的结果:\n");
                            dui_bs_sort(a,bb,dui_len);
                            dui_print(bb,dui_len);
                        }break;
                        
                        case 4:
                        {
                            dui_print(a,dui_len);
                        }break;
                        
                        case 5:
                        {
                            bs_dui_initial_document();
                        }break;
                            
                        case 6:
                        {
                            flag=1;
                        }break;
                    }
                    if(flag==1)
                    {
                        flag=0;
                        break;
                    }
                }
            }break;

            case 'u':
            {
                rb_tree_pnode root=NULL;
                int choice;
                int num;
                while(1)
                {
                    printf("1:插入节点  2:删除节点  3:搜索节点  4:打印红黑树  5:源代码打印  6:退出\n");
                    scanf("%d",&choice);
                    getchar();
                    switch(choice)
                    {
                        case 1:
                        {
                            int self_file;
                            printf("1:文件输入 or 2:手动输入？\n");
                            scanf("%d",&self_file);
                            if(self_file==1)
                            {
                                FILE*fout;
                                char buf[10];
                                int i=0,j;
                                int data;
                                int arr[100];
                                int k=0;
                                char ch;
                                fout=fopen("fin.txt","r");
                                while(1)
                                {
                                    ch=fgetc(fout);
                                    if(ch==EOF)
                                        break;
                                    else if(ch==' '||ch=='\n')
                                        i=0;
                                    else
                                    {
                                        while(ch!=' '&&ch!='\n')
                                        {
                                            buf[i++]=ch;
                                            ch=fgetc(fout);
                                        }
                                        data=0;
                                        for(j=0;j<i;j++)
                                        {
                                            switch(buf[j])
                                            {
                                                case '1':
                                                    data+=1*pow(10.0,i-j-1);
                                                    break;
                                                case '2':
                                                    data+=2*pow(10.0,i-j-1);
                                                    break;
                                                case '3':
                                                    data+=3*pow(10.0,i-j-1);
                                                    break;
                                                case '4':
                                                    data+=4*pow(10.0,i-j-1);
                                                    break;
                                                case '5':
                                                    data+=5*pow(10.0,i-j-1);
                                                    break;
                                                case '6':
                                                    data+=6*pow(10.0,i-j-1);
                                                    break;
                                                case '7':
                                                    data+=7*pow(10.0,i-j-1);
                                                    break;
                                                case '8':
                                                    data+=8*pow(10.0,i-j-1);
                                                    break;
                                                case '9':
                                                    data+=9*pow(10.0,i-j-1);
                                                    break;
                                                default:break;
                                            }
                                        }
                                        i=0;
                                        arr[k++]=data;
                                    }
                                }
                                fclose(fout);
                                for(i=0;i<k;i++)
                                {
                                    root=rb_tree_insert1(root,arr[i]);
                                }
                            }
                            else
                            {
                                printf("请输入一组数据(0截止):\n");
                                scanf("%d",&num);
                                while(num!=0)
                                {
                                    root=rb_tree_insert1(root,num);
                                    scanf("%d",&num);
                                }
                            }
                             rb_tree_print(root,root->weight,0);
                            }break;

                        case 2:
                        {
                            printf("请输入删除的数据:\n");
                            scanf("%d",&num);
                            if(!rb_tree_search(root,num))
                                printf("无法删除数据!\n");
                            else
                            {
                                root=rb_tree_del1(root,num);
                                rb_tree_print(root,root->weight,0);
                            }
                        }break;

                        case 3:
                        {
                            printf("请输入搜索的数据:\n");
                            scanf("%d",&num);
                            if(!rb_tree_search(root,num))
                                printf("数据不存在!\n");
                            else
                                printf("数据存在!\n");
                        }break;

                        case 4:
                            rb_tree_print(root,root->weight,0);
                            break;

                        case 5:
                            rb_tree_file();
                            break;
                        default:
                        {
                            flag=1;
                        }break;
                    }
                    if(flag==1)
                    {
                        flag=0;
                        break;
                    }
                }
            }break;

            case 'v':
            {
                exit(0);
            }break;
            default :break;
        }
    }
    return 0;
}



