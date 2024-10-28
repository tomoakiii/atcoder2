#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> visit(N, -1);
    for(int i=0; i<N;i++) {        
        cin >> A[i];
        A[i]--;
    }
    vector<ll> tmp(N);
    bool end = false;
    auto func = [&](auto func, ll ind, ll cnt)->void{
        ll nx = A[ind];
        tmp[cnt] = ind;
        visit[ind] = cnt;        
        if (visit[nx] != -1) {
            ll st = nx;
            ll nnx = st;
            vector<ll> ttp;       
            while(true){
                ttp.push_back(nnx);
                nnx = A[nnx];
                if (nnx == st) break;
            }
            cout << ttp.size() << endl;
            for (auto t:ttp) cout << t+1 << " ";
            cout << endl;
            return;
        }
        func(func, nx, cnt+1);
    };
    func(func, 0, 0);
    return 0;
}