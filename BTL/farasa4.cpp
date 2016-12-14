#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <list>
#include <deque>
#include <bitset>
#include <cmath>
#include <set>
#include <sstream>
#include <time.h>
#include <complex>
//#define M3
using namespace std;
 
#define oo 0x7F7F7F7F
#define LET(x,a)     __typeof(a) x(a)
#define EACH(it,v)   for(LET(it,v.begin());it!=v.end();++it)
#define REP(i,n)     for(__typeof(n) i(0); i<n; i++)
#define ALL(x)       (x).begin(), (x).end()
#define gint(t)      scanf("%d", &t);
#define pint(t)      printf("%d\n", t);
#define pb           push_back
#define mp           make_pair
#define PI 3.141592653589793
//#define JAI_ARENA
#ifdef JAI_ARENA
#define debug(args...)    {cerr<<"> "; dbg,args;cerr<<endl;}
#define debugv(v, n)      {cerr<<"> "; REP(ni, n) dbg,v[ni]; cerr<<endl;}
#else
#define debug(...) ;
#define debugv(...) ;
#endif
typedef long long int   ll;
typedef unsigned long long int ull;
typedef unsigned int    uint;
typedef pair<int, int>  pii;
typedef vector<int>     vi;
typedef vector<vi>      vii;
typedef vector<pii>     vpii;
 
struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;
 
 
#define BUF 4096
char ibuf[BUF];
int ipt = BUF;
 
int readUInt() {
    while (ipt < BUF && ibuf[ipt] < '0') ipt++;
    if (ipt == BUF) {
    fread(ibuf, 1, BUF, stdin);
    ipt = 0;
    while (ipt < BUF && ibuf[ipt] < '0') ipt++;
    }
    int n = 0; char neg = 0;
    if(ipt !=0 && ibuf[ipt-1] == '-') neg = 1;
    while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
    if (ipt == BUF) {
    fread(ibuf, 1, BUF, stdin);
    ipt = 0;
    while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
    }
    return neg?-n:n;
}
int n;
#define MAXMAP 10000000
#define MAXN 200001
char vmap1[MAXMAP];
int v[MAXN];
int sv[MAXN];
void solve_very_small()
{
	ll lv[n];
	set<ll> mk;
	for(int i = 0; i < n; i++) {
		cin>>lv[i];
	}
	for(int i = 0; i < n; i++)
	{
		ll sumt = lv[i];
		mk.insert(sumt);
		for(int j = i+1; j < n; j++) {
			sumt += lv[j];
			mk.insert(sumt);
		}
	}
	cout<<mk.size()-1<<endl;
}
void solve()
{
	for(int i = 0; i < n; i++) {
		gint(v[i]);
		//v[i] = 1;
	}
	memset(vmap1, 0, sizeof vmap1);
	set<int> mk;
	for(int i = 0; i < n; i++) {
		int sum = 0;
		for(int j = i; j < n; j++) {
			sum += v[j];
			if(sum < MAXMAP) {
				vmap1[sum] = 1;
			} else {
				mk.insert(sum);
			}
		}
	}
	int res = mk.size()-1;
	for(int i = 0; i < MAXMAP; i++) if(vmap1[i]) { res++;}
	printf("%d\n", res);
}
/*typedef complex<double> base;
double data1[8400100];
double data2[8400100];
void fft (vector<base> &a, bool invert);
void four1(double *data, int nn, int isign)
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
	theta = (2*PI)/(isign*mmax);
	wtemp = sin(0.5*theta);
	wpr = -2.0*wtemp*wtemp;
	wpi = sin(theta);
	wr = 1.0;
	wi = 0.0;
	for (m = 1; m < mmax; m += 2) {
	    for (i = m; i <= n; i += istep) {
		j 		  = i + mmax;
		tempr     = wr*data[j]   - wi*data[j+1];
		tempi 	  = wr*data[j+1] + wi*data[j];
		data[j]   = data[i]   - tempr;
		data[j+1] = data[i+1] - tempi;
		data[i]   += tempr;
		data[i+1] += tempi;
	    }
	    wr = (wtemp = wr)*wpr - wi*wpi + wr;
	    wi = wi*wpr + wtemp*wpi + wi;
	}
	mmax = istep;
    }
    debug("done");
}
void fft (vector<base> &a, bool invert) {
    
	int n = (int) a.size();
    if (n == 1)  return;
    vector<base> a0 (n/2),  a1 (n/2);
    for (int i=0, j=0; i<n; i+=2, ++j) {
        a0[j] = a[i];
        a1[j] = a[i+1];
    }
    fft (a0, invert);
    fft (a1, invert);
 
    double ang = 2*PI/n * (invert ? -1 : 1);
    base w (1),  wn (cos(ang), sin(ang));
    for (int i=0; i<n/2; ++i) {
        a[i] = a0[i] + w * a1[i];
        a[i+n/2] = a0[i] - w * a1[i];
        if (invert)
            a[i] /= 2,  a[i+n/2] /= 2;
        w *= wn;
    }
}
set<int> res;
void multiply (vector<base> & fa, vector<base> & fb) {
    size_t n = 1;
    
    while (n < max (fa.size(), fb.size()))  n <<= 1;
    n <<= 1;
    fa.resize (n),  fb.resize (n);
    fft (fa, false),  fft (fb, false);
    for (size_t i=0; i<n; ++i)
        fa[i] *= fb[i];
    fft (fa, true);
    for (size_t i=0; i<min(n, (size_t)MAXMAP); ++i)
    {    
    	int val = int (fa[i].real() + 0.5);
    	if(val)
			vmap[i]=1;
    }
	for(size_t i = MAXMAP; i<n; i++) {
		int val = int (fa[i].real() + 0.5);
    	if(val)
			res.insert(i);
	}
}
 
void mul2(int nn)
{
	debug("Multiply", nn);
	
	four1(data1, nn, 1);
	four1(data2, nn, 1);
	for(int i = 0; i < nn; i++) {
		double rel = data1[2*i+1]*data2[2*i+1]-
					 data1[2*i+2]*data2[2*i+2];
		double img = data1[2*i+1]*data2[2*i+2]+
					 data1[2*i+2]*data2[2*i+1];
		data1[2*i+1]=rel;
		data1[2*i+2]=img;
	}
	four1(data1, nn, -1);
	for(int i = 0; i<nn; i++) {
		if(int(data1[2*i+1]/nn+0.5)) {
			if(i<MAXMAP) vmap[i] = 1;
			else res.insert(i);
		}
	}
	debug("done");
}
void make_mul(int s1, int e1, int s2, int e2, int r1) {
	if(e1-s1<=10000) {
		for(int i = s1; i<=e1; i++) {
			int m1 = sv[r1] - ((i==0)?0:sv[i-1]);
			for(int j = s2; j<=e2; j++) {
				int m2 = sv[j]-sv[r1];
				vmap[m1+m2] = 1;
			}
		}
		return;
	}
	int mid1 = (s1+e1)/2;
	int mid2 = (s2+e2)/2;
	make_mul(s1, mid1, s2, mid2, r1);
	make_mul(s1, mid1, mid2+1, e2, r1);
	make_mul(mid1+1, e1, s2, mid2, r1);
	make_mul(mid1+1, e1, mid2+1, e2, r1);
		
}
void recurse(int start, int end) {
	if(end-start<=3000) {
		for(int i = start; i <= end; i++) {
			int sum = 0;
			for(int j = i; j <= end; j++) {
				sum += v[j];
				vmap[sum] = 1;
			}
		}
		return;
	}
	int mid = (start+end)/2;
	recurse(start, mid);
	recurse(mid+1, end);
	make_mul(start, mid, mid+1, end, mid);
	
}
 
 
void solve_recursive()
{
	memset(vmap, 0, sizeof vmap);
	for(int i = 0; i < n; i++) {
		gint(v[i]);
		//v[i] = 1;
		sv[i] = (i!=0)?(sv[i-1]+v[i]):v[0];
	}
	cout<<sv[n-1]<<endl;
	recurse(0, n-1);
	//EACH(it, res) cout<<*it<<endl;
	int r = res.size()-1;
	for(int i = 0; i < MAXMAP; i++)
		if(vmap[i]) { r++; }
	cout<<r<<endl;
}
void side_attack()
{
	memset(vmap, 0, sizeof vmap);
	int sumx = 0;
	for(int i = 0; i < n; i++) {
		gint(v[i]);
		sumx+=v[i];
	}
	int sf = 0, sb = 0; 
	int nn = (int)pow(2.0, ceil(log((double)(sumx))/log(2.0)));
	nn<<=1;
	cout<<2*nn+1<<endl;
	memset(data1, 0, sizeof(double)*(2*nn+1));
	memset(data2, 0, sizeof(double)*(2*nn+1));
	data1[1] = 1;
	data2[1] = 1;
	int sum = 0;
	for(int i = 0; i<n; i++) {
		sf+=v[i];
		sb+=v[n-1-i];
		data1[2*sf+1] = 1;
		data2[2*sb+1] = 1;
	}
	mul2(nn);
	int res = 0;
	for(int i = 0; i<=sumx; i++) if(vmap[i]) res++;
	cout<<res<<endl;
}*/
 
