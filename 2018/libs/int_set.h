#include <stdio.h>
#include <stdlib.h>

// IntSet is a double-linked list of ranges of integer values. It uses
// binary search for checking if a value is present in the set. Ranges
// are expanded as adjacent values are found.
//
// There is no memory management at all. This leaks memory like crazy.

struct IntSetNode
{
  int start;
  int end;

  struct IntSetNode* prev;
  struct IntSetNode* next;
};

struct IntSet
{
  unsigned int size;
  unsigned int nodes;
  struct IntSetNode* root;
};

struct IntSet new_int_set()
{
  struct IntSet i;
  i.size = 0;
  i.nodes = 0;
  i.root = NULL;
  return i;
}

struct IntSetNode* _allocate_int_set_node(int value)
{
  struct IntSetNode* new_node = malloc(sizeof(struct IntSetNode));

  new_node->start = value;
  new_node->end = value + 1;
  new_node->prev = NULL;
  new_node->next = NULL;

  return new_node;
}

struct IntSetNode* _binary_search_int_set(struct IntSetNode* head, size_t size, int sought)
{
  if (size == 0) {
    return NULL;
  } else if (size == 1) {
    if (head->start <= sought && sought < head->end) {
      return head;
    } else {
      return NULL;
    }
  } else {
    size_t left_size = size / 2;
    size_t right_size = size - left_size;
    struct IntSetNode* this_node = head;

    for (size_t i = 0; i < left_size; i++) {
      this_node = this_node->next;
    }

    if (this_node->start <= sought && sought < this_node->end) {
      return this_node;
    } else if (sought >= this_node->end) {
      return _binary_search_int_set(this_node, right_size, sought);
    } else /* this_node->start > sought */ {
      return _binary_search_int_set(head, left_size, sought);
    }
  }
}

bool int_set_includes(struct IntSet* set, int value)
{
  struct IntSetNode* node = _binary_search_int_set(set->root, set->nodes, value);

  return node != NULL;
}

void _int_set_prepend_node(struct IntSet* set, struct IntSetNode* node, int value)
{
  struct IntSetNode* right_neighbor = node;
  struct IntSetNode* left_neighbor = node->prev;

  struct IntSetNode* new_node = _allocate_int_set_node(value); 
  
  left_neighbor->next = new_node;
  new_node->prev = left_neighbor;
  
  right_neighbor->prev = new_node;
  new_node->next = right_neighbor;

  set->size++;
  set->nodes++;
}

void _int_set_append_node(struct IntSet* set, struct IntSetNode* node, int value)
{
  // At the end of the list, append our new node and wire up.
  struct IntSetNode* new_node = _allocate_int_set_node(value);
  new_node->prev = node;
  node->next = new_node;

  set->size++;
  set->nodes++;
}

void _int_set_merge_nodes(struct IntSet* set, struct IntSetNode* left, struct IntSetNode* right)
{
  // Remove the left node by making the right node encompass
  // all values.
  right->start = left->start;
  right->prev = left->prev;

  if (NULL != right->prev) {
    right->prev->next = right;
  }
  
  free(left);

  set->nodes--;
}

void int_set_add(struct IntSet* set, int value)
{
  if (set->root == NULL) {
    set->root = _allocate_int_set_node(value);
    set->size = 1;
    set->nodes = 1;
    return;
  }
  
  struct IntSetNode* this_node = set->root;

  while (true) {
    if (value == this_node->end) {
      this_node->end++;
      set->size++;
      return;
    }

    if (value == this_node->start - 1) {
      this_node->start--;
      set->size++;
      return;
    }

    if (NULL != this_node->prev && this_node->start == this_node->prev->end) {
      // Merge any previously adjascent nodes together.
      _int_set_merge_nodes(set, this_node->prev, this_node);
    }
    
    if (value < this_node->start) {
      // Should prepend the node.
      
      if (this_node->prev == NULL) {
        // It has no previous node. Our new node is the new set root.
        struct IntSetNode* right_neighbor = set->root;
        set->root = _allocate_int_set_node(value);
        set->root->next = right_neighbor;
        right_neighbor->prev = set->root;

        set->size++;
        set->nodes++;
      } else {
        _int_set_prepend_node(set, this_node, value);
      }

      return;
    } else if (this_node->start <= value && value < this_node->end) {
      // already have value -- no-op.
      return;
    }

    if (this_node->next == NULL) {
      _int_set_append_node(set, this_node, value);
      return;
    }

    this_node = this_node->next;
  }
}

void dump_int_set(struct IntSet* set)
{
  printf("Set {size:%d nodes:%d} :\n", set->size, set->nodes);

  struct IntSetNode* node = set->root;
  
  int num=0;
  while (node != NULL) {
    num++;
    printf("  Node (%d/%d) {start:%d end:%d}\n", num, set->nodes, node->start, node->end);
    node = node->next;
  }
}
