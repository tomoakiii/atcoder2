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
        bool eq=false;
        int a,b;
    };
    vector<nd> tr;
public:
    // tr[n-1] ~ tr[n-1+sz-1] = original vector v
    SegTree(string v) {
        sz = (int)v.size();
        n = 1;
        while(n < sz) n *= 2;
        trsize = 2*n-1;
        tr.resize((size_t)trsize);
        for(int i=0; i<sz; i++) {
            tr[i+n-1].a = v[i]=='1';
            tr[i+n-1].b = v[i]=='0';
        }
        for(int i=0; i<n; i++) tr[i+n-1].l = tr[i+n-1].r = tr[i+n-1].c = i;
        int k=1;
        while ((n-1)/k > 0){
            for(int i=(n-1)/k; i<(trsize-1)/k; i+=2){
                tr[i/2].a = tr[i].a + tr[i+1].a;
                tr[i/2].b = tr[i].b + tr[i+1].b;
                tr[i/2].eq = tr[i/2].a == tr[i/2].b;
            }
            k*=2;
        }
        for(int i=n-2; i>=0; i--) {
            tr[i].l = tr[i*2+1].l;
            tr[i].r = tr[i*2+2].r;
            tr[i].c = (tr[i].l + tr[i].r)/2;
        }
    }

    ll st, ed;
    ll sto, edo;
    ll ca=0,cb=0;
    ll ret;
    ll count(){
        ret = 0;
        for(auto x:tr) if(x.eq) ret++;
        return ret;
    }

    void upd(int i2){
        while(i2>0){
            int ii = (i2-1)/2;
            tr[ii].a = tr[ii*2+1].a + tr[ii*2+2].a;
            tr[ii].b = tr[ii*2+1].b + tr[ii*2+2].b;
            bool old = tr[ii].eq;
            tr[ii].eq = tr[ii].a == tr[ii].b;
            if(tr[ii].eq && !old) ret++;
            else if(!tr[ii].eq && old) ret--;
            i2 = ii;
        }
    }

    ll init(int K, int ind) {
        int i = ind+n-1;
        int j = i+K-1;
        st=i; sto=ind;
        ed=j; edo=ind+K-1;
        vector<nd> st(K);
        int id=0;
        for(int x=i;x<=j;x++){
            if(tr[x].a==1) ca++;
            else cb++;
            st[id++]=tr[x];
        }
        for(int x=i;x<i+cb;x++){
            tr[x].a=0;
            tr[x].b=1;
        }
        for(int x=i+cb;x<=j;x++){
            tr[x].a=1;
            tr[x].b=0;
        }

        for(int x=i;x<=j;x++){
            int i2=x;
            upd(i2);
        }

        ret=0;
        for(auto x:tr) if(x.eq) ret++;
        return ret;
    }


    ll slide(string &S){
        if(S[sto] == '1'){
            tr[st].a = 1;
            tr[st].b = 0;
            ca--;
        } else {
            tr[st].a = 0;
            tr[st].b = 1;
            cb--;
        }
        upd(st);
        ed++, edo++;
        st++, sto++;
        if(ed>=trsize) return -1;
        tr[ed].a = 1; tr[ed].b = 0;
        upd(ed);
        if(S[edo] == '1'){
            ca++;
        } else {
            cb++;
        }
        for(int x=st+cb-2; x<=st+cb+2; x++){
            if(x<st || x>ed) continue;
            if(x < st+cb) {
                tr[x].a = 0; tr[x].b = 1;
            } else {
                tr[x].a = 1; tr[x].b = 0;
            }
            upd(x);
        }
        upd(ed);
        return ret;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,K; string S;
    cin >> N >> K >> S;
    SegTree ST(S);
    ll M=1<<N;
    ll ans=ST.count();
    chmax(ans, ST.init(K,0));
    while(true){
        ll x = ST.slide(S);
        if(x==-1) break;
        chmax(ans,x);
    }
    cout<<ans<<endl;
    return 0;
}