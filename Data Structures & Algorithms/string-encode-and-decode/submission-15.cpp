class Solution {
public:

    string encode(vector<string>& strs) {
        string enc = "";
        for(auto& s : strs){
            enc += to_string(s.length());
            enc += 'D';
            enc += s;
        }

        // cout << enc << '\n';

        return enc;
    }

    vector<string> decode(string& s) {
        vector<string> vec;
        int n = s.length();

        for(int i = 0; i < n; i++){
            // char c = s[i];

            // if(c >= '0' && c <= '9'){
            //     // isdigit() -> equivalent
            //     int j = c - '0';
            //     string str = "";
                
            //     while(j--){
            //         str += s[++i];
            //     }

            //     vec.push_back(str);
            // }
            int len = 0;
            while(s[i] != 'D'){
                len = 10 * len + s[i++] - '0';
            }

            string str = "";
                
            while(len--){
                str.push_back(s[++i]);
            }

            // cout << str << '\n';

            vec.push_back(str);
            // i--;
        }

        return vec;
    }
};
