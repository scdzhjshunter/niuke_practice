#include<stdio.h>
#include<stdlib.h>

int Num[10000][10];    /* 定义一个二位数组，每个数组最大为10个元素0~9.假设有10000g中输出序列 */
int count=0;    /* 全局变量，用来计算当前有多少个输出序列*/
int N;          /* 一共有多少火车 */

int cmp(const void *a,const void *b)
{
    int i = 0;
    while(((int*)a)[i] == ((int*)b)[i] && i < N)
    {
        i++;
    }
    
    return ((int*)a)[i] - ((int*)b)[i];
}

void m_swap(int *a,int i,int j)
{
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}


void stack(int *a, int*num, int len)
{
    int stk[100];
    int top = -1;
    int i;
    int j = 0;
    
    /* 入栈 */
    for(i = 0; i < len; i++)
    {
        stk[++top] = num[i]; // 入栈
        
        /* 过略不合理的,如果有 while循环处理把内部参数push掉*/
        while(top >=0 && j < len && a[j] == stk[top])
        {
            top--;
            j++;
        }
    }
    
    /* 全部进栈后顺利出栈 */
    if(-1 == top)
    {
        for(i = 0; i < len; i++)
        {
            Num[count][i] = a[i];
        }
        count++;
    }
}


void fun(int i,int *a,int len,int *num)
{
    int j;
    
    if(i >= len)
    {
        stack(a, num, len);
        return;
    }
    j = i;
    for(j; j < len; j++)
    {
        /* 当i= j时，就是原队列输出 */
        m_swap(a, i, j);
        
        /* 递归 */
        fun(i+1, a, len, num);

        m_swap(a, i, j);
    }

}

int main()
{
    while(scanf("%d", &N) != EOF)
    {
        int train_list[N]; //火车输入队列
        int train_stk[N];  //用作火车栈调整
        int i, j;
        for(i = 0; i < N; i++)
        {
            scanf("%d", &train_list[i]);
            
            /* 将输入的值放入栈中，赋值 */
            train_stk[i] = train_list[i];
        }
        
        /* 全排列 */
        fun(0, train_stk, N, train_list);
        qsort(Num, count, sizeof(int)*10, cmp);
        
        for(i = 0; i < count; i++)
        {
            for(j = 0; j < N; j++)
            {
                printf("%d ", Num[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
