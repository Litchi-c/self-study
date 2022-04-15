// @Author : Sugar
// @Created Time : 2022-04-13 22:12:36
// @Description :
#include <string>
#include <algorithm>

bool isPalindrome(std::string &str){
    std::string temp(str);
    std::reverse(temp.begin(), temp.end());
    return str == temp;
}
