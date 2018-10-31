//
//  list_map.h
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/18.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//

#ifndef list_map_h
#define list_map_h

#include <stdio.h>
# include<stdlib.h>
#include<limits.h>
# define list_map_len 30


//边信息结构
typedef struct list_map_no
{
    int num_under;
    int weight;
    struct list_map_no *next;
}list_map_edge,*list_map_pedge;


//点信息结构
typedef struct list_map_nod
{
    int name;
    list_map_pedge firsttage;
}list_map_arr[list_map_len];


//链图信息结构
typedef struct list_map_node
{
    int num_spot;
    int num_edge;
    list_map_arr array;
}list_map_map,*list_map_pmap;


void list_map_creat(list_map_pmap g);//链式图生成
void list_map_dffs(list_map_pmap g,int v);
void list_map_dfs(list_map_pmap g);//深度优先遍历
void list_map_bfs(list_map_pmap g);//广度优先遍历
int list_map_locate(list_map_pmap g,int v);//节点定位
void list_map_tuopo(list_map_pmap g);//拓扑排序
int list_map_get_weight(list_map_pmap g,int start,int end);//节点间权重计算
void list_map_flod(list_map_pmap g,int list_map_dist[list_map_len][list_map_len],int list_map_path[list_map_len][list_map_len]);//多源最短距离计算
void list_map_dijkstra(list_map_pmap g,int v,int list_map_pre[],int list_map_dis[]);//单源最短距离计算
void list_map_primm(list_map_pmap g,int start);//prim最小生成树
void list_map_initial_document(void);//源代码打印


#endif /* list_map_h */
