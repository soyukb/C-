#include <iostream>
#include <vector>
#include <utility>
#include <cmath> 

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> arr(n+10);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        arr[a].push_back(b);
        for(int j=0;j<arr[b].size();j++){
            arr[a].push_back(arr[b][j]);
        }
        arr[b].clear();
    }
    // for(int i=1;i<=n;i++){;
    //     cout << i << " ";
    //     for(int j=0;j<arr[i].size();j++){
    //         cout << arr[i][j]<< " ";
    //     }
    //     cout << endl;
    // }
    vector<int> ans;
    int max_value=-1;
    for(int i=1;i<=n;i++){
        if(arr[i].size()>max_value){
            ans.clear();
            max_value=arr[i].size();
            ans.push_back(i);
        }else if(arr[i].size()==max_value){
            ans.push_back(i);
        }
    }
    cout << ans.size();
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << endl;
    }
}