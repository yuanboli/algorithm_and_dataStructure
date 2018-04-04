#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int col[1010];
int main(){
    int n, m; // n columns, m squares
    
    cin >> n >> m;

    for(int i = 0; i < 1010; i++){
        col[i] = 0;
    }

    for(int i = 0; i < m; i++){
        int tmp;
        cin >> tmp;
        col[tmp]++;
    }

    int mi = 1010;
    for(int i = 1; i < n+1; i++){
        mi = min(mi, col[i]);
    }

    cout << mi << endl;
    return 0;
}
