#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){   
    int a,b; 
    cin >> a >> b;
    if (b-a==1 && a%3!=0){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}