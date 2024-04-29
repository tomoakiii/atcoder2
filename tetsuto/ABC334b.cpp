#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    int A >> M ;
    cin >> N;
    vector<ll> A(N);
    CC cc;
    for (auto &a: A) {
        cin >> a;
        cc.add(a);
    }
    fenwick_tree<ll> ft(N);
    fenwick_tree<ll> ft2(N);
    ll sm = 0;
    for (int j = 0; j < N; j++){
        ll a = A[j];
        int cca = cc(a);
        ft.add(cca, a);
        ft2.add(cca, 1);
        sm += ft2.sum(0, cca) * a;
        sm -= ft.sum(0, cca);
    }
    cout << sm << endl;
    return 0;
}