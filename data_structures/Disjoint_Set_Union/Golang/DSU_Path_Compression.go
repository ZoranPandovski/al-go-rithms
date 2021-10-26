package dsu;

/*
A disjoint-set—also called union-find—data structure keeps track of
nonoverlapping partitions of a collection of data elements.  Initially, each
data element belongs to its own, singleton, set.  The following operations can
then be performed on these sets:
• Union merges two sets into a single set containing the union of their
elements.
• Find returns an arbitrary element from a set.
The critical feature is that Find returns the same element when given any
element in a set.  The implication is that two elements A and B belong to the
same set if and only if A.Find() == B.Find().
Both Union and Find take as arguments elements of sets, not the sets
themselves.  Because sets are mutually disjoint, an element uniquely identifies
a set.  Ergo, there is no need to pass sets to those functions.
Disjoint sets are more limited in functionality than conventional sets.  They
support only set union, not set intersection, set difference, or any other set
operation.  They don't allow an element to reside in more than one set.  They
don't even provide a way to enumerate the elements in a given set.  What makes
them useful, though, is that they're extremely fast, especially for large sets;
both Union and Find run in amortized near-constant time.  See
http://en.wikipedia.org/wiki/Disjoint-set_data_structure for more information.
Disjoint sets are often used in graph algorithms, for example to find a minimal
spanning tree for a graph or to determine if adding a given edge to a graph
would create a cycle.
*/

type Element struct {
  parent *Element
  rank int
  Data interface{}
}

func NewElement() *Element  {
  s := &Element{}
  s.parent = s
  return s
}


func (e *Element) Find() *Element {
  for e.parent != e {
    e.parent = e.parent.parent
    e = e.parent
  }
  return e
}

func Union(e1, e2 *Element) {
  e1Root := e1.Find()
  e2Root := e2.Find()
  if e1Root == e2Root {
    return
  }

  switch {
  case e1Root.rank < e2Root.rank:
    e1Root.parent = e2Root
  case e1Root.rank > e2Root.rank:
		e2Root.parent = e1Root
	default:
		e2Root.parent = e1Root
		e1Root.rank++
  }
}
