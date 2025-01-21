#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFSを使ってグラフが連結かどうかを確認する関数
bool isConnected(int n, const vector<vector<int>>& adjList) {
    vector<bool> visited(n, false);  // 各頂点の訪問状況を記録
    queue<int> q;

    // 最初の頂点（0番）をキューに追加し、訪問済みにする
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // 隣接する頂点をチェック
        for (int neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    // すべての頂点が訪問済みなら連結
    for (bool isVisited : visited) {
        if (!isVisited) return false;
    }

    return true;
}

int main() {
    // グラフの定義（隣接リスト形式）
    // 頂点数
    int n = 5;
    vector<vector<int>> adjList = {
        {1, 2},    // 頂点0に隣接する頂点
        {0, 3, 4}, // 頂点1に隣接する頂点
        {0},       // 頂点2に隣接する頂点
        {1},       // 頂点3に隣接する頂点
        {1}        // 頂点4に隣接する頂点
    };

    // グラフが連結かどうかを判定
    if (isConnected(n, adjList)) {
        cout << "The graph is connected." << endl;
    } else {
        cout << "The graph is not connected." << endl;
    }

    return 0;
}
