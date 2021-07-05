
#include "raylib.h"
#include "raygui.h"

#include "Application.h"
#include "Graph.h" 

#include <iostream>


void TestGraph() {

	Graph<char, int> graph;
	auto a = graph.AddNode('A');
	auto b = graph.AddNode('B');
	auto c = graph.AddNode('C');
	auto d = graph.AddNode('D');
	auto e = graph.AddNode('E');
	auto f = graph.AddNode('F');
	auto g = graph.AddNode('G');
	auto h = graph.AddNode('H');
	auto i = graph.AddNode('I');
	auto j = graph.AddNode('J');

	graph.AddEdge(a, b, 0); graph.AddEdge(b, a, 0);
	graph.AddEdge(a, c, 0); graph.AddEdge(c, a, 0);
	graph.AddEdge(c, d, 0); graph.AddEdge(d, c, 0);
	graph.AddEdge(d, f, 0); graph.AddEdge(f, d, 0);
	graph.AddEdge(d, e, 0); graph.AddEdge(e, d, 0);
	graph.AddEdge(e, g, 0); graph.AddEdge(g, e, 0);
	graph.AddEdge(f, g, 0); graph.AddEdge(g, f, 0);
	graph.AddEdge(f, h, 0); graph.AddEdge(h, f, 0);
	graph.AddEdge(e, i, 0); graph.AddEdge(i, e, 0);
	graph.AddEdge(i, h, 0); graph.AddEdge(h, i, 0);
	graph.AddEdge(e, j, 0); graph.AddEdge(j, e, 0);


	auto path = graph.FindPath(a, [](auto n) {
		return n->data == 'H';
	});

	for (auto n : path) {        
		std::cout << n->data << std::endl;
	}

}


int main(int argc, char** argv)
{
	//TestGraph();
	//return 0;
	{
		Application app(800, 450, "GameAI");
		app.Run();
	}
	return 0;
}













//TODO:

//fix hard coded "60" value representing the radius of nearby nodes to connect
// ( getters and setters)

//add variables to customise the graph2Deditor's node 
//- node color
//- line color
//- node radius 
//- node outline

//can you do a hovor color on nodes (prevent nodes from being placed on top of each other) ...tip -  get nearbynode function 

