#include <stdio.h>
#include <stdlib.h>

#include "hashmap.h"

struct IntSet
{
  struct HashMap* map;
};

struct IntSet new_int_set()
{
  struct IntSet i;
  i.map = new_hashmap();
  return i;
}

bool int_set_includes(struct IntSet* set, int value)
{
  return NULL != hashmap_get(set->map, value);
}

void int_set_add(struct IntSet* set, int value)
{
  hashmap_put(set->map, value, (void*) 1);
}

