#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
typedef pair<int, int> pii;
int main()
{    
    string S;
    cin >> S;
    string NG = "aiueo";
    for(auto s:S){
        bool flg = false;
        for (auto n:NG){            
            if (s == n) {                
                flg = true;
            }            
        }
        if (!flg) cout << s;
    }
    return 0;
}