#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vi vector<int>

#define tc    \
    int tc_counter ;    \
    cin >> tc_counter ; \
    while (tc_counter--)

#define el "\n"
#define spc <<" "<<

#define lpi(i, j, n)   for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)   for(int i=(j);i>=(int)(n);--i)
#define lp(i,n)    lpi(i,0,n)

#define all(v)  ((v).begin()), ((v).end())
#define sz(v)  ((int)((v).size()))
#define maxi(v) *max_element(all(v))
#define mini(v) *min_element(all(v))
#define sort(v) sort(all(v))
#define sum(v) accumulate(all(v),0)
#define find(set, x) set.find(x) != set.end()

void fast_io()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
}

void file_i()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif // ONLINE_JUDGE
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

vector<ll> v;

ll count(ll n, ll m, ll a, ll d, ll mult=1, ll total=0, ll idx = 0){
    if(idx==5){
        if(total)
            return (total%2?1:-1)*(m/mult - (n-1)/mult);
        return 0;
    }
    return count(n, m, a, d, lcm(mult, v[idx]), total+1, idx+1)
    + count(n, m, a, d, mult, total, idx+1);
}

int main()
{
    fast_io; file_i();
    tc
    {
        ll n, m, a, d;
        cin >> n >> m >> a >> d;
        v = {a, a+d, a+2*d, a+3*d, a+4*d};
        cout << (m-n+1) - count(n, m, a, d) <<el;
    }
    
    return 0;
}