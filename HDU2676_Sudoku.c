#include<stdio.h>
int n,num[9][9],book[9];
#define file
//#define nofile
void dfs(int step);
void check(int x,int y);
int main()
{
    int i,j;
#ifdef nofile
    scanf("%d",&n);
    for(i=0;i<9;++i)
        for(j=0;j<9;++j)
            scanf("%d",num[i][j]);
#endif
#ifdef file
    FILE*fp;
    fp=fopen("D:\\HDU\\HDU2676_Sudoku.txt","r");
    fscanf(fp,"%d",&n);
    for(i=0;i<9;++i)
        for(j=0;j<9;++j)
            fscanf(fp,"%d",num[i][j]);
#endif
#ifdef file
    fclose(fp);
#endif
    return 0;
}
void dfs(int step)
{
    int i,j;
    for(i=0;i<9;++i)
        for(j=0;j<9;++j)
            if(num[i][j]==0)
                break;
    if(i==9&&j==9)
    {
        
    }

}
void check(int x,int y)
{
    int i,j;
    for(i=0;i<9;++i)
        if(num[x][i]!=0)
            book[num[x][i]]=1;
    for(i=0;i<9;++i)
        if(num[i][y]!=0);
            book[num[i][y]]=1;
    for(i=x/3*3;i<x/3*3+2;++i)
        for(j=y/3*3;j<y/3*3+2;++j)
            if(num[i][j]!=0)
                book[num[i][j]]=1;
    return;
}