#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
// Given the Software Development Cost and the Peak Development Time
int K;
cout<<"-------------------- Putnam Resource Allocation Model --------------------\n\n";
double T;
cout << " Enter Software Development Cost : ";
cin >> K;
cout << " Enter Development Time : ";
cin >> T;

double peakmanning = K / (T * 1.64);
cout <<" Peak Manning = "<< round(peakmanning) <<" persons "<< endl;

double avg_team_buildup_rate = round(peakmanning) / T;
cout <<" Average rate of software Team build up  = " << avg_team_buildup_rate <<" persons / year "<< endl;

return 0;
}

