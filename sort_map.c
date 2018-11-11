//
//  sort_map.c
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/18.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//

#include "sort_map.h"



int *sort_map_visit_dfs,*sort_map_visit_bfs;



int sort_map_locate(sort_map_pmap g,int v)                        //辅助定位函数
{
    int i;
    for(i=0;i<g->num_spot;i++)
    {
        if(v==g->name[i])
            return i;
    }
    return -1;
}


int sort_map_first_bfs(sort_map_pmap g,int v)                                    //遍历通用函数
{
    int i;
    for(i=0;i<g->num_spot;i++)
    {
        if(!sort_map_visit_bfs[i]&&g->arr[v][i]>0&&g->arr[v][i]<INT_MAX)
            return i;
    }
    return -1;
}


int sort_map_last_bfs(sort_map_pmap g,int v,int w)                                //遍历通用函数
{
    int i;
    for(i=w;i<g->num_spot;i++)
    {
        if(!sort_map_visit_bfs[i]&&g->arr[v][i]>0&&g->arr[v][i]<INT_MAX)
            return i;
    }
    return -1;
}



int sort_map_first_dfs(sort_map_pmap g,int v)                                    //遍历通用函数
{
    int i;
    for(i=0;i<g->num_spot;i++)
    {
        if(!sort_map_visit_dfs[i]&&g->arr[v][i]>0&&g->arr[v][i]<INT_MAX)
            return i;
    }
    return -1;
}


//顺序进行函数
int sort_map_last_dfs(sort_map_pmap g,int v,int w)                                //遍历通用函数
{
    int i;
    for(i=w;i<g->num_spot;i++)
    {
        if(!sort_map_visit_dfs[i]&&g->arr[v][i]>0&&g->arr[v][i]<INT_MAX)
            return i;
    }
    return -1;
}

//顺序图生成函数
void sort_map_creat(sort_map_pmap g)                                //创建顺序图
{
    int i,j,k,weight;
    int v1,v2;
    printf("请输入顺序图的点数与边数:\n");
    scanf("%d %d",&g->num_spot,&g->num_edge);
    printf("请输入各个点的名称(单个数字):\n");
    for(i=0;i<g->num_spot;i++)
    {
        scanf("%d",&g->name[i]);
    }
    for(i=0;i<g->num_spot;i++)
    {
        for(j=0;j<g->num_spot;j++)
        {
            if(i==j)
                g->arr[i][j]=0;
            else
                g->arr[i][j]=INT_MAX;
        }
    }
    printf("请输入每条边的两端节点及相应权重:\n");
    for(k=0;k<g->num_edge;k++)
    {
        scanf("%d %d %d",&v1,&v2,&weight);
        i=sort_map_locate(g,v1);
        j=sort_map_locate(g,v2);
        g->arr[i][j]=weight;
        g->arr[j][i]=weight;
        getchar();
    }
}


