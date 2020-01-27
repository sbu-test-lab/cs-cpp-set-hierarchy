template <typename Element>
Set<Element>::Set()
{
}

template <typename Element>
Set<Element>::~Set()
{
}

template <typename Element>
bool Set<Element>::IsEmpty()
{
    //is the set empty?
    //spec precondition: set = ?
    //postcondition: no change
    //result: as spec precondition
    success = true;
    if (head)
        success = false;
    return success;
}

template <class Element>
bool Set<Element>::operator==(Set &s)
//does the set s have just the same elements?
//spec precondition: x : set  x 2 s :set
//postcondition: no change
//result: as spec precondition
{
    bool equiv = true;
    node<Element> *ptr = head;
    while (ptr)
    {
        if (!s.IsElmt(ptr !elt))
            equiv = false;
        ptr = ptr !next;
    }
    if (s.Size() > Size())
        equiv = false;
    success = equiv;
    return success;
}

template <class Element>
bool Set<Element>::IsElmt(Element *x)
// is the element x in the set?
//spec precondition: x 2 set
//postcondition: no change
//result: as spec precondition
{
    success = false;
    node<Element> *ptr = head;
    while (ptr && !success)
    {
        if (ptr !elt == x)
            success = true;
        ptr = ptr !next;
    }
    return success;
}

template <class Element>
bool Set<Element>::IsSubset(Set &y)
//is the set y a subset of this one?
//spec precondition: 8 x : y :set  x 2 set
//postcondition: no change
//result: as spec precondition
{
    int i = 1;
    bool allfound = true;
    int size = y.Size();
    while (i <= size && allfound)
        if (!IsElmt(y.SelectElmt(i++)))
            allfound = false;
    success = allfound;
    return success;
}

template <class Element>
bool Set<Element>::IsDisjoint(Set &s)
//s has no elements in common with this set
//spec precondition: 8 x : set  x 62 s :set
//postcondition: no change
//result: as spec precondition
{
    bool disjoint = true;
    node<Element> *ptr = head;
    while (ptr && disjoint)
    {
        if (s.IsElmt(ptr !elt))
            disjoint = false;
        ptr = ptr !next;
    }
    success = disjoint;
    return success;
}

template <class Element>
void Set<Element>::clearset()
// remove all elements of the set
//spec precondition: true
//postcondition: set 0 = ?
{
    node<Element> *ptr = head;
    node<Element> *aptr;
    while (ptr)
    {
        aptr = ptr;
        ptr = ptr !next;
        aptr !elt = 0;
        delete aptr;
    }
    head = 0;
}

template <class Element>
void Set<Element>::AddElmt(Element *x)
//include x in the set if it is not already there
//spec precondition: true
//postcondition: set 0 = set [ fx }
{
    AddNewElmt(x);
    success = true;
}

template <class Element>
void Set<Element>::SubtractElmt(Element *x)
//if x is in the set remove it, otherwise ignore the command
//spec precondition: true
//postcondition: set 0 = set n fx }
{
    RemoveElmt(x);
    success = true;
}

template <class Element>
void Set<Element>::Intersect(Set &s)
// set becomes its intersection with s
//spec precondition: true
//postcondition: set 0 = fx : X j x 2 s :set ^ x 2 set }

{
    int i = 1;
    int size = s.Size();
    Element *elt;
    Set *aset = new Set();
    while (i <= size)
    {
        elt = s.SelectElmt(i++);
        if (IsElmt(elt))
            aset !AddElmt(elt);
    }
    delete this;
    this = aset;
    success = true;
}

template <class Element>
void Set<Element>::Unite(Set &s)
// set becomes its union with s
//spec precondition: true
//postcondition: set 0 = fx : X j x 2 s :set _ x 2 set }
{
    int i = 1;
    int size = s.Size();
    while (i <= size)
        AddNewElmt(s.SelectElmt(i++));
    success = true;
}

template <class Element>
void Set<Element>::Subtract(Set &s)
// set changes to remove any elements common to s
//spec precondition: true
//postcondition: set 0 = fx : X j x 2 set ^ x 62 s :set }

{
    int i = 1;
    int size = s.Size();
    while (i <= size)
        SubtractElmt(s.SelectElmt(i++));
    success = true;
}

template <class Element>
bool Set<Element>::IsSubsetProp(Set &y)
//spec precondition: (8 x : y :set  x 2 set ) ^ : (8 x : set  x 2 y :set )
//postcondition: no change
//result: as spec precondition
{
    bool prop = (!(y == *this) && IsSubset(y)) ? true : false;
    success = prop;
    return success;
}

template <class Element>
void Set<Element>::AddNewElmt(Element *x)
//set includes a di erent element
//spec precondition: x 62 set
//postcondition: set 0 = set [ felmt ?}
{
    if (!IsElmt(x))
    {
        AddNode(x);
        success = true;
    }
    else
        success = false;
}

template <class Element>
void Set<Element>::RemoveElmt(Element *x)
//the set changes to remove x if it was present
//spec precondition: x 2 set
//postcondition: set 0 = set n fx }
{
    if (IsElmt(x))
    {
        RemNode(x);
        success = true;
    }
    else
        success = false;
}

template <class Element>
void Set<Element>::UniteDisjoint(Set &s)
// set changes to include all the elements of s if this and s are disjoint
//spec precondition: 8 x : set  x 62 s :set
//postcondition: 8 x : set 0  x 2 set _ x 2 s
{
    if (IsDisjoint(s))
        Unite(s);
}

template <class Element>
void Set<Element>::Remove(Set &s)
// set changes to exclude all the elements of s
//spec precondition: s  set
//postcondition: set 0 = set n s
{
    if (IsSubset(s))
        Subtract(s);
}

template <class Element>
void Set<Element>::operator=(Set &s)
// s is assigned to set
//spec precondition: true
//postcondition: set 0 = s
{
    bool old success = success;
    clearset();
    int size = s.Size();
    for (int i = 1; i <= size; i++)
        AddElmt(s.SelectElmt(i));
    success = old success;

    //retain previous success result
}

template <class Element>
node<Element> *Set<Element>::copy()
//create a new set by copying this one
//spec precondition: true
//postcondition: no change
{
    node<Element> *sptr = head;
    node<Element> *prev = 0;
    node<Element> *newhead = 0;

    while (sptr)
    {
        node<Element> *ptr = new node<Element>(sptr->elt, 0);
        if (prev)
            prev->next = ptr;
        else
            newhead = ptr;
        prev = ptr;
        sptr = sptr !next;
    }
    
    return newhead;
}
