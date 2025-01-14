#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int h, w, y, x;
    cin >> h >> w;
    cin >> y >> x;

    vector<vector<char>> mp(h, vector<char>(w, '.'));
    vector<vector<int>> len(h, vector<int>(w, -1));

    queue<pair<int, int>> Q;
    Q.push({y, x});
    len[y][x] = 0;
    mp[y][x] = '*';

    // 上下左右の方向ベクトル
    int dy[] = {-1, 1, 0, 0};
    int dx[] = {0, 0, -1, 1};

    while (!Q.empty()) {
        auto [ny, nx] = Q.front();
        Q.pop();

        if (len[ny][nx] == 3) continue;

        for (int d = 0; d < 4; ++d) {
            int newY = ny + dy[d];
            int newX = nx + dx[d];

            if (newY >= 0 && newY < h && newX >= 0 && newX < w && mp[newY][newX] == '.') {
                Q.push({newY, newX});
                len[newY][newX] = len[ny][nx] + 1;
                mp[newY][newX] = '*';
            }
        }
    }

    // 結果の出力
    for (const auto& row : mp) {
        for (char cell : row) {
            cout << cell;
        }
        cout << '\n';
    }
}