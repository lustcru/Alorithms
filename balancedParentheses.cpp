#include <iostream>
#include <string>
using namespace std;

int main(){

    string chain;
    int countOpenParentheses = 0;
    getline(cin, chain);

    for(char character: chain){
        if(character == '('){
            countOpenParentheses++;
        }
        if(character == ')'){
            countOpenParentheses--;
        }
        if(countOpenParentheses < 0){
            cout << "invalid" << endl;
            return 0;
        }
    }
    if(countOpenParentheses == 0){
        cout << "valid" << endl;
    } else{
        cout << "invalid" << endl;
    }
  return 0;
}
