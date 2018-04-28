#include <iostream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

int grid[110][110];
int result[110][110];

void updateRow(int i, int j, int k){
    bool flag = true;
    for(int offset = 0; offset < k; offset++){
        if(grid[i][j+offset] == 0){
            flag = false;
        }
    }
    if(flag != false){
        for(int offset = 0; offset < k; offset++){
            result[i][j+offset] += 1;
        }
    }
    
}

void updateCol(int i, int j, int k){
    bool flag = true;
    for(int offset = 0; offset < k; offset++){
        if(grid[i+offset][j] == 0){
            flag = false;
        }
    }
    if(flag != false){
        for(int offset = 0; offset < k; offset++){
            result[i+offset][j] += 1;
        }
    }
    
}

int main(){
    int n, k;
    string line;
    getline(cin, line);
    stringstream ss(line);
    
    ss >> n >> k;

    memset(grid, 0, sizeof(grid));
    memset(result, 0, sizeof(result));
    
    for(int i = 1; i < n+1; i++){
        getline(cin, line);
        for(int j = 1; j < n+1; j++){
            char ch;
            ch = line[j-1];
            if(ch == '#'){
                grid[i][j] = 0;
            }else{
                grid[i][j] = 1;
            }
        }
    }


    /*
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
    */

    //horizontal decker
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n-k+1; j++){
            updateRow(i, j, k);
        }
    }

    //vertical decker
    for(int i = 1; i <= n-k+1; i++){
        for(int j = 1; j <= n; j++){
            updateCol(i, j, k);
        }
    }

    int max, max_i, max_j;
    max = 0;
    max_i = max_j = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(result[i][j] > max){
                max = result[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }

    cout << max_i << " " << max_j << endl;
    return 0;
}
