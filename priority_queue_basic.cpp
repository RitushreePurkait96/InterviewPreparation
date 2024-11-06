// Basic Priority Queue


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Custom comparator to order elements by sum of digits
struct CompareNoOfDigits
{
	bool operator()(int a, int b)
	{
		int sum_a = 0, sum_b = 0;
	
		// sum of digits of a
		while(a > 0)
		{
			sum_a += a % 10;
			a = a / 10;
		}
		
		// sum of digits of b
		while(b > 0)
		{
			sum_b += b % 10;
			b = b / 10;
		}
		
		// Return true if a has higher priority than b (i.e., sum_a < sum_b)
		return sum_a > sum_b;
	}
};


int main() 
{
	vector<int> arr = {10, 30, 20, 5, 50, 45};
	priority_queue<int> max_heap_pq; // This is by default Max-heap 
	
	priority_queue<int, vector<int>, greater<>> min_heap_pq; // Min-heap
	
	// Custom Min-heap priority queue, prioritised as lesser sum of digits
	priority_queue<int, vector<int>, CompareNoOfDigits> custom_min_heap_pq; 
	
	for (int i = 0; i < arr.size(); i++)
	{
		max_heap_pq.push(arr[i]);
		min_heap_pq.push(arr[i]);
		custom_min_heap_pq.push(arr[i]);
	}
	
	cout << "Elements in max heap Priority queue: \n";
	
	while(!max_heap_pq.empty())
	{
		cout << "   " << max_heap_pq.top();
		max_heap_pq.pop();
	}
	
	cout << "\nElements in min heap Priority queue: \n";
	
	while(!min_heap_pq.empty())
	{
		cout << "   " << min_heap_pq.top();
		min_heap_pq.pop();
	}
	
	cout << "\nElements in Custom min heap Priority queue: \n";
	
	while(!custom_min_heap_pq.empty())
	{
		cout << "   " << custom_min_heap_pq.top();
		custom_min_heap_pq.pop();
	}
	
	return 0;
}


Output: 
Elements in max heap Priority queue: 
   50   45   30   20   10   5
Elements in min heap Priority queue: 
   5   10   20   30   45   50
Elements in Custom min heap Priority queue: 
   10   20   30   5   50   45
