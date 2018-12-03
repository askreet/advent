#include <stdbool.h>
#include <stdlib.h>

#define __HASH_MAP_TABLE_SIZE 65536

/**
 * hashmap is an implementation of a hash table with keys of type int. Values are
 * of type void*, which must be cast by the caller to the actual type.
 */
struct HashMapNode {
  int key;
  void* value;
  struct HashMapNode* next;
};
  
struct HashMap {
  struct HashMapNode* table[__HASH_MAP_TABLE_SIZE];
};

bool hashmap_has(struct HashMap* map, int key);
void hashmap_put(struct HashMap* map, int key, void* value);
void* hashmap_get(struct HashMap* map, int key);
struct HashMap* new_hashmap();

struct HashMap* new_hashmap()
{
  struct HashMap* new = malloc(sizeof(struct HashMap));

  return new;
}

struct HashMapNode* _new_hashmap_node(int key, void* value)
{
  struct HashMapNode* node = malloc(sizeof(struct HashMapNode));

  node->key = key;
  node->value = value;
  node->next = NULL;

  return node;
}

bool hashmap_has(struct HashMap* map, int key)
{
  return false;
}

void hashmap_put(struct HashMap* map, int key, void* value)
{
  int index = key % __HASH_MAP_TABLE_SIZE;

  if (NULL == map->table[index]) {
    map->table[index] = _new_hashmap_node(key, value);
  } else {
    struct HashMapNode* node = map->table[index];

    while (NULL != node) {
      if (node->key == key) {
        return;
      }

      node = node->next;
    }

    node->next = _new_hashmap_node(key, value);
  }
}

void* hashmap_get(struct HashMap* map, int key)
{
  int index = key % __HASH_MAP_TABLE_SIZE;
  
  if (NULL == map->table[index]) {
    return NULL;
  } else {
    struct HashMapNode* node = map->table[index];

    while (NULL != node) {
      if (node->key == key) {
        return node->value;
      }

      node = node->next;
    }

    return NULL;
  }
}