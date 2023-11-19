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

struct point{
    double x;
    double y;
};

struct rectangle{
    point LL;
    point UR;
    point UL;
    point LR;
    rectangle(point _LL, point _UR){
        LL = _LL;
        UR = _UR;
        UL.x = LL.x; UL.y = UR.y; 
        LR.x = UR.x; LR.y = LL.y; 
    }
};

bool isOverlap(rectangle w1, rectangle w2){
    return !(w1.UR.x <= w2.LL.x || w1.UR.y <= w2.LL.y);
}


int main()
{
    fast_io(); file_i();
    tc
    {
        double a;
        cin >> a;
        a = 360/(180 - a);
        cout << (a == floor(a)?"YES":"NO") <<el;
    }
    return 0;
}