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
    int a; cin >> a;
    int x1 = a/1000;
    int x2 = (a-x1*1000)/100;
    int x3 = (a-x1*1000-x2*100)/10;
    int x4 = (a-x1*1000-x2*100-x3*10);
    // cout << x1 << x2 << x3 << x4;
    if(x1==x2 && x2==x3 && x3==x4 &&x4 == x1) {
        cout << "Weak";
    } else if(x1 <= 6) {
        if (x1+1==x2 && x2+1==x3 && x3+1==x4) {
            cout << "Weak";
        } else {
            cout << "Strong";
        }
    } else if(x1 > 6) {
        if(x1 == 7) {
            if(x2 == 8 && x3 == 9 && x4 == 0) {
                cout << "Weak";
            } else cout << "Strong";
        } else if(x1 == 8) {
            if(x2 == 9 && x3 == 0 && x4 == 1) {
                cout << "Weak";
            } else cout << "Strong";
        } else {
            if(x2 == 0 && x3 == 1 && x4 == 2) {
                cout << "Weak";
            } else cout << "Strong";
        }
    }
	return 0;
}

// g++ D.cpp -std=c++11