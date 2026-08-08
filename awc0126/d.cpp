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
    ll N; cin>>N;
    string Ss,Ts;
    cin >> Ss >> Ts;
    map<string,ll> mp;
    mp[Ss]=0;
    queue<string> q;
    q.push(Ss);
    while(!q.empty()){
        string now=q.front();
        q.pop();
        auto func=[&](string x)->bool{
            if(mp.contains(x)) return false;
            mp[x]=mp[now]+1;
            q.push(x);
            return true;
        };
        string a=now.substr(0, 1);
        string b=now.substr(1, N-1);
        func(b+a);
        string c=now.substr(N-1, 1);
        string d=now.substr(0, N-1);
        func(c+d);
        for(int k=1;k<=N;k++){
            if(N%k!=0) continue;
            int p=N/k;
            string e=now.substr(0, k);
            string f="";
            rep(i,p){
                f+=e;   
            }
            func(f);
        }
    }
    if(!mp.contains(Ts)) cout<<-1<<endl;
    else cout<<mp[Ts]<<endl;
    return 0;
}