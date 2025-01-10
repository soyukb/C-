#include <iostream>

using namespace std;

int main() {
    int h, w, y, x;
    // グリッドの高さh、幅w、座標(y, x)の入力
    cin >> h >> w;
    cin >> y >> x;

    // 2次元グリッドを走査するための二重ループ
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            bool able_to_reach = false; // マークをつけるかどうかを判定するフラグ

            // 同じ行にあり、左または右隣のマスの場合
            if (i == y) {
                if (0 <= j && j == x - 1) {  // 左隣
                    able_to_reach = true;
                }
                if (j < w && j == x + 1) {   // 右隣
                    able_to_reach = true;
                }
            }

            // 同じ列にあり、上または下隣のマスの場合
            if (j == x) {
                if (0 <= i && i == y - 1) {  // 上隣
                    able_to_reach = true;
                }
                if (i < h && i == y + 1) {   // 下隣
                    able_to_reach = true;
                }
            }

            // 自分自身のマスの場合
            if (i == y && j == x) {
                able_to_reach = true;
            }

            // 判定に基づいて'*'または'.'を出力
            if (able_to_reach) {
                cout << '*';
            } else {
                cout << '.';
            }
        }
        cout << endl; // 次の行に移動
    }
}
