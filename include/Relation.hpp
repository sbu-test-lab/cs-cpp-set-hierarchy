#pragma once

template<typename T>
class Relation: Set<Pair<Element1,Element2> > {

public:
    Relation() : Set<Pair<Element1,Element2> >() {};
    ~Relation();
    //constructor
Relation( Relation& rel) : Set<Pair<Element1,Element2> >(rel) fg

//rename IsElmt
Boolean IsPair( Pair<Element1,Element2> * pair) {
    return IsElmt(pair);} 

//domain of the Relation
Set<Element1> dom() ;

//range of the Relation
Set<Element2> ran() ;

//transpose
virtual Set<Pair<Element2,Element1> > Transpose() ;

//image of a set
virtual Set<Element2> SetImage( Set<Element1>&) ;

//image
virtual Set<Element2> Image( Element1 *) ;

//inverse image
virtual Set<Element1> InvImage( Element2 *) ;

//is this a domain element
virtual Boolean IsDomElmt( Element1 *) ;

//is this a range element
virtual Boolean IsRanElmt( Element2 *) ;

//domain restriction
virtual void DomRestr( Set<Element1>&);

//domain exclusion
virtual void DomExcl( Set<Element1>&);

//range restriction
virtual void RanRestr( Set<Element2>&);

//range exclusion
virtual void RanExcl( Set<Element2>&);

//override
virtual void Override( Relation&);

//remove pairs with this domain element
virtual void DomElmtSub( Element1 *);

//remove pairs with this range element
virtual void RanElmtSub( Element2 *);

};

#include "../src/Relation.tpp"