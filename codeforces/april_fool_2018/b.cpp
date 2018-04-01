#include <iostream>
#include <set>
#include <string>

using namespace std;



int main(){
    set<string> normal_response;
    normal_response.insert("great!");
    normal_response.insert("not bad");
    normal_response.insert("cool");
    normal_response.insert("don't think so");
    normal_response.insert("don't touch me");
    
    set<string> grumpy_response;
    grumpy_response.insert("don't even");
    grumpy_response.insert("are you serious?");
    grumpy_response.insert("worse");
    grumpy_response.insert("terrible");
    grumpy_response.insert("go die in a hole");
    grumpy_response.insert("no way");
    
    for(int i = 0; i < 10; i++){
        cout << i << endl << flush;
        string response;
        getline(cin, response);
        if(normal_response.find(response) != normal_response.end()){
            cout << "normal" << endl;
            break;
        }
        if(grumpy_response.find(response) != grumpy_response.end()){
            cout << "grumpy" << endl;
            break;
        }
    }
    return 0;
}
