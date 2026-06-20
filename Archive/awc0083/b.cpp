#include <atcoder/all>
#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;


namespace frac_internal {
    __int128_t __gcd(__int128_t a, __int128_t b) {
        if (a % b == 0)
            return b;
        return __gcd(b, a % b);
    }

    // 絶対値の GCD を返す。片方が 0 ならもう一方の絶対値。
    __int128_t gcd(__int128_t a, __int128_t b) {
        if (b == 0)
            return (a >= 0 ? a : -a);
        return frac_internal::__gcd((a >= 0 ? a : -a), (b >= 0 ? b : -b));
    }

    inline void simplify(__int128_t &num, __int128_t &den) {
        __int128_t d = frac_internal::gcd(num, den);
        num /= (den >= 0 ? d : -d);
        den /= (den >= 0 ? d : -d);
    }
}; // namespace frac_internal

using namespace std;
using namespace atcoder;
// 演算結果の分子・分母がともに 64bit 整数の範囲でのみ動作を保証
class fraction {
  private:
    long long num, den;

    friend fraction operator+(const fraction &a) { return a; }
    friend fraction operator-(const fraction &a) {
        fraction ret;
        ret.raw_assign(-a.num, a.den);
        return ret;
    }

    friend fraction operator+(const fraction &a, const fraction &b) {
        assert(!(a.is_infinity() && b.is_infinity() &&
                 a.num * b.num == -1)); // 不定形はダメ
        if (a.is_infinity()) {
            return a;
        } else if (b.is_infinity()) {
            return b;
        } else {
            return {(__int128_t)a.num * b.den + (__int128_t)b.num * a.den,
                    (__int128_t)a.den * b.den};
        }
    }
    friend fraction operator-(const fraction &a, const fraction &b) {
        assert(!(a.is_infinity() && b.is_infinity() &&
                 a.num * b.num == 1)); // 不定形はダメ
        if (a.is_infinity()) {
            return a;
        } else if (b.is_infinity()) {
            return -b;
        } else {
            return {(__int128_t)a.num * b.den - (__int128_t)b.num * a.den,
                    (__int128_t)a.den * b.den};
        }
    }
    friend fraction operator*(const fraction &a, const fraction &b) {
        assert(a.num != 0 || b.den != 0);
        assert(a.den != 0 || b.num != 0);
        long long gcd_tmp1 = std::gcd(a.num, b.den),
                  gcd_tmp2 = std::gcd(b.num, a.den);
        fraction ret;
        ret.raw_assign((a.num / gcd_tmp1) * (b.num / gcd_tmp2),
                       (a.den / gcd_tmp2) * (b.den / gcd_tmp1));
        return ret;
    }
    friend fraction operator/(const fraction &a, const fraction &b) {
        assert(a.num != 0 || b.num != 0);
        assert(a.den != 0 || b.den != 0);
        long long gcd_tmp1 = std::gcd(a.num, b.num),
                  gcd_tmp2 = std::gcd(b.den, a.den);
        fraction ret;
        ret.raw_assign(
            (b.num >= 0 ? 1 : -1) * (a.num / gcd_tmp1) * (b.den / gcd_tmp2),
            (b.num >= 0 ? 1 : -1) * (a.den / gcd_tmp2) * (b.num / gcd_tmp1));
        return ret;
    }

    friend bool operator==(const fraction &a, const fraction &b) {
        return a.num == b.num && a.den == b.den;
    }
    friend bool operator!=(const fraction &a, const fraction &b) {
        return a.num != b.num || a.den != b.den;
    }

    friend int compare_to(const fraction &a, const fraction &b) {
        if ((a.num >= 0) ^ (b.num >= 0))
            return a.num > b.num ? 1 : -1;
        __int128_t lhs = (__int128_t)a.num * b.den;
        __int128_t rhs = (__int128_t)b.num * a.den;
        if (lhs == rhs)
            return 0;
        return lhs > rhs ? 1 : -1;
    }

    friend bool operator>(const fraction &a, const fraction &b) {
        return compare_to(a, b) > 0;
    }
    friend bool operator>=(const fraction &a, const fraction &b) {
        return compare_to(a, b) >= 0;
    }
    friend bool operator<(const fraction &a, const fraction &b) {
        return compare_to(a, b) < 0;
    }
    friend bool operator<=(const fraction &a, const fraction &b) {
        return compare_to(a, b) <= 0;
    }

