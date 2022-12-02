#include<iostream>;
#include<list>;
using namespace std;


class Graph{
 
       int V;
       list<int> *l;
    
    public:
       Graph(int v){
        this->V = v;
        l = new list<int>[V];
       }

       void addEdge(int i, int j, bool undir=true){
              l[i].push_back(i);

              if(undir){
                l[j].push_back(i);
              }
       }


       void printGraph(){
            // Iterate over the linked list
            
       }


};



int main(){

   Graph g(6);

   g.addEdge(0, 1);
   g.addEdge(0, 4);
   g.addEdge(2, 1);
   g.addEdge(3, 4);
   g.addEdge(4, 5);
   g.addEdge(2, 3);
   g.addEdge(3, 5);
   
   
    return 0;
}