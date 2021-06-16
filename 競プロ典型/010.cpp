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
    int n; cin >> n;
    vector<int> c(n), p(n);
    vector<int> sum_a(n+1,0), sum_b(n+1,0);
    rep(i,n) {
        cin >> c[i] >> p[i];
        if(c[i] == 1) {
            sum_a[i+1] = sum_a[i]+p[i];
            sum_b[i+1] = sum_b[i];
        } else {
            sum_b[i+1] = sum_b[i]+p[i];
            sum_a[i+1] = sum_a[i];
        }
    }

    int q; cin >> q;
    rep(i,q) {
        int l, r;
        cin >> l >> r;
        int ans_a = sum_a[r]-sum_a[l-1];
        int ans_b = sum_b[r]-sum_b[l-1];

        cout << ans_a << " " << ans_b << endl;
    }    
	return 0;
}