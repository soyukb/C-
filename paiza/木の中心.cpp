#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N; // 頂点数を入力

    vector<vector<int>> g(N); // グラフを隣接リストで表現
    vector<int> degree(N, 0); // 各頂点の次数（接続されている辺の数）を管理

    // 辺の入力とグラフの構築
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--; // 1-indexed から 0-indexed に変換
        g[a].push_back(b);
        g[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }

    queue<int> leaves; // 葉（次数が1の頂点）を管理するキュー

    // 最初の葉をキューに追加
    for (int i = 0; i < N; ++i) {
        if (degree[i] == 1) {
            leaves.push(i);
        }
    }

    int remaining_vertices = N; // 残りの頂点数

    // 木の中心を求めるために、葉から順に削除
    while (remaining_vertices > 2) {
        int leaf_count = leaves.size(); // 現在の葉の数
        remaining_vertices -= leaf_count; // 残りの頂点数から葉の数を引く

        for (int i = 0; i < leaf_count; ++i) {
            int leaf = leaves.front();
            leaves.pop();
            for (int neighbor : g[leaf]) { // 葉と隣接する頂点をチェック
                degree[neighbor]--; // 隣接頂点の次数を減らす
                if (degree[neighbor] == 1) { // 新たに葉となった頂点をキューに追加
                    leaves.push(neighbor);
                }
            }
        }
    }

    // 結果の出力（木の中心となる頂点は1つまたは2つ）
    while (!leaves.empty()) {
        cout << leaves.front() + 1 << endl; // 1-indexed で出力
        leaves.pop();
    }
    return 0;
}
