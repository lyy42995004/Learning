#include "cachelab.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

typedef struct cache_line 
{
    int valid_bit; // 有效位
    unsigned tag;  // 标记位
    int stamp;     // 时间戳用于LRU
}cache_line;

// S(2^s)块大小, s组索引.
// E缓存块(2^b)行数, b块偏移.
int S, s, B, b, E;
// 命中，未命中，替换
int hit, miss, eviction;
char *filepath;
cache_line **cache;

void init()
{
    // malloc cache[S][E]
    cache = (cache_line**)malloc(sizeof(cache_line*) * S);
    for (int i = 0; i < S; i++)
        cache[i] = (cache_line*)malloc(sizeof(cache_line) * E);
    for (int i = 0; i < S; i++)
    {
        for (int j = 0; j < E; j++)
        {
            cache[i][j].valid_bit = 0;
            cache[i][j].tag = cache[i][j].stamp = -1; 
        }
    }
}

void destroy()
{
    for (int i = 0; i < S; i++)
        free(cache[i]);
    free(cache);
}

void update(unsigned addr)
{
    int s_addr = (addr >> b) & ((-1U) >> (32 - s));
    int t_addr = (addr >> (s + b));
    // 缓存命中
    for (int i = 0; i < E; i++)
    {
        if (cache[s_addr][i].tag == t_addr)
        {
            cache[s_addr][i].stamp = 0;
            hit++;
            return;
        }
    }
    // 缓存未命中，还有空块
    for (int i = 0; i < E; i++)
    {
        if (cache[s_addr][i].valid_bit == 0)
        {
            miss++;
            cache[s_addr][i].valid_bit = 1;
            cache[s_addr][i].tag = t_addr;
            cache[s_addr][i].stamp = 0;
            return;
        }
    }
    // 没有空组，产生替换
    miss++;
    eviction++; 
    int max_stamp = 0, max_i = 0;
    for (int i = 0; i < E; i++)
    {
        if (cache[s_addr][i].stamp > max_stamp)
        {
            max_stamp = cache[s_addr][i].stamp;
            max_i = i;
        }
    }
    cache[s_addr][max_i].tag = t_addr; 
    cache[s_addr][max_i].stamp = 0;
    return;
}

void time()
{
    for (int i = 0; i < S; i++)
    {
        for (int j = 0; j < E; j++)
        {
            if (cache[i][j].valid_bit == 1) // 被使用了
                cache[i][j].stamp++;
        }
    }
}

int main(int argc, char* argv[])
{
    int opt;
    while (-1 != (opt = getopt(argc, argv, "s:E:b:t:")))
    {
        switch (opt)
        {
        case 's':
            s = atoi(optarg); // optarg是getopt函数设置的指向当前选项参数的指针
            S = 1 << s;
            break;
        case 'E':
            E = atoi(optarg);
            break;
        case 'b':
            b = atoi(optarg);
            B = 1 << b;
            break;
        case 't':
            filepath = optarg;
            break;
        }
    }
    init();
    FILE* pf = fopen(filepath, "r");
    if (pf == NULL)
    {
        printf("fopen fail\n");
        exit(-1);
    }
    char op;
    unsigned addr;
    int size;
    while (fscanf(pf, "%c %x,%d", &op, &addr, &size) > 0)
    {
        switch (op)
        {
        case 'L':
            update(addr);
            break;
        case 'M':   // 执行两次
            update(addr);
        case 'S':
            update(addr);
            break;
        }
        time();
    }
    destroy();
    fclose(pf);
    printSummary(hit, miss, eviction);
    return 0;
}