#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void generate_path(int s,int n,vector<vector<int>> &v,vector<int> &visit,vector<int> path)
{
 static int p;
 visit[s]=1;
 path.push_back(s);
 bool e=true;
 for(int i=s+1; i<n; i++)
 {
 if(v[s][i])
 {
 generate_path(i,n,v,visit,path); 
  e=false;
 }
 }
 if(e)
 {
 if(p<9)
 cout<<++p<<")";
 else
 cout<<++p<<")";
 for(unsigned int i=0; i<path.size(); i++)
 {
 cout<<" "<<path[i];
 if(i!=path.size()-1)
 cout<<"->";
 }
 if(p==1)
 cout<<"\t\t"<<"40"<<"\t"<<"20"<<"\t"<<"50\tObtuse Angled Triangle";
 else if(p==2)
 cout<<"\t\t"<<"30"<<"\t"<<"40"<<"\t"<<"50\tRight Angled Triangle";
 else if(p==3)
 cout<<"\t\t"<<"20"<<"\t"<<"40"<<"\t"<<"50\tAcute Angled Triangle";
 else if(p==9)
 cout<<"\t\t\t"<<"30"<<"\t"<<"10"<<"\t"<<"10\tInvalid Triangle";
 else if(p==15)
 cout<<"\t\t\t\t\t"<<"30"<<"\t"<<"-1"<<"\t"<<"50\tInput Out of Range";
 else
 {
 if(p==7 ||p==8)
 cout<<"\t\t-\t-\t-\tInvalid Test Case";
 else if(p==11)
 cout<<"\t\t\t\t-\t-\t-\tInvalid Test Case";
 else if(p==14)
 cout<<"\t\t\t\t\t-\t-\t-\tInvalid Test Case";
 else
 cout<<"\t\t\t-\t-\t-\tInvalid Test Case";
 }
 cout<<endl;
 }
 visit[s]=0;
 return;
}
int main()
{
 vector<vector<int>> graph(20,vector<int> (20,0));
 for(int i=0; i<=19; i++)
 {
 for(int j=0; j<=19; j++) 
 
 graph[i][j]=0;
 }
 for(int i=0; i<=18; i++)
 {
 graph[i][i+1]=1;
 }
 graph[3][5]=1;
 graph[2][7]=1;
 graph[4][6]=1;
 graph[7][15]=1;
 graph[9][11]=1;
 graph[11][13]=1;
 graph[14][18]=1;
 graph[15][17]=1;
 graph[16][18]=1;
 graph[12][14]=1;
 graph[10][14]=1;
 graph[4][5]=0;
 graph[10][11]=0;
 graph[12][13]=0;
 graph[14][15]=0;
 graph[16][17]=0;
 cout<<"Input Graph Matrix:"<<endl;
 for(int i=0; i<=19; i++)
 {
 for(int j=0; j<=19; j++)
 cout<<graph[i][j]<<" ";
 cout<<endl;
 }
 cout<<endl;
 vector<int> path;
 vector<int> visit(20,0);
 cout<<"SNo"<<" "<<"  Path Used\t\t\t\t\t\t\t\tA\tB\tC\tExpected Output"<<endl;
 cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
 generate_path(0,20,graph,visit,path);
 return 0;
} 

