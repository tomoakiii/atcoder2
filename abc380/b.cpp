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
    string S;
    cin >> S;
    vector<int> A{};
    reverse(S.begin(), S.end());
    int ind;
    for(char c:S) {
        if(c == '|'){            
            A.push_back(0);
            ind = A.size() - 1;
        } else {
            A[ind]++;
        }
    }
    A.pop_back();
    reverse(A.begin(), A.end());
    for(auto a : A) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}