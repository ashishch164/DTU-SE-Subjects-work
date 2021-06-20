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
int num_vars, output ,*variables;
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
void add_all(std::vector<Testcase> v){
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
//cout<<"Total Number of Testcases : "<<this->num_cases<<endl;
for (vector<Testcase>::iterator i = cases.begin(); i != cases.end(); ++i)
{
(*i).print_result();
}
cout<<"\nTotal Number of Testcases(6*n+1) : "<<num_cases<<endl;
}
};
Testcase get_nominal_testcase(int num_vars, pair<int,int> ranges[]){
int variables[num_vars];
for (int i = 0; i < num_vars; ++i)
{
variables[i] = (ranges[i].second - ranges[i].first)/2;
}
return Testcase(num_vars,variables);
}

Testsuite generate_testcases(int num_vars , pair<int,int> ranges[])
{
Testsuite suite;

for (int i = 0; i < num_vars; ++i)
{
int variables[num_vars];

for (int j = 0; j < num_vars; ++j)
{
if (i!=j)
{
variables[j] = (ranges[j].second - ranges[j].first)/2;
}
}
// Add values for the selected variable
std::vector<Testcase> v;
// 1. Minimum - 1
variables[i] = ranges[i].first-1;
v.push_back(Testcase(num_vars,variables));
// 2. Minimum
variables[i] = ranges[i].first;
v.push_back(Testcase(num_vars,variables));
// 2. Minimum + 1
variables[i] = ranges[i].first + 1;
v.push_back(Testcase(num_vars,variables));
// 3. Maximum - 1
variables[i] = ranges[i].second-1;
v.push_back(Testcase(num_vars,variables));
// 4. Maximum
variables[i] = ranges[i].second;
v.push_back(Testcase(num_vars,variables));
// 5. Maximum + 1
variables[i] = ranges[i].second+1;
v.push_back(Testcase(num_vars,variables));
suite.add_all(v);
}
// Add a nominal testcase
suite.add_testcase(get_nominal_testcase(num_vars,ranges));
return suite;
}

int main()
{
int num_vars = 0;
cout<<"Enter number of variables : ";
cin>>num_vars;
pair<int,int> ranges[num_vars];
cout<<"Enter min and max limit of each variable: \n";
for (int i = 0; i < num_vars; ++i)
{
cout<<"Limit"<<i+1<<" : ";
cin>>ranges[i].first>>ranges[i].second;
}
	cout<<"\nTEST CASES FOR LARGEST OF THREE  NUMBERS :-\n"<<endl;
	cout<<"A\t";
    cout<<"B\t";
    if(num_vars==3){ 
    cout<<"C\t";
	}
   
    cout<<"EXPECTED OUTPUT";
    cout<<endl;

Testsuite t = generate_testcases(num_vars , ranges);

t.run();
t.print_results();

return 0;
}
