#ifndef __RANDOM_H__
#define __RANDOM_H__

#include <cstdlib> // floor(): 取整函数
#include <crandom> // rand(), srand()
class Random{
public:
    int randomInteger(int low, int high){
        double d = rand() / (static_cast<double>(RAND_MAX) + 1);
        double s = d * (static_cast<double>(high) - low + 1);
        return static_cast<int>(std::floor(low + s));
    }
    double randomReal(double low, double high){
        double d = rand() / (static_cast<double>(RAND_MAX) + 1);
        double s = d * (high - low);
        return static_cast<int>(std::floor(low + s));
    }
    bool randomChance(double p){
        return readomReal(0,1) < p;
    }
}


#endif //__RANDOM_H__ 
