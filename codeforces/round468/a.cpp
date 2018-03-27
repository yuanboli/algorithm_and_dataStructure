#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int tired = 0;
    int turn = 1;
    if(a >= b){
        int temp = a;
        a = b;
        b = temp;
    }
    while(a < b){
        a ++;
        tired += turn;

        if (a >= b){
            break;
        }

        b --;
        tired += turn;

        turn ++;
    }
    cout << tired << endl;
}