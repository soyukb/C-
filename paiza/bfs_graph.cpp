#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
  // グラフの頂点数 `n` と始点のインデックス `x` を入力
  int n, x;
  cin >> n >> x;

  // グラフを表す隣接リスト `graph` と各頂点の距離を記録するリスト `len`
  vector<vector<int>> graph(n + 1); // 1-based index のため n+1
  vector<int> len(n + 1, -1);       // 初期値は -1 (未訪問を示す)

  // 辺の情報を入力し、無向グラフを構築
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);  // 頂点 a に隣接する頂点 b を追加
    graph[b].push_back(a);  // 頂点 b に隣接する頂点 a を追加
  }

  // 探索用のキュー `Q` と、距離3の頂点を格納する集合 `ans`
  queue<int> Q;
  set<int> ans;

  // 始点をキューに追加し、距離を 0 に設定
  Q.push(x);
  len[x] = 0;

  // 幅優先探索 (BFS)
  while (!Q.empty()) {
    int now = Q.front();  // 現在の頂点を取得
    Q.pop();              // キューから削除

    // 現在の頂点の距離が 3 なら、集合に追加して次の探索をスキップ
    if (len[now] == 3) {
      ans.insert(now);  // 距離3の頂点を記録
      continue;         // 探索終了
    }

    // 現在の頂点に隣接する頂点をすべて調べる
    for (int next : graph[now]) {
      if (len[next] == -1) {  // 未訪問の頂点だけを処理
        len[next] = len[now] + 1;  // 現在の距離に +1
        Q.push(next);             // 次の探索用にキューに追加

        // 距離が 3 になった場合、この時点で記録
        if (len[next] == 3) {
          ans.insert(next);
        }
      }
    }
  }

  // 距離3の頂点を 1-based index で出力
  for (int node : ans) {
    cout << node << endl;
  }
}
