class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> degrees(numCourses);//记录所有顶点的入度,未初始化的为0
        vector<vector<int>> adjacents(numCourses); //邻接表
        queue<int> zero;//零入度的顶点
        int num = numCourses;
        for (int i = 0; i < prerequisites.size(); i++)
        {
            degrees[prerequisites[i][0]]++;//入顶点
            adjacents[prerequisites[i][1]].push_back(prerequisites[i][0]);//出顶点
        }
        for (int i = 0; i < numCourses; i++)
            if (degrees[i] == 0) {
                zero.push(i); //入度为0的先入队列
                num--;
            }

        while (!zero.empty()) {
            int temp = zero.front();
            zero.pop();
            for (int j = 0; j < adjacents[temp].size(); j++)
                if (--degrees[adjacents[temp][j]] == 0) {
                    zero.push(adjacents[temp][j]);
                    num--;
                }

        }
        if (num == 0)
            return true;
        return false;
    }
};