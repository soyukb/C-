#include <bits/stdc++.h> // 標準ライブラリを一括でインクルード
using namespace std;

int main() {
    int n, m; // n: 文字列の長さ, m: 色の種類数
    string s; // 入力される文字列
    cin >> n >> m >> s; // n, m, s を入力

    vector<int> c(n); // 各インデックスの色を格納する配列
    vector<vector<int>> col(m + 1); // 色ごとにインデックスを分類するための配列

    // 色ごとにインデックスを収集
    for (int i = 0; i < n; i++) {
        cin >> c[i]; // インデックス i の色を入力
        col[c[i]].push_back(i); // 色 c[i] に属するインデックス i を保存
    }

    string ans(n, '.'); // 最終的な結果を格納する文字列（初期値はすべて '.'）

    // 各色ごとに文字列のインデックスを循環シフトする
    for (int i = 1; i <= m; i++) { // 色 i を1からmまで処理
        int size = col[i].size(); // 色 i に属するインデックスの個数
        for (int j = 0; j < size; j++) { // 色 i のインデックスを順番に処理
            int a = col[i][j]; // 現在のインデックス
            int b = col[i][(j - 1 + size) % size]; // 循環的に前のインデックスを計算
            ans[a] = s[b]; // 結果文字列のインデックス a に文字列 s のインデックス b の文字を割り当て
        }
    }

    cout << ans; // 結果文字列を出力
    return 0;
}
