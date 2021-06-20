#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findmaximum(int arr[3], int minarr[3], int maxarr[3])
{ 
for(int i=0;i<3;i++)
if(arr[i]<minarr[i] || arr[i]>maxarr[i]) 
	return -1;

int largest = arr[0];
if(largest<arr[1]) 
	largest = arr[1];
else if(largest<arr[2] ) 
	largest = arr[2];

return largest;
}

void WorstRobustApproach(int n){
int minarr[10], maxarr[10], opt[10];
for(int i=0;i<n;i++)
{
cout<<"Enter the min & max limit of the variable "<<(i+1)<<": "; 
cin>>minarr[i]>>maxarr[i];
opt[i] = (maxarr[i]+minarr[i])/2;
}
int numTestCases = pow(7,n); 
int testCases[numTestCases][n];

for(int i=n-1;i>=0;i--)
{
int flag=0, t=1, k;
for(int k=0;k<(n-i-1);k++) t*=7;
for(int j=0;j<numTestCases;j++)
{
if(j%t==0)
	flag++; 
	flag = flag%7; 
switch(flag)
{
case 0: testCases[j][i] = maxarr[i]+1; break;
case 1: testCases[j][i] = minarr[i]-1; break;
case 2: testCases[j][i] = minarr[i]; break;
case 3: testCases[j][i] = minarr[i]+1; break;
case 4: testCases[j][i] = opt[i]; break;
case 5: testCases[j][i] = maxarr[i]-1; break;
case 6: testCases[j][i] = maxarr[i];
break;
}
 
}
}
cout<<"\nTEST CASES ARE..\n";
	
if(n==2){ 
cout<<"\n\tA\t\tB\t	OUTPUT\t";
cout<<"\n";		for(int i=0;i<50;i++) cout<<"-";	cout<<""; 
}
else if(n==3){ 
cout<<"\n\tA\t\tB\t\tC\t	OUTPUT\t";
cout<<"\n";		for(int i=0;i<80;i++) cout<<"-";	cout<<""; 
}	
else if(n==4){ 
cout<<"\n\tA\t\tB\t\tC\t\tD\t	OUTPUT\t";
cout<<"\n";		for(int i=0;i<100;i++) cout<<"-";	cout<<""; 
}

for(int i=0;i<50;i++) cout<<" ";	cout<<"\n"; 
for(int i=0;i<numTestCases;i++)
{
for(int j=0;j<n;j++)
{
if(j==0)	
cout<<"\t"; 
cout<<testCases[i][j]<<"\t\t";
}
int expOut = findmaximum(testCases[i],minarr,maxarr); 
if(expOut<0)
	cout<<"invalid input";
else	
	cout<<expOut; 
	cout<<"\t"<<endl;
}
cout<<" ";  
for(int i=0;i<50;i++) cout<<" ";	cout<<" "; 

cout<<"\nTotal No. of Test Cases(7^n) = "<<numTestCases;
}

int main()
{
int numofvar;
cout<<"Enter no. of variables : "; 
cin>>numofvar; 
WorstRobustApproach(numofvar); 
return 0;
}

