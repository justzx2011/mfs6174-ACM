#include <iostream>
//#include <fstream>
#include <cstring>
#include <cstdio>


using namespace std;
//ofstream ouf("out.out");
//ifstream inf("data.in");


struct jiedian{
		int n,dao[505];
		};
		
int zuo[505],i,j,dui[1010],nn,rr=0,zushu,k,n,m,t,chu[1010];
jiedian dian[505];
bool yong[1010];

bool xiong(int x)
{
	int i,tt;
	//����ĵ㶼�����
	for (i=1;i<=dian[x].n;i++)//�������������ҵ�
	{
		tt=dian[x].dao[i];
		if ((!yong[tt])&&(dui[tt]!=x))//δ�ظ�������û�кʹ˵�ƥ�䣨��֤����1��
		{
			yong[tt]=true;
			if ((!dui[tt])||xiong(dui[tt]))//�����δƥ��㣬����Ϊ�յ㣬����˳����ƥ������������죨��֤����2��������ҵ���
			{
				dui[tt]=x;//�������ң�����ԭƥ��ı��Զ�ɾ��
				chu[x]=tt;
				return true;
			}
		}
	}
	return false;//ľ���ҵ������
}

int main()
{
	cin>>zushu;
	for (k=1;k<=zushu;k++)
	{
		memset(dian,0,sizeof(dian));
		memset(dui,0,sizeof(dui));
		memset(chu,0,sizeof(chu));
		rr=0;
		scanf("%d%d",&nn,&n);
		for (i=1;i<=nn;i++)
		{
			scanf("%d",&m);
			for (j=1;j<=m;j++)
			{
				scanf("%d",&t);
				dian[i].n++;
				dian[i].dao[dian[i].n]=t;
			}
		}
		/*if (n<nn)
		{
			cout<<"NO"<<endl;
			continue;
		}*/
		for (i=1;i<=nn;i++)
		{
			if (!chu[i])
			{
				memset(yong,0,sizeof(yong));
				if (xiong(i))//�ҵ������
					rr++;//ƥ����+1
			}
		}
		if (rr==nn)
			cout<<"YES"<<endl;
		else 
			cout<<"NO"<<endl;
	}
}
						
