#include<stdio.h>
#include<stdlib.h>
/* 记录最大长度 */
int max_len = 0;

/* 记录最大长度时下标位置 */
int max_position = 0;
/* 自己跑没问题，过牛客不行，为啥这个不能全局变量 */
/* 可以直接利用strstr判断是否是子字符串 */
/*处理函数较短的字符串a，a的长度，较长的字符串b,长度len_b*/
void process(char *a, int len_a, char *b, int len_b)
{
    int i,j;
    int i_temp, j_temp;
    int count_tmp = 0;
    for(i = 0; i < len_a; i++)
    {
        for(j = 0; j < len_b; j++)
        {
            count_tmp = 0;
            i_temp = i;
            j_temp = j;
            while(a[i_temp] == b[j_temp])
            {
                i_temp++;
                j_temp++;
                count_tmp++;
                
                /* 越界判断 */
                if(i_temp >= len_a || j_temp >= len_b)
                {
                    /* count是个数，存在后才加一，所以此处不回退 */
                    break;
                }
            }
            
            if(count_tmp > max_len)
            {
                max_len = count_tmp;
                max_position = i_temp;
            }
        }
    }
    printf("the max_position is %d\n", max_position);
    printf("the max_len is %d\n", max_len);
    for(i = max_position - max_len; i < max_position; i++)
    {
        printf("%c", a[i]);
    }
    printf("\n");
}

int main()
{
    char a[1000],b[1000];
    while(scanf("%s", &a) != EOF)
    {
        scanf("%s", &b);
        int len_a = strlen(a);
        int len_b = strlen(b);
        if(len_a <= len_b)
        {
            process(a, len_a, b, len_b);
        }
        else
        {
            process(b, len_b, a, len_a);
        }
    }
    return 0;
}
