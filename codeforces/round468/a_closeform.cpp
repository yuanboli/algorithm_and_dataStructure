#include <iostream>
#include <algorithm>

using namespace std;
int main(){
    int a, b;
    cin >> a >> b;
    if (a > b)
        swap(a, b);
    int t = (a + b) / 2;
    int result = (1 + t - a) * (t - a) / 2 + (1 + b - t) * (b - t) / 2;
    cout << result << endl;
    return 0;

}
