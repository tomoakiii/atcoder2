#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main() {
    const int N = 4;
    vector<int> c{1,3,3,1};
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

    /* 値が小さい順に並べて、同値ならインデックス小さいもの勝ちにする */
    iota(ord.begin(), ord.end(), 0);
    auto func = [&](int l, int r){
        ll lft = c[l];
        ll rgt = c[r];
        if(lft == rgt) {
            return (l < r); // lインデックスの方が小さいのが正解
        } else {
            return (lft < rgt); // lftの方が小さいのが正解
        }                
    };
    sort(ord.begin(), ord.end(), func);
    rep(i, N){
        cout << ord[i] << " ";
    }
    cout << endl;
    typedef pair<ll, int> pli;
    auto comp = [](pli &a, pli &b){return a.first > b.first;}; // > (<) is smallest (largest) first
    priority_queue<pli, vector<pli>, decltype(comp)> que(comp);
    pli cp;
    rep(i, N) {
        cp.first = c[i];
        cp.second = i;
        que.push(cp);
    }
    while(!que.empty()){
        auto q = que.top();
        que.pop();
        cout << q.second << " ";
    }
    cout << endl;


    return 0;
}
