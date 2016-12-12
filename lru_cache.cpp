#include <unordered_map>
#include <list>
#include <iostream>

using namespace std;

class LRUCache{
public:

    LRUCache(int capacity) {
        if (capacity < 1)
            return;
            
        cache.reserve(capacity);
		cacheCapacity = capacity;

    }

public:
	// Create a cache which would be a hash map of (key, ptr to node in list)
	// also create a doubly link list which can be used to maintain the LRU aspect of this
	unordered_map<int, list<pair<int, int> >::iterator> cache;

	// create a doubly link list to hold these nodes
	list<pair<int, int> > dlist;
	
	size_t cacheCapacity;
    
    int get(int key) {
        
        // check in cache if it's there
        unordered_map<int, list<pair<int, int> >::iterator>::iterator got = cache.find(key);
        if (got == cache.end())
            return -1;
        
		// Move the element to top of queue as it has been accessed now
		if (got->second != dlist.begin()) {
			dlist.splice(dlist.begin(), dlist, got->second, std::next(got->second));
		}
		return (*(got->second)).second;
    }
    
    void set(int key, int value) {
        
        // if element is already there, just move it ahead in queue and return
		unordered_map<int, list<pair<int, int> >::iterator>::iterator got = cache.find(key);

        if (got != cache.end())
        {
            // Element is found. Update the value in cache as well as
			// dlist. ALso move entry to top in dlist
			(*(got->second)).second = value;
			if (got->second != dlist.begin()) {
				dlist.splice(dlist.begin(), dlist, got->second, std::next(got->second));
			}
            return;
        }
        
        // Element is not found. See if we are hitting the capacity
        if (!cache.empty() && cache.size() >= cacheCapacity)
        {
            // cache is full and we need to remove some element.
            // get the last element from the queue and simply remove
            int keyToInvalidate = (dlist.back()).first;

			// Cache contains the reference to list node, so first erase from cache as pop calls node
			// destructor
			cache.erase(keyToInvalidate);
			dlist.pop_back();
        }
        
        // add element in hash and also in queue
		dlist.push_front(pair<int,int>{key, value});
		cache.insert(pair<int, list<pair<int, int> >::iterator>{key, dlist.begin()});
        return;
        
    }
};

int main()
{
	int res = 0;

	// testing for LRU cache
	LRUCache cacheObj{ 5 };

	for (int i = 1; i < 6; i++)
	{
		cacheObj.set(i, i*100);
	}

	cacheObj.set(2, 400);
	// Check getting an element
	res = cacheObj.get(0);
	if (res == -1)
		cout << "Didn't find value in cache" << endl;

	// Simply sanity checks
	for (int i = 1; i < 6; i++)
		cout << " Key :" << i + 1 << "has value :" << cacheObj.get(i) << endl;
}