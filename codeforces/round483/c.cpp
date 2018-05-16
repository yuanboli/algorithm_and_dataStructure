#include <iostream>
#include <ios>
#include <numeric>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a%b);
}

bool dividesexp(ll q, ll b){
    while(b != 1){
        while(q % b == 0){
            q /= b;
        }
        b = gcd(q, b);
    }
    return q == 1;
}
int main(){
    int n;
    ll p, q, b;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    while(n--){
        cin >> p >> q >> b;
        ll d = gcd(p, q);
        q /= d;
        b = gcd(q, b);
        if(dividesexp(q, b)){
            cout << "Finite\n";
        }else{
            cout << "Infinite\n";
        }
    }
    return 0;
}
