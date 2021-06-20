#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int find_min(int nums[] , int len){
int max = INT_MIN;
for (int i = 0; i < len; ++i)
{
if (nums[i] > max)
{
max = nums[i];
}
}
return max;
}

struct Testcase {
int num_vars,*variables;
int output;
Testcase(int num_vars , int* variables){
this->num_vars = num_vars;
this->variables = new int[num_vars];
memcpy(this->variables,variables,sizeof(int)*num_vars);
}
void run(){
output = find_min(variables,num_vars);
}
void print_result(){


for (int i = 0; i < num_vars; ++i)
{
cout<<variables[i]<<"\t";
}
cout<<"\t"<<output<<endl;
}
};

struct Testsuite {
int num_cases;
vector<Testcase> cases;
Testsuite(){
num_cases = 0;
}
void add_testcase(Testcase testcase){
num_cases++;
cases.push_back(testcase);
}
void add_all(vector<Testcase> v){
num_cases += v.size();
for (vector<Testcase>::iterator i = v.begin(); i != v.end(); ++i)
{
cases.push_back(*i);
}
}
void run(){
for (vector<Testcase>::iterator i = cases.begin(); i != cases.end(); ++i)
{
(*i).run();
}
}
void print_results(){

for (vector<Testcase>::iterator i = cases.begin(); i != cases.end(); ++i)
{
(*i).print_result();
}
cout<<"\nTotal No. of Test Cases(5^n) = "<<num_cases<<endl;
}
};

Testsuite generate_testcases(int num_vars , pair<int,int> ranges[] , int variables[], int i,
Testsuite &suite)
{
//basecase
if (i == num_vars)
{
suite.add_testcase(Testcase(num_vars,variables));
return suite;
}
// 2. Minimum
variables[i] = ranges[i].first;
generate_testcases(num_vars,ranges,variables,i+1,suite);
// 3. Minimum + 1
variables[i] = ranges[i].first + 1;
generate_testcases(num_vars,ranges,variables,i+1,suite);
// 4. Nominal
variables[i] = (ranges[i].second + ranges[i].first)/2;
generate_testcases(num_vars,ranges,variables,i+1,suite);
// 5. Maximum - 1
variables[i] = ranges[i].second-1;
generate_testcases(num_vars,ranges,variables,i+1,suite);
// 6. Maximum
variables[i] = ranges[i].second;
generate_testcases(num_vars,ranges,variables,i+1,suite);
return suite;
}

int main()
{
int num_vars = 0;
cout<<"Enter number of variables : ";
cin>>num_vars;
pair<int,int> ranges[num_vars];
for (int i = 0; i < num_vars; ++i)
{
cout<<"Enter the min & max limit of variable "<<i+1<<" : ";
cin>>ranges[i].first>>ranges[i].second;
}
Testsuite suite;
int variables[num_vars];
cout<<"\nTEST CASES FOR LARGEST OF THREE  NUMBERS :-\n"<<endl;
	if(num_vars==2){ 
   cout<<"A\t";
    cout<<"B\t"; 
    cout<<"\tOUTPUT\t";
	}
	if(num_vars==3){ 
   cout<<"A\t";
    cout<<"B\t";
    cout<<"C\t";   
    cout<<"\tOUTPUT\t";
	}
   if(num_vars==4){ 
   cout<<"A\t";
    cout<<"B\t";
    cout<<"C\t";
    cout<<"D\t";
    cout<<"\tOUTPUT\t";
	}
cout<<endl;
suite = generate_testcases(num_vars , ranges ,variables, 0, suite);
suite.run();
suite.print_results();
return 0;
}
