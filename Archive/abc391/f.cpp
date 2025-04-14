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
    int N, K;
    cin >> N >> K;
    struct abc{ int a, b, c; };
    vector<ll> A(N), B(N), C(N);    
    rep(i,N) cin>>A[i];
    rep(i,N) cin>>B[i];
    rep(i,N) cin>>C[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    auto abbcca = [&](vector<int> in)->ll{
        int a = in[0], b=in[1], c=in[2];
        if(a<0 || b<0 || c<0) return -INF;
        return A[a]*B[b] + B[b]*C[c] + C[c]*A[a];
    };
    vector<int> st = {N-1, N-1, N-1}; // No.1
    vector index(K*5, vector<int>(3));
    int cnt = 0;
    rep(i,3) index[cnt][i] = st[i];    
    typedef pair<ll, int> pli;
    pli p1 = {abbcca(st), 0};
    priority_queue<pli> pq;
    pq.push(p1);
    unordered_map<int, unordered_map<int, unordered_map<int, bool>>> visit;
    ll ans;
    visit[st[0]][st[1]][st[2]];
    while(K--) {
        auto [v, key] = pq.top();
        ans = v;
        pq.pop();
        rep(i, 3) {
            vector in2 = index[key];
            in2[i]--;
            if(in2[i]<0) continue;
            if(visit[in2[0]][in2[1]][in2[2]]) continue;
            visit[in2[0]][in2[1]][in2[2]] = true;
            cnt++;
            rep(i,3) index[cnt][i] = in2[i];            
            pli p2 = {abbcca(in2), cnt};
            pq.push(p2);
        }        
    }
    cout << ans << endl;
    return 0;
}
