#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <numeric>

#define endl '\n'

using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    int n;

    void update(int node, int start, int end, int idx, int val) {
        if (idx < start || idx > end) return;

        if (start == end) {
            tree[node] = val;
            return;
        }

        int mid = (start + end) / 2;
        update(node * 2, start, mid, idx, val);
        update(node * 2 + 1, mid + 1, end, idx, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    // k번째로 남아있는 사람의 인덱스 찾기
    int query(int node, int start, int end, int k) {
        if (start == end) return start;

        int mid = (start + end) / 2;
        int leftCount = tree[node * 2];

        if (k <= leftCount) {
            return query(node * 2, start, mid, k);
        }
        else {
            return query(node * 2 + 1, mid + 1, end, k - leftCount);
        }
    }

public:
    SegmentTree(int size) : n(size) {
        tree.resize(4 * n, 0);
        // 초기화: 모든 위치에 사람이 있음
        for (int i = 1; i <= n; i++) {
            update(1, 1, n, i, 1);
        }
    }

    void remove(int idx) {
        update(1, 1, n, idx, 0);
    }

    int findKth(int k) {
        return query(1, 1, n, k);
    }

    int getCount() {
        return tree[1];
    }
};

int solution(int n, int k) {
    SegmentTree st(n);
    int currentPos = 0;

    while (st.getCount() > 1) {
        int remaining = st.getCount();
        // 다음 제거할 위치 계산 (원형 처리)
        currentPos = (currentPos + k - 1) % remaining + 1;

        // currentPos번째 사람 찾기
        int targetIdx = st.findKth(currentPos);

        // 제거
        st.remove(targetIdx);

        // 다음 시작 위치
        currentPos = currentPos % st.getCount();
        if (currentPos == 0) currentPos = st.getCount();
    }

    return st.findKth(1);
}

int main()
{


	int ret = solution(5, 2);
	cout << ret;
}

