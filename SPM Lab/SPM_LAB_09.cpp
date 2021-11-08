#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define mon(x) cerr << #x << " is " << x << " "
#define mon_br(x) cerr << #x << " is " << x << endl
#define ll long long

int main() {
  
  //Actors
  int Ano;
  cout << "Enter the number of Actors: ";
  cin >> Ano;
  int actors[Ano];
  cout << "Enter the Complexity for each Actor  0 - simple, 1- complex, 2- High:\n";
  for (int i = 0; i < Ano; i++)
    cin >> actors[i];

  //UAW
  float UAW = 0;
  for (int i = 0; i < Ano; i++)
    UAW += actors[i] + 1;

  //Use cases
  int UCno;
  cout << "\nEnter the number of Use Cases: ";
  cin >> UCno;
  int use_cases[UCno][2];
  cout << "Enter the transactions and Analysis objects for each Use Case \n";
  for (int i = 0; i < UCno; i++)
    cin >> use_cases[i][0] >> use_cases[i][1];
  int use_cases_weight_factor[UCno];
  for (int i = 0; i < UCno; i++) {
    if (use_cases[i][0] <= 3 || use_cases[i][1] <= 5) {
      use_cases_weight_factor[i] = 5;
    }
    else if(use_cases[i][0] < 7 || use_cases[i][1] < 10) {
      use_cases_weight_factor[i] = 10;
    }
    else {
      use_cases_weight_factor[i] = 15;
    }
  }

  //UUCW
  float UUCW = 0;
  for (int i = 0; i < UCno; i++)
    UUCW += use_cases_weight_factor[i];

  //UUCP
  float UUCP = UAW + UUCW;

  //FCF
  cout << "\nEnter the value of 13 technical factors on a scale of 0-5: \n";
  float Wi[13] = {2,1,1,1,1,0.5,0.5,2,1,1,1,1,1};
  float Fi[13];
  float TCF = 0;
  for (int i = 0; i < 13; i++)
    cin >> Fi[i];
  for (int i = 0; i < 13; i++)
    TCF += Fi[i] * Wi[i];
  TCF *= 0.01;
  TCF += 0.6;
  //ECF
  cout << "Enter the value of 8 environmental factors on a scale of 0-5\n";
  float Wj[13] = {1.5, 0.5, 0.5, 1, 1, -1, -1, 2 };
  float Fj[13];
  float ECF = 0;
  for (int i = 0; i < 8; i++)
    cin >> Fj[i];
  for (int i = 0; i < 8; i++)
    TCF += Fj[i] * Wj[i];
  TCF *= -0.03;
  TCF += 1.4;

  //UCP
  float UCP = UUCP + TCF + ECF;
  cout << "\nThe value of Use Case Point is : " << UCP;
  return 0;
}
