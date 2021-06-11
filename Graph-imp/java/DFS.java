import java.util.*;


class DFS {

    public static void main(String[] args) {
       Scanner sc = new Scanner(System.in);
       int n = sc.nextInt();
       int e = sc.nextInt();

       ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>(n+1);
       for(int i=0; i<n+1; i++)
         adj.add(new ArrayList<Integer>());

       for(int i=0; i<e; i++){
           int  u = sc.nextInt();
           int  v = sc.nextInt();

           adj.get(u).add(v);
           adj.get(v).add(v);
       }

       Sol obj = new Sol();

       ArrayList<Integer> result = new ArrayList<>();

       result = obj.dfsOfGraph(n, adj);

       for(Integer it: result){
           System.out.print(it+" ");
       }
    }
       
}



class Sol{

    void dfs(int node, boolean visited[], ArrayList<ArrayList<Integer>> adj, ArrayList<Integer> storeDfs ){
             storeDfs.add(node);
             for(Integer it: adj.get(node)){
                if(visited[it] == false){
                    visited[it] = true;
                    dfs(it, visited, adj, storeDfs);
                }
             }
    }

    public ArrayList<Integer> dfsOfGraph(int node, ArrayList<ArrayList<Integer>> adj){
        ArrayList<Integer> storeDfs = new ArrayList<>();
        boolean[] visited = new boolean[node+1];
    
        for(int i=1; i<=node; i++){
            if(visited[i] == false){
                 visited[i] = true;
                 dfs(i,visited, adj, storeDfs);
            }
        }

      return storeDfs;
    }
}
