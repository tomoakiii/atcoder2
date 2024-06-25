#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N, 0);
    rep(i, N) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    auto B = A;
    ll sm = 0;
    bool oK = false;
    int lind = 0;
    vector<bool> ind(N, 0);
    vector<ll> out;
    rep(i, N){
        if (!oK) {
            sm += A[0];
            out.push_back(A[0]);
            A.erase(A.begin());            
            if (sm >= K) oK = true;
        } else {
            ll tgt = K - sm;
            auto lb = lower_bound(A.begin(), A.end(), tgt);
            if (lb == A.end()) {
                cout << "No" << endl;
                return 0;
            }
            out.push_back(*lb);
            A.erase(lb);
        }       
    }
    if(!oK) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    for (auto o: out) cout << o << " ";
    cout << endl;
    return 0;
}