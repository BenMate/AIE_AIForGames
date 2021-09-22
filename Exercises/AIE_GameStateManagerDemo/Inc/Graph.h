#pragma once

#include <vector>
#include <list>
#include <iostream>
#include <functional>
#include <algorithm>


class IGraph 
{
public :
	enum class SearchType
	{
		BFS,
		DIJKSTRA,
		//ASTAR
	};
};

template<class TNodeData, class TEdgeData>
class Graph : public IGraph
{
public:
	struct Node;
	struct Edge;

	struct Node
	{
		TNodeData data;
		std::vector<Edge> connections;
	};

	struct Edge
	{
		Node* to;
		TEdgeData data;
	};

	struct PFNode
	{
		Node* node;
		PFNode* parent = nullptr;

		int depth = 0;
		float gScore = 0;
		float hScore = 0; 

		PFNode() {}
		PFNode(Node* n, PFNode* p) : node(n), parent(p) {}
	};

	

public:
	// ===========================================================================
	// Constructor
	// ===========================================================================
	Graph()
	{

	}
	// ===========================================================================
	// Destructor
	// ===========================================================================
	virtual ~Graph()
	{
		for (auto node : m_nodes)
		{
			delete node;
		}
		m_nodes.clear();
	}
	// ===========================================================================
	// Add Node
	// ===========================================================================
	Node* AddNode(const TNodeData& data)
	{
		Node* node = new Node();
		node->data = data;
		m_nodes.push_back(node);
		return node;
	}
	// ===========================================================================
	// AddEdge
	// ===========================================================================
	void AddEdge(Node* nodeA, Node* nodeB, const TEdgeData& data)
	{
		nodeA->connections.push_back({ nodeB, data });
	}
	// ===========================================================================
	// GetNodes
	// ===========================================================================
	const std::vector<Node*>& GetNodes()
	{
		return m_nodes;
	}
	// ===========================================================================
	// For Each BFS print
	// ===========================================================================
	void ForEachBFSPrint(Node* startNode, std::function<bool(Node* n)> processNode)
	{
		std::list<Node*> stack;

		stack.push_back(startNode);

		std::list<Node*> visited;


		while (stack.empty() == false)
		{

			auto node = stack.front();
			stack.pop_front();

			visited.push_back(node);


			if (processNode(node) == false)
			{
				//TODO: calculate path
				break;
			}

			for (auto& edge : node->connections)
			{
				if (std::find(visited.begin(), visited.end(), edge.to) == visited.end() &&
					std::find(stack.begin(), stack.end(), edge.to) == stack.end())
				{
					stack.push_back(edge.to);
				}
			}
		}
	}

	// ===========================================================================
	// FindPath
	// ===========================================================================
	std::list<Node*> FindPath(SearchType type, Node* startNode, std::function<bool(Node* n)> processNode)
	{
		std::list<PFNode*> stack; //open list
		std::list<PFNode*> visited; //close list
		std::list<Node*> path;

		auto GetNodeInLists = [&](Node* nodeToFind) -> PFNode* {

			for (auto& n : stack)
				if (n->node == nodeToFind)
					return n;

			for (auto& n : visited)
				if (n->node == nodeToFind)
					return n;

			return nullptr;
		};

		// push the start node on the stack
		stack.push_back(new PFNode(startNode, nullptr));

		while (stack.empty() == false)
		{
			// Get the node from the stack and remove it
			auto pfNode = stack.front();
			stack.pop_front();

			// add the node to the visited list
			visited.push_back(pfNode);

			// did we find a target node?
			if (processNode(pfNode->node) == true)
			{
				// Calculate path
				PFNode* current = pfNode;
				while (current != nullptr)
				{
					path.push_front(current->node);
					current = current->parent;
				}
				break;
			}

			// add children to the stack
			for (auto& edge : pfNode->node->connections)
			{
				auto childNode = edge.to;
				float gScore = (pfNode->parent ? pfNode->parent->gScore : 0) + edge.data;
				float hScore = 0; //we dont know the target node if you want astar change the find node 
				int depth = pfNode->depth + 1;

				// check if the node exists in the stack/visited list
				PFNode* childPFNode = GetNodeInLists(edge.to);
				if (childPFNode == nullptr)
				{
					childPFNode = new PFNode(edge.to, pfNode);
					childPFNode->gScore = gScore;
					childPFNode->hScore = hScore;
					childPFNode->depth = depth;

					stack.push_back(childPFNode);
				}
				else if (childPFNode->gScore > gScore) 
				{
					//the child node is on te stack already
					//but we can get to it faster...update
					childPFNode->parent = pfNode;
					childPFNode->gScore = gScore;
					childPFNode->hScore = hScore;
					childPFNode->depth = depth;
				}
			}

			//sort stack by gScore;
			stack.sort( [&](const PFNode* a, const PFNode* b) -> bool {
				
				switch (type) 
				{
				case SearchType::DIJKSTRA:  return a->gScore < b->gScore;
				case SearchType::BFS:		return a->depth < b->depth;
				default:					return a->gScore < b->gScore; //default is dijkstr
				}


			});


		}

		// delete the allocated memory
		for (auto& n : stack)
			delete n;

		for (auto& n : visited)
			delete n;

		// return the found path
		// it will be empty if it's not found.
		return path;
	}


protected:
	std::vector<Node*> m_nodes;
private:
};