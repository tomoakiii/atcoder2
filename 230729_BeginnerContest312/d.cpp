#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const ll INFi = 0x0F0F0F0F;

// modint: mod 計算を int を扱うように扱える構造体
template<int MOD> struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0) val += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr Fp operator - () const noexcept {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    constexpr Fp& operator -= (const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr Fp& operator *= (const Fp& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator == (const Fp& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const Fp& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
        return os << x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};


const int MOD = 998244353;
using mint = Fp<MOD>;

int main(){
    string S;
    cin >> S;        
    vector<map<ll, mint>> dp(S.size() + 1);    
    dp[0][0] = 1;
    for(int i = 1; i <= S.size(); i++){
        if (S[i-1] == '?'){
            for (auto m: dp[i-1]){
                ll g = m.first;
                if (g < S.size()/2){
                    dp[i][g+1] += dp[i-1][g];
                }
                if (g > 0){
                    dp[i][g-1] += dp[i-1][g];
                }
            }
        } else if (S[i-1] == '('){
            for (auto m: dp[i-1]){
                ll g = m.first;
                if (g >= S.size()/2) continue;
                dp[i][g+1] = dp[i-1][g];
            }
        } else if (S[i-1] == ')'){
            for (auto m: dp[i-1]){
                ll g = m.first;                
                if (g == 0) continue;
                dp[i][g-1] = dp[i-1][g];
            }
        }
    }
    cout << dp[S.size()][0] << endl;
    return 0;
}