#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;
ifstream inf("data.in");
ofstream outf("out.out");

vector<int> a(101);
int n,i;


int main()
{
	inf>>n;
	for (i=1;i<=n;i++)
        inf>>a[i];
    sort(a.begin()+1,a.begin()+n+1);//ϰ�ߴ�1��ʼ�棬begin��0�����Դ�begin+1��ʼ���ڶ������������Ԫ���Ժ�������begin+n+1 
    outf<<*(a.begin()+1)<<endl;
    for (i=1;i<=n;i++)
        outf<<a[i]<<" ";
    outf<<endl;
}
