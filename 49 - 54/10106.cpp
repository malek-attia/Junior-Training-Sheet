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
    fast_io(); file_i();
    string x, y;
    while(getline(cin, x)){
        getline(cin, y);
        int sx = sz(x), sy = sz(y);
        vi n1(251, 0), n2(251, 0), ans(501, 0);
        for(int i=0; i<max(sx,sy); i++){
            if(sx>i)n1[i] = x[sx-i-1]-'0';
            if(sy>i)n2[i] = y[sy-i-1]-'0';
        }
        int remain = 0;
        for(int i = 0; i <= 250; i++){
            for(int j = 0; j <= 250; j++){
                if(!n2[i]) break;
                ans[j+i] += (n1[j] * n2[i]) + remain;
                remain = 0;
                if(ans[j+i] >= 10){
                    remain = ans[j+i]/10;
                    ans[j+i] %= 10;
                }
            }
        }
        int i = 500;
        bool zero = 1;
        while(i >= 0){
            if(ans[i] != 0){
                zero = 0;
                break;
            }
            i--;
        }
        for(; i >= 0; i--){
            cout << ans[i];
        }
        if(zero) cout << 0;
        cout << el;
    }
    return 0;
}



/*

9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999
9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999


99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999980000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001

*/