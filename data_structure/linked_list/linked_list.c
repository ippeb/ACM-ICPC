/*
  Singly Linked List.

  This code was not written by me, could not find the original sources.

  (c) 2015 Josef Ziegler

*/

#include <stdio.h>
#include <stdlib.h>

struct elem {
  int pos;
  struct elem *next;
};

static void panic(const char *serror)
{
  printf("%s", serror);
  exit(1);
}

static void *xmalloc(size_t size)
{
  void *ptr;
  if (size == 0)
    panic("Size is 0!\n");
  ptr = malloc(size);
  if (!ptr)
    panic("No mem left!\n");
  return ptr;
}

static void xfree(void *ptr)
{
  if (ptr == NULL)
    panic("Got Null-Pointer!\n");
  free(ptr);
}

static struct elem *init_list(size_t len)
{
  //
  struct elem *head = xmalloc( sizeof (struct elem) );
  head->pos = 1;

  struct elem *tail = head;
  int i;
  for (i = 2; i <= 10; i++) {
    struct elem *to = xmalloc( sizeof (struct elem) );
    to->pos = i;
    tail->next = to;
    tail = to;
  }
  tail->next = head;

  return head;
  //
}

static void clean_list(struct elem *head, size_t len)
{
  //
  struct elem *ptr = NULL;
  while (len > 0) {
    if (len > 0) 
      ptr = head->next;
    xfree(head);
    if (len > 0) 
      head = ptr;
    len--;
  }
  //
}

static void traverse_list(struct elem *head, int times)
{
  //
  int i;
  for (i = 1; i <= times; i++) {
    struct elem *ptr = head;
    do {
      printf("iter: %d, pos: %d\n", i, ptr->pos);
      ptr = ptr->next;
    } while (ptr != head);
  }
  //
}

int main(void)
{
  struct elem *head = NULL;
  size_t len = 10;
  
  //
  head = init_list(len);
  traverse_list(head, 2);
  clean_list(head, len);
  //
  
  return 0;
}

