#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main() {
  double loc, B = 0, E = 1, PM_nominal, PM_adjusted, y;
  int x;
  double scaling_factors[5][6] = {
    {     //for "Precedentness "
      6.20,
      4.96,
      3.72,
      2.48,
      1.24,
      0.00
    },
    {  //for "Development flexibility "
      5.07,
      4.05,
      3.04,
      2.03,
      1.01,
      0.00
    },
    {    //for "Archietecture Risk & resolution "
      7.07,
      5.65,
      4.24,
      2.83,
      1.41,
      0.00
    },
    {   //for "Team Cohesion "
      5.48,
      4.38,
      3.29,
      2.19,
      1.10,
      0.00
    },
    {    //for "Process maturity "
      7.80,
      6.24,
      4.68,
      3.12,
      1.56,
      0.00
    }
  };
  double cost_drivers[7][7] = {
    {
      0.73,
      0.81,
      0.98,
      1.0,
      1.3,
      1.74,
      2.38
    },
    {
      -1,
      -1,
      0.95,
      1.0,
      1.07,
      1.15,
      1.24
    },
    {
      -1,
      -1,
      0.87,
      1.0,
      1.29,
      1.81,
      2.61
    },
    {
      2.12,
      1.62,
      1.26,
      1.0,
      0.83,
      0.63,
      0.5
    },
    {
      1.59,
      1.33,
      1.12,
      1.0,
      0.87,
      0.71,
      0.62
    },
    {
      1.43,
      1.30,
      1.10,
      1.0,
      0.87,
      0.73,
      0.62
    },
    {
      -1,
      1.43,
      1.14,
      1.0,
      1.0,
      1.0,
      -1
    }
  };
  string factors[5] = {
    "Precedentness ",
    "Development flexibility ",
    "Archietecture Risk & resolution ",
    "Team Cohesion ",
    "Process maturity "
  };
  string drivers[7] = {
    "RCPX ",
    "RUSE ",
    "PDIF ",
    "PERS ",
    "PREX ",
    "FCIL ",
    "SCED "
  };
  cout<<"--------------------------EARLY DESIGN MODEL--------------------------"<<endl;
  cout << "\nEnter the number of lines of code(in KLOC): ";
  cin >> loc;
  cout << endl <<"Enter the value of Scaling factors ranging from 0 to 5: (1 - Very Low, 2 - Low, 3 - Nominal, 4 - High,  5 - Very high) ";
  for (int i = 0; i < 5; i++) {
    cout << endl << factors[i];
    cin >> x;
    B += scaling_factors[i][x];
  } 
	B *= 0.01;
    B += 0.91;
  //B=0.91+(0.01*20.29);
  PM_nominal = 2.5 * pow(loc, B);
  cout << endl << "Nominal effort is: " << PM_nominal << " Person-months"<< endl;
  x = 0;
  cout << endl << "Enter the value of 7 early design cost drivers from 0 to 6" << endl;
  for (int i = 0; i < 7; i++) {
    do {
      cout << endl << drivers[i];
      cin >> x;
      y = cost_drivers[i][x];
      if (y != -1) {
        E *= y;
      } else {
		cout << endl << "Entered value is not permissable, please enter another value";
        }
    } while (y == -1);
  }
  PM_adjusted = PM_nominal * E;
  cout << "\nAdjusted effort is: " << PM_adjusted << " Person-months" << endl;
  return 0;
}
