ll gcd(ll a, ll b) {
    ll _max = max(a, b);
    ll _min = min(a, b);
    ll mod = _max % _min;
    return mod ? gcd(_min, _max % _min) : _min;
}