#include <iostream>
#include <vector>
#include <utility>
#include <cmath> 

#include<bits/stdc++.h>
using namespace std;

int main() {
    int h,w;
    cin >> h >> w;
    vector<string> mp(h);
    for(int i=0;i<h;i++){
        cin >> mp[i];
    }
    int a=INT_MAX;
    int b=INT_MAX;
    int c=INT_MIN;
    int d=INT_MIN;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(mp[i][j]=='#'){
                a=min(a,i);
                b=min(b,j);
                c=max(c,i);
                d=max(d,j);
            }
        }
    }
    for(int i=a;i<=c;i++){
        for(int j=b;j<=d;j++){
            if(mp[i][j]=='.'){
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
}
