#include<iostream>
using namespace std;

struct node
{
unsigned dist[20];
unsigned parent[20];
} rt[10];
int main()
{
int costmat[20][20];
int nodes,i,j,k,count=0;
cout<<"\nEnter the number of nodes : ";
cin>>nodes;
cout<<"\nEnter the cost matrix :\n";
for(i=0;i<nodes;i++)
for(j=0;j<nodes;j++)
{
cin>>costmat[i][j];
costmat[i][i]=0;
rt[i].dist[j]=costmat[i][j];
rt[i].parent[j]=j; 
}
do
{
count=0;
for(i=0;i<nodes;i++)
for(j=0;j<nodes;j++)
for(k=0;k<nodes;k++)
if(rt[i].dist[j]>costmat[i][k]+rt[k].dist[j])
{
rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
rt[i].parent[j]=k;
count++;
}
}while(count!=0);
for(i=0;i<nodes;i++)
{ 
cout<<"\n\nFor " <<"router "<<i+1;
for(j=0;j<nodes;j++)
cout<<"\nNode "<<j+1<<" via "<<rt[i].parent[j]+1<<" Distance "<<rt[i].dist[j]<<" ";
}
cout<<endl;
return 0;
}
