#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    deque<pair<int, int>> dq;
    int offset = 0;

    for (int i=0;i<q;i++) {
        int a;
        cin >> a;
        if (a == 1) {
            int x;
            cin >> x;
            int cumulative_sum = (dq.empty() ? 0 : dq.back().first) + x;
            dq.push_back({cumulative_sum, x});
        }
        else if(a==2) {
            int y = dq.front().second;
            dq.pop_front();
            offset += y;
        }
        else if(a==3) {
            int y;
            cin >> y;
            cout << dq[y - 1].first - offset << endl;
        }
    }
    return 0;
}
