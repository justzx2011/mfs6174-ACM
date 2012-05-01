//�����������,�ڽ�����ʽ
//�����������,flow����ÿ���ߵ�����
//��������ڵ���n,����mat,Դ��source,���sink

#define MAXN 100
#define inf 1000000000

int max_flow(int n,int mat[][MAXN],int source,int sink,int flow[][MAXN])
{
int pre[MAXN],que[MAXN],d[MAXN],p,q,t,i,j;
if (source==sink) return inf;
for (i=0;i<n;i++)
   for (j=0;j<n;flow[i][j++]=0);
for (;;){
   for (i=0;i<n;pre[i++]=0);
   pre[t=source]=source+1,d[t]=inf;
   for (p=q=0;p<=q&&!pre[sink];t=que[p++])
    for (i=0;i<n;i++)
     if (!pre[i]&&j=mat[t][i]-flow[t][i])
      pre[que[q++]=i]=t+1,d[i]=d[t]<j?d[t]:j;
     else if (!pre[i]&&j=flow[i][t])
      pre[que[q++]=i]=-t-1,d[i]=d[t]<j?d[t]:j;
   if (!pre[sink]) break;
   for (i=sink;i!=source;)
    if (pre[i]>0)
     flow[pre[i]-1][i]+=d[sink],i=pre[i]-1;
    else
     flow[i][-pre[i]-1]-=d[sink],i=-pre[i]-1;
}
for (j=i=0;i<n;j+=flow[source][i++]);
return j;
}



��С���������

//��������С���������,�ڽ�����ʽ
//�����������,flow����ÿ���ߵ�����,netcost�����ܷ���
//��������ڵ���n,����mat,��λ����cost,Դ��source,���sink

#define MAXN 100
#define inf 1000000000

int min_cost_max_flow(int n,int mat[][MAXN],int cost[][MAXN],int source,int sink,int flow[][MAXN],int& netcost){
int pre[MAXN],min[MAXN],d[MAXN],i,j,t,tag;
if (source==sink) return inf;
for (i=0;i<n;i++)
   for (j=0;j<n;flow[i][j++]=0);
for (netcost=0;;){
   for (i=0;i<n;i++)
    pre[i]=0,min[i]=inf;
   //ͨ��bellman_fordѰ�����·������С���ÿɸĽ�·
   for (pre[source]=source+1,min[source]=0,d[source]=inf,tag=1;tag;)
    for (tag=t=0;t<n;t++)
     if (d[t])
      for (i=0;i<n;i++)
       if (j=mat[t][i]-flow[t][i]&&min[t]+cost[t][i]<min[i])
        tag=1,min[i]=min[t]+cost[t][i],pre[i]=t+1,d[i]=d[t]<j?d[t]:j;
       else if (j=flow[i][t]&&min[t]<inf&&min[t]-cost[i][t]<min[i])
        tag=1,min[i]=min[t]-cost[i][t],pre[i]=-t-1,d[i]=d[t]<j?d[t]:j;
   if (!pre[sink]) break;
   for (netcost+=min[sink]*d[i=sink];i!=source;)
    if (pre[i]>0)
     flow[pre[i]-1][i]+=d[sink],i=pre[i]-1;
    else
     flow[i][-pre[i]-1]-=d[sink],i=-pre[i]-1;
}
for (j=i=0;i<n;j+=flow[source][i++]);
return j;
}

//�����½�������С��,�ڽ�����ʽ
//�����������,-1��ʾ�޿�����,flow����ÿ���ߵ�����
//��������ڵ���n,����mat,�����½�bf,Դ��source,���sink
//MAXNӦ�����������2,�޿���������-1ʱmatδ��ԭ!

#define MAXN 100
#define inf 1000000000

void _max_flow(int n,int mat[][MAXN],int source,int sink,int flow[][MAXN]){
int pre[MAXN],que[MAXN],d[MAXN],p,q,t,i,j;
for (;;){
   for (i=0;i<n;pre[i++]=0);
   pre[t=source]=source+1,d[t]=inf;
   for (p=q=0;p<=q&&!pre[sink];t=que[p++])
    for (i=0;i<n;i++)
     if (!pre[i]&&j=mat[t][i]-flow[t][i])
      pre[que[q++]=i]=t+1,d[i]=d[t]<j?d[t]:j;
     else if (!pre[i]&&j=flow[i][t])
      pre[que[q++]=i]=-t-1,d[i]=d[t]<j?d[t]:j;
   if (!pre[sink]) break;
   for (i=sink;i!=source;)
    if (pre[i]>0)
     flow[pre[i]-1][i]+=d[sink],i=pre[i]-1;
    else
     flow[i][-pre[i]-1]-=d[sink],i=-pre[i]-1;
}
}

