#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;
ofstream ouf("out.out");
ifstream inf("data.in");

const int maxn=500;

struct jiedian
{
  int n,dao[maxn];
};

int zuo[maxn],i,j,duiz[maxn],duiy[maxn],nn,rr=0,t;
jiedian dian[maxn];
bool yong[maxn];

bool xiong(int x)
{
  int i,tt;
  //����ĵ㶼�����
  for (i=1;i<=dian[x].n;i++)//�������������ҵ�
  {
    tt=dian[x].dao[i];
    if ((!yong[tt])&&(duiy[tt]!=x))//δ�ظ�������û�кʹ˵�ƥ�䣨��֤����1��
    {
      yong[tt]=true;
      if ((!duiy[tt])||xiong(dui[tt]))//�����δƥ��㣬����Ϊ�յ㣬����˳����ƥ������������죨��֤����2��������ҵ���
      {
        duiz[x]=tt;
        duiy[tt]=x;//�������ң�����ԭƥ��ı��Զ�ɾ��
        return true;
      }
    }
  }
  return false;//ľ���ҵ������
}

int main()
{
  for (i=1;i<=nn;i++)
  {
    t=zuo[i];
    if (!duiz[t])
    {
      memset(yong,0,sizeof(yong));
      if (xiong(t)//�ҵ������
          rr++;//ƥ����+1
	}
  }
			
			
			
