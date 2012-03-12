
typedef long long ll;
struct Triple
{
	ll d, x, y;
	Triple(ll q, ll w, ll e ) : d( q ), x( w ), y( e ) {}
};
Triple egcd( ll a, ll b )
{
	if( !b ) return Triple( a, ll( 1 ), ll( 0 ) );
	Triple q = egcd( b, a % b );
	return Triple( q.d, q.y, q.x - a / b * q.y );
}
Triple ldioph( ll a, ll b, ll c )
{
	Triple t = egcd( a, b );
	if( c % t.d ) return Triple( 0, 0, 0 );
	t.x *= c / t.d; t.y *= c / t.d;
	return t;
}
