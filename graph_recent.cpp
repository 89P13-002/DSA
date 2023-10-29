#include<bits/stdc++.h>
using namespace std;
void DFS (int st,vector<vector<int>> adj_ls,vector<bool> &visited,vector<pair<int,int>> &order){
    int i;
    visited[st] = true;
    for(i=0;i<adj_ls[st].size();i++){
        if(visited[adj_ls[st][i]]==false){
            order.push_back(make_pair(adj_ls[st][i],st));
            DFS(adj_ls[st][i],adj_ls ,visited,order);
        }
    }
    return; 
}
vector<pair<int,int>> BFS(int st,int vertex_num,vector<bool> &visited,vector<vector<int>> adj_ls){
    vector <pair<int,int>> order;
    queue<int> q;
        visited[st] = true;
        q.push(st);
        q.push(-1);
        order.push_back(make_pair(st,0));
        // cout<<"Pushing -1 from start"<<endl;
         order.push_back(make_pair(-1,-1));
       // cout<<"BFS order traversal"<<endl;
        int j;
        int k =0 ;
        while(!q.empty() ){
            int y = q.front();
            q.pop();
            if(y==-1 && q.empty()){
                // cout<<"Pushing -1 from empty"<<endl;
                // order.push_back(make_pair(-1,-1));
                break;
            }
            if(y == -1 && !q.empty()){
                q.push(-1);
                cout<<"Pushing -1 from y=-1"<<endl;
                order.push_back(make_pair(-1,-1));
                continue;
            }
            for(j=0;j<adj_ls[y].size();j++){
                if(visited[adj_ls[y][j]]==false){
                    visited[adj_ls[y][j]]=true;
                    q.push(adj_ls[y][j]);
                    order.push_back(make_pair(adj_ls[y][j],y));
                }
            }
        }
        // int i;
        // for(i=0;i<order.size();i++){
        //     cout<<order[i].first<<" "<<order[i].second<<endl;
        // }
        return order;  
}
void adj_list_print(vector<vector<int>> adj_ls){
    cout<<"Your adjecency list"<<endl;
    int i,j;
    for(i=1;i<adj_ls.size();i++){
        for(j=0;j<adj_ls[i].size();j++){
            cout<<adj_ls[i][j]<<" ";
        }
        cout<<endl;
    }
    return ;
}
void  adj_mat_print(vector<vector<int>> adj_mat){
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
    vector<vector<int>> adj_mat(vertex_num+1 , vector<int> (vertex_num+1, 0));
    vector <vector<int>> adj_ls;
    adj_ls.resize(vertex_num+1);
    int i,x,y;
    for(i=0;i<edge_num;i++){
        cin>>x;
        cin>>y;
        adj_mat[x][y] = 1;
        adj_mat[y][x] = 1;
        adj_ls[x].push_back(y);
        adj_ls[y].push_back(x);
    }
    for(i=1;i<vertex_num;i++){
        // sort(adj_ls[i].begin(),adj_ls[i].end(), greater<int>());
        sort(adj_ls[i].begin(),adj_ls[i].end());
    }
    vector<bool> visited(vertex_num+1,false);
    // adj_list_print(adj_ls);
    // adj_mat_print(adj_mat);
    int st;



    //for bfs
    // vector<vector <pair<int,int>>> ans;
    // vector<pair<int,int>> temp; 
    // for(st = 1;st<vertex_num+1;st++){
    //     if(visited[st]==false){
    //         temp = BFS(st,vertex_num,visited,adj_ls);
    //         ans.push_back(temp);
    //     }
    // }

    // // for(st = 0;st<ans.size();st++){
    // //     sort(ans[st].begin(),ans[st].end());
    // // }
    // int j;
    // cout<<ans.size()<<endl;
    // for(i=0;i<ans.size();i++){
    //     cout<<ans[i].size()<<endl;
    //     for(j=0;j<ans[i].size();j++){
    //         cout<<ans[i][j].first<<" ";//<<ans[i][j].second<<" ";
    //     }
    //     cout<<endl;
    // }
    

    //for dfs
    vector<vector <pair<int,int>>> ans;
    for(st = 1;st<vertex_num+1;st++){
        if(visited[st]==false){
            vector<pair<int,int>> order;
            order.push_back(make_pair(st,0));
            DFS(st,adj_ls,visited,order);
            ans.push_back(order);
            order.clear();
        }
    }
    int j;
    cout<<ans.size()<<endl;
    for(i=0;i<ans.size();i++){
        cout<<ans[i].size()<<endl;
        for(j=0;j<ans[i].size();j++){
            cout<<ans[i][j].first<<" "<<ans[i][j].second<<" "<<endl;
        }
    }
    return 0; 
}
