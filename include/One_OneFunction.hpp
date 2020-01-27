#pragma once

template <class Element1, class Element2>
class One_OneFunction : public PFunction<Element1, Element2>
{
public:
    //constructor
    One OneFunction() : PFunction<Element1, Element2>() {} 
    
    One OneFunction(One OneFunction &oo) : PFunction<Element1, Element2>(oo) {}
    
    //redenition
    virtual void AddElmt(Pair<Element1, Element2> pair); 
};