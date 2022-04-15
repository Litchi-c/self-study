// @Author : Sugar 
// @Created Time : 2022-04-13 21:55:19
// @Description : 

#include "Random.h"
#include <iostream>
using std::cin;
using std::cout;

int main(int argc,char **argv){
    Random rd;
    int num = 10000;
    int year;
    cout << "Please Enter a year:";
    cin >> year;
    cout << "There are 10000 atoms initially" << std::endl;
    while (year--){
        for (int i = num; i > 0; i--)
            if (rd.randomChance(0.5))
                num--;
        cout << "There are " << num << " atoms "
            << "at the end of years " << year << std::endl;
    }
    return 0;
}
