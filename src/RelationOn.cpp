#include "RelationOn.hpp"

template <class Element>
void RelationOn<Element>::trans_clos()
//build transitive closure as in Warshall's algorithm
{
    delete (tcl);
    tcl = new Relation<Element, Element>();
    node<Pair<Element, Element>> *ptr = head;

    while (ptr)
    {
        tcl->AddElmt(ptr->elt);
        ptr = ptr->next;
    }

    int i, j, k;
    Element ei, ej, ek;
    Set<Element> domain = dom();
    Set<Element> range = ran();
    domain.Unite(range);

    int max = domain.Size();
    for (i = 1; i <= max; i++)
    {
        ei = domain.SelectElmt(i);
        for (j = 1; j <= max; j++)
        {
            ej = domain.SelectElmt(j);
            if (tcl->IsElmt(&Pair<Element, Element>(ej, ei)))
                for (k = 1; k <= max; k++)
                {
                    ek = domain.SelectElmt(k);

                    if (tcl->IsElmt(&Pair<Element, Element>(ei, ek)))
                        tcl->AddElmt(&Pair<Element, Element>(ej, ek));
                }
        }
    }
    success = true;
}

template <class Element>
bool RelationOn<Element>::circular()
//is the relation circular
//spec precondition:  ∄x:X ∘ (x , x ) ∈ trans_clos.rel
//postcondition: no change
//result: as spec precondition
{
    bool noncircular = true;
    Set<Element> domain = dom();
    int max = domain.Size();
    int i = 0;
    Element elt;
    while ((i < max) && noncircular)
    {
        elt = domain.SelectElmt(i);
        if (tcl->IsElmt(&Pair<Element, Element>(elt, elt)))
            noncircular = false;
        i++;
    }
    success = noncircular ? false : true;
    return success;
}

template <class Element>
Set<Element> RelationOn<Element>::TransImage(Element *elt)
//transitive image
//spec precondition: true
//postcondition: no change
//result: { x : X | (elmt?, x) ∈ trans_clos.rel }
{
    Set<Element> image = tcl->Image(elt);
    success = true;
    return image;
}

template <class Element>
Set<Element> RelationOn<Element>::InvTransImage(Element *elt)
//Inverse transitive image
//spec precondition: true
//postcondition: no change
//result: { x : X | (x, elmt?) ∈ trans_clos.rel }
{
    Set<Element> invimage = tcl->InvImage(elt);
    success = true;
    return invimage;
}

template <class Element>
void RelationOn<Element>::AddElmt(Pair<Element, Element> *pair)
//redenition
{
    if (!IsElmt(pair))
    {
        AddNode(pair);
        AddTcl(pair);
        success = true;
    }
    else
        success = false;
}

template <class Element>
void RelationOn<Element>::RemoveElmt(Pair<Element, Element> *pair)
//redenition
{
    RemNode(pair);
    if (success)
        trans clos();
}

template <class Element>
void RelationOn<Element>::AddTcl(Pair<Element, Element> *pair)
//add to tcl relation
{
    if (!tcl->IsElmt(pair))
    {
        Set<Element> invimage = tcl->InvImage(pair->First());
        Set<Element> image = tcl->Image(pair->Second());
        
        int size = invimage.Size();
        for (int i = 1; i <= size; i++)
            tcl->AddElmt(&Pair<Element, Element>(invimage.SelectElmt(i), pair->Second()));
        
        size = image.Size();
        for (i = 1; i <= size; i++)
            tcl->AddElmt(&Pair<Element, Element>(pair->First(), image.SelectElmt(i)));
        
        tcl->AddElmt(pair);
    }
    success = true;
}