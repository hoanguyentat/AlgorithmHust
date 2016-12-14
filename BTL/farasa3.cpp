#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

const int maxn = 200200;
ll a[maxn];
int s[maxn];
bool f[20000010];

int main(int argc, char **argv) {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%lld", a + i);
	}
	ll ans = 0;
	if(n <= 1500) {
		set<ll> res;
		for(int l = 0; l < n; ++l) {
			ll sum = 0;
			for(int r = l; r < n; ++r) {
				sum += a[r];
				res.insert(sum);
			}
		}
		ans = res.size();
	} else {
		s[0] = 0;
		f[0] = true;
		for(int i = 0; i < n; ++i) {
			s[i + 1] = s[i] + a[i];
			f[s[i + 1]] = true;
		}
		int sum = s[n];
		for(int i = 1; i <= sum; ++i) {
			if(!f[i]) {
				for(int j = 1; j <= n; ++j) {
					int cur = s[j] + i;
					if(f[cur]) {
						f[i] = true;
						break;
					}
				}
			}
			ans += f[i];
		}
	}
	cout << ans - 1 << endl;
	return 0;
}
