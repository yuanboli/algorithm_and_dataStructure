#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(){
    ll n, k, M, D;
    cin >> n >> k >> M >> D;
    
    ll max = 0;
    ll maxRound = (n-1)/k+1;
    for(int round = 1; round <= min(D, maxRound); round++){
        ll t = n/((round-1)*k+1);
        t = min(t, M);
        ll result = round * t;
        if(result > max){
            //cout << "Cur Strategy: " << t << endl;
            max = result;
        }

    }
    cout << max << endl;
    return 0;
}
