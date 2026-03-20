#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    auto countK = [&](ll thr)->ll{
        int r=0;
        multiset<ll> st;
        ll cnt = 0;
        st.insert(A[0]);
        int l=0;
        auto get = [&]()->ll{
            if(st.empty()) return 0;
            if(st.size() <= 1) return 0;
            auto it = st.end();
            it--;
            return *it - *st.begin();
        };

        rep(l,N) {
            while(r < N) {
                auto k = get();
                if(k <= thr) {
                    r++;
                    if(r<N) st.insert(A[r]);
                } else {
                    break;
                }
            }
            //cerr<< "**" << r << " " << l << endl;
            cnt+=r-l;
            st.erase(st.find(A[l]));
        }
        return cnt;
    };
    ll q = (K==0)?0:countK(K-1);
    ll p = countK(K);

    cerr << p << " " << q << endl;
    cout << p - q << endl;
    return 0;
}