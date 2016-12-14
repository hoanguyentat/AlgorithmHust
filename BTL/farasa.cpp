#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <complex>

using namespace std;

const double PI = 4*atan(1);
typedef complex<double> base; // Định nghĩa số phức với a, b là double

vector<base> omega; // biến vector là dãy số phức
int FFT_N;


void init_fft(int n){
	FFT_N = n;
	omega.resize(n);
	double angle = 2 * PI / n;

	for(int i = 0; i < n; i++){
		omega[i] = base(cos(i * angle), sin(i * angle));
		// cout << omega[i];
	}

}

// Fast fourier transform
void fft (vector<base> &a){
	int n = (int) a.size();
	if (n == 1)  return;
	int half = n / 2;

	vector<base> even(half),  odd(half);
	for (int i=0, j=0; i<n; i+=2, ++j)
	{
		even[j] = a[i];   // Day con voi he so bac chan
		odd[j] = a[i+1];	// Day con voi he so bac le
	}
	fft (even), fft (odd);

	//Tính các giá trị hệ số
	for (int i = 0, fact = FFT_N/n; i < half; ++i)
	{
		base twiddle =  odd[i] * omega[i * fact] ;
		a[i] =  even[i] + twiddle;
		a[i+half] = even[i] - twiddle;
	}
}

//Nhan hai da thuc voi phuong phap fft
void multiply (const vector<int> &a, const vector<int> &b, vector<int> &res){
	vector<base> fa(a.begin(), a.end()),  fb(b.begin(), b.end());
//	printf("fa: ");
//	for (int i = 0; i < fa.size(); ++i)
//	{
//		cout << fa[i] << " ";
//	}
//	printf("\n");
//
//	printf("a: ");
//	for (int i = 0; i < a.size(); ++i)
//	{
//		cout << a[i] << " ";
//	}
	// printf("\n");
	int n = 1;
	//Tái tạo lại kích cỡ của mảng thành lũy thừa của 2 gần nhất với size() của a
	while (n < 2 * max(a.size(), b.size()))  n = n * 2;
	fa.resize(n);			
	fb.resize (n);

	init_fft(n);

	fft(fa);
	fft(fb);
	for (size_t i=0; i<n; ++i){
		fa[i] = conj(fa[i] * fb[i]);
	}
	fft(fa);

	res.resize (n);
	for (size_t i=0; i<n; ++i)
		res[i] = (int) (fa[i].real() / n + 0.5);
}

int n, in[200005];
bool res[10000007];

std::map<int,bool> sums;

void method1(){
	int i,j,sum;
	for(i=0;i<n;i++)
		scanf("%d",&in[i]);
	for(i=0;i<n;i++){	
		sum=0;
		for(j=i;j<n;j++){	
			sum+=in[j];
			sums.insert(std::pair<int,bool>(sum,true));	
		}
	}
	cout<<sums.size()-1<<endl;
}
void method2(){	
	int count = 0, sum, max_sum = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &in[i]);
		max_sum += in[i];
	}
	for(int j = 1; j <= max_sum; j++)	res[j]=false;
	for(int i = 0; i < n; i++){
		sum = 0;
		for(int j=i;j<n;j++){
			sum += in[j];
			res[sum]=true;
		}
	}
	for(int j = 1; j <= max_sum ; j++)	count += res[j];
	cout<<count-1<<endl;
}
void method3(){
	int i,j,count=0;
	vector<int> a,b,res;
	in[0]=0;
	// in[i] la tong cua cac phan tu tu 0->i-1
	for( i=1 ; i <= n; i++){
		scanf("%d", &in[i]);
		in[i] += in[i-1];
//		cout << in[i] << " ";
	}
	// printf("\n");
	// Khoi tao hai da thuc a, b
	i = j = 0;
	while(i<=n){
		if(in[i]==j){
			a.push_back(1);
			i++;
			j++;
		} else {
			a.push_back(0);
			j++;
		}
	}
	j = 0; i = n;
	while(i >= 0){
		if(in[n]-in[i] == j){
			b.push_back(1);
			i--;
			j++;
		}
		else {
			b.push_back(0);
			j++;
		}
	}
	// printf("Day a: ");
	// for (int i = 0; i < a.size(); ++i)
	// {
	// 	cout << a[i] << " ";
	// }
	// printf("\nDay b: ");
	// for (int i = 0; i < b.size(); ++i)
	// {
	// 	cout << b[i] << " ";
	// }
	// printf("\n");
	multiply(a,b,res);

	count = 0;

	for(i = a.size(); i < res.size(); i++)
		if(res[i]) count++;
		cout<<count-1<<endl;
}
int main(){
	cin>>n; // Nhap vao so phan tu cua mang
// 	method1();
	method3();
// 	method2();
//	if(n<=4000) method1();
//	else if(n<=10000) method2();
//	else method3();
	return 0;
} 
