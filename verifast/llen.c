#include "stdlib.h"

/*@

predicate list(void **x; list<void *> l) =
  x == 0 ?
    l == nil
  :
    pointers(x, 2, cons(?elem, (cons(?y, nil)))) &*&
    list((void **) y, ?tail) &*&
    l == cons(elem, tail);

@*/

int llen(void **x)
  //@ requires list(x, ?l) &*& length(l) < INT_MAX;
  //@ ensures list(x, l) &*& result == length(l);
{
  int result;
  if (x == 0) {
    //@ open list(x, l);
    result = 1;
  } else {
    //@ open list(x, l);
    void *t = x[1];
    int len = llen((void **) t);
    result = len + 1;
  }
  return result;
}

