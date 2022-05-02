// @Author : Sugar 
// @Created Time : 2022-04-11 20:19:26
// @Description : 
                 
#include <iostream>
#include "QuickFindUF.h"
using std::cin;
using std::cout;
                 
int main(int argc,char **argv){
		int num;
		cin >> num;
		QuickFindUF uf{num};
		cout << uf;	
		int p,q;
		while (cin >> p >> q){
				if (!uf.connected(p,q)){
						uf.UFunion(p,q);
						cout << p << " " << q << std::endl;
						cout << uf;
				}
    }
		
    return 0;
}
