#include <vector>
#include <cmath>
#include <ctime>
#include <fstream>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef long long _ll;
typedef vector<int> _vi;
typedef vector<_ll> _vll;
typedef vector<string> _vs;
typedef istringstream _iss;
#define _a(v) (v).begin(),(v).end()
#define _e(x,y) (fabs((x)-(y))<1e-10)
#define _p push_back
#define _mp make_pair
#define _m(v) memset(v,0,sizeof(v));
#define _f(i,b,e) for(int i=b;i<e;i++)
#define _fl(i,n) for(int i=0;i<(n).length();i++)
#define _fs(i,n) for(int i=0;i<(n).size();i++)
#define _fe(t,i,n) for(t::iterator i=(n).begin();i!=(n).end();i++)
#define _fd(t,e) ((t).find(e)!=(t).end())
#define _s(x,y) {x+=y;y=x-y;x-=y;}
#define _st(x, y, t) {t _t_; _t_=x;x=y;y=_t_;}

int cnt[2010];
int main()
{
	srand((unsigned long)time(NULL));

	double E = exp(1.0);
	double PI = 3.1415926535;

	_m(cnt);

	_f(i, 0, 10000)
	{
		double z1 = (double)rand()/RAND_MAX;
		double z2 = (double)rand()/RAND_MAX;
		double d1 = sqrt(-2.0*log(z1)/log(E))*cos(2.0*PI*z2);
		double d2 = sqrt(-2.0*log(z1)/log(E))*sin(2.0*PI*z2);

		//Maximum likelihood estimation with precision 0.01
		cnt[int(d1*100)+1000]++;
		cnt[int(d2*100)+1000]++;
	}

	ofstream outf("out.txt");
	_f(i, 0, 2000)
	{
		outf<<(double)i/100-10.0<<"\t"<<cnt[i]<<endl;
	}
	outf.close();

	return 0;
}

