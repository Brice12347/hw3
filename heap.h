#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
 std::vector<T> temp;
 PComparator compare;
 int ary;



};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c){
	compare = c;
	ary = m;

}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
	return temp.size() == 0;
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){

}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::underflow_error("empty heap");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

	return temp.front();

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::underflow_error("empty heap");

  }else if(temp.size() == 1){
		temp.pop_back();
	}else if(temp.size() > 1){
		int iteration = 0;
		int right = 0;
		int left = 0;
		int best = 0;
		std::swap(temp.back(),temp.front());
		temp.pop_back();
		while(true){
			best = iteration;
			if(ary*iteration + 1 < temp.size()){
				left = ary*iteration + 1; 
				best = left;
			}
			for(int i = 0; i < ary - 1; i++){
				if(ary * iteration + 2 + i < temp.size() && compare(temp[ary * iteration + 2 + i],temp[best])){
					right = ary * iteration + 2 + i;
					best = right;
				}
			}
			if(best == iteration || !compare(temp[best], temp[iteration])){
				break;
			}else{
				std::swap(temp[iteration],temp[best]);
			}
			iteration = best;
		}
	}
}
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{	
	temp.push_back(item);
	std::size_t i = temp.size()-1;
	while(i != 0){
		std::size_t parenti = (i - 1)/ary;
		T& current = temp[i];
		T& parent = temp[parenti];
		if(!compare(current,parent)){
			break;
		}
		std::swap(current, parent);
		i = parenti;

	}
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
	return temp.size();
}

#endif

