#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;

#define REP(i,n)      FOR(i,0,n)
#define FOR(i,a,b)    for(int i = a; i < b; i++)
#define ROF(i,a,b)    for(int i=a;i>b;i--)
#define GI 		      ({int t;scanf("%d",&t);t;})
#define GL 		      ({LL t;scanf("%lld",&t);t;})
#define GD 		      ({double t;scanf("%lf",&t);t;})
#define pb 	          push_back
#define mp 	          make_pair
#define MOD 	      1000000007
#define INF	          (int)1e9
#define EPS	          1e-9
#define TR(a,it)      for(typeof((a).begin()) it = (a).begin(); it!=(a).end(); ++it)
// ignoring even numbers
int flag[MAX >> 6];
/**
#define TEST(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define SET(x) (flag[x>>6]|=(1<<((x>>1)&31)))
**/

#define TEST(f,x) (*(f+(x)/16)&(1<<(((x)%16L)/2)))
#define SET(f,x)  *(f+(x)/16)|=1<<(((x)%16L)/2)

#define ONEPRIME 0 
#define UL unsigned long
#define UC unsigned char


UC primes[87000000/16] = {0};

void getPrimes(UL maxn){
  UL x, y;


  for (x = 3; x*x <= maxn; x+=2)
    if (!TEST(primes, x))
      for (y = x*x; y <= maxn; y += x<<1) SET (primes, y);

}

int isPrime(UL x){
  if(x == 1) return ONEPRIME;
  if(x == 2) return 1;
  if(x % 2 == 0) return 0;
  return (!TEST(primes, x));
}

int main()
{


	int T, k;
	getPrimes(87000000);

    vector<int> prime_stored;
    prime_stored.pb(-1);
    prime_stored.pb(2);
    for (int i=3; i<=87000000; i += 2)
        if (isPrime(i))
            prime_stored.pb(i);
    cout<<prime_stored.size();

	scanf("%d", &T);
	while (T--){
	    scanf("%d", &k);
	    printf("%d\n", prime_stored[k]);
	}
	return 0;
}

