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

int BSfirst(vi v,int start, int end, int val){
    while(start < end){
        int mid = start + (end-start)/2;
        if(v[mid] < val) start = mid+1;
        else if(v[mid] > val) end = mid-1;
        else end = mid;
    }
    return ((v[start]>=val)?start:start+1);
}
int BSlast(vi v,int start, int end, int val){
    while(start < end){
        int mid = start + (end-start+1)/2;
        if(v[mid] < val) start = mid+1;
        else if(v[mid] > val) end = mid-1;
        else start = mid;
    }
    return ((v[start]<=val)?start:start-1);

}


int main()
{
    fast_io(); file_i();
    int n, q;
    cin >> n;
    vi v(n);
    lp(i, n) cin >> v[i];
    cin >> q;
    while(q--){
        int h;
        cin >> h;
        int l = BSfirst(v, 0, n-1, h);
        if(l) cout << v[l-1] <<" ";
        else  cout << "X ";
        l = BSlast(v, 0, n-1, h);
        if(l<n-1) cout << v[l+1] <<el;
        else  cout << "X\n";
    }
    return 0;
}