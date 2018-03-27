#include <iostream>
#include <cstring>


using namespace std;
int main(){
    // dp is depth, p is parent, cnt is count of each depth
    int dp[100010], cnt[100010];
    memset(dp, 0, sizeof(dp));
    memset(cnt, 0, sizeof(cnt));
    int n;
    cin >> n;
    dp[1] = cnt[1] = 1;
    for(int i = 2; i <= n; i++){
        int x;
        cin >> x;
        dp[i] = dp[x] + 1;
        cnt[dp[i]]++;
    }

    int result = 0;
    for(int i = 1; i <= n; i++)
        result += (cnt[i] % 2);

    cout << result;
    return 0;
}
