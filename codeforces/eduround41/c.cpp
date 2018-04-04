#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;


int pieces[5][10010];
int cost[5][2];
int n;

int get_cost(int* arr, int start){
    int cost = 0;
    int should = start;
    for(int i = 0; i < n*n; i++){
        if(arr[i] != should)
            cost++;

        should += 1;
        should %= 2;
    }
    return cost;
}

int main(){
    cin >> n;

    for(int i = 1; i < 5; i++){
        for(int j = 0; j < n*n; j++){
            char ch = getchar();
            while(ch =='\n')
                ch = getchar();
            pieces[i][j] = ch - '0';
        }
    }

    for(int i = 1; i < 5; i++){
        cost[i][0] = get_cost(pieces[i], 0);
        cost[i][1] = get_cost(pieces[i], 1);
    }

    int result;
    result = cost[1][0] + cost[2][0] + cost[3][1] + cost[4][1];
    result = min(result, cost[1][0] + cost[2][1] + cost[3][0] + cost[4][1]);
    result = min(result, cost[1][0] + cost[2][1] + cost[3][1] + cost[4][0]);
    result = min(result, cost[1][1] + cost[2][0] + cost[3][0] + cost[4][1]);
    result = min(result, cost[1][1] + cost[2][0] + cost[3][1] + cost[4][0]);
    result = min(result, cost[1][1] + cost[2][1] + cost[3][0] + cost[4][0]);

    cout << result << endl;
    return 0;

}
