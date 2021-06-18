#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1e9+7;

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
    ll k;
    cin >> n >> k;
    vector<pair<ll,ll>> a(n);
    rep(i,n) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());

    rep(i,n){
        if (k - a[i].first < 0){
            break;
        }
        k += a[i].second;
    }
    cout << k << endl;

	return 0;
}

// g++ D.cpp -std=c++11
