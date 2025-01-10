#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int H, W, y, x; // グリッドの高さ、幅、および座標 (y, x) の宣言
    int move[2] = {-1, 1}; // 上下左右の移動量を表す配列
    cin >> H >> W; // グリッドサイズの入力
    vector<string> S(H); // 文字列ベクトル S を作成し、各行を格納

    // グリッドの各行を入力
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }

    cin >> y >> x; // 開始位置の座標を入力

    // 指定座標のセルの反転
    if (S[y][x] == '.') {
        S[y][x] = '#';
    } else {
        S[y][x] = '.';
    }

    // 上下左右のセルの反転
    for (int i = 0; i < 2; i++) {
        // 上下のセルの反転
        if (0 <= y + move[i] && y + move[i] < H) {
            if (S[y + move[i]][x] == '.') {
                S[y + move[i]][x] = '#';
            } else {
                S[y + move[i]][x] = '.';
            }
        }
        // 左右のセルの反転
        if (0 <= x + move[i] && x + move[i] < W) {
            if (S[y][x + move[i]] == '.') {
                S[y][x + move[i]] = '#';
            } else {
                S[y][x + move[i]] = '.';
            }
        }
    }

    // 結果のグリッドを出力
    for (auto val : S) {
        cout << val << endl;
    }
}
