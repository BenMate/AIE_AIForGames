#include "raylib.h"
#define RAYGUY_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
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

	graph.AddEdge(a, b, 1); graph.AddEdge(b, a, 1);
	graph.AddEdge(a, c, 1); graph.AddEdge(c, a, 1);
	graph.AddEdge(c, d, 1); graph.AddEdge(d, c, 1);
	graph.AddEdge(d, f, 100); graph.AddEdge(f, d, 100);
	graph.AddEdge(d, e, 1); graph.AddEdge(e, d, 1);
	graph.AddEdge(e, g, 1); graph.AddEdge(g, e, 1);
	graph.AddEdge(f, g, 1); graph.AddEdge(g, f, 1);
	graph.AddEdge(f, h, 1); graph.AddEdge(h, f, 1);
	graph.AddEdge(e, i, 100); graph.AddEdge(i, e, 100);
	graph.AddEdge(i, h, 1); graph.AddEdge(h, i, 1);
	graph.AddEdge(e, j, 1); graph.AddEdge(j, e, 1);


	auto path = graph.FindPath(IGraph::SearchType::DIJKSTRA, a, [](auto n) {
		return n->data == 'H';
		});

	for (auto n : path) {
		std::cout << n->data << std::endl;
	}
}



int main(int argc, char** argv)
{
	bool playTest = false;

	if (playTest == true)
	{
		TestGraph();
		return 0;
	}
	else
	{
		{
			Application app(1600, 900);
			app.Run();
		}
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
