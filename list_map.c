//
//  list_map.c
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/18.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//

#include "list_map.h"

//全局变量申明
int *list_map_visit_dfs,*list_map_visit_bfs,*ins,*top;


int list_map_locate(list_map_pmap g,int v)
{
    int i;
    for(i=0;i<g->num_spot;i++)
    {
        if(v==g->array[i].name)
            return i;
    }
    return -1;
}


void list_map_creat(list_map_pmap g)//链图生成
{
    int i,k,j,l;
    printf("请输入节点数目和边数目:\n");
    scanf("%d %d",&g->num_spot,&g->num_edge);
    printf("请输入点信息:\n");
    for(i=0;i<g->num_spot;i++)
    {
        scanf("%d",&g->array[i].name);
        g->array[i].firsttage=NULL;
    }
    printf("请输入边信息:\n");
    list_map_pedge e,f;
    for(k=0;k<g->num_edge;k++)
    {
        scanf("%d %d %d",&i,&j,&l);
        i=list_map_locate(g,i);                            //相当于定位函数！！！！！！！！！！！！！！！！！！！！！！！！
        j=list_map_locate(g,j);
        e=(list_map_pedge)malloc(sizeof(list_map_edge));
        e->num_under=i;
        e->weight=l;
        e->next=g->array[j].firsttage;
        g->array[j].firsttage=e;
        f=(list_map_pedge)malloc(sizeof(list_map_edge));
        f->num_under=j;
        f->weight=l;
        f->next=g->array[i].firsttage;
        g->array[i].firsttage=f;
    }
}


void list_map_dffs(list_map_pmap g,int v)//深度优先遍历
{
    list_map_pedge p;
    list_map_visit_dfs[v]=1;
    printf("%4d",g->array[v].name);
    p=g->array[v].firsttage;
    while(p)
    {
        if(!list_map_visit_dfs[p->num_under])
            list_map_dffs(g,p->num_under);
        p=p->next;
    }
}
void list_map_dfs(list_map_pmap g)
{
    int i;
    list_map_visit_dfs=(int *)malloc(g->num_spot*sizeof(int));
    for(i=0;i<g->num_spot;i++)
        list_map_visit_dfs[i]=0;
    for(i=0;i<g->num_spot;i++)
    {
        if(!list_map_visit_dfs[i])
        {
            list_map_dffs(g,i);
        }
    }
    printf("\n");
}



void list_map_bfs(list_map_pmap g)//广度优先遍历
{
    int i,tem;
    list_map_pedge q;
    int que[list_map_len];
    int front=0,rear=0;
    list_map_visit_bfs=(int *)malloc(g->num_spot*sizeof(int));
    for(i=0;i<g->num_spot;i++)
        list_map_visit_bfs[i]=0;
    for(i=0;i<g->num_spot;i++)
    {
        if(!list_map_visit_bfs[i])
        {
            list_map_visit_bfs[i]=1;
            printf("%4d",g->array[i].name);
            que[rear++]=i;
            while(front!=rear)
            {
                tem=que[front++];
                q=g->array[tem].firsttage;
                while(q)
                {
                    if(!list_map_visit_bfs[q->num_under])
                    {
                        list_map_visit_bfs[q->num_under]=1;
                        printf("%4d",g->array[q->num_under].name);
                        que[rear++]=q->num_under;
                    }
                    q=q->next;
                }
            }
        }
    }
    printf("\n");
}


void list_map_tuopo(list_map_pmap g)//拓扑排序
{
    int i,j,k=0;
    int *ins,*top,*quene;
    list_map_pedge node;
    int front=0,rear=0;
    ins=(int*)malloc(g->num_spot*sizeof(int));
    top=(int*)malloc(g->num_spot*sizeof(int));
    quene=(int*)malloc(g->num_spot*sizeof(int));
    for(i=0;i<g->num_spot;i++)
    {
        ins[i]=0;
        top[i]=0;
        quene[i]=0;
    }
    
    for(i=0;i<g->num_spot;i++)
    {
        node=g->array[i].firsttage;
        while(node)
        {
            ins[(node->num_under)]++;
            node=node->next;
        }
    }
    for(i=0;i<g->num_spot;i++)
    {
        if(ins[i]==0)
            quene[rear++]=i;
    }
    while(rear!=front)
    {
        j=quene[front++];
        top[k++]=g->array[j].name;
        node=g->array[j].firsttage;
        while(node)
        {
            ins[node->num_under]--;
            if(ins[node->num_under]==0)
                quene[rear++]=node->num_under;
            node=node->next;
        }
    }
    if(k!=g->num_spot)
    {
        printf("there is a circle!\n");
        free(ins);
        free(top);
        free(quene);
    }
    else
    {
        for(i=0;i<g->num_spot;i++)
            printf("%3d",top[i]);
        free(ins);
        free(top);
        free(quene);
    }
    printf("\n");
}


