#include <iostream>
#include <cstdlib>

using namespace std;

int input[20];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> input[i];
        if(i != 0){
            if(abs(input[i] - input[i-1]) >= 2){
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;
    return 0;
}
