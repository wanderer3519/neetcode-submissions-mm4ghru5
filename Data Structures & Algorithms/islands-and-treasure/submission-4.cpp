const int INF = INT_MAX;

int dr[] = {-1, 0, 0, 1};
int dc[] = {0, -1, 1, 0};

bool in(int x, int size){
    return 0 <= x && x < size;
}

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        // vector<vector<int>> vis(ROWS, vector<int>(COLS));

        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                if(grid[r][c] == 0){
                    q.push({{r, c}, 0});
                    // vis[r][c] = 1;
                }
            }
        }

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(in(nr, ROWS) && in(nc, COLS) && grid[nr][nc] == INF){
                    // vis[nr][nc] = 1;
                    grid[nr][nc] = d + 1;
                    q.push({{nr, nc}, d + 1});
                }
            }
        }
    }
};
