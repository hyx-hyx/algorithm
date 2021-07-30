#include<stdio.h>
int n,num[9][9],book[10];
char map[9][9];
#define file
//#define nofile
void dfs(int x,int y);
void check(int x,int y);
void uncheck(int x,int y);
int main()
{
    int i,j;
#ifdef nofile
    scanf("%d",&n);
	getchar();
    for(i=0;i<9;++i)
	{
        for(j=0;j<9;++j)
        {
            scanf("%c",&map[i][j]);
            num[i][j]=(int)map[i][j]-48;
        }
		getchar();
	}
#endif
#ifdef file
    FILE*fp;
    fp=fopen("D:\\vscode\\HDU\\HDU2676_Sudoku.txt","r");
    fscanf(fp,"%d",&n);
    fgetc(fp);
    for(i=0;i<9;++i)
    {
        for(j=0;j<9;++j)
        {
            fscanf(fp,"%c",&map[i][j]);
            num[i][j]=(int)map[i][j]-48;
        }
        fgetc(fp);
    }
#endif
    dfs(0,0);
#ifdef file
    fclose(fp);
#endif
    return 0;
}
void dfs(int x,int y)
{
    int i,j,k;
    if(x==9&&y==0)
    {
        for(i=0;i<9;++i)
            for(j=0;j<9;++j)
                printf("%d ",num[i][j]);
            printf("\n");
        return;
    }
    if(num[x][y]==0)
    {
        for(k=1;k<10;++k)
        {
            check(x,y);
            if(book[k]==0)
                num[x][y]=k;
            if(y+1==9)
                dfs(x+1,0);
            else
                dfs(x,y+1);
            uncheck(x,y);
        }
    }
	else
		if(y+1==9)
			dfs(x+1,0);
        else
			dfs(x,y+1);
}
void  check(int x,int y)
{
    int i,j;
    for(i=0;i<9;++i)
        if(num[x][i]!=0)
            book[num[x][i]]=1;
    for(i=0;i<9;++i)
        if(num[i][y]!=0)
            book[num[i][y]]=1;
    for(i=x/3*3;i<x/3*3+2;++i)
        for(j=y/3*3;j<y/3*3+2;++j)
            if(num[i][j]!=0)
                book[num[i][j]]=1;
    return;
}
void  uncheck(int x,int y)
{
    int i,j;
    for(i=0;i<9;++i)
        if(num[x][i]!=0)
            book[num[x][i]]=0;
    for(i=0;i<9;++i)
        if(num[i][y]!=0);
            book[num[i][y]]=0;
    for(i=x/3*3;i<x/3*3+2;++i)
        for(j=y/3*3;j<y/3*3+2;++j)
            if(num[i][j]!=0)
                book[num[i][j]]=0;
    return;
}

