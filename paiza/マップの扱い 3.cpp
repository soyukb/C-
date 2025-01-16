#include<bits/stdc++.h> // すべての標準ライブラリを一括でインクルード
using namespace std;

int main() {
    int h, w, y, x; // グリッドの高さ(h)と幅(w)、操作を開始する座標(y, x)を定義
    cin >> h >> w;  // グリッドのサイズを入力

    vector<string> arr(h); // 文字列のベクトルを用いてグリッドを表現
    for(auto &row : arr) {  // グリッドの各行を入力
        cin >> row;
    }

    cin >> y >> x;  // 開始座標を入力

    // 8方向の移動ベクトルを定義
    vector<pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}, // 上下左右
        {1, 1}, {-1, -1}, {1, -1}, {-1, 1} // 斜め
    };

    // 各方向に探索を行う
    for(const auto &[dy, dx] : directions) {
        int ny = y, nx = x;  // 開始座標を代入
        // グリッドの範囲内でループし続ける
        while(ny >= 0 && ny < h && nx >= 0 && nx < w) {
            // '.' を '#' に、'#' を '.' にトグル（反転）
            arr[ny][nx] = (arr[ny][nx] == '.') ? '#' : '.';
            // 次のセルに移動
            ny += dy;
            nx += dx;
        }
    }

    // 結果を出力
    for(const auto &row : arr) {
        cout << row << "\n";
    }

    return 0;
}
