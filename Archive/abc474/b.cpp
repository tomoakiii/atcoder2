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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    ll N2=N;
    vector<bool> oc(101);
    while(N){
        set<int> st;
        rep(i,10) {
            if(N==0) break;
            int p; cin>>p;
            for(int j=p+1;j<=100;j++) {
                if(oc[j]) {
                    cout<<"No"<<endl;
                    return 0;
                }
            }
            N--;
            st.insert(p);
        }
        for(int p:st) oc[p] = true;
    }
    cout<<"Yes"<<endl;
    return 0;
}