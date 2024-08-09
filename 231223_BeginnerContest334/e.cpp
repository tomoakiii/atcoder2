#include <bits/stdc++.h>
using namespace std;

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

vector<vector<int>> S;
int d[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
void dfs(int y,int x,int z){
	S[y][x] = z;
	for(int i=0; i<4; i++){
		int dy = y + d[i][0], dx = x + d[i][1];
		if(S[dy][dx] == 0){
			dfs(dy, dx, z);
        }
	}
}
int main(){
    int H, W;
    cin >> H >> W;
    mint acnt = 0, dcnt = 0;
    S.resize(H+2, vector<int>(W+2, -1));
    for(int h=1;h<=H;h++) for(int w=1;w<=W;w++){
        char ctmp;
        cin >> ctmp;
        if (ctmp == '.'){
            dcnt += 1;
            S[h][w] = -1;
        } else {
            S[h][w] = 0;
        }
    }
    int ind=0;
    int y,x;
    for(int h=1;h<=H;h++) for(int w=1;w<=W;w++){
        if (S[h][w] == 0){
            dfs(h, w, ++ind);
        }
    }
    for(int h=1;h<=H;h++) for(int w=1;w<=W;w++){
        if (S[h][w] == -1){
            set<int> s;
            for (int i=0; i<4; i++){
                y=h+d[i][0];
                x=w+d[i][1];
                if (S[y][x] > 0){
                    s.insert(S[y][x]);
                }
            }
            acnt += ind - (s.size() - 1); // 0->1, 2->0, 3->-1, 1->0
        }
    }
    acnt = acnt / dcnt;
    cout << acnt << endl;
    return 0;
}