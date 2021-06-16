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

vector<bool> seen;
ll ans = 0;
void dfs(const G &g, int v) {
    seen[v] = true;

    for(auto next_v : g[v]) {
        if(seen[next_v]) continue;
        ans++;
        dfs(g, next_v);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    G g(n);
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
    }

    for(int i = 0; i < n; ++i){
        seen.assign(n, false);
        dfs(g, i);
    }

    cout << ans+n << endl;

	return 0;
}

// g++ D.cpp -std=c++11
