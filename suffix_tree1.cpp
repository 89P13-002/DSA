#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class node
{
public:
    vector<string> str;
    vector<node *> child;
    vector<vector<pair<int, int>>> num_rank;
    void printNode(){
        for(int i=0;i<child.size();i++){
            cout<<str[i]<<" ";
        }
        cout<<endl;
    }
    node(string s, vector<pair<int,int>> ip);
    int edgeChange(string s, int str_num, int sub_num, int pos);
    int checkSplit(string s);
    void addStr(string s, vector<pair<int,int>> ip);
};

void node :: addStr (string s,vector<pair<int,int>> ip)
{
    str.push_back(s);
    child.push_back(NULL);
    
    num_rank.push_back(ip);
    // num_rank.push_back(make_pair(str_num, sub_num));
}

int node ::checkSplit(string s)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (s[0] == str[i][0])
        {
            return i;
        }
    }
    return -1;
}

int node ::edgeChange(string s, int str_num, int sub_num, int pos)
{
    node *t;
    string common;
    int i = 0;
    common = s[0];
    for (i = 1; i < s.size(); i++)
    {
        if (s[i] == str[pos][i])
        {
            common += s[i];
        }
        else
        {
            break;
        }
    }
    if(common.compare(s) == 0){
        num_rank[pos].push_back(make_pair(str_num,sub_num));
        return -1;
    }

    t = new node(str[pos].substr(common.size()), num_rank[pos]);
    (t->str).push_back(s.substr(common.size()));
    t->child.push_back(NULL);
    vector<pair<int,int>> ip;
    ip.push_back(make_pair(str_num,sub_num));
    t->num_rank.push_back(ip);
    // t->num_rank.push_back(make_pair(str_num,sub_num));
    str[pos] = common;
    child[pos] = t;
    num_rank[pos].clear();
    // num_rank[pos].second = -1;
    return (common.size());
}

node :: node (string s,vector<pair<int,int>> ip)
{
    // cout<<"In constructor"<<endl;
    str.push_back(s);

    num_rank.push_back(ip);
    child.push_back(NULL);

}

class suffix_tree
{
public:
    node *root;
    suffix_tree()
    {
        root = NULL;
    }
    void addString(string s, int j);
    void print();
};

void suffix_tree ::print()
{
    node *t;
    queue<node *> q;
    t = root;
    q.push(t);
    // cout<<"In print function"<<endl;
    int i;
    int j =1;
    while (!q.empty())
    {
        node *y;
        y = q.front();
        q.pop();
        // if((y->child).size() == 0){
        //     continue;
        // }
        // cout<<(y->child).size()<<endl;
        for (i = 0; i < (y->child).size(); i++)
        {
            //cout<<"Inside for loop"<<endl;
            cout << y->str[i] << " ";
            int b;
            for(b=0;b<y->num_rank[i].size();b++){
                cout<<y->num_rank[i][b].first<<" "<<(y->num_rank[i][b].second)+1<<" ";
            }
            // if(y->num_rank[i].first != -1 ){
            //     cout<<y->num_rank[i].first<<" "<<(y->num_rank[i].second)+1<<" ";
            // }
            if (y->child[i] != NULL)
            {
                q.push(y->child[i]);
                // cout<<"Pushing "<<y->str[i]<<endl;
            }
        }
        cout<<endl;
        // j++;
    }
}

void suffix_tree ::addString(string s, int j){
    s += '$';
    int i;
    int k = s.size();
    for(i=0;i<k-1;i++){
        if(root == NULL){
            vector<pair<int,int>> ip;
            ip.push_back(make_pair(j,0));
            root = new node(s, ip);
            s = s.substr(1);
        }
        else{
            node* t;
            t = root;
            string v = s;
            while(1){
                if(t->checkSplit(v) == -1){
                    vector<pair<int,int>> ip;
                    ip.push_back(make_pair(j,i));
                    t->addStr(v, ip);
                    break;
                }
                else{
                    int l = t->checkSplit(v);
                    if(t->child[l] != NULL){
                        v = v.substr((t->str[l]).size());
                        t = t->child[l];

                        // int g = t->edgeChange(v,j,i,l);
                        // v =  v.substr(g);
                    }
                    else{
                        t->edgeChange(v,j,i,l);
                        break;
                    }
                }
            }
            s = s.substr(1);
        }
    }

}


int main()
{
    suffix_tree *b;
    b = new suffix_tree();
    b->addString("cagaagt", 1);
    b->addString("tgacag",2);
    b->addString("gaagt",3);
    b->print();
    // cout<<b->root->child[2]->child[0];
    return 0;
}
