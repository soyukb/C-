#include <iostream>
#include <vector>
#include <utility>
#include <cmath> 

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(n+1);
    vector<bool> vesited(n+1,false); 
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    vesited[1]=true;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=0;i<g[now].size();i++){
            int next = g[now][i];
            if(vesited[next]==false){
                q.push(next);
                vesited[next]=true;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(vesited[i]==false){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}    