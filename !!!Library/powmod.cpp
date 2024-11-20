
/* return x^k % mod */
ll powmod(ll x, ll k, ll mod) {
    if(k==0) return 1%mod;
    ll res = powmod(x, k/2, mod);
    res = (res * res) % mod;
    if(k%2 == 1) res = (res * x) % mod;
    return res;
}
