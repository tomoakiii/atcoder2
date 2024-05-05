#include <bits/stdc++.h>
#include <atcoder/dsu>

using namespace std;
using namespace atcoder;

int main() {
    const int N = 4;
    vector<int> c{30, 40, 10, 20};
    /* C[0], C[1], ... C[N-1] の小さいもの順のインデックスを返す。Cのsortはしない。 */
    /* Ord[0], Ord[1], ... Ord[N-1] は並び替え前のA番目になる */
    /* C = {30, 40, 10, 20} --> {10, 20, 30, 40} になったとしたら、Ord = {2, 3, 0, 1} */
    for (int i: c) {
        cout << i << " ";
    }
    cout << endl;
    vector<int> ord(N);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return c[i] < c[j]; });
    for (int i: ord) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
