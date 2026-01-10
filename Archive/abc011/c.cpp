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
    ll N;
    cin >> N;
    vector<int> NG(3);
    cin>>NG[0]>>NG[1]>>NG[2];
    sort(NG.begin(),NG.end());
    if(NG[0]==N || NG[1]==N ||  N==NG[2]) {
        cout<< "NO"<<endl;
        return 0;
    }
    set<int> st;
    st.insert(N);
    rep(i,100) {
        set<int> st2;
        for(auto s : st) {
            for(int k=1; k<=3; k++) {
                bool flg = true;
                for(auto n: NG) if(s-k == n) flg = false;
                if(flg && s-k>=0) st2.insert(s-k);
            }
        }
        swap(st, st2);
        if(st.contains(0)) {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}