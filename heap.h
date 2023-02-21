#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T>>
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
  Heap(int m = 2, PComparator c = PComparator());

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
  void push(const T &item);

  /**
   * @brief Returns the top (priority) item
   *
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const &top() const;

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
  /// Add whatever helper functions and heap members you need below

  std::vector<T> heap;
  int m;
  PComparator comp;

};



// Add implementation of member functions here
/**
   * @brief Construct a new Heap object
   *
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  
  
  template <typename T, typename Comparator>
  Heap<T,Comparator>::Heap(int m, Comparator c ){
    this->m = m;
    comp = c;
  } 
// Your code here
  /**
   * @brief Destroy the Heap object
   *
   */
  template <typename T, typename Comparator>
  Heap<T,Comparator>::~Heap(){

  }
/**
 * @brief Push an item to the heap
 *
 * @param item item to heap
 */
template <typename T, typename Comparator>
void Heap<T,Comparator>::push(const T &item){
  //add to next open spot
    heap.push_back(item);
    int loc = heap.size()-1;
    int parent = (loc/m);    
    while ((parent>=0) && (comp(heap[loc],heap[parent]))){
      std::swap(heap[parent],heap[loc]);
      loc=parent;
      parent = parent/2;
    }

}

/// returns true if the heap is empty

/**
 * @brief Returns true if the heap is empty
 *
 */
template <typename T, typename Comparator>
bool Heap<T,Comparator>::empty() const{
  return (heap.size() == 0);
}

/**
 * @brief Returns size of the heap
 *
 */
template <typename T, typename Comparator>
size_t Heap<T,Comparator>::size() const{
  return (heap.size());
}

// We will start top() for you to handle the case of
// calling top on an empty heap

/**
 * @brief Returns the top (priority) item
 *
 * @return T const& top priority item
 * @throw std::underflow_error if the heap is empty
 */

template <typename T, typename PComparator>
T const &Heap<T, PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if (empty())
  {
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::exception(); // fix exception
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heap[0];
}

// We will start pop() for you to handle the case of
// calling top on an empty heap

/**
 * @brief Remove the top priority item
 *
 * @throw std::underflow_error if the heap is empty
 */

template <typename T, typename PComparator>
void Heap<T, PComparator>::pop()
{
  if (empty())
  {
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::exception(); // fix exception
  }

  // swap top with bottom
  std::swap(heap[0], heap[heap.size() - 1]);
  // remove bottom
  heap.pop_back();
  // trickle down;
  int curr = 0;
  while ((int)heap.size() > (m * curr + 1))
  { // while not at the end node

    if ((m * curr + 2) < heap.size())
    { // check if we have right node


      if (( comp (heap[m * curr + 1],heap[curr])) || ( comp(heap[m * curr + 2],heap[curr])))
      { // check if child node has priority over parent

        if (comp(heap[m * curr + 2], heap[m * curr + 1]))
        { // swap with priority node
          std::swap(heap[curr], heap[m * curr + 2]);
          curr = m * curr + 2;
        }
        else
        {
          std::swap(heap[curr], heap[m * curr + 1]);
          curr = m * curr + 1;
        }
      }
      else
      {
        break;
      }
    }

    else if (((m * curr + 1) < (int)heap.size()) && ((m * curr + 2) >= (int)heap.size()))
    { // check if we only have a left child
      if (comp(heap[m * curr + 1], heap[curr]))
      { // if left child has priority than parent swap
        std::swap(heap[curr], heap[m * curr + 1]);
        curr = m * curr + 1;
      }
      else
      {
        break;
      }
    }
  }
}

#endif
