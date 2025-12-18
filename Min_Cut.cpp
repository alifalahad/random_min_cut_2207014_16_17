#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int u,v,w;
};
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;cin>>n;
    int m;
    cin>>m;
    vector<Edge>E;
    for(int i=0;i<m;i++){
        //1 indexed
        int a,b;
        cin>>a>>b;
        Edge e;
        e.u=a;
        e.v=b;
        e.w=1;
        E.push_back(e);
    }

    while(E.size()>1){
        //1 indexed
        n++;
        int rnd=(rand() %(E.size())); 
        int a,b;
        a=E[rnd].u;
        b=E[rnd].v;
        //n
        auto e=E[rnd];
        E.erase(E.begin()+rnd);

        for(int i=0;i<E.size();i++){
            auto tmp=E[i];
            if(tmp.u==a|| tmp.v==a){
                if(tmp.v==a)swap(tmp.v,tmp.u);
                //a=tmp.u;
                int tb=tmp.v;
                int wt=tmp.w;
                E.erase(E.begin()+i);
                //find
                int toAdd=0;
                for(int j=0;j<E.size();j++){
                    auto news=E[j];
                    if((news.u==n&&news.v==tb)||(news.v==n&&news.v==tb)){
                        toAdd=news.w;
                        E.erase(E.begin()+j);
                        break;
                    }


                }
                Edge newe;
                newe.w=n;
                newe.v=tb;
                newe.w=wt+toAdd;
                E.push_back(newe);


            }
            else if(tmp.u==b||tmp.v==b){
                if(tmp.u==b)swap(tmp.u,tmp.v);
                int ta=tmp.u;
                int wt=tmp.w;
                 E.erase(E.begin()+i);
                 //find
                int toAdd=0;
                for(int j=0;j<E.size();j++){
                    auto news=E[j];
                    if((news.u==n&&news.v==ta)||(news.v==n&&news.v==ta)){
                        toAdd=news.w;
                        E.erase(E.begin()+j);
                        break;
                    }


                }
                Edge newe;
                newe.w=n;
                newe.v=ta;
                newe.w=wt+toAdd;
                E.push_back(newe);
                
                


            }
        }




    }
    cout<<E[0].w<<endl;
}