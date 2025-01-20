#include <iostream> // 標準入力出力を扱うライブラリ
using namespace std; // 標準名前空間を使用

int main() {
    int n, k; // 配列のサイズnとウィンドウサイズkを定義
    cin >> n >> k; // ユーザーからnとkを入力

    int a[n]; // サイズnの整数型配列を定義
    for (int i = 0; i < n; i++) { // 配列aに要素を入力
        cin >> a[i];
    }

    // 最初のウィンドウ（最初のk個の要素）の合計を計算
    int max_sum = 0, current_sum = 0; // 最大合計と現在の合計を初期化
    for (int i = 0; i < k; i++) { // 最初のk個の要素を加算
        current_sum += a[i];
    }
    max_sum = current_sum; // 最大合計を最初のウィンドウの合計で初期化
    int max_sum_idx = 0; // 最大合計を持つウィンドウの開始インデックスを0で初期化

    // スライディングウィンドウ法で最大合計を更新
    for (int i = k; i < n; i++) { // k番目以降の要素をループ
        // 新しい要素を加え、古い要素を引いてウィンドウの合計を更新
        current_sum += a[i] - a[i - k];
        if (current_sum > max_sum) { // 現在の合計が最大合計を超えた場合
            max_sum = current_sum; // 最大合計を更新
            max_sum_idx = i - k + 1; // 新しい最大合計の開始インデックスを記録
        }
    }

    // 最大合計を持つウィンドウの開始インデックスを1ベースで出力
    cout << max_sum_idx + 1 << endl; 
    return 0; // プログラム終了
}
