#include <iostream>
#include <vector>
#include <utility>
#include <cmath> 

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n+10);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int count=0;
    for(int i=0;i<n;i++){
        int it = upper_bound(arr.begin(),arr.begin()+n,arr[i]/2)-arr.begin();
        count+=it;
    }
    cout << count;
}
    