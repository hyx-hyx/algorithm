#include<stdio.h>
#include<math.h>
int n,t=0,num[26],sum=0,flag=0;//t代表字符串的个数
char ch[26],output[5];
int book[26];
#define file
//#define nofile
void dfs(int step);
int main()
{
    int i;
#ifdef nofile
    scanf("%d",&n);
    getchar();
   do{
        scanf("%c",&ch[t]);
        ++t;
    }while(ch[t-1]!='\n');
    for(i=t-2;i>=0;--i)
        num[t-2-i]=ch[i]-'A'+1;
#endif
#ifdef file
    FILE*fp;
    fp=fopen("D:\\vscode\\HDU\\HDU1015_Safacraker.txt","r");
    fscanf(fp,"%d",&n);
    fgetc(fp);
    do{
        fscanf(fp,"%c",&ch[t]);
        ++t;
    }while(ch[t-1]!='\n');
    for(i=t-2;i>=0;--i)
        num[t-2-i]=ch[i]-'A'+1;
#endif
    dfs(0);
    if(!flag) printf("no solution");
#ifdef file
    fclose(fp);
#endif
    return 0; 
}
void dfs(int step)
{
    int i;
    if(flag) return;
    if(step==5)
    {
        if(output[0]-output[1]*output[1]+pow(output[2],3)-pow(output[3],4)+pow(output[4],5)==n)
        {
            for(i=0;i<5;++i)
                printf("%c ",ch[output[i]-1]);
            printf("\n");
            flag=1;
            return;
        }
        return;
    }
    for(i=0;i<t-1;++i)
    {
        if(book[i]!=1)
        {
            output[step]=num[i];
            book[i]=1;
            dfs(step+1);
            book[i]=0;
        }
    }
}