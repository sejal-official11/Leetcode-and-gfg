class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
         vector<int> ans;
        if(n == 1) {
            ans.push_back(0);
            return ans;
        }
        
        vector<int> adj[n];
        vector<int>deg(n);
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(deg[i] == 1) {
                q.push(i);
            }
        }

        // we know we can have atmost 2 elements remianing as an answer so
        while(n > 2) {
            int size = q.size();
            n = n - size;

            while(size > 0) {
                int node = q.front();
                q.pop();

                for(auto nbr : adj[node]) {
                    deg[nbr]--;
                    if(deg[nbr] == 1) {
                        q.push(nbr);
                    }
                }
                 size--;    
            }
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

        }
        return ans;
    }
};