// @Author : Sugar 
// @Created Time : 2022-04-13 21:05:37
// @Description : 
#include "Random.h"
#include <iostream>
using std::cin;
using std::cout;
int main(int argc,char **argv){
    Random rd;
    int num;
    cin >> num;
    double sum = 0;
    for (int i = 0; i < num; i++){
        sum += rd.randomReal(0,1);
    }
    cout << sum / num << std::endl;
    return 0;
}
