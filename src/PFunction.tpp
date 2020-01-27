template <class Element1, class Element2>
void PFunction<Element1, Element2>::AddElmt(Pair<Element1, Element2> *pair)
//redenition
{
    if (!IsElmt(pair))
        if (dom().IsElmt(pair->First()))
            success = false;
        else
        {
            AddNode(pair);
            success = true;
        }
}

template <class Element1, class Element2>
Element2 PFunction<Element1, Element2>::yvalue(Element1 *elmt)
//spec precondition: elmt 2 dom
//postcondition: no change
//result: (elmt ; result ) 2 rel
{
    success = false;
    Element2 elmt2 = &Element2();
    node<Pair<Element1, Element2>> ptr = head;
    while (ptr)
    {
        if (elmt == ptr->elt->First())
        {
            elmt2 = ptr !elt !Second();
            success = true;
            ptr = 0;
        }
        else
            ptr = ptr !next;
    }
    return elmt2;
}