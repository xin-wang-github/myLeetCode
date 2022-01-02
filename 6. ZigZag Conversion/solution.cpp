#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string new_s;
        if(numRows==1) return s;
        int r,i,j;
        for(r=0;r<numRows;r++){
            if(r==0||r==numRows-1){
                for(i=r;i<s.length();i=i+2*numRows-2){
                    new_s.append(1,s[i]);
                }
            }
            else{
                for(i=r,j=2*numRows-2-i;i<s.length();i+=2*numRows-2,j+=2*numRows-2){
                    new_s.append(1,s[i]);
                    if(j<s.length()) new_s.append(1,s[j]);
                }
            }
        }
        return new_s;
    }
};



int main() {
    int l=2;
    int r=2;
    // cout<<Solution().longestPalindromeWithCenter("abcbacd",2,l,r)<<' '<<l<<' '<<r<<endl;
    cout<<Solution().convert("A",1)<<endl;
    return 0;
}