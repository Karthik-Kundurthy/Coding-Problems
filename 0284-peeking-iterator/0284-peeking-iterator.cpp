
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

// declaring a class peeking iterator
// publicly inherits from iterator class

class PeekingIterator : public Iterator {
private:
    bool flag;
    int val;
    bool expected;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    flag = false;
        val = 0;
        expected = Iterator::hasNext();
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (flag) {
            return val;
        } else {
            flag = true;
            // store the current hasNext() state
            expected = Iterator::hasNext();
            val = Iterator::next();
            return val; 
        }
        
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        // peek was not called before next()
	    if (!flag) {
            val = Iterator::next();
            // std::cout << val << std::endl;
            // normal next() operation, 
            return val;
        } else { 
            // if peek was called then we cannot advance the pointer
            flag = false;
            // std::cout << "hello: " << val << std::endl;
            return val;
        }
        
	}
	
	bool hasNext() const {
        if (flag) {
            return expected;
        } else {
            return Iterator::hasNext();
        }
	    
	}
};