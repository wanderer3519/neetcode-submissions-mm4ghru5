class Solution {
private:
    vector<int> tpsort(vector<vector<int>>& adjList){
        int V = adjList.size();

        vector<int> indegree(V);
        for(int node = 0; node < V; node++){
            for(auto& adjNode : adjList[node])
                indegree[adjNode]++;
        }

        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);

            q.pop();

            for(auto& adjNode : adjList[node]){
                indegree[adjNode]--;

                if(indegree[adjNode] == 0)
                    q.push(adjNode);
            }
        }

        return ans;
    }

public:
    string foreignDictionary(vector<string>& words) {
        int m = words.size();


        int n = 0;

        unordered_map<char, int> st;
        vector<char> vec;

        for(auto& word : words){
            for(char ch : word){
                if(!st.count(ch)){
                    st[ch] = n++;
                    vec.push_back(ch);
                }
                
            }
        }


        vector<vector<int>> adjList(n, vector<int>());

        int nedges = 0;

        for(int i = 1; i < m; i++){
            string word1 = words[i - 1];
            string word2 = words[i];

            int n1 = word1.size();
            int n2 = word2.size();

            bool foundDiff = false;

            for(int j = 0; j < min(n1, n2); j++){
                char c1 = word1[j];
                char c2 = word2[j];
                
                if(c1 != c2){
                    adjList[st[c1]].push_back(st[c2]);
                    foundDiff = true;
                    break;
                }
            }

            if(!foundDiff && n1 > n2)
                return "";
        }

        vector<int> vec1 = tpsort(adjList);

        if(vec1.size() != n)
            return "";

        string str = "";
        for(int node : vec1){
            str.push_back(vec[node]);
        }

        return str;
        
    }
};
