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
    ll N, M;
    cin >> N >> M;
    vector S(N+1, vector<ll>{});
    vector T(N+1, vector<ll>{});
    multiset<ll> st, st2;
    map<pair<ll,ll>, int> mp;
    st.insert(INF);
    st2.insert(INF);
    rep(i,M) {
        int s, t;
        cin>>s>>t;
        S[s].push_back(t);
        T[t].push_back(s);
        st.insert(t);
        st2.insert(-s);
        mp[{s,t}]++;
    }
    vector<ll> mnsearch(N+1);
    vector<ll> mxsearch(N+1);

    rep(i,N+1) {
        mnsearch[i] = *st.begin();
        for(auto t:S[i]) st.erase(st.find(t));
    }
    for(int i=N; i>=0; i--) {
        ll p = *st2.begin();
        mxsearch[i] = (-1) * p;
        for(auto s:T[i]) st2.erase(st2.find(-s));
    }
    rep(i,N+1){
        sort(S[i].begin(), S[i].end());
        sort(T[i].begin(), T[i].end());
    }
    int Q; cin>>Q;
    while(Q--){
        int s, t;
        cin>>s>>t;

        if(S[s].empty() || T[t].empty()) {
            cout<<"No"<<endl;
            continue;
        }

        if(mp.contains({s,t})) {
            if(mp[{s,t}] > 1) {
                cout<<"Yes"<<endl;
                continue;
            } else {
                if(mnsearch[s] < t) {
                    cout<<"Yes"<<endl;
                    continue;
                } else if (mxsearch[t] > s) {
                    cout<<"Yes"<<endl;
                    continue;
                } else {
                    cout << "No" << endl;
                    continue;
                }
            }
        }


        ll send, tfirst;
        {
            int sz = S[s].size();
            auto it = lower_bound(S[s].begin(), S[s].end(), t) - S[s].begin();
            if(it == 0) {
                cout<<"No"<<endl;
                continue;
            }
            send = S[s][it-1];
        }

        {
            int sz = T[t].size();
            auto it = lower_bound(T[t].begin(), T[t].end(), s) - T[t].begin();
            if(it == sz) {
                cout<<"No"<<endl;
                continue;
            }
            tfirst = T[t][it];
        }
        if(tfirst <= send+1)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}