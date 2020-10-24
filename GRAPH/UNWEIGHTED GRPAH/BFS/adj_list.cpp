#include<iostream>
#include<string>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<list>
#include<vector>
#include<queue>

using namespace std;

template <typename T>
class graph
{
	private:
		int v,e;
		map<T,list<T> > node;

	public:
		graph(int vertex,int edge)								//constructor 
		{
			v=vertex;
			e=edge;
		}

		void addedge(T s,T d,bool directed_graph)				//method for add edge in graph
		{
			node[s].push_back(d);
			if(!directed_graph)									//if undirected graph then add edge in both direction
			{
				node[d].push_back(s);
			}
		}

		void print_graph()										//print graph
		{
			for(auto i:node)
			{
				cout<<i.first<<" -> ";
				for(auto j:i.second)
				{
					cout<<j<<" ";
				}
				cout<<endl;
			}
		}

		void bfs(T source)										//method bfs
		{
			queue<T> q;											//queue for inserting neighbours
			unordered_set<T> visited;							//set of visited nodes
			q.push(source);										//insert source node in queue
			visited.insert(source);								//mark source as visited
			

			while(!q.empty())
			{
				T front=q.front();								//front node of queue
				cout<<front<<" ";

				for(auto i:node[front])
				{
					if(visited.find(i)==visited.end())			//if node not visited yet
					{
						q.push(i);								//add node to queue
						visited.insert(i);						//mark node as visited
					}	
				}

				q.pop();										//pop front node from queue
			}
		}
};

int main()
{
	int v,e;
	cout<<"how many vertex in graph? : ";
	cin>>v;
	cout<<"how many edge in graph? : ";
	cin>>e;

	graph<string> g(v,e);										//create object of graph class

	for(int i=0;i<e;i++)
	{
		string e1,e2;
		cout<<"enter edge-1 and edge-2 : ";
		cin>>e1>>e2;
		g.addedge(e1,e2,false);
	}

	g.print_graph();

	string source;
	cout<<"enter vertex on which you want to apply BFS : ";
	cin>>source;
	g.bfs(source);
}