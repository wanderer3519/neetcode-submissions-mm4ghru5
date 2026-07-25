class Solution {
private:
    void bfs(int src, vector<int>& vis, vector<vector<int>>& adjList){
        int n = adjList.size();
        queue<int> q;

        vis[src] = 1;
        q.push(src);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto& adjNode : adjList[node]){
                if(!vis[adjNode]){
                    vis[adjNode] = 1;
                    q.push(adjNode);
                }
            }
        }
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int cnt = 0;
        vector<int> vis(n);
        vector<vector<int>> adjList(n, vector<int>());

        for(auto& e : edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                cnt++;
                bfs(i, vis, adjList);
            }
        }

        return cnt;
    }
};
