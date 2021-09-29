#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main() {

    float effort ;
    cout<<"Enter the expected Efforts (in Persons/Years): ";
    cin>>effort;
    effort=effort*12;
    cout<<endl;

    cout<<"\nCalculation using SEL Model:"<<endl;
    float LOC = pow((effort/1.4),(1/0.93));
    float duration = 4.6* pow(LOC,0.26);
    cout<<"Lines of Code =  " << round(LOC*1000) <<" LOC"<<endl;
    cout<<"Development Duration = "<< round(duration) << " Months"<<endl;
    cout<<"Productivity = " << round((LOC*1000)/(effort/12))<<" LOC / Person-Years"<<endl;
    cout<<endl;

    cout<<"Calculation using Walston-Felix Model:"<<endl;
    LOC = pow((effort/5.2),(1/0.91));
    duration = 4.1* pow(LOC,0.36);
    cout<<"Lines of Code = "<< round(LOC*1000) <<" LOC"<<endl;
    cout<<"Development Duration = "<< round(duration) << " Months"<< endl;
    cout<<"Productivity = " << round((LOC*1000)/(effort/12)) <<" LOC / Person-Years"<<endl;
}
