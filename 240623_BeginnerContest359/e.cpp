#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N;
    cin >> N;
    vector<ll> H(N+1);
    for(int i=1; i<=N; i++) cin>>H[i];
    H[0] = INF;
    struct strt{
        int w;
        ll sm;
    };
    stack<strt> st;
    strt t;
    t.w = 0;
    t.sm = 0;
    st.push(t);
    for(int i=1; i<=N; i++) {
        while (true) {
            auto s = st.top();
            strt t;
            if (H[s.w] > H[i]) {
                ll ln = i-s.w;
                t.sm = s.sm + (ln*H[i]);
                t.w = i;
                st.push(t);
                cout << t.sm + 1 << " ";
                break;
            } else {
                st.pop();
            }                        
        }
    }
    cout << endl;
    return 0;
}