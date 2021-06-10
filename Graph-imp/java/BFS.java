import java.util.*;
import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;


    class BFS{
        public static void main(String[] args) {
         
            int n ,e;
    
            Scanner sc = new Scanner(System.in);
             n = sc.nextInt();
             e = sc.nextInt();
           
            
            
            ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>(n+1);
            for(int i=0; i<n+1; i++)
            adj.add(new ArrayList<Integer>());
            for(int i=0; i<e; i++){
                int u = sc.nextInt();
                int v = sc.nextInt();
                
                adj.get(u).add(v);
                adj.get(v).add(u);
               
            }
           
    
            ArrayList<Integer> bfsResult =  new ArrayList<>();

            Solution objBfs = new Solution();
    
            bfsResult = objBfs.bfsOfGraph(n, adj);
            
            for(Integer it: bfsResult){
                
                System.out.print(it+" ");
            }
    
           
    
        }
    }



/* 
BFS
 */
class Solution {

    public static ArrayList<Integer> bfsOfGraph(int N, ArrayList<ArrayList<Integer>> adj){
         ArrayList<Integer> bfs = new ArrayList<>();
         boolean visited[] = new boolean[N+1];

         for(int i=1; i<=N; i++){

            if(visited[i]==false){
                Queue<Integer> q = new LinkedList<>();
                q.add(i);
                visited[i] = true;

                while(!q.isEmpty()){
                    int node = q.poll();
                    bfs.add(node);

                    for(Integer it:adj.get(node)){
                          if(visited[it]==false){
                              visited[it] = true;
                              q.add(it);
                          }
                    }
                }
            }
         }
         return bfs;
    }

}

