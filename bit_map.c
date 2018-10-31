//
//  bit_map.c
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/18.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//

#include "bit_map.h"

int a[1+bit_map_max/32];

void clr(int i)
{
    a[i>>sheft] &=~(1<<(i&mask));
}

void set(int i)
{
    a[i>>sheft] |=(1<<(i&mask));
}

int  test(int i)
{
    return a[i>>sheft]&(1<<(i&mask));
}

void bit_map_initial_document()
{
    FILE*fp;
    char ch;
    fp=fopen(__FILE__,"r");
    while((ch=fgetc(fp))!=EOF)
        putchar(ch);
    fclose(fp);
}
