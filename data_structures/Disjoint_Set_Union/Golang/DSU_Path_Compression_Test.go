package dsu

import (
  "math/rand"
  "testing"
)

func TestEvenOdd(t *testing.T) {
  const N  = 1000;
  sets := make([]*Element, n)
  for i:=0; i < N; i++ {
    sets[i] = NewElement()
  }
  for i := 2; i < N; i += 2 {
		Union(sets[i], sets[i-2])
	}
	for i := 3; i < N; i += 2 {
		Union(sets[i], sets[i-2])
	}

	for i := 0; i < N*3; i++ {
		s1 := rand.Intn(N)
		s2 := rand.Intn(N)
		sameMod2 := s1%2 == s2%2
		sameRep := sets[s1].Find() == sets[s2].Find()
		if sameMod2 != sameRep {
			t.Fatalf("Should %d and %d lie in the same set?  The package incorrectly says %v.",
				s1, s2, sameRep)
		}
	}
}

func createElements(n int) []*Element {
	elts := make([]*Element, n)
	for i := range elts {
		elts[i] = NewElement()
	}
	return elts
}

func selectIndexes(n int) [][2]int {
	idxes := make([][2]int, n)
	if n < 2 {
		return idxes
	}
	for i := range idxes {
		idxes[i][0] = i
		if i == 0 {
			idxes[i][1] = rand.Intn(n)
		} else {
			idxes[i][1] = rand.Intn(i)
		}
	}
	return idxes
}

func pairwiseUnions(elts []*Element, idxes [][2]int) {
	for _, idx := range idxes {
		e1 := elts[idx[0]]
		e2 := elts[idx[1]]
		Union(e1, e2)
	}
}
