/*******************************************|
|===========================================|

                    ال
                Time Limit
                  صابتني
              ورب العرش نجاني

|===========================================|
|*******************************************/

#include<bits/stdc++.h>
//color a & curl parrot.live
//type in cmd w ed3ely ;)

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

bool f(vector<ll> v, ll d, ll c){
    int last = -1;
    for(int i=0; i < sz(v) && c; i++){
        if(last==-1 || v[i]-v[last] >= d){
            c--;
            last = i;
        }
    }
    return (!c);
}

int main()
{
    fast_io(); file_i();
    tc
    {
        ll n, c;
        cin >> n >> c;
        vector<ll> v(n);
        lp(i, n) cin >> v[i];
        asort(v);
        ll l = 1, r = 1e10;
        while(l <= r){
            ll mid = l + (r - l)/2;
            if(f(v, mid, c)) l = mid+1;
            else r = mid-1;
        }
        cout << r;
        if(tc_counter) cout << el;
    }
    return 0;
}