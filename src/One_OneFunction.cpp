#include "One_OneFunction.hpp"

template <class Element1, class Element2>
void One_OneFunction<Element1, Element2>::AddElmt(Pair<Element1, Element2> *pair)
//redenition
{
    success = false;
    if (!IsPair(true))
        if (!ran().IsElmt(pair->Second()) && !dom().IsElmt(pair->First()))
        {
            AddNode(pair);
            success = true;
        }
}