int limit_min_flow(int n,int mat[][MAXN],int bf[][MAXN],int source,int sink,int flow[][MAXN]){
int i,j,sk,ks;
if (source==sink) return inf;
for (mat[n][n+1]=mat[n+1][n]=mat[n][n]=mat[n+1][n+1]=i=0;i<n;i++)
   for (mat[n][i]=mat[i][n]=mat[n+1][i]=mat[i][n+1]=j=0;j<n;j++)
    mat[i][j]-=bf[i][j],mat[n][i]+=bf[j][i],mat[i][n+1]+=bf[i][j];
sk=mat[source][sink],ks=mat[sink][source],mat[source][sink]=mat[sink][source]=inf;
for (i=0;i<n+2;i++)
   for (j=0;j<n+2;flow[i][j++]=0);
_max_flow(n+2,mat,n,n+1,flow);
for (i=0;i<n;i++)
   if (flow[n][i]<mat[n][i]) return -1;
flow[source][sink]=flow[sink][source]=0,mat[source][sink]=sk,mat[sink][source]=ks;
_max_flow(n,mat,sink,source,flow);
for (i=0;i<n;i++)
   for (j=0;j<n;j++)
    mat[i][j]+=bf[i][j],flow[i][j]+=bf[i][j];
for (j=i=0;i<n;j+=flow[source][i++]);
return j;
}

//�����½����������,�ڽ�����ʽ
//�����������,-1��ʾ�޿�����,flow����ÿ���ߵ�����
//��������ڵ���n,����mat,�����½�bf,Դ��source,���sink
//MAXNӦ�����������2,�޿���������-1ʱmatδ��ԭ!

#define MAXN 100
#define inf 1000000000

void _max_flow(int n,int mat[][MAXN],int source,int sink,int flow[][MAXN]){
int pre[MAXN],que[MAXN],d[MAXN],p,q,t,i,j;
for (;;){
   for (i=0;i<n;pre[i++]=0);
   pre[t=source]=source+1,d[t]=inf;
   for (p=q=0;p<=q&&!pre[sink];t=que[p++])
    for (i=0;i<n;i++)
     if (!pre[i]&&j=mat[t][i]-flow[t][i])
      pre[que[q++]=i]=t+1,d[i]=d[t]<j?d[t]:j;
     else if (!pre[i]&&j=flow[i][t])
      pre[que[q++]=i]=-t-1,d[i]=d[t]<j?d[t]:j;
   if (!pre[sink]) break;
   for (i=sink;i!=source;)
    if (pre[i]>0)
     flow[pre[i]-1][i]+=d[sink],i=pre[i]-1;
    else
     flow[i][-pre[i]-1]-=d[sink],i=-pre[i]-1;
} 
}

int limit_max_flow(int n,int mat[][MAXN],int bf[][MAXN],int source,int sink,int flow[][MAXN]){
int i,j,sk,ks;
if (source==sink) return inf;
for (mat[n][n+1]=mat[n+1][n]=mat[n][n]=mat[n+1][n+1]=i=0;i<n;i++)
   for (mat[n][i]=mat[i][n]=mat[n+1][i]=mat[i][n+1]=j=0;j<n;j++)
    mat[i][j]-=bf[i][j],mat[n][i]+=bf[j][i],mat[i][n+1]+=bf[i][j];
sk=mat[source][sink],ks=mat[sink][source],mat[source][sink]=mat[sink][source]=inf;
for (i=0;i<n+2;i++)
   for (j=0;j<n+2;flow[i][j++]=0);
_max_flow(n+2,mat,n,n+1,flow);
for (i=0;i<n;i++)
   if (flow[n][i]<mat[n][i]) return -1;
flow[source][sink]=flow[sink][source]=0,mat[source][sink]=sk,mat[sink][source]=ks;
_max_flow(n,mat,source,sink,flow);
for (i=0;i<n;i++)
   for (j=0;j<n;j++)
    mat[i][j]+=bf[i][j],flow[i][j]+=bf[i][j];
for (j=i=0;i<n;j+=flow[source][i++]);
return j;
}

