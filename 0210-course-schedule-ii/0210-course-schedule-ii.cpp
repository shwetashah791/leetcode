class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses,0);
        vector<vector<int>> adjList(numCourses);
        for(const auto& pre:prerequisites){
            int course=pre[0],prereq=pre[1];
            adjList[prereq].push_back(course);
            inDegree[course]++;
        }
        queue<int>q;
        vector<int>order;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int course=q.front();
            q.pop();
            order.push_back(course);
            for(int nextCourse:adjList[course]){
                inDegree[nextCourse]--;
                if(inDegree[nextCourse]==0){
                    q.push(nextCourse);
                }
            }
        }
        return (order.size()==numCourses)? order:vector<int>();
    }
};