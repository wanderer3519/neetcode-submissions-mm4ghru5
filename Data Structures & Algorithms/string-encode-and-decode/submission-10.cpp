class Solution {
public:

    string encode(vector<string>& strs) {
        string enc = "";
        for(auto& str : strs){
            enc += str;
            enc += '~';
        }

        return enc;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int n = s.size();
        
        string temp = "";
        for(int i = 0; i < n; i++){
            char c = s[i];
            if(c != '~')
                temp += c;
            else{
                ans.push_back(temp);
                // i++;
                temp = "";
            }
        }

        return ans;
    }
};
