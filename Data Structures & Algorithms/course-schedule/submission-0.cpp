#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        
        for (const auto& pre : prerequisites) {
            int course = pre[0];
            int prerequisite = pre[1];
            adj[prerequisite].push_back(course);
            indegree[course]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        int visited_courses = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            visited_courses++; 
            for (int next_course : adj[curr]) {
                indegree[next_course]--;
                if (indegree[next_course] == 0) {
                    q.push(next_course);
                }
            }
        }
        return visited_courses == numCourses;
    }
};