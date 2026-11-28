//#include <atcoder/all>
//using namespace atcoder;
#include <bits/stdc++.h>
using namespace std;
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
    deque<ll> AA(N), BB(N);
    rep(i,N) cin>>AA[i];
    rep(i,N) cin>>BB[i];
    auto func = [&](bool xxx, deque<ll> A, deque<ll> B)->bool{
        int flg=0;
        while(!A.empty()){
            if(flg==0){
                if(A[0] == B[0]) {
                    A.pop_front();
                    B.pop_front();
                } else if (A.back() == B.back()){
                    A.pop_back();
                    B.pop_back();
                } else {
                    flg = 1;
                }
            } else if (flg == 1){
                if(xxx){
                    if(A.back() == B.front()){
                        A.pop_back(), B.pop_front();
                        flg = 2;
                    } else {
                        return false;
                    }
                } else {
                    if (A.front() == B.back()){
                        A.pop_front(), B.pop_back();
                        flg = 2;
                    }  else {
                        return false;
                    }
                }

            } else {
                if(A.front() == B.front()) {
                    A.pop_front(), B.pop_front();
                } else {
                    return false;
                }
            }
        }
        return true;
    };

    if(func(true, AA, BB)) cout<<"Yes"<<endl;
    else if(func(false, AA, BB)) cout<<"Yes"<<endl;
    else cout << "No" << endl;
    return 0;
}