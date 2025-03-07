#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <iostream>
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
  
  // delete later - keep for testing 
  void printHeap() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> heapData;
  void trickleDown(int idx);
  void trickleUp(int idx);
  bool isLeafNode(int idx);
  void swap(int first, int second);
  int heapM;
  PComparator heapComp;

};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c)
{
  heapM=m;
  heapComp = c;

}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{
  heapData.clear();
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  heapData.push_back(item);
  trickleUp(heapData.size()-1);
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return heapData.empty();
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return heapData.size();
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
    throw std::underflow_error("Empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heapData[0];
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
    throw std::underflow_error("Empty");
  }
  int n = heapData.size();
  heapData[0]=heapData[n-1];
  heapData.pop_back();
  trickleDown(0);
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::isLeafNode(int idx)
{
  if(static_cast<size_t>((idx*heapM)+1)>=heapData.size())
  {
    return true;
  }
  else
  {
    return false;
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::swap(int first, int second)
{
  T temp= heapData[first];
  heapData[first] = heapData[second];
  heapData[second]=temp;
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::printHeap() const
{
  for (size_t i = 0; i < heapData.size(); i++)
  {
    std::cout << heapData[i] << " ";
  }
  std::cout<<std::endl;
}


template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleDown(int idx)
{
  if(isLeafNode(idx))
  {
    return;
  }

  int firstChild = heapM*idx+1;
  int targetChild = firstChild;

  for(int i=1;i<heapM;++i)
  {
    int currChild = firstChild+i;
    
    if(heapComp(heapData[currChild],heapData[targetChild]))
    {
      targetChild = currChild;
    }
  }

  if(heapComp(heapData[targetChild],heapData[idx]))
  {
    swap(idx,targetChild);
    trickleDown(targetChild);
  }
}


template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(int idx)
{
  if(idx==0)
  {
    return;
  }

  for(int i=1;i<heapM;++i)
  {
    int currChild = idx-i;
    
    if(heapComp(heapData[idx],heapData[currChild]))
    {
      swap(idx, currChild);
      trickleUp(currChild);
    }
  }

}

#endif

