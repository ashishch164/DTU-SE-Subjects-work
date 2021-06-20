#include<iostream>
#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int main(){
     int i,j,a[MAX],n,new_n;
     cout<<"Enter string length:";
	cin>>n;
	if(n<=0){ 
	cout<<"Invalid size specified.\n";
	exit(0);
	}
	cout<<"\nEnter input string (0's & 1's only):";
	for(int i=0;i<n;i++)
	{ 
	cin>>a[i];   //storing each 0 & 1 in array
	}
     
     //Stuffing     
     new_n=n;
     for(i=0;i<=MAX;i++){
          if(a[i]==0 && i+7 < new_n){
               if(a[i+1] == a[i+2] == a[i+3] == a[i+4] == a[i+5] == a[i+6] == 1 && a[i+7]==0) {
                    new_n++;
                    
                    for(j=new_n-1;j>i+6;j--){
                         a[j] = a[j-1];                 
                    }
                    a[i+6] = 0;
                    i=i+8;
                    
               }     
          }
    
     }  
    cout<<"\nAfter bit stuffing the string becomes:";
     for(i=0;i<new_n;i++){ 
      	cout <<  a[i] << " ";
	 }      
 return 0;    
}
