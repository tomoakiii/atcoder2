#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    int N;
    ll K;
    cin >> N >> K;
    vector<ll> a(N), b(N);
    ll sm = 0;
    rep(i, N){
        cin >> a[i] >> b[i];
        sm += b[i];
    }
    if (sm <= K){
        cout << 1 << endl;
        return 0;
    }

    vector<int> ord(N);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] < a[j]; });    

    rep(i, N){
        int p = ord[i];
        sm -= b[p];
        if (sm <= K){
            cout << a[p] + 1 << endl;
            return 0;
        }
    }
    return 0;
}