#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a[1000];
    int count = 0;
    int n1, n2, i, j;
    int rep = 0;
    while(scanf("%d", &n1) != EOF)
    {
        /* 输入后就直接处理重复部分 count作为计数自加加*/
        for(i = 0; i < n1; i++)
        {
            scanf("%d", &a[count]);
            for(j = 0; j < count; j++)
            {
                if(a[j] == a[count])
                {
                    rep = 1;
                    break;
                }
            }
            
            if(1 == rep)
            {
                rep = 0;
            }
            else{
                count++;
            }
        }
        
        scanf("%d", &n2);
        for(i = 0; i < n2; i++)
        {
            scanf("%d", &a[count]);
            for(j = 0; j < count; j++)
            {
                if(a[j] == a[count])
                {
                    rep = 1;
                    break;
                }
            }
            
            if(1 == rep)
            {
                rep = 0;
            }
            else{
                count++;
            }
        }
        int temp = 0;

        /* 冒泡排序法粗暴排序 */
        for(i = 0; i < count; i++)
        {
            for(j = 0; j < count -i-1; j++)
            {
                if(a[j] > a[j+1])
                {
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        }
        
        for(i = 0; i < count; i++)
        {
            printf("%d", a[i]);
        }
        printf("\n");
        count = 0;
    }
    return 0;
}
