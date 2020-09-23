/*
John has n tasks to do. Unfortunately, the tasks are not independent and the execution of one task is
only possible if other tasks have already been executed.
Input
The input will consist of several instances of the problem. Each instance begins with a line containing
two integers, 1 ≤ n ≤ 100 and m. n is the number of tasks (numbered from 1 to n) and m is the
number of direct precedence relations between tasks. After this, there will be m lines with two integers
i and j, representing the fact that task i must be executed before task j.
An instance with n = m = 0 will finish the input.
Output
For each instance, print a line with n integers representing the tasks in a possible order of execution.
Sample Input
5 4
1 2
2 3
1 3
1 5
0 0
Sample Output
1 4 2 5 3
*/ 

#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
typedef vector<int>vi;
vi G[10000];
bool visitado[100];
int distancia[100];
int aux_dist = 0;
queue<int>q;
stack<int>s;
int grau_adj[100000];
void dfs(int at)
{
  visitado[at] = true;
  //distancia[at] = aux_dist;
  q.push(at);

  for(int i=0; i < (int) G[at].size(); i++)
    {
      int adj = G[at][i];

      if(!visitado[adj]){
          //aux_dist++;
          dfs(adj);
        }
    }
}
int main()
{
  int n,m;
  while(cin>>n>>m && n||m){
      for(int i=1 ; i<=n;i++)
        {
          G[i].clear();
          visitado[i] = false;
          grau_adj[i] = 0;
        }
      for(int i=0;i<m;i++)
        {
          int a, b;
          cin>>a>>b;
          G[a].push_back(b);
          grau_adj[b] ++;
        }

      while(!q.empty())
        {
          q.pop();
        }
      for(int i=1;i<=n;i++)
        {
          if(!visitado[i] && grau_adj[i] == 0) dfs(i);
        }

      while(!q.empty())
        {
          cout<<q.front()<<" ";
          q.pop();
        }
      cout<<endl;
    }

}
