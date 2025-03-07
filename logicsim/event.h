#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

typedef struct EventLess {
        //write the operator() required to make this a functor that compares Events by time
        //take two Event*'s as it’s input 
        // sort them using the Event::time data member 
        //in such a way that your heap will be a min-heap. 
        //i.e. Event's are sorted by time
    bool operator()(Event* left, Event* right)
    {
        return left->time < right->time;
    }
} EventLess;
	
#endif
