#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    // incorrect tree
    if(n >= 6){
        cout << "1 2" << endl;
        cout << "2 3" << endl;
        cout << "2 4" << endl;
        for(int i = 5; i < n+1; i++){
            cout << "1 " << i << endl;
        }
    }else{
        cout << "-1" << endl;
    }

    // correct tree
    for(int i = 1; i < n; i++){
        cout << i << " " << i+1 << endl;
    }

    return 0;
}
