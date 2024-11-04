/*
Design LRU cache:
To design an LRU (Least Recently Used) Cache in C++ in an optimal way, you can use a combination of a hash map and a doubly linked list. This approach ensures 
O(1) time complexity for both get and put operations.

Key Data Structures:
Hash Map (unordered_map): Maps keys to nodes in the doubly linked list for quick lookup.
Doubly Linked List: Stores the cache items and maintains the order from most recently used to least recently used.
Steps to Implement:
Use a doubly linked list to keep track of the usage order.
Use an unordered map for quick access to the nodes of the doubly linked list.
When a new item is added or an existing item is accessed, move it to the front of the list (most recently used position).
If the cache exceeds its capacity, remove the node at the end of the list (least recently used).

*/

#include <iostream>
#include <unordered_map>

using namespace std;

class Node
{
	public:
		int key;
		int value;
		Node *prev;
		Node *next;
		
		Node(int k, int v)
		{
			key = k;
			value = v;
			prev = NULL;
			next = NULL;
		}
};

class lruCache
{
	public:
		int capacity;
		Node *head;
		Node *tail;
		unordered_map<int, Node*>cacheMap;
		
		lruCache(int capacity)
		{
			this->capacity = capacity;
			head = new Node(-1, -1);
			tail = new Node(-1, -1);
			head->next = tail;
			tail->prev = head;
		}
		
		// utility method to add node at front
		void add(Node *node)
		{
			Node *nextNode = head->next;
			head->next = node;
			node->prev = head;
			node->next = nextNode;
			nextNode->prev = node;
		}
		
		// utility method to remove a node
		void remove(Node *node)
		{
			Node *prevNode = node->prev;
			Node *nextNode = node->next;	
			prevNode->next = nextNode;
			nextNode->prev = prevNode;
		}
		
		void put(int key, int val)
		{
			if(cacheMap.find(key) != cacheMap.end())
			{
				Node *oldNode = cacheMap[key];
				remove(oldNode);
				delete(oldNode);
			}
			
			Node *node = new Node(key, val);
			cacheMap[key] = node;
			add(node);
			
			if(cacheMap.size() > capacity)
			{
				Node *nodeToDelete = tail->prev; 
				remove(nodeToDelete);
				cacheMap.erase(nodeToDelete->key);
				delete(nodeToDelete);
			}
		}
		
		int get(int key)
		{
			if(cacheMap.find(key) == cacheMap.end())
				return -1;
			
			Node *node = cacheMap[key];
			remove(node); // utility method to remove the node
			add(node); // utility method to add node at front
			return node->value;
		}
};

int main() {
	
	lruCache cache(2);
	cache.put(1, 1);
  cache.put(2, 2);
  cout << cache.get(1) << endl; // Should print 1
  cache.put(3, 3);
  cout << cache.get(2) << endl; // Should print -1 (not found)
  cache.put(4, 4);
  cout << cache.get(1) << endl; // Should print -1 (not found)
  cout << cache.get(3) << endl; // Should print 3
  cout << cache.get(4) << endl; // Should print 4
	
	return 0;
}
