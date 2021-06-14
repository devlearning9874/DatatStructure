import java.util.*;

class Cycledetectionbfs{
    public static void main(String[] args) {
    
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int e = sc.nextInt();
        ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>(n+1);
        for(int i=0; i<n+1; i++)
          adj.add(new ArrayList<Integer>());
        for(int i=0; i<e; i++){
            int u = sc.nextInt();
            int v = sc.nextInt();

            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        SolutionCycle obj = new SolutionCycle();

        boolean result = obj.bfsCycleDetection(n, adj);
        System.out.println(result);
    }
}

class Node{
    int first;
    int second;
    public Node(int first, int second){
        this.first = first;
        this.second = second;
    }
}

class SolutionCycle{

   static boolean checkCycle(int s, ArrayList<ArrayList<Integer>> adj, boolean visited[]){
           
         Queue<Node> q = new LinkedList<>();
         q.add(new Node(s,-1));

         visited[s]  = true;

         while(!q.isEmpty()){
             int node = q.peek().first;
             int par = q.peek().second;
             q.remove();

             for(Integer it : adj.get(node)){

                if(visited[it] != true){
                    visited[it] = true;
                    q.add(new Node(it,node));
                }
                else if(par != it){
                    return true;
                }
             }
         }

    return false;
   }

   public boolean bfsCycleDetection(int node, ArrayList<ArrayList<Integer>> adj){
         boolean visited[] = new boolean[node+1];

         Arrays.fill(visited, false);

         for(int i=1; i<=node; i++){

            if(visited[i] != true){

                if(checkCycle(i, adj, visited))
                     return true;
            }
         }
     return false;
   }

}