class Solution {
private:
    bool hasCycle(vector<vector<int>>& adjList){
        int n = adjList.size();

        vector<int> vis(n);

        queue<pair<int, int>> q;
        
        vis[0] = 1;
        q.push({0, -1});

        while(!q.empty()){
            int node = q.front().first;
            int par = q.front().second;
            q.pop();

            for(auto& adjNode : adjList[node]){
                if(!vis[adjNode]){
                    vis[adjNode] = 1;
                    q.push({adjNode, node});
                }
                else if(adjNode != par)
                    return true;
            }
        }

        return false;
    }

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
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n, vector<int>());

        for(auto& e : edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }

        // acyclicity
        if(hasCycle(adjList))
            return false;

        // connectivity
        vector<int> vis(n);
        bfs(0, vis, adjList);

        for(int i = 0; i < n; i++){
            if(!vis[i])
                return false;
        }

        return true;
    }
};
