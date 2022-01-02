#include<iostream>
#include<string>
#include<vector>
#include<limits>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        //const int INTMIN=numeric_limits<int>::min();
        //const int INTMAX=numeric_limits<int>::max();
        int sign=1;
        int number_start=-1;
        int number_end=-1;
        int number=0;
        int last_number=0;
        int beyound_limit=0;
        for(int i=0;i<str.length();i++){
        	if(number_start<0&&str[i]!=' '){
        		if(str[i]=='-'||str[i]=='+'){
        			if(str[i]=='-'){
        				sign=-1;
        			}else{
        				sign=1;
        			}
        			number_start=i;
        		}else if(str[i]>='0'&&str[i]<='9'){
        			number_start=i;
        			number=number*10+sign*(str[i]-'0');
        		}else break;

        	}else if(number_start>=0){
        		if(str[i]<'0'||str[i]>'9'){
        			number_end=i;
        			break;
        		}else{
        			last_number=number;
        			number=number*10+sign*(str[i]-'0');
        			//cout<<"number:"<<number<<endl;
        			if(last_number!=number/10){
        				//cout<<sign<<endl;
        				if(sign>=0) return INT_MAX;
        				else return INT_MIN;
        			}
        		}
        	}
        	
        }
        //cout<<number_start<<' '<<number_end<<endl;
        return number;

    }
};

int main() {
    cout<<numeric_limits<int>::min()<<' '<<numeric_limits<int>::max()<<endl;
    cout<<Solution().myAtoi("-111134");
    return 0;
}