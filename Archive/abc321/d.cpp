#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;


int main(){
    int N, M;
    ll P;
    cin >> N >> M >> P;
    vector<ll> A(N), B(M);
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=0; i<M; i++) cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    fenwick_tree<ll> ft(N);
    for(int i=0; i<N; i++) ft.add(i, A[i]);

    ll sum = 0;
    for(auto b: B){
        int ub = upper_bound(A.begin(), A.end(), P-b) - A.begin();
        sum += (b*ub + ft.sum(0, ub));
        sum += (N-ub) * P;
    }
    cout << sum << endl;
    return 0;
}