//https://atcoder.jp/contests/awc0076/tasks/awc0076_c

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
    vector<string> A(N);
    rep(i,N)cin>>A[i];
    map<string,ll> c2l;
    c2l["+"]=0;
    c2l["*"]=1;
    c2l["-"]=2;
    c2l["/"]=3;
    map<ll,string> l2c;
    l2c[0]="+";
    l2c[1]="*";
    l2c[2]="-";
    l2c[3]="/";
    auto func=[&]()->ll{
        if(A.size()==1){
            return stoi(A[0]);
        }
        vector<vector<ll>> st;
        ll p;
        for(auto c:A){
            if(c=="+" || c=="-" || c=="*" || c=="/"){
                p=c2l[c];
                st.push_back(vector<ll>(1,p));
            }else{
                ll p=stoi(c);
                int id=st.size()-1;
                st[id].push_back(p);
                while(!st.empty() && st[id].size()==3){
                    ll q;
                    if(st[id][0]==0){
                        q=st[id][1]+st[id][2];
                    }else if(st[id][0]==1){
                        q=st[id][1]*st[id][2];
                    }else if(st[id][0]==2){
                        q=st[id][1]-st[id][2];
                    }else{
                        q=st[id][1]/st[id][2];
                    }
                    st.pop_back();
                    id--;
                    if(st.empty()){
                        return q;
                    }
                    st[id].push_back(q);
                }
            }
        }
        return -1;
    };
    cout << func() << endl;
    int K; cin>>K;
    rep(i,K){
        int j; cin>>j; j--;
        string c=A[j];
        ll p=c2l[c];
        p+=2;
        p%=4;
        A[j]=l2c[p];
    }
    cout<<func()<<endl;

    return 0;
}