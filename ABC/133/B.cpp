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

struct UnionFind {
    vector<int> par, siz;

    // 初期化
    UnionFind(int n) : par(n, -1), siz(n, 1) {}

    // 根を求める
    int root(int x){
        if(par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }

    // x と y が同じグループに属するかどうか
    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    // x を含むグループと y を含むグループとを併合する
    bool unite(int x, int y) {
        // x, y をそれぞれ根まで移動する
        x = root(x), y = root(y);

        // すでに同じグループのときは何もしない
        if(x == y) return false;

        // union by size (y 側のサイズが小さくなるようにする)
        if(siz[x] < siz[y]) swap(x, y);

        // y を x の子とする
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    // x を含むグループのサイズ
    int size(int x){
        return siz[root(x)];
    }
};
	
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
    int n, d;
    cin >> n >> d;
    vector<vector<int>> x(n, vector<int>(d));
    rep(i,n) {
        rep(j,d) {
            cin >> x[i][j];
        }
    }
    
    int ans = 0;
    rep(i,n-1) {
        for(int j = i+1; j < n; ++j) {
            int D = 0;
            for(int k = 0; k < d; ++k) {
                D += pow(x[i][k] - x[j][k], 2);
            }
            double sq = sqrt((double)D);
            if(sq == (int)sq) ans++;
        }
    }
    cout << ans << endl;
	return 0;
}

// g++ D.cpp -std=c++11