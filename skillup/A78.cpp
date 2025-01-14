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
            for(int j = 0; j < 5; j++){
                if(arr[i][j] == '.') continue;
                bool removed = true;
                if(i > 0 && arr[i-1][j] != arr[i][j]) removed = false;
                if(i < h-1 && arr[i+1][j] != arr[i][j]) removed = false;
                if(j > 0 && arr[i][j-1] != arr[i][j]) removed = false;
                if(j < 4 && arr[i][j+1] != arr[i][j]) removed = false;

                if(removed){
                    brr[i][j] = '.';
                    if(i>0)brr[i-1][j] = '.';
                    if(i<h-1)brr[i+1][j] = '.';
                    if(j>0)brr[i][j-1] = '.';
                    if(j<4)brr[i][j+1] = '.';

                    count++;
                }
            }
        }
        for(int j = 0; j < 5; j++){
            for(int i = h-1; i >= 0; i--){
                if(brr[i][j] == '.'){
                    int k = i - 1;
                    while(k >= 0 && brr[k][j] == '.') k--;
                    if(k >= 0){
                        swap(brr[i][j], brr[k][j]);
                    }
                }
            }
        }
        for(int i = 0; i < h; i++){
            arr[i] = brr[i];
        }
    }

    for(int i = 0; i < h; i++){
        cout << brr[i] << endl;
    }
    
}