#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    rep (i, N){
        cin >> A[i] >> B[i];
    }
    vector<pair<int, int>> pr;
    vector tr(N, vector<int>{});
    rep(i, N){
        for(int j=i+1; j<N; j++){
            if(A[i] == A[j] || B[i] == B[j]){
                pr.push_back({i, j});
                tr[i].push_back(j);
                tr[j].push_back(i);
            }
        }
    }
    int ps = pr.size();
    unordered_map<unsigned long long, bool> memo;

    auto func = [&](auto func, unsigned long long cd, bool t)->bool{
        rep(i, ps) {
            auto cd2 = cd;
            if (((cd2>>pr[i].first) & 1)==1 || ((cd2>>pr[i].second) & 1)==1){
                continue;
            } else {
                cd2 |= (1<<pr[i].first);
                cd2 |= (1<<pr[i].second);
                bool r;
                if (memo.count(cd2) == 0){
                    r = func(func, cd2, !t);
                    memo[cd2] = r;
                } else {
                    r = memo[cd2];
                }
                if (r == t){
                    return r;
                } else {
                    continue;
                }
            }
                    
        }
        return !t;

    };

    if(!func(func, 0, false)){
        cout << "Takahashi" << endl;
    } else {
        cout << "Aoki" << endl;
    }
    
    return 0;
}