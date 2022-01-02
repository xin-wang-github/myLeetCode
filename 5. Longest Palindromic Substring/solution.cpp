#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        s=insertSeparator(s);
        // cout<<"size: "<<s.length()<<endl;
        vector<int> p;
        string p_str,max_p_str;
        int max_length=1;
        p.push_back(1);
        
        int c=0;
        int r=1;
        int l=0;
        int i,j;
        for(i=1;i<s.length();i++){
            j=2*c-i;
            // cout<<"j="<<j<<" i="<<i<<endl;
            

            if(j>=0&&p[j]<=r-i){
                // cout<<"--- test:"<<"j"<<j<<"pj"<<p[j]<<"r"<<r<<"i"<<i<<endl;
                p.push_back(p[j]);
            }else{
                c=i;
                r=max(r,c);
                l=2*c-r;
                p_str=longestPalindromeWithCenter(s,c,l,r);
                p.push_back(p_str.length());
                if(p_str.length()>max_length){
                    max_length=p_str.length();
                    max_p_str=p_str;
                }
            }
        }
        

        return removeSeparator(max_p_str);
    }
    string insertSeparator(string s){
        string new_s;
        for(int i=0;i<s.length();i++){
            new_s.append(1,'#');
            new_s.append(1,s[i]);
        }
        new_s.append(1,'#');
        return new_s;
    }
    string removeSeparator(string s){
        string new_s;
        for(int i=1;i<s.length();i=i+2){
            new_s.append(1,s[i]);
        }
        return new_s;
    }
    string longestPalindromeWithCenter(string& s,int c,int &l, int& r){
        int n=s.length();
        // cout<<"in l="<<l<<" c= "<<c<<" r="<<r<<endl;
        while(r<n||l>=0){
            if(s[l]==s[r]){
                l--;
                r++;
            }else{
                break;
            }
        }
        l++;
        r--;
        // cout<<"out l="<<l<<" c= "<<c<<" r="<<r<<endl;
        return s.substr(l,r-l+1);
    }
};



int main() {
    int l=2;
    int r=2;
    // cout<<Solution().longestPalindromeWithCenter("abcbacd",2,l,r)<<' '<<l<<' '<<r<<endl;
    cout<<Solution().longestPalindrome("bananas")<<endl;
    return 0;
}