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

struct Trie{
    ll ans = 0;
    int M = 'b'-'a'+1;
    vector<vector<int>> to;

    // how many times each node is visited?
    vector<ll> val;
    Trie(){
        to.push_back(vector<int>(M,-1));
        val.push_back(0);
    }

    int add(const string &s, ll x = 1) {
        int v = 0;
        val[v]+=x;
        for(char c: s) {
            int nc = c-'a';
            if(to[v][nc] == -1) {
                int u = to.size();
                to[v][nc] = u;
                to.push_back(vector<int>(M,-1));
                val.push_back(0);
            }
            v = to[v][nc];
            val[v]+=x;
        }
        return v;
    }

    // flg=false : ealier than me
    // flg=true : same or earlier than me
    ll count_earlier(string s, bool flg = false){
        int v = 0;
        ll ret = 0;
        for(char c:s){
            int nc = c-'a';
            rep(i, nc){
                if(to[v][i] == -1) continue;
                ret += val[to[v][i]];
            }
            v = to[v][nc];
        }
        if(!flg) return ret;
        ret += val[v];
        return ret;
    }


    // flg=false : later than me
    // flg=true : same or later than me
    ll count_later(string s, bool flg = false){
        int v = 0;
        ll ret = 0;
        for(char c:s){
            int nc = c-'a';
            for(int i=nc+1;nc<M;i++){
                if(to[v][i] == -1) continue;
                ret += val[to[v][i]];
            }
            v = to[v][nc];
        }
        if(!flg) return ret;
        ret += val[v];
        return ret;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,M,K;
    cin >> N >> M >> K;
    string T; cin>>T;
    vector<string> S(N);
    Trie Tr;
    rep(i,N){
        string s; cin>>s;
        rep(j,K){
            if(s[j]==T[j]) {
                s[j] = 'a';
            } else {
                s[j] = 'b';
            }
        }
        Tr.add(s);
        S[i]=s;
    }

    int Q; cin>>Q;
    rep(q,Q){
        int i,j; cin>>i>>j;
        i--,j--;
        Tr.add(S[i], -1);
        S[i][j] = (S[i][j] == 'a')?'b':'a';
        Tr.add(S[i], 1);
        if(S[i] == string(K,'b')) cout<<"No"<<endl;
        else if(Tr.count_earlier(S[i],true) <= M) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}