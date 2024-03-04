#include <iostream>
#include <vector>
using namespace std;

int main(){
    int input;
    int imparSize, parSize, limite;
    cin >> input;
    if(input % 2 == 0){
        imparSize = input + 1;
        parSize = input;
    } else {
        imparSize = input;
        parSize = input - 1;
    }

    vector <int> impar(imparSize, 0);
    vector <int> par(parSize, 0);

    cout << endl;
    impar[imparSize / 2] = 1;

    for(int num: impar){
         if(num == 0){
            cout << "   ";
        } else{
            cout << " " << num << " ";
        }
    }
    cout << endl;

    for(int x = 1; x < input; x++){
        if(x % 2 == 0){
            limite = imparSize;
        } else{
            limite = parSize;
            cout << " ";
        }
        for(int y = 0; y < limite; y++){
            if(x % 2 == 0){
                if(y == 0){
                    impar[y] = par[0];
                } else{
                    impar[y] = par[y-1] + par[y];
                }
                if(impar[y] == 0){
                    cout << "   ";
                } else{
                    cout << " " << impar[y] << " ";
                }   
            } else{
                par[y] = impar[y] + impar[y+1];
                if(par[y] == 0){
                    cout << "   ";
                } else{
                    cout << " " << par[y] << " ";
                }
            }
        }
        cout << endl;
    }

}
