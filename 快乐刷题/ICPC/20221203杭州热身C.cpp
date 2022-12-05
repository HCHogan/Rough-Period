#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
#define PB emplace_back
// #define int long long
#define ll long long
#define vi vector<int>
#define siz(a) ((int)((a).size()))
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

const int N = 1.4e7, mod = 1e9 + 7;
int a, f[2][N + 5];
ll pw[31];
int fac[N + 5], inv[N + 5];
int qp(int n, int m = mod - 2) {
	int res = 1;
	for(; m; m >>= 1) {
		if(m & 1) res = 1ll * res * n % mod;
		n = 1ll * n * n % mod;
	}
	return res;
}
void init() {
	fac[0] = fac[1] = 1;
	rep(i, 2, N) fac[i] = 1ll * fac[i - 1] * i % mod;
	inv[N] = qp(fac[N]);
	per(i, N - 1, 0) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
}
int C(int n, int m) {return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;}

signed main() {
	// freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	init();
	cin >> a;
	f[0][1] = 1;
	pw[0] = 1;
	rep(i, 1, 30) {
		pw[i] = pw[i - 1] * 3 % mod;
		if(pw[i] > 1e9) break;
	}
	int ans = 0;
	rep(i, 0, 30) {
		(ans += 1ll * f[i & 1][0] * i % mod) %= mod;
		f[i & 1][0] = 0;
		if(pw[i] > a) break;
		int cnt = pw[i];
		rep(j, 1, a) {
			if(!f[i & 1][j]) continue;
			if(pw[i + 1] >= a) {
				(f[(i & 1) ^ 1][0] += f[i & 1][j]) %= mod;
				continue;
			}
			int k = min(a - cnt, 2 * j), b = a - cnt, w = qp(C(b, 2 * cnt));
			rep(p, max(0, 2 * cnt - b + k), min(k, 2 * cnt)) {
				int q = 2 * cnt - p;
				if(q < 0 || q > b - k) assert(0);
				(f[(i & 1) ^ 1][k - p] += 1ll * f[i & 1][j] * C(k, p) % mod * C(b - k, q) % mod * w % mod) %= mod;
			}
			f[i & 1][j] = 0;
		}
	}
	cout << ans;
	return 0;
