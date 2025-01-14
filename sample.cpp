#include <iostream>
#include <vector>
#include <utility>
#include <cmath> 

#include<bits/stdc++.h>
using namespace std;

int main() {
    int h;
    cin >> h;
    vector<string> arr(h+10);
    vector<string> brr(h+10);
    for(int i=0;i<h;i++){
        string s;
        cin >> s;
        arr[i]=s;
        brr[i]=s;
    }
    int count =100;
    while(count!=0){
        count=0;
        for(int i=0;i<h;i++){
            for(int j=0;j<5;j++){
                if(arr[i][j]=='.')continue;
                if(i-1>=0){
                    if(arr[i-1][j]!=arr[i][j]){
                        brr[i][j]=arr[i][j];
                        continue;
                    }
                }
                if(i+1<=h-1){
                    if(arr[i+1][j]!=arr[i][j]){
                        brr[i][j]=arr[i][j];
                        continue;
                    }
                }
                if(j-1>=0){
                    if(arr[i][j-1]!=arr[i][j]){
                        brr[i][j]=arr[i][j];
                        continue;
                    }
                }
                if(j+1<=4){
                    if(arr[i][j+1]!=arr[i][j]){
                        brr[i][j]=arr[i][j];
                        continue;
                    }
                }
                brr[i][j]='.';
                count++;
            }
        }
        for(int i=0;i<5;i++){
            int s=h-1;
            int e=h-2;
            while(s>-1){
                while(brr[i][s]=='.' && s>-1){
                    s++;
                }
                while(brr[i][e]!='.' && e>0){
                    e++;
                }
                swap(brr[s][i],brr[e][i]);
            }
        }
        for(int i = 0; i < h; i++){
            arr[i] = brr[i];
        }
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<5;j++){
            cout << brr[i][j];
        }
        cout << endl;
    }
    
}