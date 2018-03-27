#include <iostream>

using namespace std;
int main(){
    int n, a, b;
    cin >> n >> a >> b;
    if(a >= b){
        int temp = a;
        a = b;
        b = temp;
    }

    int turn = 1;
    while(!(a + 1 == b && a & 1 == 1)){
        turn += 1;
        n /= 2;
        a = (a + 1) / 2;
        b = (b + 1) / 2;
    }

    if (n == 2){
        cout << "Final!" << endl;
    }else{
        cout << turn << endl;
    }
    return 0;
}
