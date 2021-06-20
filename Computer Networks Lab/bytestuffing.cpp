#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int main()
{
        char a[30], fs[50] = " ", t[3], sd, ed, x[3], s[3], d[3], y[3];
        int i, j;
       /*we will consider only three types of byte sequences in the sent data, as :
		F : Flag Sequence
		E : Escape Sequence
		D : Any other Data Sequence*/
        cout<<" Enter characters to be stuffed:";
        cin>>a;
        cout<<"\n Enter a character that represents starting delimiter:";
        cin>>sd;
        cout<<"\n Enter a character that represents ending delimiter:";
        cin>>ed;
        
        x[0] = s[0] = s[1] = sd;
        x[1] = s[2] = '\0';
        y[0] = d[0] = d[1] = ed;
        d[2] = y[1] = '\0';
        strcat(fs, x);
        for(i = 0; i < strlen(a); i++)
        {
            t[0] = a[i];
            t[1] = '\0';
            if(t[0] == 'F')     //if we see a flag byte,then insert E before F
                strcat(fs, "EF");
            else if(t[0] == 'E')    //if we see a ESC byte,then insert E before E
                strcat(fs, "EE");
            else
                strcat(fs, "D");    //if we see data,then nothing will be done 
        }
        strcat(fs, y);
        cout<<"\n After character stuffing:"<< fs;
        return 0;
    } 
