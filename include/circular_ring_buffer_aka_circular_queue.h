#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <iostream>
#include <vector>
#define BUFFER_SIZE 100
template<typename T>

class circular_ring_buffer // It is same as circular queue
{
  public:
    explicit circular_ring_buffer(int capacity_v):capacity(capacity_v),front(0),rear(0),buffer(capacity_v){}
    void enqueue(const T& value);
    T dequeue();
    bool is_full();
    bool is_empty();
    void print();
  private:
    int capacity;
    int front;
    int rear;
    std::vector<T> buffer;
};

template<typename T>
bool circular_ring_buffer<T>::is_full()
{
  return (rear+1)%capacity == front ;
}

template<typename T>
bool circular_ring_buffer<T>::is_empty()
{
  return front == rear ;
}

template<typename T>
void circular_ring_buffer<T>::enqueue(const T& value)
{
  if(is_full())
  { 
    std::cout << "Queue if full" <<std::endl;
    return;
  }
  buffer[rear] =  value;
  std::cout<<"Enqueued: " << value << " rear: " << rear << std::endl ;
  rear = (rear + 1) % capacity; 
}

template<typename T>
T circular_ring_buffer<T>::dequeue()
{
  if(!is_empty())
  {
    T tmp = buffer[front];
    front = (front+1) % capacity;
    return tmp;
  }
  else return 0;
}

template<typename T>
void circular_ring_buffer<T>::print()
{
  if(is_empty())
  {
    std::cout << "No Item to Print"<<std::endl;
    return;
  }
  int i = front;
  while(i != rear)
  {
    std::cout << buffer[i] << " ";
    std::cout << std::endl;
    i = (i+1) % capacity;
  }
}

#endif
