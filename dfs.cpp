#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#include<algorithm>
#include<stack>
#include<cstring>
#include<vector>
#include<list>
#include<set>
#include<map>

using namespace std;

int scan()
{
    int res = 0 , ch;

    while( !( ( ch = getchar() ) >= '0' && ch <= '9' ) )
    {
        if( ch == EOF )  return 1 << 30 ;
    }

    res = ch - '0' ;
    while( ( ch = getchar() ) >= '0' && ch <= '9' )
        res = res * 10 + ( ch - '0' ) ;

    return res ;
}

char input[10][10],ans;

int check(int x,int y)
{
    if(x<=0||x>8||y<=0||y>8)
        return 0;

    return 1;
}

void dfs(int x,int y,int step)
{
    if(step>7)
    {
        ans=1;
        return;
    }
    for(int i=-1;i<=1;i++)
    for(int j=-1;j<=1;j++)
    {
        if(ans)
        break;

        int xx=x+i;
        int yy=y+j;

        if(check(xx,yy)&&input[xx-step][yy]!='S'&&input[xx-step-1][yy]!='S')
        dfs(xx,yy,step+1);
    }
}

int main()
{
    int i,j;

    printf("Please input:\n");

    for(i=1;i<=8;i++)
    for(j=1;j<=8;j++)
    cin>>input[i][j];

    dfs(8,1,0);

    if(ans)
        printf("WIN\n");
    else
        printf("LOSE\n");

    return 0;
}
