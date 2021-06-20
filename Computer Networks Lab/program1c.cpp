#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    char input[100];
    cout<<"Enter Data: ";
    for(int i=0;i<20;i++){
    	cin>>input[i];     //0011010101111111111000110
	}
    cout<<"\nFlag: 11111111\n";
    cout<<"\nEscape Seq: 00000000\n";
    cout<<"\nOuput after  byte stuffing:";
    cout<<"11111111 ";
    int count=0,ce=0;

    for(int i=0;i<20;i++){
        if(input[i]=='1'){
            if(count==7){
                cout<<" ";
                for(int j=0;j<8;j++){

                    cout<<"0";
                }
                cout<<" ";
                count=0;
            }
            else{
                count++;
            }
        }
        else{
            count=0;
        }
        if(input[i]=='0'){
            if(ce==7){
                 cout<<" ";
                for(int j=0;j<8;j++){
                    cout<<"0";
                }
                cout<<" ";
                ce=0;
            }
            else{
                ce++;
            }
        }
        else{
            ce=0;
        }
        cout<<input[i];
    }

    cout<<" 11111111";
    return 0;
}
