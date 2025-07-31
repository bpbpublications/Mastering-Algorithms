#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
int min_dist(int[], bool[]);
void dijsktra(int[][6],int);
int min_dist(int dist[], bool visited[]){ // finding minimum dist
   int minimum=INT_MAX,ind;
   for(int k=0; k<6; k++) {
      if(visited[k]==false && dist[k]<=minimum) {
         minimum=dist[k];
         ind=k;
      }
   }
   return ind;
}
void dijsktra(int graph[6][6],int src){
   int dist[6];
   bool visited[6];
   for(int k = 0; k<6; k++) {
      dist[k] = INT_MAX;
      visited[k] = false;
   }
   dist[src] = 0; // Source vertex dist is set 0
   for(int k = 0; k<6; k++) {
      int m=min_dist(dist,visited);
      visited[m]=true;
      for(int k = 0; k<6; k++) {


         // updating the dist of neighbouring vertex
         if(!visited[k] && graph[m][k] && dist[m]!=INT_MAX && dist[m]+graph[m][k]<dist[k])
            dist[k]=dist[m]+graph[m][k];
      }
   }
   printf("Vertex\t\tdist from source vertex\n");
   for(int k = 0; k<6; k++) {
      char str=65+k;
      printf("%c\t\t\t%d\n", str, dist[k]);
   }
}
int main(){
   int graph[6][6]= {
      {0, 1, 2, 0, 0, 0},
      {1, 0, 0, 5, 1, 0},
      {2, 0, 0, 2, 3, 0},
      {0, 5, 2, 0, 2, 2},
      {0, 1, 3, 2, 0, 1},
      {0, 0, 0, 2, 1, 0}
   };
   dijsktra(graph,0);
   return 0;
}
