//
//  open_hash.h
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/21.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//

#ifndef open_hash_h
#define open_hash_h

# include <stdio.h>
# include <stdlib.h>
# define open_hash_len 40          //哈希表长度
# define open_hash_key 25          //key值（除数留余法）
static int open_hash_flag=0;            //删除是否成功执行标志位

typedef struct open_hash_nod
{
    int data;
    int null;
}open_hash_arr[open_hash_len];


void hash_ini(open_hash_arr p);               //哈希表初始化
void hash_push(open_hash_arr p,int k);        //哈希表数据插入
void hash_print(open_hash_arr p);             //打印哈希表
void hash_search(open_hash_arr p,int k);      //哈希表数据查询
void hash_del(open_hash_arr p,int k);         //哈希表数据删除
void open_hash_initial_document(void);
#endif /* open_hash_h */
