#include <iostream>
#include <cstring>

using namespace std;

int thms[100010];
int awake[100010];

int bonus[100010];

int main(){
    int n, k;
    cin >> n >> k;

    for(int i = 1; i < n+1; i++){
        cin >> thms[i];
    }


    memset(bonus, 0, sizeof(bonus));

    int result = 0;
    for(int i = 1; i < n+1; i++){
        cin >> awake[i];
        if(awake[i] == 0){
            bonus[i] = thms[i];
        }else{
            result += thms[i];
        }
    }


    int max_bonus = 0;
    int last_bonus = 0;
    int idx = 0;
    for(int i = 1; i <= n-k+1; i++){
        int cur_bonus = 0;
        if(i == 1){
            for(int j = 0; j < k; j++){
                cur_bonus += bonus[i+j];
            }
        }else{
            cur_bonus = last_bonus - bonus[i-1] + bonus[i+k-1];    
        }

        if(cur_bonus > max_bonus){
            idx = i;
            max_bonus = cur_bonus;
        }
        last_bonus = cur_bonus;
    }

    result += max_bonus;
    cout << result << endl;
    return 0;
}
