//
//  sort_map.h
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/18.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//

#ifndef sort_map_h
#define sort_map_h

#include <stdio.h>
# include <stdlib.h>
# include <limits.h>

# define sort_map_len 30
//顺序图的存储结构
typedef struct sort_map_nod
{
    int name[sort_map_len];
    int num_spot,num_edge;
    int arr[sort_map_len][sort_map_len];
}sort_map_map,*sort_map_pmap;


//图的前期准备
int sort_map_locate(sort_map_pmap g,int v);//节点定位函数
int sort_map_first_dfs(sort_map_pmap g,int v);//
int sort_map_last_dfs(sort_map_pmap g,int v,int w);//节点遍历辅助函数
int sort_map_first_bfs(sort_map_pmap g,int v);//节点遍历辅助函数
int sort_map_last_bfs(sort_map_pmap g,int v,int w);//
void sort_map_creat(sort_map_pmap g);//邻接矩阵创建
void sort_map_print(sort_map_pmap g);//邻接矩阵打印
void sort_map_primm(sort_map_pmap g,int start);//prim最小生成树
void sort_map_initial_document(void);//源代码打印
void sort_map_dffs(sort_map_pmap g);//深度优先遍历
void sort_map_dfs(sort_map_pmap g,int v);
void sort_map_bfs(sort_map_pmap g);//广度优先遍历
void sort_map_dijkstra(sort_map_pmap g, int v, int sort_map_pre[], int sort_map_dis[]);//单源最短路径算法
void sort_map_flod(sort_map_pmap g,int sort_map_dist[][sort_map_len],int sort_map_path[][sort_map_len]);//多源最短路径算法

#endif /* sort_map_h */
