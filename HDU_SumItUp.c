#include<stdio.h>
#define file
//#define nofile
void dfs(int step);
int map[12],t,n,output[12],book[12],sum,m=0;//m代表数组中元素的个数
int main()
{
    int i;
#ifdef nofile
    do{
        scanf("%d%d",&t,&n);
        if(t==0||n==0)
            break;
        for(i=0;i<n;++i)
            scanf("%d",&map[j][i]);
        ++j;
    }while(1);
#endif
#ifdef file
    FILE*fp;
    fp=fopen("D:\\HDU\\HDU_SumItUp.txt","r");
    fscanf(fp,"%d%d",&t,&n);
    if(t!=0&&n!=0)
        for(i=0;i<n;++i)
            fscanf(fp,"%d",&map[i]);
#endif
    dfs(0);
#ifdef file
    fclose(fp);
#endif
    return 0;
}
void dfs(int step)
{
    int i;
    if(sum==t)
    {
        printf("Sums of %d\n",t);
        for(i=0;i<m-1;++i)
            printf("%d+",output[i]);
        printf("%d",output[m-1]);
        printf("\n");
        return;
    }
    for(i=step;i<n;++i)
    {
        if(book[i]==0&&book[i-1]!=map[i])
        {
            book[i]=i;
            output[step]=map[i];
            ++m;
            sum+=output[step];
            dfs(step+1);
            sum-=output[step];
            output[step]=0;
            --m;
            book[i]=0; 
        }
    }
}