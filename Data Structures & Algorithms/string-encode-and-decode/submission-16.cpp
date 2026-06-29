#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string enc = "";
        for(auto& s : strs){
            enc += to_string(s.length());
            enc += 'D'; // Monkey.D.Luffy
            enc += s;
        }

        return enc;
    }

    vector<string> decode(string& s) {
        vector<string> vec;
        int n = s.length();

        for(int i = 0; i < n; i++){
            
            int len = 0;
            while(s[i] != 'D'){
                len = 10 * len + s[i++] - '0';
            }

            string str = "";
                
            while(len--){
                str.push_back(s[++i]);
            }


            vec.push_back(str);
        }

        return vec;
    }
};
