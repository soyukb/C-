#include <iostream>
#include <vector>
#include <utility>
#include <cmath> 

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    n = 2*n;
    vector<vector<char>> mp(n+1,vector<char>(m+1));
    vector<pair<int,int>> ans(n+1);
    map<int,int> win;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> mp[i][j];
        }
        win[i]=0;
        ans[i]={0,i};
    }
    for(int i=1;i<=m;i++){
        for(int k=1;k<=n/2;k++){
            int x = 2*k-1;
            int y = 2*k;
            char a = mp[ans[x].second][i];
            char b = mp[ans[y].second][i];
            if(a==b){
                continue;
            }else if(a>b){
                win[x]++;
                ans[x].first++;
            }else if(a<b){
                win[y]++;
                ans[y].first++;
            }
            sort(ans.begin(),ans.end());
        }
    }
    for(auto [dy,dx]:ans){
        cout << dx << endl;
    }
}    