#pragma once

template <class Element>

class RelationOn : public Relation<Element, Element>
{
protected:
    //transitive closure
    Relation<Element, Element> *tcl;

    void AddTcl(Pair<Element, Element> *pair);
    //add to tcl relation

public:
    //constructor
    RelationOn() : Relation<Element, Element>()
    {
        tcl = new Relation<Element, Element>();
    }

    RelationOn(RelationOn &rel) : Relation<Element, Element>(rel)
    {
        tcl = new Relation<Element, Element>(rel.tcl);
    }

    //build transitive closure
    void trans_clos();

    //do circularities exist
    bool circular();

    //transitive image
    Set<Element> TransImage(Element*);

    //inverse transitive image
    Set<Element> InvTransImage(Element*);

    //redenition
    void AddElmt(Pair<Element, Element> *pair);

    //redenition
    void RemoveElmt(Pair<Element, Element> *pair);
};