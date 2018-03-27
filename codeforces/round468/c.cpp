#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int get_strike_count(const int* result, const int *orig, int size=3){
    int sum = 0;
    for(int i = 0; i < size; i++){
        sum += min(result[i], orig[i]);
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    vector<int> input;
    
    int min = 100000;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        input.push_back(tmp);
        
        if(tmp < min){
            min = tmp;
        }
    }

    // get measure distribution
    int count[3];
    memset(count, 0, sizeof(count));
    int sum = 0;
    for(int i = 0; i < input.size(); i++){
        count[input[i] - min]++;
        sum += input[i] - (min + 1);
    }
    bool fixed_flag = false;
    if (count[0] == 0 || count[2] == 0){
        // fixed
        fixed_flag = true;
    }

    // initialize solution
    int result[3];
    memset(result, 0, sizeof(result));
    if(sum < 0)
        result[0] = -sum;
    else
        result[2] = sum;
    result[1] = n - abs(sum);

    int choice[3];
    memcpy(choice, result, sizeof(result));
    int strike = n;
    while(result[1] >= 0 && fixed_flag == false){
        if(get_strike_count(result, count) < strike){
            for(int i = 0; i < 3; i++)
                choice[i] = result[i];
            strike = get_strike_count(result, count);
        }

        result[0] += 1;
        result[1] -= 2;
        result[2] += 1;
    }

    cout << strike << endl;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < choice[i]; j++)
            cout << (min + i) << " ";
    cout << endl;
    return 0;

}
