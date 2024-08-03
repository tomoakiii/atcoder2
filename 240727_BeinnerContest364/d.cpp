#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, Q;
    cin >> N >> Q;    
    vector<ll> A(N);    
    rep(i, N) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    while(Q--) {
        ll b;
        int k;
        cin >> b >> k;     
        auto binary_search = [&]()->ll {            
            int left = min(b, A[0]), right = max(b, A[A.size()-1]);
            while (right >= left) {                
                int mid = left + (right - left) / 2;
                auto it = lower_bound(A.begin(), A.end(), b - mid);
                auto bl1 = distance(A.begin(), it);                            
                int bl2;                
                it = upper_bound(A.begin(), A.end(), b - mid);
                bl2 = distance(A.begin(), it) - 1;
            
                it = lower_bound(A.begin(), A.end(), b + mid);                
                auto bu1 = distance(A.begin(), it);
                if(A[bu1] == b+mid) {
                    bu1--;
                }
                int bu2;                
                it = upper_bound(A.begin(), A.end(), b + mid);
                bu2 = distance(A.begin(), it) - 1;

                if(bu2 - bl1 + 1 >= k && bu1 - bl2 + 1 <= k) {                    
                    return mid;
                }                
                //if (a[mid] == key) return mid;
                else if (bu2 - bl1 + 1 < k) left = mid + 1;
                else if (bu1 - bl2 > k) right = mid - 1;
            }
            return -1;
        };
        cout << binary_search() << endl;

    }    
    return 0;
}