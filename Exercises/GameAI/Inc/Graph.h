#pragma once


#include <vector>
#include <list>
#include <iostream>
#include <functional>
#include <algorithm>

template<class TNodeData, class TEdgeData>
class Graph
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
	// FindNode
	// ===========================================================================
	std::list<Node*> FindPath(Node* startNode, std::function<bool(Node*)> processNode)
	{
		std::list<PFNode*> stack;
		std::list<PFNode*> visited;
		std::list<Node*> pathNodes;

		auto GetNodeInLists = [&](Node* nodeToFind)->PFNode* {
			for (auto& pn : stack)
				if (pn->node == nodeToFind)
					return pn;

			for (auto& pn : visited)
				if (pn->node == nodeToFind)
					return pn;

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
			if (processNode(pfNode->node) == true) {

				// Calculate path
				PFNode* current = pfNode;
				while (current != nullptr)
				{
					pathNodes.push_front(current->node);
					current = current->parent;
				}
				break;
			}

			// add children to the stack
			for (Edge& edge : pfNode->node->connections)
			{
				// check if the node exists in the stack/visited list
				PFNode* pfChild = GetNodeInLists(edge.to);
				if (pfChild == nullptr)
				{
					pfChild = new PFNode(edge.to, pfNode);
					stack.push_back(pfChild);
				}
			}
		}

		// delete the allocated memory
		for (auto pfNode : visited)
			delete pfNode;

		for (auto pfNode : stack)
			delete pfNode;

		// return the found path
		// it will be empty if it's not found.
		return pathNodes;
	}


protected:
	std::vector<Node*> m_nodes;
private:
};