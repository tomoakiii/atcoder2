#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    int N, K;
    cin >> N >> K;    
    vector<int> R(N);
    int alen = 1;
    rep(i,N) {
        cin>>R[i];        
    }
    //vetor<vector<int>> ans{};

    auto f = [&](auto f, int cur, int sum, vector<int> tans)->void{
        for(int k=1; k<=R[cur]; k++){
            int sum2 = sum+k;
            tans[cur] = k;
            if(cur == N-1) {
                if (sum2%K == 0) {
                    rep(i, N) cout<<tans[i]<<" ";
                    cout<<endl;
                }
            }
            else {                
                f(f, cur+1, sum2, tans);
            }
        }
    };
    vector<int> t(N, 0);
    f(f, 0, 0, t);

    return 0;
}