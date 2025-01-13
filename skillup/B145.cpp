#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector<vector<pair<int,bool>>> arr(n+10,vector<pair<int,bool>>(n+10));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int a;
            cin >> a;
            arr[i][j].first=a;
            arr[i][j].second=false; 
            if(a==0){
                arr[i][j].second=true;
            }
        }
    }
    for(int i=1;i<=k;i++){
        int b;
        cin >> b;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(arr[i][j].first==b){
                    arr[i][j].second=true;
                }
            }
        }
    }
    int count=0;
    for(int i=1;i<=n;i++){
        bool ans=true;
        for(int j=1;j<=n;j++){
            if(arr[i][j].second==false){
                ans=false;
                continue;
            }
        }
        if(ans==true){
            count++;
        }
    }
    for(int i=1;i<=n;i++){
        bool ans=true;
        for(int j=1;j<=n;j++){
            if(arr[j][i].second==false){
                ans=false;
                continue;
            }
        }
        if(ans==true){
            count++;
        }
    }
    bool ans=true;
    for(int i=1;i<=n;i++){
        if(arr[i][i].second==false){
            ans=false;
            continue;
        }
    }
    if(ans==true){
        count++;
    }
    ans=true;
    for(int i=1;i<=n;i++){
        if(arr[i][n-i+1].second==false){
            ans=false;
            continue;
        }
    }
    if(ans==true){
        count++;
    }
    cout << count;


}