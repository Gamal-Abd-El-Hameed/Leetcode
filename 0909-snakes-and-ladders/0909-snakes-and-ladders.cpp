class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> flattenedBoard(n * n + 1, 0); // Include 0 to make indexing easier
        
        // Flatten the 2D board into a 1D vector
        int idx = 1;
        for (int i = n - 1; i >= 0; i--) {
            if ((n - 1 - i) % 2 == 0) {
                for (int j = 0; j < n; j++) {
                    flattenedBoard[idx++] = board[i][j];
                }
            } else {
                for (int j = n - 1; j >= 0; j--) {
                    flattenedBoard[idx++] = board[i][j];
                }
            }
        }
        
        vector<int> dist(n * n + 1, INT_MAX);
        dist[1] = 0; // Start from cell 1
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1}); // {distance, cell}
        
        while (!pq.empty()) {
            int curr_dist = pq.top().first;
            int curr = pq.top().second;
            pq.pop();
            
            if (curr == n * n) {
                // Reached the end
                return dist[curr];
            }
            
            // Roll a 6-sided die
            for (int i = 1; i <= 6; i++) {
                int next = curr + i;
                if (next > n * n) {
                    continue; // Skip if next is out of bounds
                }
                
                if (flattenedBoard[next] != -1) {
                    // If there's a snake or ladder, go to its destination
                    next = flattenedBoard[next];
                }
                
                if (dist[next] > dist[curr] + 1) {
                    // If this path is shorter, update the distance and enqueue
                    dist[next] = dist[curr] + 1;
                    pq.push({dist[next], next});
                }
            }
        }
        
        return -1; // Cannot reach the end
    }
};
