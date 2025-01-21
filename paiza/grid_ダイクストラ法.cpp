#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// 無限大を表す定数
const int INF = numeric_limits<int>::max();

// 移動方向を表す配列（上下左右）
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

// ダイクストラ法で最小コストを求める関数
int findMinCost(const vector<vector<int>>& grid, int h, int w) {
    // 各マスの最小コストを記録する配列
    vector<vector<int>> cost(h, vector<int>(w, INF));
    cost[0][0] = grid[0][0]; // スタート地点のコストを初期化

    // 優先度付きキュー（最小コストを優先して取り出す仕組み）
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({cost[0][0], {0, 0}}); // スタート地点をキューに追加

    // キューが空になるまで処理を繰り返す
    while (!pq.empty()) {
        // 現在のコストと位置を取得
        int current_cost = pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();

        // 記録されているコストより大きければスキップ
        if (current_cost > cost[y][x]) continue;

        // 上下左右の4方向を探索
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 範囲外の座標は無視
            if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;

            // 次のマスのコストを計算
            int new_cost = current_cost + grid[ny][nx];

            // コストが小さければ更新し、次の位置をキューに追加
            if (new_cost < cost[ny][nx]) {
                cost[ny][nx] = new_cost;
                pq.push({new_cost, {ny, nx}});
            }
        }
    }

    // ゴール地点の最小コストを返す
    return cost[h - 1][w - 1];
}

int main() {
    // グリッドのサイズを入力
    int h, w;
    cin >> h >> w;

    // グリッドの値を入力
    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }

    // ダイクストラ法を使って最小コストを計算
    int result = findMinCost(grid, h, w);

    // 結果を出力
    cout << result << endl;

    return 0;
}
