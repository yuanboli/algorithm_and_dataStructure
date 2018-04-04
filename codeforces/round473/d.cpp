#include <iostream>
#include <cstring>

using namespace std;



const int upper_bound = 2000001;
int candidate[2000001]; // more than 100000 primes in it
// candidate: 0 is available, 1 is invalid.
int orig[100010];
int result[100010];

int find_next(int cur){
    return 0;
}

void cross_out(int num){
    for(int i = nu,; i < upper_bound; i += num){
        candidate[i] = 1;
    }
    return 0;
}

void remove_according_to(int cur, int endwith, int restriction){
    // cur >= 2 notice.
    for(int i = cur; i <= endwith; i++){
        if(i % restriction == 0){
            cross_out(i);
        }
    }
    
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i < n+1; i++){
        cin >> orig[i];
    }

    memset(candidate, 0, sizeof(candidate)); 

    result[1] = orig[1];
    int cur = 2;
    remove_according_to(cur, result[1]);

    int already_greater = false;
    for(int i = 2; i < n+1; i++){
        
    }
}
