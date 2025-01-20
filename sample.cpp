#include <iostream>
#include <vector>
#include <utility>
#include <cmath> 

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> sum(n+1);
    sum[0]=0;
    sum[1]=0;
    for(int i=1;i<n;i++){
        if(s[i]=='C' && s[i-1]=='A'){
            sum[i+1]=sum[i]+1;
        }else{
            sum[i+1]=sum[i];
        }
    }
    for(auto a:sum){
        cout << a << endl;
    }
    // for(int i=0;i<q;i++){
    //     int a,b;
    //     cin >> a >> b;
    //     cout << sum[b]-sum[a-1] << endl;
    // }
}    