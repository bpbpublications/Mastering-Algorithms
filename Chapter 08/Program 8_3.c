#include <bits/stdc++.h>
using namespace std;
#define V 4
void printSolution(int color[]);
bool isSafe(int v, bool graph[V][V], int color[], int c)
{
	for (int i = 0; i < V; i++)
		if (graph[v][i] && c == color[i])
			return false;
	return true;
}
// A recursive utility function to solve m coloring problem
bool graphColoringUtil(bool graph[V][V], int m, int color[], int v)
{
	// base case: If all vertices are assigned a color then return true
	if (v == V)
		return true;
	// Consider this vertex v and try different colors
	for (int c = 1; c <= m; c++) {
		if (isSafe(v, graph, color, c)) {
			color[v] = c;
			if (graphColoringUtil(graph, m, color, v + 1) == true)
				return true;
			// If assigning color c doesn't lead to a solution then remove it
			color[v] = 0;
			}
		}
	      //If no color can be assigned to this vertex then return false
	return false;
}
/* This function solves the m Coloring problem using Backtracking. It mainly uses graphColoringUtil() to solve the problem. It returns false if the m colors cannot be assigned, otherwise return true and prints assignments of colors to all vertices. Please note that there may be more than one solutions, this function prints one of the feasible solutions.*/
bool graphColoring(bool graph[V][V], int m)
{
// Initialize all color values as 0. This initialization is needed correct functioning of isSafe()
	int color[V];
	for (int i = 0; i < V; i++)
		color[i] = 0;
	// Call graphColoringUtil() for vertex 0
	if (graphColoringUtil(graph, m, color, 0) == false) {
		cout << "Solution does not exist";
		return false;
	}
	printSolution(color);
	return true;
}
// A utility function to print solution
void printSolution(int color[])
{
	cout << "Solution Exists:"
		<< " Following are the assigned colors"
		<< "\n";
	for (int i = 0; i < V; i++)
		cout << " " << color[i] << " ";
	cout << "\n";
}
int main()
{
	// Create following graph and test whether it is 3 colorable
	bool graph[V][V] = {
		{ 0, 1, 1, 1 },
		{ 1, 0, 1, 0 },
		{ 1, 1, 0, 1 },
		{ 1, 0, 1, 0 },
	};
	// Number of colors
	int m = 3;
	// Function call
	graphColoring(graph, m);
	return 0;
}
