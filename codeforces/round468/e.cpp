#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>

using namespace std;
int dp[30][5010][30];
int main(){
    string s;
    cin >> s;
    int len = s.size();
    memset(dp, 0, sizeof(dp)); 

    for(int i = 0; i < len; i++){
        for(int j = 1; j <= len - 1; j++){
            dp[s[i] - 'a'][j][s[(i+j)%len] - 'a']++;
        }
    }

    double result = 0;
    // notice prob = \sum_{f} (# f)/(len) * (# work out | f) / (# all | f) = \sum_{f} (# work out | f) / len = (# work out) / len
    for(int i = 0; i < 26; i++){
        int ma = 0;
        for(int j = 1; j <= len-1; j++){
            int temp = 0;
            for(int k = 0; k < 26; k++){
                if(dp[i][j][k] == 1){
                    temp ++;
                }
            }
            ma = max(ma, temp);
        }
        result += 1.0 * ma / len;
    }

    cout << setprecision(7) << result << endl;
    return 0;

}
