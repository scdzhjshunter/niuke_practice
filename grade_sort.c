#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student{
    char Name[64];
    int  Grade;
}st;

int main()
{
    int n = 0;
    int flag = 0;
    int i, j = 0;
    st grade[100];
    st temp;
    while(scanf("%d", &n) != EOF)
    {
        scanf("%d", &flag);
        for(i = 0; i < n; i++)
        {
            scanf("%s %d", grade[i].Name, &grade[i].Grade);
            //scanf("%d", &grade[i].Grade);
        }
        if(!flag)
        {
            for(i = 0; i < n; i++)
            {
                for(j = 0; j < n - 1 -i; j++)
                {
                    if(grade[j].Grade < grade[j + 1].Grade)
                    {
                        temp = grade[j];
                        grade[j] = grade[j + 1];
                        grade[j + 1] = temp;
                    }
                }
            }
        }
        else
        {
            for(i = 0; i < n; i++)
            {
                for(j = 0; j < n - 1 -i; j++)
                {
                    if(grade[j].Grade > grade[j + 1].Grade)
                    {
                        temp = grade[j];
                        grade[j] = grade[j + 1];
                        grade[j + 1] = temp;
                    }
                }
            }
        }
        for(i = 0; i < n; i++)
        {
            printf("%s %d\n", grade[i].Name, grade[i].Grade);
        }
    }
    
    return 0;
}
