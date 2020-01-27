#pragma once

template <class Element1, class Element2>

class PFunction : public Relation<Element1, Element2>
{
public:
    
    //constructor
    PFunction() : Relation<Element1, Element2>() {}
    PFunction(PFunction &pfun) : Relation<Element1, Element2>(pfun) {}

    //redenition
    virtual void AddElmt(Pair<Element1, Element2> *pair);

    //function applied to a value
    Element2 yvalue(Element1 *);
};

#include "../src/PFunction.tpp"