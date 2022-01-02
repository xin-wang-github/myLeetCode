#include<iostream>
#include<string>
#include<vector>
#include<limits>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int y=0;
        int x_i=x;
        while(x>0){
        	y=y*10+x%10;
        	x/=10;
        }
        return x_i==y;
    }
};

int main() {
    //cout<<numeric_limits<int>::min()<<' '<<numeric_limits<int>::max()<<endl;
    cout<<Solution().isPalindrome(12212);
    return 0;
}