  public:
    fraction(long long n) : num(n), den(1) {}
    fraction(__int128_t numerator, __int128_t denominator) {
        frac_internal::simplify(numerator, denominator);
        num = numerator, den = denominator;
    }
    fraction() : num(0), den(1) {}

    fraction &operator=(const fraction &a) = default;
    fraction &operator+=(const fraction &a) { return *this = *this + a; }
    fraction &operator-=(const fraction &a) { return *this = *this - a; }
    fraction &operator*=(const fraction &a) { return *this = *this * a; }
    fraction &operator/=(const fraction &a) { return *this = *this / a; }

    friend std::istream &operator>>(std::istream &is, fraction &a) {
        std::string buf;
        is >> buf;
        __int128_t num_tmp = 0, den_tmp = 0;
        int i = (buf[0] == '-'), sz = buf.size();
        for (; i < sz && buf[i] != '/'; i++)
            num_tmp = num_tmp * 10 + buf[i] - '0';
        if (i == sz)
            den_tmp = 1;
        else
            for (i = i + 1; i < sz; i++)
                den_tmp = den_tmp * 10 + buf[i] - '0';
        if (buf[0] == '-')
            num_tmp *= -1;
        frac_internal::simplify(num_tmp, den_tmp);
        a.num = num_tmp, a.den = den_tmp;
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const fraction &a) {
        if (a.den == 0)
            os << (a.num >= 0 ? "inf" : "-inf");
        else if (a.den == 1)
            os << a.num;
        else
            os << a.num << '/' << a.den;
        return os;
    }

    // 約分を省略して代入する
    fraction &raw_assign(long long _num, long long _den) {
        num = _num, den = _den;
        return *this;
    }

    // ------------------------------- optional ------------------------------- //

    long long numerator() const { return num; }
    long long denomitnator() const { return den; }
    long long floor() const { return num / den; }
    long long ceil() const { return ((__int128_t)num + den - 1) / den; }
    double real() const { return (double)num / den; }
    fraction abs() const { return (*this >= 0 ? *this : -*this); }
    fraction inverse() const {
        fraction ret;
        ret.raw_assign((num >= 0 ? den : -den), (num >= 0 ? num : -num));
        return ret;
    }
    /*int mod(int _mod) const {
        assert(_mod > 0);
        long long ret = num % _mod;
        if (ret < 0)
            ret += _mod;
        return (ret *= mod_inverse(den, _mod)) %= _mod;
    }*/
    bool is_infinity() const { return (den == 0); }

    static const fraction M_INF, INF;
};
const fraction fraction::M_INF(-1, 0), fraction::INF(1, 0); // -∞, ∞ を表す定数


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,Q;
    cin >> N >> Q;
    vector<ll> H(N);
    rep(i,N) cin>>H[i];
    typedef fraction Rat;
    vector Lp(N, vector<Rat>(N, Rat(0,1)));
    vector Rp(N, vector<Rat>(N, Rat(0,1)));

    rep(i,N){
        rep(j,N) {
            if(i==j)continue;
            Rat x = Rat(H[j], abs(i-j));
            if(i>j) {
                Lp[i][j] = x;
            } else {
                Rp[i][j] = x;
            }
        }
    }

    while(Q--){
        int query; cin>>query;
        if(query==1){
            int p; ll h;
            cin>>p>>h; p--;
            H[p]=h;
            rep(i,N) {
                if(i==p) continue;
                Rat x = Rat(H[p], abs(i-p));
                if(i>p) {
                    Lp[i][p] = x;
                } else {
                    Rp[i][p] = x;
                }
            }
            rep(j,N) {
                if(j==p) continue;
                Rat x = Rat(H[j], abs(p-j));
                if(p>j) {
                    Lp[p][j] = x;
                } else {
                    Rp[p][j] = x;
                }
            }
        } else {
            int a,b; cin>>a>>b; a--,b--;
            Rat mx(0,1);
            int ans=-1;
            for(int i=a; i<=b; i++) {
                Rat mxl(0,1);
                Rat mxr(0,1);
                rep(j,N) {
                    if(i==j) continue;
                    chmax(mxl, Lp[i][j]);
                    chmax(mxr, Rp[i][j]);
                }
                Rat q = 1 / (1+mxl+mxr);
                if(chmax(mx, q)) ans=i+1;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}