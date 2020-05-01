#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Graph{
        int vertex;
    public:
        vector<int> graph[1000];
        Graph(int vertices){
            this->vertex=vertices;
            graph[vertices];
            cout<<"constructor is called"<<endl;
        }
        void single_direction(int src,int dest);
        void bi_direction(int src,int dest);
        void BFS(int start);
        void DFS(int start,vector<bool>&visit);
        void graph_print();
};
void Graph::graph_print(){
    for(int x=0;x<vertex;x++){
        cout<<"Vertex for "<<x<<endl;
        for(int y=0;y<graph[x].size();y++)cout<<graph[x][y]<<" ";
        cout<<endl;
    }
}
void Graph::single_direction(int src,int dest){
    graph[src].push_back(dest);
}
void Graph::bi_direction(int src,int dest){
    graph[src].push_back(dest);
    graph[dest].push_back(src);
}
void Graph::BFS(int start){
    vector<bool>visit(vertex+1,false);
    visit[start]=true;
    queue<int>qu;
    qu.push(start);
    while(!qu.empty()){
        int n=qu.front();
        cout<<n<<" ";
        qu.pop();
        for(int i=0;i<graph[n].size();i++){
            if(visit[graph[n][i]]==false){
                qu.push(graph[n][i]);
                visit[graph[n][i]]=true;
            }
        }
    }
}
void Graph::DFS(int start,vector<bool>&visit){
    visit[start]=true;
    cout<<start<<" ";
    for(int i=0;i<graph[start].size();i++){
        if(visit[graph[start][i]]==false)DFS(graph[start][i],visit);
    }
    return;
}
int main(){
    int n,src,dest;
    cin>>n;
    Graph gp(5);
    for(int i=0;i<n;i++){
        cin>>src>>dest;
        gp.bi_direction(src,dest);
    }
    gp.graph_print();
    cout<<"enter the traversal vertex"<<endl;
    int vertex;
    cin>>vertex;
    vector<bool>visit(n+1,false);
    gp.DFS(vertex,visit);
    cout<<endl;
    cout<<"perfect"<<endl;
}