class Solution {
public:

    string encode(vector<string>& strs) {
        // length#string
        string crypt = "";
        for(auto& str : strs){
            int len = str.size();
            string enc_str = to_string(len) + '#' + str;

            crypt += enc_str;
        }

        // cout << crypt << '\n';

        return crypt;
    }

    vector<string> decode(string s) {
        vector<string> vec;
        int n = s.size();


        // bool flag = true;
        for(int i = 0; i < n; i++){
            int num = 0;
            
            while(i < n && isdigit(s[i])){
                num = num * 10 + (s[i] - '0');
                i++;
            }
            
            // if(flag){
            //     cout << num << '\n';
            //     cout << i << '\n';
            //     flag = false;
            // }
            
            // if(i < n)
            //     cout << s[i] << '\n';
            string str = s.substr(i + 1, num);
            
            // cout << str << '\n';
            vec.push_back(str);

            i += num;
        }

        return vec;
    }
};
