#include <bits/stdc++.h>
using namespace std;

// Function to calculate Function Point
void calfp(int frates[][3], int fac_rate)
{

	// Function Units
	string funUnits[5] = {
		"External Inputs",
		"External Outputs",
		"External Inquiries",
		"Internal Logical Files",
		"External Interface Files"
	};

	// Weight Rates
	string wtRates[3] = { "Low", "Average", "High" };

	// Weight Factors
	int wtFactors[5][3] = {
		{ 3, 4, 6 },
		{ 4, 5, 7 },
		{ 3, 4, 6 },
		{ 7, 10, 15 },
		{ 5, 7, 10 },
	};

	int UFP = 0;

	// Calculating UFP (Unadjusted Function Point)
	for (int i = 0; i < 5; i++) {

		for (int j = 0; j < 3; j++) {

			int freq = frates[i][j];

			UFP += freq * wtFactors[i][j];
		}
	}

	// 14 factors
	string aspects[14] = {
		"reliable backup and recovery required ?",
		"data communication required ?",
		"are there distributed processing functions ?",
		"is performance critical ?",
		"will the system run in an existing heavily utilized operational environment ?",
		"on line data entry required ?",
		"does the on line data entry require the input transaction to be built over multiple screens or operations ?",
		"are the master files updated on line ?",
		"is the inputs, outputs, files or inquiries complex ?",
		"is the internal processing complex ?",
		"is the code designed to be reusable ?",
		"are the conversion and installation included in the design ?",
		"is the system designed for multiple installations in different organizations ?",
		"is the application designed to facilitate change and ease of use by the user ?"
	};

	/*
	Rate Scale of Factors
	Rate the following aspects on a scale of 0-5 :-
	0 - No influence
	1 - Incidental
	2 - Moderate
	3 - Average
	4 - Significant
	5 - Essential
	*/

	int sumF = 0;

	// Taking Input of factors rate
	for (int i = 0; i < 14; i++) {

		int rate = fac_rate;

		sumF += rate;
	}

	// Calculate CFP
	double CAF = 0.65 + 0.01 * sumF;

	// Calculate Function Point (FP)
	double FP = UFP * CAF;

	// Output Values
	cout << "Function Point Analysis is given below" << endl;

	cout << "Unadjusted Function Points (UFP) : " << UFP << endl;

	cout << "Complexity Adjustment Factor (CAF) : " << CAF << endl;

	cout << "Function Points (FP) : " << round(FP) << endl;
}

// driver function
int main()
{
	int frates[5][3] = {
		{ 0, 50, 0 },
		{ 0, 40, 0 },
		{ 0, 35, 0 },
		{ 0, 6, 0 },
		{ 0, 4, 0 }
	};

	int fac_rate = 3;

	calfp(frates, fac_rate);

	return 0;
}

