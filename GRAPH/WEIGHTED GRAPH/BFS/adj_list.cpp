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
		map<T,list<pair<T,int> > > node;

	public:
		graph(int vertex,int edge)								//constructor 
		{
			v=vertex;
			e=edge;
		}

		void addedge(T s,T d,int w,bool directed_graph)				//method for add edge in graph
		{
			node[s].push_back(make_pair(d,w));
			if(!directed_graph)									//if undirected graph then add edge in both direction
			{
				node[d].push_back(make_pair(s,w));
			}
		}

		void print_graph()										//print graph
		{
			for(auto i:node)
			{
				cout<<i.first<<" -> ";
				for(auto j:i.second)
				{
					cout<<j.first<<", "<<j.second<<"\t";
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
					if(visited.find(i.first)==visited.end())			//if node not visited yet
					{
						q.push(i.first);								//add node to queue
						visited.insert(i.first);						//mark node as visited
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
		int w;
		cout<<"enter edge-1 and edge-2 and weight : ";
		cin>>e1>>e2>>w;
		g.addedge(e1,e2,w,false);
	}

	g.print_graph();

	string source;
	cout<<"enter vertex on which you want to apply BFS : ";
	cin>>source;
	g.bfs(source);
}