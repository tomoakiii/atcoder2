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

class SegTree {
private:    
    int n, sz, trsize;
    struct nd{
        int l;
        int r;
        int c;
        map<char, int> mp;
    };
    vector<nd> tr;
public:
    // tr[n-1] ~ tr[n-1+sz-1] = original vector v
    SegTree(string S) {
        sz = (int)S.size();
        n = 1;
        while(n < sz) n *= 2;
        trsize = 2*n-1;
        tr.resize((size_t)trsize);
        for(int i=0; i<sz; i++) {
            tr[i+n-1].mp[S[i]] = 1;            
        }
        for(int i=0; i<n; i++) tr[i+n-1].l = tr[i+n-1].r = tr[i+n-1].c = i;
        int k=1;
        while ((n-1)/k > 0){
            for(int i=(n-1)/k; i<(trsize-1)/k; i+=2){
                for(auto m: tr[i].mp){
                    tr[i/2].mp[m.first] += m.second;
                }
                for(auto m: tr[i+1].mp){
                    tr[i/2].mp[m.first] += m.second;
                }
            }
            k*=2;
        }
        for(int i=n-2; i>=0; i--) {      
            tr[i].l = tr[i*2+1].l;
            tr[i].r = tr[i*2+2].r;
            tr[i].c = (tr[i].l + tr[i].r)/2;        
        }
    }

    // MinElement(0, start, end);
    // 0 is top of segtree. Start and End are number of original array. End is included in search area
    void count_unique(int ind, int a, int b, map<char,int> &mp){
        if(tr[ind].l == a && tr[ind].r == b){
            auto mp2 = tr[ind].mp;
            mp.merge(mp2);
            return;
        }
        if (tr[ind].c >= a && tr[ind].c < b) {
            count_unique(2*ind+1, a, tr[ind].c, mp);
            count_unique(2*ind+2, tr[ind].c + 1, b, mp);
            return;
        }
        if (tr[ind].c >= b) {
            count_unique(2*ind+1, a, b, mp);
            return;
        }
        count_unique(2*ind+2, a, b, mp);
    }

    void SetVal(int ind, char c){
        int i = ind+n-1;
        auto m = *tr[i].mp.begin();
        char co = m.first;
        if(co == c) return;
        tr[i].mp.clear();
        tr[i].mp[c] = 1;
        while(i>0){
            int ii = (i-1)/2;
            tr[ii].mp[co]--;
            if(tr[ii].mp[co] == 0) tr[ii].mp.erase(co);            
            tr[ii].mp[c]++;
            i = ii;
        }
    }
};

// test case:
// 10 5
// 10 1 6 8 7 2 5 9 3 4

int main(){
    ll N; cin>>N;
    string S; cin>>S;
    SegTree ST(S);
    int Q; cin>>Q;
    while (Q--)
    {
        int t; cin>>t;
        if(t==1) {
            int i; char c; cin>>i>>c;
            i--;
            ST.SetVal(i, c);
        } else {
            int l, r; cin>>l>>r;
            l--,r--;
            map<char,int> mp;
            ST.count_unique(0, l, r, mp);
            cout<<mp.size()<<endl;
        }
    }
    return 0;
}