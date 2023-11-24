#include<bits/stdc++.h>
//color a & curl parrot.live

using namespace std;

#define ll long long
#define ld long double
#define vi vector<int>
#define vc vector<char>
#define vb vector<bool>
#define vll vector<ll>

#define in [&](){int num; cin >> num; return num;}()
#define ins [&](){string s; cin >> s; return s;}()
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
#define asort(v) sort(all(v))
#define sum(v) accumulate(all(v),0)
#define sfind(set, x) set.find(x) != set.end()


void fast_io()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
}

void file_i()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif // ONLINE_JUDGE
}

ll gcd(ll a, ll b) { return (!b? a : gcd(b, a % b));}

ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b;}

bool isPrime (int x){
    for(int i = 2; i*i <= x; i++) if(x%i == 0) return 0;
    return (x<2? 0 : 1);
}



int main()
{
    fast_io(); file_i();
    ll n, l;
    cin >> n >> l;
    vll v(n);
    lp(i, n) cin >> v[i];
    asort(v);
    ll mx = -1;
    lpi(i, 1, n) mx = max(mx, v[i]-v[i-1]);
    if(v[0] > (double)mx/2 || l-v[n-1] > (double)mx/2){
        cout << (double)max(v[0], l-v[n-1]);
    }else{
        cout << fixed << setprecision(10) << (double)mx/2;
    }
    
    return 0;
}