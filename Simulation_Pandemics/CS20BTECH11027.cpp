#include <bits/stdc++.h>
using namespace std;

//function for adding an edge between two vetices.

void add_edge(vector <int> adj[],int i,int j){
    adj[i].push_back(j);
    adj[j].push_back(i);
}

//class for the heap node.

class  Heap_node {
  
  public :
  int node_id;
  int time_stamp;
  string event_type;

  
  Heap_node (int id,int time,string event){
      node_id=id;
      time_stamp=time;
      event_type=event;
  }
};

//comparison function while creating an min priority queue.

struct comp{

    bool operator()(const Heap_node &a ,const Heap_node &b){
      return a.time_stamp > b.time_stamp ;

  }
};

//BFS function for caluclating shortest distance of a node from the intial node.

bool BFS(vector<int> adj[], int intial, int final, int v,
         int pred[], int dist[])
{
    
    list<int> q;
 
    
    bool visited[v];
 

    for (int i = 0; i < v; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }
 
    
    visited[intial] = true;
    dist[intial] = 0;
    q.push_back(intial);
 
    
    while (!q.empty()) {
        int u = q.front();
        q.pop_front();
        for (int i = 0; i < adj[u].size(); i++) {
            if (visited[adj[u][i]] == false) {
                visited[adj[u][i]] = true;
                dist[adj[u][i]] = dist[u] + 1;
                pred[adj[u][i]] = u;
                q.push_back(adj[u][i]);
 
                
                if (adj[u][i] == final)
                    return true;
            }
        }
    }
 
    return false;
}

//function for caluclating shortest distance.

int short_distance(vector<int> adj[], int s,int dest, int v)
{
    
    int pred[v], dist[v];
 
    if (BFS(adj, s, dest, v, pred, dist) == false) {
        cout << "Given source and destination"
             << " are not connected";
        return -1;
    }
 
    vector<int> path;
    int crawl = dest;
    path.push_back(crawl);
    while (pred[crawl] != -1) {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }
 
    
    return  dist[dest];
 
}



int main(){

srand(time(0));

int array[100]; //array for storing the value of nodes.

vector <int> adj[100]; //vectors for storing the adjacent vertices of a vextex.

set<int> S,I,R; // sets for susceptible,infected,recovery events.

priority_queue< Heap_node,vector<Heap_node>, comp > Q; //priority queue for inserting the nodes.

int  plot[20][3]; //2D array for storing no of susceptible,infected,recovered at a time stamp.

int stamp[100]; //stamp array for storing infection time stamps of a node.

set<int> P; 

for (int i=0;i<100;i++){
    array[i]=i;
}

for (int i=0;i<100;i++){

    for (int j=i+1;j<100;j++){

        int random =rand()%2;    //random is 0 for tail and 1 for head.

        if (random==1){

          add_edge(adj,array[i],array[j]); // we add an edge between 2 nodes iff we get an head.

        }
    }
}

for (int i=0;i<100;i++){
    S.insert(array[i]); //intially all the individual are in susceptible set S.
}

Heap_node * tmp = new Heap_node(0,0,"Infection"); //starting node u . 

Q.push(*tmp);

int s= 1+rand()%4;

Heap_node * tmp1  = new Heap_node (0,s,"Recovery"); //recovery event for u.

Q.push(*tmp1);


//these 4 are temporary variables which will be used in the while loop.

int count1=0;
int count2=0;
int count3=0;
int c;

while(1){

    count1++;

    Heap_node e = Q.top(); //min element of the priority queue.

    //printf("%d ",e.time_stamp);

     c=e.time_stamp;
    
    P.insert(c);

    Q.pop(); //deletes the min element of the priority queue

    if (e.event_type=="Recovery"){

        R.insert(e.node_id); //adds to the set R.

        I.erase(e.node_id); // deletes from the set I.

        count2++;
    }
    if (e.event_type=="Infection"){
       
        I.insert(e.node_id);  // adds to the set I.

        S.erase(e.node_id);   //deletes from the set S.

        count3++;

        for (auto x :adj[e.node_id]){ //for neighbours of an individual

            if (S.find(x)!=S.end()){ //cheeck for that the neighbours should be susceptible.

             for (int i=0;i<5;i++){ //tossing a coin 5 times.

                 int j=i+1;

                 if (rand()%2==1){ //if an head occurs 

                     S.erase(x);
                     
                  Heap_node * temp = new Heap_node (x,e.time_stamp+j,"Infection"); //infection event for the neighbour.

                  stamp[x]= e.time_stamp + j; //store infection time stamp of an node in the stamp array.

                  Q.push(*temp); // add the neighbour with the random time stamp to priority queue.

                  int k = e.time_stamp+ j+1+ (rand () % 5);

                  Heap_node * temp1 = new Heap_node (x,k,"Recovery"); //recovery event for the neighbour.

                  Q.push(*temp1); //add the neighbour with its recovery time stamp.

                  delete(temp);

                  delete(temp1);

                     break; //break the loop if we occur an head.

                 }
             }
            }
        }
    }

      plot[c][0]=100-(count3); // no of susceptible individuals at a time stamp.

      plot[c][1]=count3-count2; // no of infected individuals at a time stamp.

      plot[c][2]=count2; // no of recovered individuals at a time stamp.
 
    
  if (Q.empty()){ //loop breaks when the priority queue is empty.
      break;
  }
}



printf("\nPlot of number of susceptible,infected,recovered individuals against time stamp:\n");

printf("\n");

for (auto i=P.begin();i!=P.end();++i){

    printf("time stamp: %d , ",*i);

    printf("No of susceptible individuals: %d , ",plot[*i][0]);

    printf("No of infected individuals: %d , ",plot[*i][1]);

    printf("No of recovered individuals: %d\n ",plot[*i][2] );
}


printf("\n");

printf("Shortest distances from node 0 are :\n");

printf("\n");

for (int i=1;i<100;i++){

    printf("shortest distance of node %d is : %d , time instant at which node is infected : %d \n",i,short_distance(adj,0,i,100),stamp[i]);

}

    return 0;
}