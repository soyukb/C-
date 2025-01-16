#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int h, w, y, x;
    cin >> h >> w; // グリッドの高さ h と幅 w を入力
    cin >> y >> x; // スタート位置 (y, x) を入力

    // グリッドと到達距離を格納する2次元配列を作成
    vector<vector<char>> mp(h, vector<char>(w, '.')); // 全てのマスを '.' で初期化
    vector<vector<int>> len(h, vector<int>(w, -1));  // 距離を -1 (未訪問) で初期化

    // BFSのためのキューを用意し、スタート地点を設定
    queue<pair<int, int>> Q;
    Q.push({y, x});
    len[y][x] = 0;       // スタート地点の距離を0に設定
    mp[y][x] = '*';      // スタート地点を '*' でマーク

    // 上下左右の移動を表す方向ベクトル
    int dy[] = {-1, 1, 0, 0};
    int dx[] = {0, 0, -1, 1};

    // 幅優先探索 (BFS) 開始
    while (!Q.empty()) {
        // キューから現在位置を取得
        auto [ny, nx] = Q.front();
        Q.pop();

        // 距離が3に達した場合、それ以上探索しない
        if (len[ny][nx] == 3) continue;

        // 4方向をループして次の移動先を確認
        for (int d = 0; d < 4; ++d) {
            int newY = ny + dy[d];
            int newX = nx + dx[d];

            // グリッドの範囲内で、未訪問のマスの場合
            if (newY >= 0 && newY < h && newX >= 0 && newX < w && mp[newY][newX] == '.') {
                Q.push({newY, newX});                    // 次の探索地点をキューに追加
                len[newY][newX] = len[ny][nx] + 1;      // 距離を更新
                mp[newY][newX] = '*';                   // マスを '*' でマーク
            }
        }
    }

    // 結果の出力 (探索結果を表示)
    for (const auto& row : mp) {
        for (char cell : row) {
            cout << cell;
        }
        cout << '\n';
    }
}