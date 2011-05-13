#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;
ifstream inf("ti.in");
ofstream ouf("ti.out");
const int maxlongint=2147483647;

int n,m,i,j,k,t,mm,tt;
int tu[100][100],zhen[100][100],zhong[100][100],he[100][100];

void floyd(int n)
{
  int i,j,k;
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    {
      if (i==j)
        zhen[i][j]=0;
      zhen[i][j]=maxlongint;
      if (tu[i][j])
        zhen[i][j]=tu[i][j];
      zhong[i][j]=i;
    }
  for (k=1;k<=n;k++)
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
      {
        if ((zhen[i][k]==maxlongint)||(zhen[k][j]==maxlongint))
          continue;
        if (zhen[i][k]+zhen[k][j]<zhen[i][j])
        {
          zhen[i][j]=zhen[i][k]+zhen[k][j];
          zhong[i][j]=k;
        }
      }
}

int tongji(int n)
{
  int i,j,k,d;
  mm=maxlongint;
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    {
      if (i==j)
        continue;
      for (k=1;k<=n;k++)
      {
        if (zhen[i][k]<zhen[j][k])
          d=i;
        else
          d=j;
        he[i][j]+=zhen[d][k];
      }
        if (he[i][j]<mm)
        {
          mm=he[i][j];
          t=i;
          tt=j;
        }
    }
  return mm;
}

int main()
{
  while (inf>>i>>j>>k)
  {
    tu[i][j]=tu[j][i]=k;
  }
  n=50;
  floyd(n);
  tongji(n);
  ouf<<t<<' '<<tt<<' '<<mm<<endl;
//   for (i=1;i<=n;i++)
//     ouf<<i<<' '<<he[i]<<endl;
  return 0;
}

