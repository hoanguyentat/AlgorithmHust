#include <bits/stdc++.h>
#define MAX 1048576
using namespace std;
 
struct cpx {
	cpx() {
		a = b = 0;
	}
	cpx(double aa) :
			a(aa), b(0) {
	}
	cpx(double aa, double bb) :
			a(aa), b(bb) {
	}
	double a;
	double b;
	double modsq(void) const {
		return a * a + b * b;
	}
	cpx bar(void) const {
		return cpx(a, -b);
	}
	void sq() {
		double aa = a * a - b * b;
		double bb = a * b + a * b;
		a = aa;
		b = bb;
	}
	void multiply(const cpx &X) {
		double aa = X.a * a - X.b * b;
		double bb = X.a * b + X.b * a;
		a = aa;
		b = bb;
	}
	void div2() {
		a /= 2;
		b /= 2;
	}
};
 
cpx operator +(const cpx &a, const cpx &b) {
	return cpx(a.a + b.a, a.b + b.b);
}
cpx operator -(const cpx &a, const cpx &b) {
	return cpx(a.a - b.a, a.b - b.b);
}
 
cpx operator *(const cpx &a, const cpx &b) {
	return cpx(a.a * b.a - a.b * b.b, a.a * b.b + a.b * b.a);
}
 
cpx operator /(const cpx &a, const cpx &b) {
	cpx r = a * b.bar();
	return cpx(r.a / b.modsq(), r.b / b.modsq());
}
 
cpx EXP(double theta) {
	return cpx(cos(theta), sin(theta));
}
 
const double two_pi = 4 * acos(0);
 
void fft(cpx *in, cpx *out, int step, int size, int dir) {
	if (size < 1)
		return;
	if (size == 1) {
		out[0] = in[0];
		return;
	}
	fft(in, out, step * 2, size / 2, dir);
	fft(in + step, out + size / 2, step * 2, size / 2, dir);
 
	double ang = two_pi / size * dir;
	cpx w(1, 0), wn(cos(ang), sin(ang));
	for (int i = 0; i < size / 2; ++i) {
		cpx even = out[i];
		cpx odd = out[i + size / 2];
		out[i] = even + w * odd;
		out[i + size / 2] = even - w * odd;
		if (dir == -1) {
			out[i].div2();
			out[i + size / 2].div2();
		}
		w = w * wn;
	}
 
}
 
long long a[200005];
 
bool ok[10000005];
unordered_set<long long> S;
 
cpx A[8000003], B[8000004], C[8000008];
cpx AA[8000003], BB[8000004], CC[8000008];
 
int main() {
	ios::sync_with_stdio(false);
 
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", a + i);
 
	if (n <= 5000) {
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			long long cur = 0;
			for (int j = i; j < n; j++) {
				cur += a[j];
				if (cur <= 10000000)
					ans += !ok[cur], ok[cur] = 1;
				else
					S.insert(cur);
			}
		}
		ans += S.size();
		cout << ans - 1 << endl;
	}
 
	else {
		for (int i = 1; i < n; i++)
			a[i] += a[i - 1];
		int offset = a[n - 1];
		B[offset] = cpx(1, 0);
		for (int i = 0; i < n; i++) {
			A[a[i]] = cpx(1, 0);
			B[offset - a[i]] = cpx(1, 0);
		}
		int msk = 1;
		while (msk < offset)
			msk *= 2;
		msk *= 2;
		fft(A, AA, 1, msk, 1);
		fft(B, BB, 1, msk, 1);
		for (int i = 0; i < msk; i++)
			CC[i] = AA[i] * BB[i];
		fft(CC, C, 1, msk, -1);
		int ans = 0;
		for (int i = offset + 1; i <= offset + offset; i++)
			if (int(C[i].a + 0.5))
				ans++;
		cout << ans - 1 << endl;
	}
 
	return 0;
}