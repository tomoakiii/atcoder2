#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N,a;
    cin >> N;    
    vector<ll> A(N), B(N);
    int ind = 0;
    rep(i,N) cin>>A[i];
    rep(i,N) cin>>B[i];
    int Q, indQ = 0;
    cin >> Q;
    unordered_set<ll> visitA, visitB;
    vector<int> sA(N), sB(N);
    vector<bool> ans(N+1);
    deque<ll> AA, BB;
    rep(i,N) {
        if(!visitA.contains(A[i])) {
            visitA.insert(A[i]);
            AA.push_back(A[i]);
        }
        sA[i] = visitA.size();  
    }
    rep(i,N) {
        if(!visitB.contains(B[i])) {
            visitB.insert(B[i]);
            BB.push_back(B[i]);
        }
        sB[i] = visitB.size();
    }
    unordered_set<ll> stA, stB;
    visitA.clear();
    for(auto sa: AA) {
        visitA.insert(sa);
        if(stB.contains(sa)) stB.erase(sa);
        else stA.insert(sa);
        while(stA.size() > stB.size()) {
            if(BB.empty()) break;
            ll sb = BB.front();
            BB.pop_front();
            if(stA.contains(sb)) stA.erase(sb);
            else stB.insert(sb);
        }
        ans[visitA.size()] = (stA.size() == 0 && stB.size() == 0);
    }

    rep(i,Q) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if(sA[x] != sB[y])  cout<<"No"<<endl;
        else if(ans[sA[x]]) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
} 
