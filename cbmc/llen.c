// CBMC llen test
#include <stdlib.h>

struct node_t {
  void *elem;
  struct node_t *next;
};

int llen(struct node_t *x) {
  if (x == NULL) {
    return 1;
  } else {
    struct node_t *t = x->next;
    int len = llen(t);
    return len + 1;
  }
}

struct node_t *build_list(int s) {
  struct node_t *x = NULL;
  for (int i = 0; i < s; i++) {
    struct node_t *t = malloc(sizeof(struct node_t));
    t->next = x;
    x = t;
  }
  return x;
}

int main() {
  int s;
  __CPROVER_assume(s >= 0);
  struct node_t *x = build_list(s);
  int len = llen(x);
  __CPROVER_assert(len == s, "length correct");
  return 0;
}

