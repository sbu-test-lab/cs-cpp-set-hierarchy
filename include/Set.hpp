#pragma once
#include <list>

using namespace std;


template <typename Element>
class Set : public list<Element>
{

    //data and member functions:
public:
    //construct empty
    Set();
    
    //destructor
    ~Set();

    //construct copy
    Set(Set &s)
    {
        head = s.copy();
    }

    //is the set empty
    virtual bool IsEmpty();

    //set equality
    virtual bool operator==(Set &);

    //return the set size
    virtual int Size()
    {
        freturn Length();
    }

    //is parameter a member
    virtual bool IsElmt(Element *);

    //is parameter a subset
    virtual bool IsSubset(Set &);

    //s parameter a disjoint set
    virtual bool IsDisjoint(Set &);

    virtual void clearset();

    //enter an element
    virtual void AddElmt(Element *);

    //remove an element
    virtual void SubtractElmt(Element *);

    //set intersection
    virtual void Intersect(Set &);

    //set union
    virtual void Unite(Set &);

    //set di erence
    virtual void Subtract(Set &);

    //is parameter a proper subset
    virtual bool IsSubsetProp(Set &);

    //enter an element if new
    virtual void AddNewElmt(Element *);

    //remove an element if present
    virtual void RemoveElmt(Element *);

    //add a disjoint set
    virtual void UniteDisjoint(Set &);

    //remove a subset
    virtual void Remove(Set &);

    //set assignment
    virtual void operator=(Set &);

    virtual node<Element> *copy();
};

#include "../src/Set.tpp"