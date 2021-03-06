/*
ID: mfs6174
PROG: HDU1754 sagements tree
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
#include<cstdio>

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;
struct D
{
  int l,r,d,xx,yy;
};

D shu[600000];
int i,j,k,t,n,m,tt,mm,c,cc;
char st[3];


void jia(int x,int w,int d)
{
  int m=(shu[x].xx+shu[x].yy)/2;
  shu[x].d=max(shu[x].d,d);
  if (shu[x].xx==shu[x].yy)
    return;
  if (w<=m)
  {
    if (!shu[x].l)
    {
      c++;
      shu[c].xx=shu[x].xx;
      shu[c].yy=m;
      shu[x].l=c;
    }
    jia(shu[x].l,w,d);
  }
  else
  {
    if (!shu[x].r)
    {
      c++;
      shu[c].xx=m+1;
      shu[c].yy=shu[x].yy;
      shu[x].r=c;
    }
    jia(shu[x].r,w,d);
  }
}


int  cha(int tt,int x,int y)
{
  //if (cc>20)
  // return;
  int md=(shu[tt].xx+shu[tt].yy)>>1;
  if ((x<=shu[tt].xx)&&(y>=shu[tt].yy))
  {
    return shu[tt].d;
  }
  if (y<=md)
  {
    return  cha(shu[tt].l,x,y);
  }
  if (x>md)
  {
    return cha(shu[tt].r,x,y);
  }
  return max(cha(shu[tt].l,x,y),cha(shu[tt].r,x,y));
}

  
int main()
{
  // freopen("ti.in","r",stdin);
  while (scanf("%d%d",&n,&m)!=EOF)
  {
    memset(shu,0,sizeof(shu));
    c=0;
    shu[0].xx=1;
    shu[0].yy=n;
    for (i=1;i<=n;i++)
    {
      scanf("%d",&t);
      jia(0,i,t);
    }
    for (i=1;i<=m;i++)
    {
      scanf("%s%d%d",st,&t,&tt);
      if (st[0]=='U')
      {
        jia(0,t,tt);
      }
      else
      {
        if (t>tt)
        {
          mm=t;
          t=tt;
          tt=m;
        }
        mm=0;
        mm=cha(0,t,tt);
        printf("%d\n",mm);
      }
    }
  }
}

