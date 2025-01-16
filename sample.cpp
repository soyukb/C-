#include <iostream>
#include <vector>
#include <utility>
#include <cmath> 

#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin,s);
    int now=0;
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            cout << s.substr(now,i-now) << endl;
            now+=i+1;
        }
       
    }
}
    