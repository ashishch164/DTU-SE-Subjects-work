#include<bits/stdc++.h> 
#include<cstdio>
#include<iostream>
using namespace std;

int main(){
int f,w; 
int cnt=0;
cout<<"\nEnter the Window Size : "; 
cin>>w;
cout<<"Enter the number of frames : "; 
cin>>f; 

int i=1; int k=1;
cout<<"\nAfter sending "<<w<<" frames, sender waits for acknowledgment to be sent by receiver."<<endl; 
while(i<=f) {
if(i==1){
for(int j=1;j<=w && j<=f;j++){
   cout<<"\nFrame "<<j<<" is sent "<<endl;
   cnt++;
  }
} 
if(i != 1){
cout<<"Sent Frame "<<i<<endl; 
cnt++; 
}
cout<<"\nAcknowledgment is received for frame "<<k<<" by sender"<<endl; 
 k++;
cout<<endl;
 if(i==1){
  i += w ;
 } 
  else{
    i++;
  } 
} 

for(int a=k; a<=f; a++){ 
    cout<<"\nAcknowledgment is received for frame "<<a<<" by sender"<<endl; 
} 
cout<<"\nTotal number of transmissions : "<<cnt<<endl; 
return 0; 
}
