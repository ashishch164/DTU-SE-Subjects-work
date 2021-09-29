#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int i,ss[3];

float kloc,fp,E[3],D[3],P[3];

float a[3] = {2.4, 3.0, 3.6};

float b[3] = {1.05, 1.12, 1.20};

float c[3] = {2.5, 2.5, 2.5};

float d[3] = {0.38, 0.35, 0.32};

void calc(int i)
{
E[i] = a[i]*(pow(kloc,b[i])); 
D[i] = c[i]*(pow(E[i],d[i]));
cout<<"\n\t Effort, E = "<<E[i]<<" PM";
cout<<"\n\t Development Time, D = "<<D[i]<<" M";
}

int main()
{
cout<<"Enter size of project (in KLOC) : ";
cin>>kloc;
cout<<"\nESTIMATIONS FOR BASIC COCOMO ARE:" ;
cout<<"\n\nFor Organic Mode :"; calc(0); 
cout<<"\n\nFor Semidetatched Mode :"; calc(1);
cout<<"\n\nFor Embedded Mode :"; calc(2);
return 0;
}
