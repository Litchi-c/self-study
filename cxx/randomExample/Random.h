#ifndef __RANDOM_H__
#define __RANDOM_H__

#include <cmath> // floor(): 取整函数
#include <cstdlib> // rand(), srand()
#include <ctime> // git time()

class Random{
public:
		Random(){
				std::srand(time(NULL));
		}
    /* 
		 * Usage: int num = randomInteger(5, 10);
		 *  num is int, and scope is [5, 10).
		 */
    int randomInteger(int low, int high){
        double d = std::rand() / (static_cast<double>(RAND_MAX) + 1);
				double s = d * (static_cast<double>(high) - low + 1);
        return static_cast<int>(std::floor(low + s));
    }
		/*
     *  Usage: same as randomIngeger,but return a real number.
		 */
    double randomReal(double low, double high){
        double d = std::rand() / (static_cast<double>(RAND_MAX) + 1);
        double s = d * (high - low);
        return low + s;
    }
		/* 
     * ASSUME: scope of p is [0,1].
     * Usage: randomChance(0.75) 
		 * 75% return true, else return false.
		 */
    bool randomChance(double p){
        return randomReal(0,1) < p;
    }
};


#endif //__RANDOM_H__ 
