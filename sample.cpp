#include <iostream>
#include <vector>
#include <utility>
#include <cmath> 

#include<bits/stdc++.h>
using namespace std;

int main() {
    int N,K;
    cin >> N >> K;
    vector<vector<int>> arr(N+10);
    for(int i=1;i<=N-1;i++){
        int a,b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for(int i=1;i<=K;i++){
        int c,d;
        cin >> c >> d;
        if (count(arr[c].begin(), arr[c].end(), d)) {
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

}