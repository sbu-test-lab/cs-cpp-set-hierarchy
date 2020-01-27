#pragma once

class DAG : public RelationOn<Element> {
public:

//constructor
DAG() : RelationOn<Element>() {} 

//wil l the addition of this pair cause a circularity
bool IsCandidatePair(Pair<Element,Element> *pair);

//add if non-circular
void AddElmt(Pair<Element,Element> *pair) ; 
};

#include "../src/DAG.tpp"