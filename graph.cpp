#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
class graph{
    int vertx_num;
    int edg_num;
    vector<vector<int>> adj_mat;
    vector <vector<int>> adj_ls;
    public:
    graph(int v,int e);
    void input();
    void adj_mat_print();
    void adj_list_print();
    void BFS(int);
    void dfs(int,bool* ,vector <pair<int,int>> &);
    void DFS();
    bool cycle(int i);
};
graph :: graph(int v,int e){
    vertx_num = v;
    edg_num = e;
    adj_mat.resize(vertx_num+1);
    for(int i=0;i<vertx_num+1;i++){
        for(int j=0;j<vertx_num+1;j++){
            adj_mat[i].push_back(0);
        }
    }
    //vector<vector<int>> adj_mat(vertx_num+1 , vector<int> (vertx_num+1, 0));
    adj_ls.resize(vertx_num+1);
}
bool graph :: cycle(int i){
    static vector<bool> visited (vertx_num+1,false);
    static int j = 0;
    visited[i] = true;
    for(auto x : adj_ls[i]){
            if(visited[x] && j>2){
                return true;
            }
            j++;
            if(!visited[x] && cycle(x)){
                return true;
            }
        
    }
    return false;
}
void graph :: DFS(){
    vector <pair<int,int>> order;
    bool visited[vertx_num+1] = {false};
    int st;
    cout<<"Enter the start vertex"<<endl;
    cin>>st;
    order.push_back(make_pair(st,0));
    dfs(st,visited,order);
    int i;
    for(i=0;i<order.size();i++){
        cout<<order[i].first<<" "<<order[i].second<<endl;
    }
    return ;
}
void graph :: dfs(int st,bool* v,vector <pair<int,int>> &o){
    v[st] = true;
    cout<<st<<" "; //start to end me
    for(auto x:adj_ls[st]){
        if(v[x]==false){
            o.push_back(make_pair(x,st));
            dfs(x,v,o);
        }
    }
    //cout<<st<<" "; //last to start then
}
void graph :: BFS(int st){
    vector <pair<int,int>> order;
    bool visited[vertx_num+1] = {false};
    queue<int> q;
        visited[st] = true;
        q.push(st);
        q.push(-1);
        order.push_back(make_pair(st,0));
        order.push_back(make_pair(-1,-1));
        cout<<"BFS order traversal"<<endl;
        int j = 0;
        while(!q.empty() && j<(vertx_num+1)){
            int y = q.front();
            q.pop();
            if(y == -1){
                q.push(-1);
                j++;
                continue;
            }
            cout<<y<<" ";
            for(auto v:adj_ls[y]){
                if(visited[v]==false){
                    visited[v]=true;
                    q.push(v);
                    order.push_back(make_pair(v,y));
                }
            }
            order.push_back(make_pair(-1,-1));
        }
        cout<<endl;
        int i;
        for(i=0;i<order.size();i++){
            if(order[i].first == -1){
                continue;
            }
            cout<<order[i].first<<" "<<order[i].second<<endl;
        }
        cout<<endl;
        return ;
        
}
void graph :: adj_list_print(){
    cout<<"Your adjecency list"<<endl;
    int i;
    for(i=0;i<adj_ls.size();i++){
        cout<<i<<" -> ";
        for(auto x : adj_ls[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return ;
}
void graph :: input(){
    int i,x,y;
    //cout<<"Enter edges"<<endl;
    //vector<vector<int>> adj_mat(vertx_num+1 , vector<int> (vertx_num+1, 0));
    for(i=0;i<edg_num;i++){
        cin>>x;
        cin>>y;
        adj_mat[x][y] = 1;
        adj_mat[y][x] = 1;
        adj_ls[x].push_back(y);
        adj_ls[y].push_back(x);
    }
    for(i=1;i<vertx_num;i++){
        // sort(adj_ls[i].begin(),adj_ls[i].end(), greater<int>());
        sort(adj_ls[i].begin(),adj_ls[i].end());
    }
    return ;
}

void graph :: adj_mat_print(){
    cout<<"Adjeceny matrix "<<endl;
    int i,j;
    for(i=1;i<adj_mat.size();i++){
        for(j=1;j<adj_mat.size();j++){
            cout<<adj_mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return ;
}
int main(){
    int vertex_num,edge_num;
    cout<<"Enter total vertex and edge "<<endl;
    cin>>vertex_num>>edge_num;
    graph* g;
    g = new graph(vertex_num,edge_num);
    g->input(); 
    // if(g->cycle(2)){
    //     cout<<"sjdnf"<<endl;
    // }
    g->adj_list_print();
    g->adj_mat_print();
    int t;
    cout<<"Enter start"<<endl;
    cin>>t;
    g->BFS(t);
    g->DFS();
    return 0;
}
