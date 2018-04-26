#include <iostream>

using namespace std;
int main(){
    int k, n, s, p;
    cin >> k >> n >> s >> p;
    int sheetPerPerson = (n-1)/s + 1;
    int sheetNeeded = sheetPerPerson * k;
    int result = (sheetNeeded-1) / p + 1;
    cout << result << endl;
    return 0;
}
