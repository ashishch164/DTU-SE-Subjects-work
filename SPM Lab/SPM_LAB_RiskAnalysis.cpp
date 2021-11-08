#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    cout<<"RISK ANALYSIS "<<endl;
    int n;
    cout<<"\nEnter the number of Risks identified in the project : ";
    cin>>n;
    cout<<endl;
    int riskList[1000][4]; 
    // Low =0 ; Medium =1 ; High=2; Urgent =3
      for(int i=0;i<n;i++){
       cout<<"Enter the Probability of Occurrence of Risk R"<< i+1<<" "<< ": ";
        cin>>riskList[i][0];
        if(riskList[i][0]>=0 && riskList[i][0]<=2){
            riskList[i][2]=0;
        }
        else if(riskList[i][0]>=3 && riskList[i][0]<=5){
            riskList[i][2]=1;
        }
        else if(riskList[i][0]==6 || riskList[i][0]==7){
            riskList[i][2]=2;
        }
        else{
            riskList[i][2]=3;
        }
       
        cout<<"Enter the Probability of Impact of Risk R"<< i+1<< ": ";
        cin>>riskList[i][1];

        if(riskList[i][1]==0 || riskList[i][1]==1){
            riskList[i][3]=0;
        }
        else if(riskList[i][1]==2 || riskList[i][1]==3){
            riskList[i][3]=1;
        }
        else if(riskList[i][1]==4 || riskList[i][1]==5){
            riskList[i][3]=2;
        }
        else{
            riskList[i][3]=3;
        }
    }
    
    cout<<"\nRISK\tOCCURRENCE\tTYPE\tIMPACT\tTYPE\t"<<endl;
    for(int i=0;i<n;i++){
            cout<<"R"<<i+1<<"\t"<<riskList[i][0]<<"\t\t";
            
            if(riskList[i][2]==0){
                cout<<"Low\t";
            }
            else if(riskList[i][2]==1){
                cout<<"Medium\t";
            }
            else if(riskList[i][2]==2){
                cout<<"High\t";
            }
            else{
                cout<<"Urgent\t";
            }
 	cout<<riskList[i][1]<<"\t";
            
            if(riskList[i][3]==0){
                cout<<"Low\t";
            }
            else if(riskList[i][3]==1){
                cout<<"Medium\t";
            }
            else if(riskList[i][3]==2){
                cout<<"High\t";
            }
            else{
                cout<<"Urgent\t";
            }
            cout<<"\t"<<" "<<endl;
    }  
}

