#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> ta(n+1);
    vector<vector<int>> ao(n+1);
    
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        ta[a].push_back(b);
        ta[b].push_back(a);
    }
    for(int i=0;i<m;i++){
        int c,d;
        cin >> c >> d;
        ao[c].push_back(d);
        ao[d].push_back(c);
    }
    vector<int> taka(n,0);
    vector<int> aoki(n,0);
    for(int i=1;i<=n;i++){
        taka[i-1]=ta[i].size();
        aoki[i-1]=ao[i].size();
    }
    sort(taka.begin(),taka.end());
    sort(aoki.begin(),aoki.end());
    for(int i=0;i<n;i++){
        if(taka[i]!=aoki[i]){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    
} 