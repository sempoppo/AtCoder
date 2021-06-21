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

int my_gcd(int x, int y){
    if(x%y == 0){
        return y;
    } else{
        return my_gcd(y, x%y);
    }
}

int main(){
    ll n; cin >> n;
    vector<int> a(n);
    map<int,int> mp;
    rep(i,n) {
        cin >> a[i];
    }
    ll ans = n*(n-1)/2, c = 1;
    sort(a.begin(), a.end());
    a.push_back(-1);
    rep(i,n) {
        if(a[i] != a[i+1]) {
            ans -= (c*(c-1)/2);
            c = 1;
        } else {
            c++;
        }
    }

    // ll ans2 = 0;
    // rep(j,n) {
    //     ans2 += j - mp[a[j]];
    //     mp[a[j]]++;
    // }

    cout << ans << endl;
    // cout << ans2 << endl;
	return 0;
}

// g++ D.cpp -std=c++11
