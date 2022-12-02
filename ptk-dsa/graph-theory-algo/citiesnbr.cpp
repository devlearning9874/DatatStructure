#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;



class Node{
        public:
          string name;
          list<string> nbrs;
     
          Node(string name){
            this->name = name;
          }
};

class Graph{

    unordered_map<string, Node*> m;

    public: 
       Graph(vector<string> cities){

              for(auto city: cities){
                m[city] = new Node(city);
              }
       }

       void addEdges(string x, string y, bool undir=false){
              
                m[x]->nbrs.push_back(y);

                if(undir){
                    m[y]->nbrs.push_back(x);
                }
       }

       void printCityNbr(){
               
               for(auto cities: m){
                    
                    cout<<cities.first<<"-->";

                    Node *node = cities.second;

                    for(auto nbr: node->nbrs){
                        cout<<nbr<<"->";
                    }
                     cout<<endl;
               }
       }
};



int main(){


    vector<string> cities = {"Delhi", "London", "Paris", "Newyork"};

    Graph g(cities);

    g.addEdges("Delhi", "London");
    g.addEdges("Newyork", "London");
    g.addEdges("Delhi", "Paris");
    g.addEdges("Paris", "New York");

    g.printCityNbr();

}