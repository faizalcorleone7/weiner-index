#include<bits/stdc++.h>			//weiner index
using namespace std;
struct node
{
	int no,dist;
};
/*bool comp(struct node n1,struct node n2)
{
    return n1.dist<n2.dist;
};*/
vector<int> arr[1000000];
vector<int> dist1[1000000];
vector<struct node> v[1000000];
int dijkstra(vector<struct node> v[],vector<int> arr[],vector<int> dist[],int start,int n)
{
	int s1=0;
	vector<int> queue;
	queue.push_back(start);
	arr[start][start]=1;
	while (queue.size()!=0)
	{
		for (int i=0;i<v[queue[0]].size();i++)
		{
			if (dist[start][v[queue[0]][i].no]==-1)
			{
				dist[start][v[queue[0]][i].no]=v[queue[0]][i].dist+dist[start][queue[0]];	//updating distance for first time
			}
			else
			{
				dist[start][v[queue[0]][i].no]=min(dist[start][v[queue[0]][i].no],v[queue[0]][i].dist+dist[start][queue[0]]);	//updating minimum distance	
			}
			if (arr[start][v[queue[0]][i].no]==-1)
			{
				queue.push_back(v[queue[0]][i].no);		//pushing back of neighbours that have not been visited
				arr[start][v[queue[0]][i].no]=1;
			}
		}
		queue.erase(queue.begin());
		if (queue.size()>0)
		{
		int m=0,m1=dist[start][queue[0]];
		for (int i=0;i<queue.size();i++)	//finding minimum
		{
			if (dist[start][queue[i]]<m1)
			{
				m1=dist[start][queue[i]];
				m=i;
			}
		}
		if (m!=0)
		{
			swap(queue[0],queue[m]);
		}
		}
	}
	//cout<<"Node at start now - "<<start<<endl;
	//cout<<"arr[start].size() = "<<arr[start].size()<<endl;
	for (int i=start;i<n;i++)
	{
		//cout<<start<<" - "<<i<<" = "<<dist[start][i]<<endl;
		if (dist[start][i]!=-1)
		{s1=s1+dist[start][i];}
	}
	cout<<"s1 = "<<s1<<endl;
	return s1;
}
int main()
{
	int n,m;
	cout<<"Enter the number of nodes: ";
	cin>>n;
	cout<<"Enter the number of edges: ";
	cin>>m;	
	for (int i=0;i<m;i++)
	{
		cout<<i<<" ";
		cout<<"Enter nodes and the distance between them: ";
		int a,b,d;
		cin>>a>>b>>d;
		//d=1;
		struct node t1,t2;
		t1.no=b;
		t1.dist=d;
		t2.no=a;
		t2.dist=d;
		v[a].push_back(t1);
		v[b].push_back(t2);
	}	
	cout<<"done 1"<<endl;
	for (int i=0;i<n;i++)	//initialisation of arr and dist matrix
	{
		for (int j=0;j<n;j++)
		{
			arr[i].push_back(-1);
			dist1[i].push_back(-1);
		}
	}
	cout<<"done 2"<<endl;
	for (int i=0;i<n;i++)	//initialisation of neighbouring node distance
	{
		for (int j=0;j<v[i].size();j++)
		{
				dist1[i][v[i][j].no]=v[i][j].dist;
			//	dist1[v[i][j].no][i]=v[i][j].dist;
		}
	}
	cout<<"done 3"<<endl;
	for (int i=0;i<n;i++)		//self loops have 0 distance
	{
		dist1[i][i]=0;
	}
	cout<<"done 4"<<endl;
	int s=0;
	cout<<"Initailisation done"<<endl;
	for (int i=0;i<n;i++)
	{
		s=s+dijkstra(v,arr,dist1,i,n);
	}
	cout<<s;
	return 0;
}
