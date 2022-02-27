#include<bits/stdc++.h>
using namespace std;
class employee{ 
public:
	int empid;
	string emailid;
	vector<string> getmeetinglist(){ 
	
	}
	void getinfo(){ 
	
	}
};
class SDE: public employee{ 
public:
	SDE(int eid,string email){ 
	empid=eid;
	emailid=email;
	}
	string managername;
	string businessunitid;
	bool ishandlingsecurity(){ 
	
	}
	int getdepid(){ 
	  //string info = getinfo();
	}
};
int main(){ 
SDE ashish(1,"abc@gmail.com");
ashish.businessunitid=2;
ashish.getdepid();
ashish.getmeetinglist();
ashish.getinfo();
return 0;
}
