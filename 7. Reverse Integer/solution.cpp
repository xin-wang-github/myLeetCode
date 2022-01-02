#include<iostream>
#include<string>
#include<vector>
#include <limits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int sign=1;
        int res=0;
        int last_res;
        if(x<0){
            sign=-1;
            x=-x;
        }

        while(x>0){
            last_res=res;
            res=res*10+x%10;
            if(res/10!=last_res) return 0;
            x=x/10;
        }

        if(res<0){
            return 0;
        } else if(sign<0){
            return -res;
        } else return res;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    cout<<numeric_limits<int>::min()<<' '<<numeric_limits<int>::max()<<endl;
    cout<<Solution().reverse(2147483640);
    return 0;
}