//
//  bmp_kmp_search.h
//  struct_combine
//
//  Created by 暴走的小钢镚儿 on 2018/3/18.
//  Copyright © 2018年 暴走的小钢镚儿. All rights reserved.
//

#ifndef bmp_kmp_search_h
#define bmp_kmp_search_h

# include <stdio.h>
# include<stdlib.h>
# include<string.h>
# define string_len 100


void bmp_search(char str1[],char str2[]);
void kmp_search(char str1[],char str2[]);
void get_line(char str[],int tem[]);
void bmp_kmp_initial_document(void);
#endif /* bmp_kmp_search_h */
