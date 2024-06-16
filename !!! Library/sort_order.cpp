#include <bits/stdc++.h>
#include <atcoder/dsu>

#define rep(i,n) for (int i = 0; i < (n); ++i)
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

    /* 値が大きい順に並べて、同値ならインデックス小さいもの勝ちにする */
    rep(i, N){
        cin >> A[i] >> B[i];
    }
    vector<int> ord(N);
    iota(ord.begin(), ord.end(), 0);
    auto func = [&](int l, int r){
        ll lft = A[l];
        ll rgt = A[r];
        if(lft == rgt) {
            return (l < r); // lインデックスの方が小さいのが正解
        } else {
            return (lft > rgt); // lftの方が大きいのが正解
        }                
    };
    sort(ord.begin(), ord.end(), func);
    rep(i, N){
        cout << ord[i] + 1 << " ";
    }
    cout << endl;



    return 0;
}
