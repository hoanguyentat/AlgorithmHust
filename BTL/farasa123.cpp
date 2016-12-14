#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <ctime>
#include <iostream>

#include <set>
#include <algorithm>

using namespace std;

#define PI M_PI
#define TWOPI (2.0*PI)

void fft(double data[], int nn, int isign)
{
    int n, mmax, m, j, istep, i;
    double wtemp, wr, wpr, wpi, wi, theta;
    double tempr, tempi;

    n = nn << 1;
    j = 1;
    for (i = 1; i < n; i += 2) {
        if (j > i) {
            tempr = data[j];     data[j] = data[i];     data[i] = tempr;
            tempr = data[j+1]; data[j+1] = data[i+1]; data[i+1] = tempr;
        }
        m = n >> 1;
        while (m >= 2 && j > m) {
            j -= m;
            m >>= 1;
        }
        j += m;
    }
    mmax = 2;
    while (n > mmax) {
        istep = 2*mmax;
        // printf("istep: %d\n",istep);
        theta = TWOPI/(isign*mmax);
        wtemp = sin(0.5*theta);
        wpr = -2.0*wtemp*wtemp;
        wpi = sin(theta);
        wr = 1.0;
        wi = 0.0;
        for (m = 1; m < mmax; m += 2) {
            for (i = m; i <= n; i += istep) {
                j = i + mmax;
                tempr = wr*data[j]   - wi*data[j+1];
                tempi = wr*data[j+1] + wi*data[j];
                data[j]   = data[i]   - tempr;
                data[j+1] = data[i+1] - tempi;
                data[i] += tempr;
                data[i+1] += tempi;
            }
            wr = (wtemp = wr)*wpr - wi*wpi + wr;
            // printf("wi, wir: %d %d\n ", wr, wi);
            wi = wi*wpr + wtemp*wpi + wi;
        }
        mmax = istep;
    }
}

#define ASSERT(A,p,q) assert(p <= A && q >= A)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)

typedef long long ll;

int N;
ll A[1<<18];

double X[1<<24], Y[1<<24];

int method3() {
    int su = 0;
    FOR(i,1,N+1) su += A[i];
    FOR(i,0,1<<23) X[i] = Y[i] = 0;
    X[1] = Y[2*su + 1] = 1;
    int t = 0;
    FOR(i,1,N+1) {
        t += A[i];
        X[2*t + 1] = Y[2*(su-t) + 1] = 1;
    }
    int lim = su;
    while(su&(su-1)) su &= su-1;
    su <<= 1;
    fft(X,su*2,1);
    fft(Y,su*2,1);
    FOR(i,0,su*2) {
        int p = 2*i + 1, q = 2*i + 2;
        double a = X[p]*Y[p] - X[q]*Y[q], b = X[p]*Y[q] + X[q]*Y[p];
        X[p] = a;
        X[q] = b;
    }
    fft(X,su*2,-1);
    int res = 0;
    FOR(i,lim+1,lim*2+1) {
        if(X[2*i + 1] > 1e-6) res++;
    }
    return res;
}

int method2() {
    int *s = new int[20010];
    bool *t = new bool[20000010];
    s[0] = 0;
    s[1] = A[1];
    FOR(i,2,N+1) s[i] = s[i-1] + A[i];
    FOR(i,1,20000001) t[i] = 0;
    FOR(i,1,N+1) FOR(j,0,i) t[s[i]-s[j]] = 1;
    int res = 0;
    FOR(i,1,20000001) res += t[i];
    delete []s;
    delete []t;
    return res;
}

int method1() {
    ll *s = new ll[2010];
    ll *t = new ll[2001000];
    s[0] = 0;
    s[1] = A[1];
    FOR(i,2,N+1) s[i] = s[i-1] + A[i];
    int k = 0;
    FOR(i,1,N+1) FOR(j,0,i) t[k++] = s[i]-s[j];
    sort(t,t+k);
    int res = unique(t,t+k)-t;
    delete[] s;
    delete[] t;
    return res;
}

int main() {
    scanf("%d",&N);
    long long t = N, s = 0;
    FOR(i,1,N+1) {
        scanf("%lld",&A[i]);
        s += A[i];
    }
    ASSERT(t*s,1ll,40000000000ll);
    int res;
    // if(N <= 2000) res = method1();
    // else if(N <= 20000) res = method2();
    // else
    res = method3();
    printf("%d\n",res-1);
    return 0;
}

