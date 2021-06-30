#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;

typedef pair<int, int> PII;

class Solution
{
    public:
        int minimumJumps(vector<int> &forbidden, int a, int b, int x)
        {
            unordered_set<int> f(forbidden.begin(), forbidden.end());
            // each state is a pair {p, t}
            // p is the position of the node
            // t is the direction the former node traverse to current node, 0 for forward, 1 for backward
            queue<PII> q;
            // each node has two states
            // s[i].first == 1 represents the node has been visited from forward
            // s[i].second == 1 represents the node has been visitied from backward
            vector<PII> s(6000, {0, 0});
            
            int steps = 0;
            q.push({0, 0});
            
            while ( q.size() )
            {
                int n = q.size();
                // the current queue has n nodes, these nodes have the same steps
                while ( n -- )
                {
                    auto u = q.front();
                    q.pop();
                    if ( u.first == x ) return steps;

                    int forward = u.first + a;
                    if ( forward >= 0 and forward < 6000 and !s[forward].first and !f.count(u.first) )
                    {
                        // node {forward, 0} is visited from backward -> for checking if the next node can move backward
                        q.push({forward, 0});
                        // node {forward, 0} has been visited from backward -> for checking if the next node can be visited
                        s[forward].first = 1;
                    }

                    int backward = u.first - b;
                    if ( backward >= 0 and !u.second and !s[backward].second and !f.count(u.first) )
                    {
                        q.push({backward, 1});
                        s[backward].second = 1;
                    }
                }
                steps ++ ;
            }
            return -1;
        }
};