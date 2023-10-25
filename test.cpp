class Solution { 
public: 
    bool findingWater(int r, int c, int k, vector<vector<char>>& desert) { 
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
        queue<pair<int, int>> q; 
        vector<vector<int>> timeToDry(r, vector<int>(c, -1)); 
 
        // Find the initial position of '2' 
        int startX, startY; 
        for (int i = 0; i < r; i++) { 
            for (int j = 0; j < c; j++) { 
                if (desert[i][j] == '2') { 
                    startX = i; 
                    startY = j; 
                    break; 
                } 
            } 
        } 
 
        // Initialize time to reach the starting position as 0 
        timeToDry[startX][startY] = 0; 
        q.push({startX, startY}); 
 
        while (!q.empty()) { 
            int x = q.front().first; 
            int y = q.front().second; 
            q.pop(); 
 
            // Calculate the time to reach the current cell 
            int currentTime = timeToDry[x][y]; 
            for (const vector<int>& dir : directions) { 
                int newX = x + dir[0]; 
                int newY = y + dir[1]; 
 
                if (newX >= 0 && newX < r && newY >= 0 && newY < c && timeToDry[newX][newY] == -1) { 
                    if (desert[newX][newY] == '1') { 
                        // Calculate the time it takes to reach the water patch 
                        int distance = abs(newX - startX) + abs(newY - startY); 
                        int timeToReach = (distance + k - 1) / k; 
 
                        // Calculate the time for the water patch to dry up 
                        int timeToDryUp = currentTime + 1; 
 
                        // Check if you can reach the water patch before it dries up 
                        if (timeToReach < timeToDryUp) { 
                            return true; 
                        } 
                    } 
                    timeToDry[newX][newY] = currentTime + 1; 
                    q.push({newX, newY}); 
                } 
            } 
        } 
 
        return false; 
    } 
};