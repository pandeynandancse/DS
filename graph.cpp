1) Town Judge : https://leetcode.com/problems/find-the-town-judge/discuss/891189/Using-Degree


              a) InDegree OutDegree storation
              b) each edge of Directed graph can be stored as vector of vectors(i.e. [src,dst])
              
              
              
              Solution : 
              
              
              int findJudge(int N, vector<vector<int>> &trust)
                    {
                        vector<int> degree(N + 1);
                        for (int i = 0; i < trust.size(); i++)
                        {
                            degree[trust[i][0]]--; // outDegree
                            degree[trust[i][1]]++; // inDegree
                        }

                        for (int i = 1; i <= N; i++)
                        {
                            if (degree[i] == N - 1)
                                return i;
                        }
                        return -1;
                    }
                    
                    
                    
                    
                    
                    
                    
                    
                    