uint vmap[MAXMAP];
uint vmap2[MAXMAP];
void simple_convolution()
{
	const uint SZ = 32;
	const uint NB = 5;
	const uint MASK = SZ-1;
	memset(vmap, 0, sizeof vmap);
	uint sumx = 0;
	for(int i = 0; i < n; i++) {
		gint(v[i]);
		sumx+=v[i];
		vmap[sumx>>NB]|=(1<<(sumx&MASK));
	}
	vmap[0]|=1;
	memcpy(vmap2, vmap, sizeof vmap);
	int ne = 1 + sumx/SZ;
	sumx = 0;
	for(int i = n-1; i>=0; i--)
	{
		sumx += v[i];
		uint lf = (sumx>>NB);
		uint ff = (sumx&MASK);
		vmap[lf] |= (vmap2[0]<<ff);
		for(int j = lf+1; j<=ne; j++) {
			vmap[j]|=ff?((vmap2[j-lf]<<ff)|(vmap2[j-lf-1]>>(SZ-ff))):vmap2[j-lf];
		}
	}
	int res = 0;
	uint val = (sumx+1)%SZ;
	uint msk = (1<<val)-1;
	vmap[(sumx+1)/SZ]&=msk;
	for(int i = (sumx+1)/SZ; i>=0; i--) {
		res += __builtin_popcount(vmap[i]);
	}
	cout<<res-2<<endl;
}
bool input() {
	gint(n);
	//n=15000;
	return true;
}
void preprocess() {
 
}
int main()
{
#ifdef JAI_ARENA
	freopen("4.in", "r", stdin);
	time_t start = time(NULL);
#endif
	preprocess();
    input();
    if(n>200000) {
    	while(1);
    }
    if(n <= 100) {
    	solve_very_small();
    } else if(n<40001) {
    	solve();
    } else {
    	simple_convolution();
    }
#ifdef JAI_ARENA
    time_t end = time(NULL);
    
    cerr<<end-start<<endl;
#endif
    return 0;
}