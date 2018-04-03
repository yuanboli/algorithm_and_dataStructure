#include <iostream>
#include <climits>
#include <sstream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

map<string, int> word2index;
int index2cost[100010];
int index2group[100010];
int group2mincost[100010];
int main(){
    int n, k, m;
    cin >> n >> k >> m;

    for(int i = 1; i < n+1; i++){
        string tmp;
        cin >> tmp;
        word2index.insert(make_pair(tmp, i));
    }

    for(int i = 1; i < n+1; i++){
        cin >> index2cost[i];
    }

    for(int i = 1; i < k+1; i++){
        int count;
        cin >> count;
        for(int j = 0; j < count; j++){
            int idx;
            cin >> idx;
            index2group[idx] = i;
        }
    }

    // form the min cost array
    for(int i = 1; i < k+1; i++){
        group2mincost[i] = INT_MAX;
    }
    for(int i = 1; i < n+1; i++){
        int groupidx = index2group[i];
        int curcost = index2cost[i];
        group2mincost[groupidx] = min(curcost, group2mincost[groupidx]);
    }

    // get the result;
    long long total_cost = 0;
    for(int i = 0; i < m; i++){
        string tmp;
        cin >> tmp;
        int idx = word2index[tmp];
        int grp_idx = index2group[idx];
        total_cost += group2mincost[grp_idx];
    }

    cout << total_cost << endl;
    return 0;


}
