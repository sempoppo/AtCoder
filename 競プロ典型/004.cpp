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
    int h,w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w)), b(h, vector<int>(w));
    rep(i,h) rep(j,w) cin >> a[i][j];
    vector<int> H(h), W(w);
    rep(i,h) rep(j,w) {
        H[i] += a[i][j];
    }
    rep(j,w) rep(i,h) {
        W[j] += a[i][j];
    }

    rep(i,h) rep(j,w) {
        b[i][j] = H[i]+W[j]-a[i][j];
    }

    rep(i,h){
        rep(j,w) {
            cout << b[i][j] << " ";
            if(j == w-1){
                cout << endl;
            }
        }

    }
    
	return 0;
}