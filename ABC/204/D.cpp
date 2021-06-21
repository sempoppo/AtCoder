#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
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
    int n;
    cin >> n;
    bitset<100001> dp;
    dp[0] = 1;
    int tot = 0;
    rep(i,n) {
        int t;
        cin >> t;
        tot += t;
        dp |= dp << t;
    }
    int ans = tot;
    rep(i, tot+1) if (dp[i]) ans = min(ans, max(i,(tot-i)));
    cout << ans << endl;
	return 0;
}

// g++ D.cpp -std=c++11