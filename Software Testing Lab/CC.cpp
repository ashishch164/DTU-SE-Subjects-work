#include <iostream> 
#include<fstream> 
#include<string.h>
#include<stdlib.h>
using namespace std; 

int CyclomaticComlexity(int e, int n, int P) 
{ 
	int V = e - n + 2 * P; 
	return V; 
} 

int main() 
{ 
	int cnt = 0;
	ifstream myfile; 
 	string line; 
 	myfile.open("triangle.cpp"); 

	if (myfile.is_open()) { 
		int e = 0, n = 0, p = 1; 
		bool isStartProg; 
		size_t found; 
		while (getline(myfile, line)) {
			
			if (line.empty())
				continue; 
			if (!isStartProg) { 
				std::cout<<line<<endl;
				found = line.find("void main()"); 
				if (found != string::npos) { 
					isStartProg = true; 
					e++; 
					n++;
				}
			} 
			else { 
			
				if(line.find_first_of("//") != string::npos){
					cout << line << endl;
					continue; 
			}
				if(line.find("if") != string::npos)
				{	
					cnt++;	
				}	
				e++;
				n++; 
			cout << line << endl; 
			} 
		} 
		myfile.close(); 	 
		int no_edges = e+cnt-1;
		cout << " \nCyclomatic Complexity: V(G) = E - N + 2*P = " << no_edges << " - " << n << " + 2 * " << p << " = " << CyclomaticComlexity(no_edges, n, p) << endl; 	 
	} 
	else { 
		cout << "Unable to open file"; 
	} 
	return 0; 
}
