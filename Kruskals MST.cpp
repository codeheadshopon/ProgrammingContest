//*********************SHOPON(CODEHEAD)- UNIVERSITY OF ASIA PACIFIC *************************//
//******************************************************************************************//
//************************************Header Files*****************************************//
#include <iostream>
#include <numeric>
#include <sstream>
#include <fstream>
#include<ctype.h>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <iterator>
#include <map>

using namespace std;
//****************************************************************************************//
//************************************Macros*********************************************//
#define MAX 100000
#define fmax(a,b) ((a>b)?a:b)
#define fmin(a,b) ((a<b)?a:b)
#define pii pair< int, int >
#define FOR(i,A,B) for(int i = (A); i < (B); ++i)
#define sqr(num) ((num)*(num))
#define PI 3.1415926535897
#define pitr (2*acos(0))
#define lp 20071027
#define input() freopen("C:\\Users\\Bad-''CODEHEAD''-Ass\\Desktop\\input.txt","r",stdin);
#define write freopen("C:\\Users\\Bad-''CODEHEAD''-Ass\\Desktop\\output.txt","w",stdout);
#define pf printf
#define REP(n) for(int i=0;i<n;i++)
#define pb push_back
#define sc1(t) scanf("%d",&t)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sc164(t) scanf("%lld",&t)
#define sc264(a,b) scanf("%lld%lld",&a,&b)
#define sc364(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define scstr(l) scanf("%[^\n]",l)
#define make(a,d) memset(a,d,sizeof(a))
#define lld long long int
#define print(x) printf("%d\n",x)
#define print64(x) printf("%lld\n",x)
#define printcase(x,n) printf("Case %d: %d\n",x,n)
#define printyn(x,s) printf("Case %d: %s\n",x,s)
#define debug(a, i) printf(#a "[%d] = %d\n", i, a[i]);
#define _i int
const lld INF = 0x7fffffff;
//*************************************************************************************************//
//******************************************Checkers**********************************************//
bool isUpperCase(char c){return c>='A' && c<='Z';}
bool isLowerCase(char c){return c>='a' && c<='z';}
bool isLetter(char c){return c>='A' && c<='Z' || c>='a' && c<='z';}
bool isDigit(char c){return c>='0' && c<='9';}

//************************************************************************************************//
//****************************************Templates**********************************************//
template<class T> inline bool isPrimeNumber(T n)
{if(n<=1)return false;for (T i=2;i*i<=n;i++) if (n%i==0) return false;return true;}
template<class T>T gcd(T a,T b){return b == 0 ? a : gcd(b, a % b);}
template<typename T>T lcm(T a, T b) {return a / gcd(a,b) * b;}
template<class T>T big_mod(T n,T p,T m){if(p==0)return (T)1;T x=big_mod(n,p/2,m);x=(x*x)%m;if(p&1)x=(x*n)%m;return x;}
template <class T> inline T mod_inverse(T a, T M){return BM(a, M - 2, M);}
template <class T>T stringtonumber ( const string &Text ){istringstream ss(Text);T result;return ss >> result ? result : 0;}
template<class T>T power(T n,T p){if(p==0)return 1;T x=mpower(n,p/2);x=(x*x);if(p&1)x=(x*n);return x;} ///n to the power p
//*************************************************************************************************//
//************************************Bit Works***************************************************//
int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
//*********************************************************************************************//
//************************************Neccessary Codes*****************************************//
/*
bool PRIME[10000009];
void sieve_for_primecheck()
{
    long long i,j,sq=sqrt(10000000);
    for(i=4;i<=10000000;i=i+2)
        PRIME[i]=1;
    for(i=3;i<=sq;i=i+2)
    {
        if(PRIME[i]==0)
        {
            for(j=i*i;j<=10000000;j=j+2*i)
                PRIME[j]=1;
        }
    }
}

void BUS()
{
    _i a[10000],n;
    for(_i i=0;i<n;i++)
            cin>>a[i];

        for(_i i=0;i<n-1;i++)
        {
            for(_i j=0;j<n-2-i;j++)
            {
                if(a[j]>a[j+1])
                    swap(a[j],a[j+1]);
            }
        }
}

bool Binary_Search(int low,int high,int value)
{
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]==value) return 1;
        else if(a[mid]<value)
            low=mid+1;
        else
            high=mid-1;
    }
    return 0;
}
*/
//***************************************************************************************//
//***********************************Work Starts From Here******************************//
 /*
    _i cases,cas=0;
    sc1(cases);
    while(cases--)
    {

    }
*/


struct edge
{
	int u,v,w;
	bool operator < ( const edge& p ) const
	{
		return w < p.w;
	}
};
_i Priority[MAX];
vector<edge>e;
int find(int r)
{
   return (pr[r]==r) ? r:  find(pr[r]);
}
_i _FindMinNode(_i n)
{
    make(Priority,0)
	sort(e.begin(),e.end());
	for(_i  i=1;i<=n;i++)pr[i]=i;

	int count=0,s=0;
	for(int i=0;i<(int)e.size();i++)
	{
		int u=find(e[i].u);
		int v=find(e[i].v);
		printf("%d %d\n",u,v);
		if(u!=v)
		{
			pr[u]=v;
			count++;
			s+=e[i].w;
			if(count==n-1) break;
		}
	}
	return s;
}

int main(){
//	READ("in");
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		edge get;
		get.u=u; get.v=v; get.w=w;
		e.push_back(get);
	}
	cout<<mst(n)<<endl;
	return 0;

}