int list_map_get_weight(list_map_pmap g,int start,int end)//节点间距离计算
{
    if(start==end)
        return 0;
    list_map_pedge node;
    node=g->array[start].firsttage;
    while(node)
    {
        if(node->num_under==end)
            return node->weight;
        node=node->next;
    }
    return INT_MAX;
}


void list_map_dijkstra(list_map_pmap g,int v,int pre[],int dis[])//单源最短路径
{
    int flag[list_map_len];
    int i,j,k=0,tem;
    int min;
    v=list_map_locate(g, v);
    for(i=0;i<g->num_spot;i++)
    {
        flag[i]=0;
        pre[i]=0;
        dis[i]=list_map_get_weight(g,v,i);
    }
    flag[v]=1;
    dis[v]=0;
    for(i=1;i<g->num_spot;i++)
    {
        min=INT_MAX;
        for(j=0;j<g->num_spot;j++)
        {
            if(flag[j]==0&&min>dis[j])
            {
                min=dis[j];
                k=j;
            }
        }
        flag[k]=1;
        for(j=0;j<g->num_spot;j++)
        {
            tem=list_map_get_weight(g,k,j);
            tem=(tem==INT_MAX?INT_MAX:(min+tem));
            if(flag[j]==0&&dis[j]>tem)
            {
                dis[j]=tem;
                pre[j]=k;
            }
        }
    }
    for(i=0;i<g->num_spot;i++)
    {
        if(dis[i]>=INT_MAX)
            printf("%d %d:%5s\n",g->array[v].name,g->array[i].name,"N");
        else
            printf("%d %d:%5d\n",g->array[v].name,g->array[i].name,dis[i]);
        
    }
    
}


void list_map_flod(list_map_pmap g,int dis[][list_map_len],int path[][list_map_len])//多源最短路径
{
    int i,j,k,tem;
    for(i=0;i<g->num_spot;i++)
    {
        for(j=0;j<g->num_spot;j++)
        {
            dis[i][j]=list_map_get_weight(g,i,j);
            path[i][j]=j;
        }
    }
    for(i=0;i<g->num_spot;i++)
    {
        for(k=0;k<g->num_spot;k++)
        {
            for(j=0;j<g->num_spot;j++)
            {
                tem=(dis[k][i]==INT_MAX||dis[i][j]==INT_MAX)?INT_MAX:(dis[k][i]+dis[i][j]);
                if(dis[k][j]>tem)
                {
                    dis[k][j]=tem;
                    path[k][j]=path[k][i];
                }
            }
        }
    }
    for(i=0;i<g->num_spot;i++)
    {
        for(j=0;j<g->num_spot;j++)
        {
            if(j%g->num_spot==0)
                printf("\n");
            if(dis[i][j]>=INT_MAX)
                printf("%3s","N");
            else
                printf("%3d",dis[i][j]);
        }
    }
    printf("\n");
}


void list_map_primm(list_map_pmap g,int start)//prim最小生成树
{
    int prim[list_map_len],weight[list_map_len];
    int i,j,k,min,m,n,sum,ins=0;
    start=list_map_locate(g,start);
    for(i=0;i<g->num_spot;i++)
        weight[i]=list_map_get_weight(g,start,i);
    weight[start]=0;
    prim[ins++]=g->array[start].name;
    for(i=0;i<g->num_spot;i++)
    {
        if(start==i)
            continue;
        k=0;
        min=INT_MAX;
        for(j=0;j<g->num_spot;j++)
        {
            if(weight[j]&&weight[j]<min)
            {
                min=weight[j];
                k=j;
            }
        }
        weight[k]=0;
        prim[ins++]=g->array[k].name;
        for(j=0;j<g->num_spot;j++)
        {
            if(weight[j]&&weight[j]>list_map_get_weight(g,k,j))
                weight[j]=list_map_get_weight(g,k,j);
        }
    }
    sum=0;
    for(i=1;i<g->num_spot;i++)
    {
        min=INT_MAX;
        m=list_map_locate(g,prim[i]);
        for(j=0;j<i;j++)
        {
            n=list_map_locate(g,prim[j]);
            if(min>list_map_get_weight(g,m,n))
                min=list_map_get_weight(g,m,n);
        }
        sum+=min;
    }
    printf("最小生成树路径:");
    for(i=0;i<g->num_spot;i++)
    {
        printf("%3d",prim[i]);
    }
    printf("\n最短距离:%3d\n",sum);
}


void list_map_initial_document()//源代码打印
{
    FILE*fp;
    char ch;
    fp=fopen(__FILE__,"r");
    while((ch=fgetc(fp))!=EOF)
        putchar(ch);
    fclose(fp);
}
