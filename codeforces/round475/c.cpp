#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 9;
int ans;

int po(int a, int b){
    int ans = 1;
    while(b){
        if(b & 1){
            ans = 1ll * ans * a % mod;
        }
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return ans;
}

// modular multiplicative inverse, notice that 1e9 + 9 is prime, btw, 1e9 + 7 is also prime

int main(){
    int n, a, b, k;
    string s;
    cin >> n >> a >> b >> k;
    cin >> s;

    ll sum = 0;
    for(int i = 0; i < k; i++){
        if(s[i] == '+'){
            sum = (sum + 1ll * po(a, n-i) * po(b, i) % mod) % mod;
        }else{
            sum = (sum - 1ll * po(a, n-i) * po(b, i) % mod + mod) % mod; //plus mod to make sure non negative
        }
    }
    

    //ll t = po(a, k*(mod-2)%(mod-1)) * po(b, k) % mod;
    ll tmp = po(a, 1ll*k*(mod-2) % (mod-1)) % mod;
    ll t = 1ll * tmp * po(b, k) %mod;
    if(t == 1){
        cout << (1ll * sum * (n+1) / k) % mod << endl;
    }else{
        cout << (1ll * sum * po(t-1, mod-2)%mod * (po(t, (n+1)/k)-1) %mod) %mod << endl;
    }
    return 0;
    
}
