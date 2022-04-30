// @Author : Sugar
// @Created Time : 2022-04-16 22:00:20
// @Description :
#include "Random.h"
#include <iostream>
#include <fstream>
using std::cin;
using std::cout;

int main(int argc,char **argv){
  std::ifstream wordTxt;

  wordTxt.open("word.txt");

  if (!wordTxt.is_open()) return -1;

  std::string champion;
  std::string tmp;
  Random rd;

  while (!wordTxt.eof()){
    wordTxt >> tmp;
    if (rd.randomChance(0.375)){
      champion = tmp;
    }
  }
  cout << champion << std::endl;
  wordTxt.close();
  return 0;
}
