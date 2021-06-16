#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using G = vector<vector<int>>;
const int MOD = 1e9+7;
const int dx[4] = { 1, 0, -1, 0};
const int dy[4] = { 0, 1, 0, -1};

template<class T> void chmax(T& a, T b) {
    if(a < b) {
        a = b;
    }
}
	
ll modPow(ll n, ll p, ll m){
    if (p == 0) return 1;
    if (p % 2 == 1) return (n * modPow(n, p - 1, m)) % m;
    ll t = modPow(n, p / 2, m);
    return (t * t) % m;
}

int main(){
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> c(n);
    rep(i,n) {
        c[i] = a[i] - i - 1;
    }
    rep(qi,q) {
        ll k;
        cin >> k;
        int r = lower_bound(c.begin(), c.end(), k)-c.begin();
        ll ans;
        if(r == 0) {
            ans = k;
        } else {
            ans = a[r-1] + (k - c[r-1]);
        }
        cout << ans << endl;
    }
	return 0;
}

// g++ D.cpp -std=c++11