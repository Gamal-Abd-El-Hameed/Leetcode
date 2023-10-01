class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> flattenedBoard(n * n + 1, 0);

        int value = 1, direction = 1;
        for (int i = n - 1; i >= 0; i--) {
            int j = (direction == 1) ? 0 : n - 1;
            while (j >= 0 && j < n) {
                flattenedBoard[value++] = board[i][j];
                j += direction;
            }
            direction *= -1;
        }

        vector<int> distances(n * n + 1, INT_MAX);
        distances[1] = 0; // Start from cell 1

        queue<int> q;
        q.push(1); // Start from cell 1

        while (!q.empty()) {
            int curr = q.front(); q.pop();

            if (curr == n * n) {
                // Reached the end
                return distances[curr];
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

                if (distances[next] == INT_MAX) {
                    // If not visited, enqueue and mark as visited
                    distances[next] = distances[curr] + 1;
                    q.push(next);
                }
            }
        }

        return -1; // Cannot reach the end
    }
};