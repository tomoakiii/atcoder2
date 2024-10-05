#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{    
    int N;
    cin >> N;
    vector P(N, vector<int>{});
    vector<bool> visit(N, false);
    vector<int> ans;

    for(int i=0; i<N; i++){
        int c;
        cin >> c;
        for (int j=0; j<c; j++){
            int p;            
            cin >> p;
            p--;
            P[i].push_back(p);
        }
    }
    auto func = [&](auto func, int x) -> void{
        visit[x] = true;
        for (auto p: P[x]){
            if (!visit[p]){
                func(func, p);
            }
        }
        ans.push_back(x);
    };
    func(func, 0);
    for (auto a:ans){
        if(a != 0){
            cout << a+1 << " ";
        }        
    }
    cout << endl;
    return 0;
}