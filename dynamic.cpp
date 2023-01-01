#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
#define vpll vector< pair< ll, ll> >
#define vll vector< ll>
#define pll pair<ll, ll>
#define ln '\n'
#define strdel( S, c) S.erase( remove( S.begin(), S.end(), c), S.begin())
#define rep(i,a,b) for (ll i = a; i <= b; i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
//MARK:- DEBUGGER===================================================
#ifndef ONLINE_JUDGE
#define debug( x) cerr<< #x<< " : "; __print__d( x); cerr<< ln;
#else
#define debug( x)
#endif
void __print__d( int x)     {    cerr<< x;    } void __print__d( ll x)      {    cerr<< x;    } void __print__d( char x)    {    cerr<< x;    } void __print__d( string x)  {    cerr<< x;    }
void __print__d( double x)  {    cerr<< x;    } void __print__d( float x)   {    cerr<< x;    } void __print__d( bool x)    {    cerr<< x;    }
template< class P1, class P2> void __print__d( pair< P1, P2> x){     cerr<< " { "; __print__d( x.fi); cerr<< " -> "; __print__d( x.se); cerr<< " } "<< ln;     }
template<class T> void __print__d( vector< T> v){                    cerr<< " [ "; for( T i : v){ __print__d( i); cerr<< ' '; } cerr<< "] ";                   }
template<class T> void __print__d( set< T> v){                       cerr<< " [ "; for( T i : v){ __print__d( i); cerr<< ' '; } cerr<< "] ";                   }
template<class T> void __print__d( unordered_set< T> v){             cerr<< " [ "; for( T i : v){ __print__d( i); cerr<< ' '; } cerr<< "] ";                   }
template<class T> void __print__d( map< T, T> v){                       cerr<< " [ "; for( pair< T, T> i : v){ __print__d( i); cerr<< ' '; } cerr<< "] ";                   }
template<class T> void __print__d( unordered_map< T, T> v){             cerr<< " [ "; for( pair< T, T> i : v){ __print__d( i); cerr<< ' '; } cerr<< "] ";                   }
 
//MARK:- PREDEFINED DP SEQUENCES====================================
vector< ll> fact_dp;
 
//MARK:- FUNCTION DEFINITIONS=======================================
bool doubleequal( double a, double b);  
ll power( ll base, ll exponent, ll modulo_factor);
ll modInverse(ll n,ll p);
ll combinate(ll n, ll r, ll modulo_factor);
ll permutate(ll n, ll r, ll modulo_factor);
ll gcd( ll num1, ll num2);
ll lcm( ll num1, ll num2);
ll factorial( ll num, ll mod);
 
void solve();
 
//MARK:- Defined Funtions===========================================
bool doubleequal( double a, double b){ if (abs(a-b) < 1e-9) return true; return false; }
ll power( ll base, ll exponent, ll modulo_factor){ ll x = base, y = exponent, p = modulo_factor;
    ll res = 1; x = x % p; while (y > 0) { if (y & 1) res = (res * x) % p; y = y >> 1; x = (x * x) % p; } return res; }
ll modInverse(ll n,ll p){ return power(n, p - 2, p); }
ll combinate(ll n, ll r, ll modulo_factor){ ll p = modulo_factor; if (n < r)  return 0; if (r == 0) return 1;
    return (factorial(n,p) * modInverse(factorial(r,p), p) % p * modInverse(factorial(n-r,p), p) % p) % p; }
ll permutate(ll n, ll r, ll modulo_factor){
    ll p = modulo_factor; if (r == 0) return 1; return (factorial(n,p) * modInverse( factorial(n - r, p), p)) % p; }
ll gcd( ll num1, ll num2){
    if( num1 == 0 || num2 == 0){ return max( num1, num2); } if( num1 > num2){ return gcd( num2, num1 % num2); } return gcd( num1, num2 % num1); }
ll lcm( ll num1, ll num2){ return (num1 * num2)/ gcd( num1, num2); }
ll factorial( ll num, ll mod){ if( ::fact_dp.size() == 0){ ::fact_dp.push_back( 1); } for( ll i = ::fact_dp.size(); i <= num; i++){ ::fact_dp.push_back( ( ::fact_dp[ i - 1] * ( i % mod)) % mod); } return ::fact_dp[ num]; }
//MARK:- Supplimentary Functions====================================
 
 
 
 
//MARK:- Test Case==================================================
bool testcase = false;
int main() { ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen( "error.txt", "w", stderr); freopen( "output.txt", "w", stdout); freopen( "input.txt", "r", stdin);
#endif
    ll t; t = 1; if( testcase) cin>> t; while( t--) solve(); return 0; }
 
 
//MARK:- Solution===================================================