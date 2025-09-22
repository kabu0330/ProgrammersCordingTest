#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 아이템 정보를 담을 구조체
struct Item {
    int w, v;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    // 이진 분할을 통해 생성된 새 아이템들을 저장할 벡터
    vector<Item> items;

    for (int i = 0; i < n; ++i) {
        int w, v, c; // 무게(w), 가치(v), 수량(c)
        cin >> w >> v >> c;

        // 이진 분할 (Binary Splitting)
        for (int j = 1; c > 0; j *= 2) {
            int count = min(j, c);
            items.push_back({ w * count, v * count });
            c -= count;
        }
    }

    // --- 이제부터는 일반적인 0/1 배낭 문제와 동일 ---
    vector<int> dp(k + 1, 0);

    for (const auto& item : items) {
        for (int j = k; j >= item.w; --j) {
            dp[j] = max(dp[j], dp[j - item.w] + item.v);
        }
    }

    cout << dp[k] << endl;

    return 0;
}