void sort_map_print(sort_map_pmap g)                               //顺序图格式打印
{
    int i,j;
    printf("\n");
    for(i=0;i<g->num_spot;i++)
    {
        for(j=0;j<g->num_spot;j++)
        {
            if(g->arr[i][j]==INT_MAX)
                printf("%5s","N");
            else
                printf("%5d",g->arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}



void sort_map_dfs(sort_map_pmap g,int v)                          //深度优先遍历，分为两部分
{
    int w;
    sort_map_visit_dfs[v]=1;
    printf("%3d",g->name[v]);
    for(w=sort_map_first_dfs(g,v);w>=0;w=sort_map_last_dfs(g,v,w))
    {
        if(!sort_map_visit_dfs[w])
            sort_map_dfs(g,w);
    }
}
void sort_map_dffs(sort_map_pmap g)
{
    int i;
    sort_map_visit_dfs=(int *)malloc(g->num_spot*sizeof(int));
    for(i=0;i<g->num_spot;i++)
        sort_map_visit_dfs[i]=0;
    printf("DFS:");
    for(i=0;i<g->num_spot;i++)
    {
        if(!sort_map_visit_dfs[i])
            sort_map_dfs(g,i);
    }
}



void sort_map_bfs(sort_map_pmap g)//广度优先遍历
{
    int i,w;
    int tem;
    int quene[sort_map_len]={0};
    int f,r;
    f=0;
    r=0;
    sort_map_visit_bfs=(int *)malloc(g->num_spot*sizeof(int));
    for(i=0;i<g->num_spot;i++)
        sort_map_visit_bfs[i]=0;
    printf("BFS:");
    for(i=0;i<g->num_spot;i++)
    {
        if(!sort_map_visit_bfs[i])
        {
            sort_map_visit_bfs[i]=1;
            printf("%3d",g->name[i]);
            quene[r++]=i;
            while(f!=r)
            {
                tem=quene[f++];
                for(w=sort_map_first_bfs(g,tem);w>=0;w=sort_map_last_bfs(g,tem,w))
                {
                    if(!sort_map_visit_bfs[w])
                    {
                        sort_map_visit_bfs[w]=1;
                        printf("%3d",g->name[w]);
                        quene[r++]=w;
                    }
                }
            }
        }
    }
}



void sort_map_dijkstra(sort_map_pmap g,int v,int sort_map_pre[],int sort_map_dis[])//dijkstra算法，计算单个节点到图中各节点的距离，单源算法
{
    int flag[sort_map_len];
    int i,j,tem,min,k=0;
    v=sort_map_locate(g,v);
    for(i=0;i<g->num_spot;i++)
    {
        flag[i]=0;
        sort_map_pre[i]=0;
        sort_map_dis[i]=g->arr[v][i];
    }
    flag[v]=1;
    sort_map_dis[v]=0;
    for(i=1;i<g->num_spot;i++)
    {
        min=INT_MAX;
        for(j=0;j<g->num_spot;j++)
        {
            if(flag[j]==0&&min>sort_map_dis[j])
            {
                min=sort_map_dis[j];
                k=j;
            }
        }
        flag[k]=1;
        for(j=0;j<g->num_spot;j++)
        {
            tem=(g->arr[k][j]==INT_MAX?INT_MAX:(min+g->arr[k][j]));
            if(flag[j]==0&&sort_map_dis[j]>tem)
            {
                sort_map_dis[j]=tem;
                sort_map_pre[j]=k;
            }
        }
    }
    printf("起始节点:%3d\n",v);
    for(i=0;i<g->num_spot;i++)
    {
        if(sort_map_dis[i]>=INT_MAX)
            printf("(%2d %2d):%3s\n",g->name[v],g->name[i],"N");
        else
            printf("(%2d %2d):%3d\n",g->name[v],g->name[i],sort_map_dis[i]);
    }
}


void sort_map_flod(sort_map_pmap g,int sort_map_dist[sort_map_len][sort_map_len],int sort_map_path[sort_map_len][sort_map_len])//多源最短路径计算
{
    int i,j,k,tem;
    for(i=0;i<g->num_spot;i++)
    {
        for(j=0;j<g->num_spot;j++)
        {
            sort_map_dist[i][j]=g->arr[i][j];
            sort_map_path[i][j]=j;
        }
    }
    for(k=0;k<g->num_spot;k++)
    {
        for(i=0;i<g->num_spot;i++)
        {
            for(j=0;j<g->num_spot;j++)
            {
                tem=(sort_map_dist[i][k]==INT_MAX||sort_map_dist[k][j]==INT_MAX)?INT_MAX:(sort_map_dist[i][k]+sort_map_dist[k][j]);
                if(sort_map_dist[i][j]>tem)
                {
                    sort_map_dist[i][j]=tem;
                    sort_map_path[i][j]=sort_map_path[i][k];
                }
            }
        }
    }
    printf("distance:");
    for(i=0;i<g->num_spot;i++)
    {
        for(j=0;j<g->num_spot;j++)
        {
            if(j%sort_map_len==0)
                printf("\n");
            if(sort_map_dist[i][j]>=INT_MAX)
                printf("%3s","N");
            else
                printf("%3d",sort_map_dist[i][j]);
        }
    }
    printf("\n");
    printf("path:");
    for(i=0;i<g->num_spot;i++)
    {
        for(j=0;j<g->num_spot;j++)
        {
            if(j%sort_map_len==0)
                printf("\n");
            printf("%3d",sort_map_path[i][j]);
        }
    }
    printf("\n");
}


void sort_map_primm(sort_map_pmap g,int start)//prim最小生成树
{
    int prim[sort_map_len],weight[sort_map_len];
    int i,j,k,min,m,n,sum,ins=0;
    start=sort_map_locate(g,start);
    for(i=0;i<g->num_spot;i++)
        weight[i]=g->arr[start][i];
    weight[start]=0;
    prim[ins++]=g->name[start];
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
        prim[ins++]=g->name[k];
        for(j=0;j<g->num_spot;j++)
        {
            if(weight[j]&&weight[j]>g->arr[k][j])
                weight[j]=g->arr[k][j];
        }
    }
    sum=0;
    for(i=1;i<g->num_spot;i++)
    {
        min=INT_MAX;
        m=sort_map_locate(g,prim[i]);
        for(j=0;j<i;j++)
        {
            n=sort_map_locate(g,prim[j]);
            if(min>g->arr[m][n])
                min=g->arr[m][n];
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


void sort_map_initial_document()//源代码打印
{
    FILE*fp;
    char ch;
    fp=fopen(__FILE__,"r");
    while((ch=fgetc(fp))!=EOF)
        putchar(ch);
    fclose(fp);
}


