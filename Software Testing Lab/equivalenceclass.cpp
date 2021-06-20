#include<iostream>
#include<bits/stdc++.h>
#include<time.h>
#include<math.h>
using namespace std;

int main(){
 int n;
 int MAXN=0;
 srand(time(0));
 cout<<"Enter number of variables: ";
 cin>>n;
 int upper[n], lower[n], value[n][3],wc[n];
 for(int i=0; i<n; i++){
 cout<<"Enter lower limit of variable "<<i+1<<": ";
 cin>>lower[i];
 cout<<"Enter upper limit of variable "<<i+1<<": ";
 cin>>upper[i];
 if(upper[i] - lower[i]<2){
 cout<<endl<<"Unable to apply Equivalence Class Testing because of invalid range specified by the user."<<endl;
 exit(0);
 }
 }
 for(int i=0;i<n;i++){
 value[i][0]=lower[i] - 1 ;
 value[i][1]=(rand() % upper[i]) + lower[i];
 value[i][2]=upper[i] + 1;
 }
 cout<<endl<<"Input Domain Test Cases are : "<<endl;
 cout<<"-------------------------------------------------------------------------------------";
 cout<<endl<<"Test Case\t";

 if(n==2){ 
   cout<<"A\t\t";
    cout<<"B\t\t";
    cout<<"Expected Output\t";
}
   if(n==3){ 
    cout<<"A\t\t";
    cout<<"B\t\t";
    cout<<"C\t\t";
   	cout<<"Expected Output\t";
}
   if(n==4){ 
    cout<<"A\t\t";
    cout<<"B\t\t";
    cout<<"C\t\t";
    cout<<"D\t\t";
    cout<<"Expected Output\t";
}

 int tc=1,k,check=0;
 for(int i=0;i<n;i++)
 wc[i]=0;
 for(int i=0,j=0; i<pow(3,n);i++){
 cout<<endl<<"I"<<tc<<"\t";
 while(j<n){
 k=wc[j];
 cout<<"\t"<<value[j][k]<<"\t";
 j++;
 } 
 for(j=0; j<n;j++)
 if(wc[j]!=1){
 check=1;
 break;
 }
 if(check==1){
 cout<<"Input values are out of range\t";
 check=0;
 }
 else{
 	int max=0;
 	if(value[0][1]>=value[1][1] && value[0][1] >=value[2][1])
 	    max=value[0][1];
 	else if (value[1][1]>= value[0][1] && value[1][1] >=value[2][1])
 	    max=value[1][1];
 	else 
 	   max= value[2][1];
 	cout<<max<<"\t";
 }
  
 j=0;
 wc[j]++;
 for(j=0;j<n;j++)
 if (wc[j]==3){
 wc[j]=0;
 wc[j+1]++;
 }
 j=0;
 tc++;
 if(tc>pow(3,n))
 break;
 }
 tc=0;
 
  if(n==2){ 
   int res=pow(3,n);
    cout<<"\n\nTotal No. of input Test Cases(3^n) = "<<res<<endl;
}
   if(n==3){ 
   int res=pow(3,n);
  cout<<"\n\nTotal No. of input Test Cases(3^n) = "<<res<<endl;
}
   if(n==4){ 
   int res=pow(3,n);
   cout<<"\n\nTotal No. of input Test Cases(3^n) = "<<res<<endl;
}

  cout<<endl<<endl<<"\nOutput Domain Test Cases are : "<<endl;
  cout<<"-------------------------------------------------------------------------------------";
  cout<<endl<<"Test Case\t";
  if(n==2){ 
    cout<<"A\t\t";
    cout<<"B\t\t";
    cout<<"Expected Output\t";
}
   if(n==3){ 
   cout<<"A\t\t";
    cout<<"B\t\t";
    cout<<"C\t\t";
 	cout<<"Expected Output\t";
}
   if(n==4){ 
    cout<<"A\t\t";
    cout<<"B\t\t";
    cout<<"C\t\t";
    cout<<"D\t\t";
    cout<<"Expected Output\t";
}
 cout<<endl<<"O1\t";
 for(int i=0;i<n;i++)
 cout<<"\t"<<value[i][0]<<"\t";
 cout<<"Input values are out of range";
 cout<<endl<<"O2\t";
 for(int i=0;i<n;i++)
 cout<<"\t"<<value[i][1]<<"\t";
  MAXN=value[0][1];
 for(int i=0;i<n;i++)
 {
 	if(MAXN<value[i][1])
 	{
 		MAXN=value[i][1];
	 }
 }
 cout<<MAXN<<endl;
 return 0;
}
