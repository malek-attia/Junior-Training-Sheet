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

int main()
{
    fast_io; file_i();
    int r, c, w;
    while(cin >> r >> c >> w){
        if(!r && !c && !w) break;
        int sum = 0;
        while(c >= 8 && r >= 8){
            int m1 = 0, m2 = 0;
            if(c-1+w >= 8) m1 = (c-1+w - 8)/2 + 1;
            if(r-1+w >= 8) m2 = (r-1+w - 8)/2 + 1;
            sum += m1 + m2 - w;
            c--; r--;
        }
        cout << sum <<el;
    }
    return 0;
}
