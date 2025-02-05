class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if (n <= 1) return n;

        int maxPointsOnLine = 1;
        
        for (int i = 0; i < n; i++) {
            unordered_map<string, int> slopeMap;
            int duplicate = 0, vertical = 0, localMax = 0;
            
            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                
                if (dx == 0 && dy == 0) {
                    duplicate++; // Overlapping points
                } else if (dx == 0) {
                    vertical++; // Vertical line
                } else {
                    int gcdVal = gcd(dx, dy);
                    dx /= gcdVal;
                    dy /= gcdVal;
                    string slope = to_string(dx) + "/" + to_string(dy);
                    slopeMap[slope]++;
                    localMax = max(localMax, slopeMap[slope]);
                }
            }
            
            localMax = max(localMax, vertical);
            maxPointsOnLine = max(maxPointsOnLine, localMax + duplicate + 1);
        }
        
        return maxPointsOnLine;
    }
    
private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
