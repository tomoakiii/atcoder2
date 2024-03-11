#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;

int main () {
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    ll suma = 0;
    for (auto &a:A){
        cin>>a;
        suma+=a;
    }
    sort(A.begin(), A.end());
    map<ll, ll> ans;
    ans[0] = suma;
    vector<ll> X(Q);
    for (auto &x:X) cin >> x;
    auto xs = X;
    sort(xs.begin(), xs.end());
    auto prevans = ans[0];
    ll prevkey = 0;
    int lastsumidx = 0;
    for (int i=0; i<Q; i++){
        auto it = lower_bound(A.begin(), A.end(), xs[i]);
        int idx_lower = distance(A.begin(), it); // a[idx_lwer] >= key
        auto tans = prevans - (xs[i] - prevkey) * (N - idx_lower);
        tans += (xs[i] - prevkey) * (lastsumidx);
        for (int j = lastsumidx; j < idx_lower; j++) {
            tans -= A[j] - prevkey;
            tans += (xs[i] - A[j]);
        }
        lastsumidx = idx_lower;
        ans[xs[i]] = tans;
        prevans = tans;
        prevkey = xs[i];
    }
    for (auto x:X) cout << ans[x] << endl;
    return 0;
}

