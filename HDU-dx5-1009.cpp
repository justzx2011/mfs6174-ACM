/*
ID: mfs6174
PROG: BIT
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;
//ofstream ouf("ti.out");
//freopen("ti.i","r",stdin);
const int maxlongint=2147483647;

#define MAXN 110000
int shu[MAXN],f[MAXN];
int n;
int pre[MAXN];
int vis[MAXN];

//f[x]总是表示x-lowbit+1 到 x的和
//注意up中的n表示数组最大范围，如果离散化就是数字数，在线算法不方便离散化就是数字最大范围，灵活处理
//注意从1开始，如果有0号数组，可以每个加1表示
inline int lowbit(int x)
{
  return x&(x^(x-1));
}

void upc(int x,int d,int n) //更新，x是位置，d是增加量，n是上界
{
  while (x<=n)
  {
    f[x]+=d;
    x+=lowbit(x);
  }
}

int downs(int x) //查找
{
  int s=0;
  while (x>0)
  {
    s+=f[x];
    x-=lowbit(x);
  }
  return s;
}

int pos=0,head[MAXN];
struct Edge  
{  
  int next,u,v;  
}node[MAXN*2]; //使用的结构 这里由于是树，所以边数跟点数一样了，否则要单独算边数
void add(int u,int v)  //这里没有边权，如果加上边权则结构里加一个东西
{  
  if(u==v) return;  
  node[pos].u=u;                 //如果指向自己的边则舍去  
  node[pos].v=v;  
  node[pos].next=head[u];  
  head[u]=pos++;  
}

void mfs(int fu,int u)
{
  int flag,v;
  memset(vis,0,sizeof(vis));
  pre[u]=0;
  while (u!=0){
    flag=0;
    if (!vis[u]) {
      shu[u]=downs(u-1);
      vis[u]=1;
    }
    for(int i=head[u];i!=-1;i=node[i].next)
    {
      v=node[i].v;
      if (v!=fu){
        upc(v,1,n);
        flag=1;
        pre[v]=u;
        fu=u;
        u=v;
        head[u]=node[i].next;
        break;
      }
    }
    if (flag) continue;
    if (head[u]==-1) shu[u]=downs(u-1)-shu[u];
    u=pre[u];
  }
}

inline int  get()
{
    char c;
    while (c=getchar(),c<'0'||c>'9');
    int ret=c-'0';
    while (c=getchar(),c>='0'&&c<='9') ret=ret*10+c-'0';
    return ret;
}

int i,j,t,m,p,k;
int main()
{
  freopen("ti.in","r",stdin);
  while (scanf("%d%d",&n,&p)!=EOF&&n)
  {
    pos=1;  
    memset(head,-1,sizeof(head)); //2个初始化
    for (i=1;i<n;i++)
    {
      j=get();k=get();
      add(j,k);
      add(k,j);
    }
    memset(f,0,sizeof(f));
    memset(shu,0,sizeof(shu));
    mfs(0,p);
    shu[p]=downs(p-1);
    for (i=1;i<n;i++)
      cout<<shu[i]<<' ';
    cout<<shu[n]<<endl;
  }
  return 0;
}
