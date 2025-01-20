#include <iostream>
#include <stack>
#include <tuple> // tupleを使用

using namespace std;

int main() {
    int h, w, startY, startX;
    cin >> h >> w >> startY >> startX;

    // スタック: (現在のステップ数, y座標, x座標)
    stack<tuple<int, int, int>> s;
    s.push({0, startY, startX});
    
    while (!s.empty()) {
        // 現在の状態を取得
        auto [steps, y, x] = s.top();
        s.pop();
        
        // ステップ数が3の場合、座標を出力
        if (steps == 3) {
            cout << y << " " << x << endl;
            continue;
        }

        // 移動方向（上, 右, 下, 左）
        const int dy[] = {-1, 0, 1, 0};
        const int dx[] = {0, 1, 0, -1};

        // 次の候補をスタックに追加
        for (int i = 0; i < 4; ++i) {
            int newY = y + dy[i];
            int newX = x + dx[i];
            // 移動先が範囲内であれば追加
            if (0 <= newY && newY < h && 0 <= newX && newX < w) {
                s.push({steps + 1, newY, newX});
            }
        }
    }

    return 0;
}
