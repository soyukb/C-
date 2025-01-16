#include <bits/stdc++.h>
using namespace std;

// 二分探索で最大のパイプ長を求める
double search(vector<int>& arr, int k, int n) {
    double s = 0.0;
    double e = *max_element(arr.begin(), arr.end());
    double result = 0.0;
    const double precision = 1e-6; // 精度の設定

    while (e - s > precision) {
        double mid = s + (e - s) / 2.0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += static_cast<int>(arr[i] / mid);
        }
        if (count < k) {
            e = mid; // 長さを短くする
        } else {
            result = mid; // 結果を更新
            s = mid; // 長さを長くする
        }
    }
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    double ans = search(arr, k, n);
    cout << fixed << setprecision(6) << ans << endl;

    return 0;
}