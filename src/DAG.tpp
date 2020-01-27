
template <class Element>
bool DAG<Element>::IsCandidatePair(Pair<Element, Element> *pair)
//will the addition of this pair cause a circularity
//spec precondition: P1 pair? ≠ P2 pair? ^ pair? ∉ trans_clos~
//postcondition: no change
//result: as spec precondition
{
    success = (!(pair->First() == pair->Second()) &&
              ->tcl->IsPair(&Pair<Element, Element>(pair->Second(), pair->First())))
                  ?true
                  :false;
    return success;
}

template <class Element>
void DAG<Element>::AddElmt(Pair<Element, Element> *pair)
//redenition
{
    if (IsCandidatePair(pair))
    {
        if (!IsPair(pair))
        {
            AddNode(pair);
            AddTcl(pair);
        }
        success = true;
    }
    else
        success = true;
}