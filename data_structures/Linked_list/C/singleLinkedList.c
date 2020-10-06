#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *
new_node(int n) {
  struct node *elem;

  if ((elem = malloc(sizeof(struct node))) == NULL) {
    fprintf(stderr, "Malloc error in %s (%d)", __FILE__, __LINE__);
    return NULL;
  }

  elem->data = n;
  elem->next = NULL;

  return elem;
}

int
add_as_head(struct node **list, int n) {
  struct node *head = new_node(n);

  if (head == NULL)
    return 0;

  if (*list == NULL) {
    *list = head;
    return 1;
  }

  head->next = *list;
  *list = head;

  return 1;
}

int
add_as_tail(struct node **list, int n) {
  struct node *tail = new_node(n);
  struct node *tmp = *list;

  if (tail == NULL)
    return 0;

  if (*list == NULL) {
    *list = tail;
    return 1;
  }

  for (tmp = *list; tmp->next != NULL; tmp = tmp->next);

  tmp->next = tail;

  return 1;
}

int
free_node(struct node *node) {
  if (node == NULL) {
    fprintf(stderr, "Illegal free attempt : node is NULL\n");
    return 0;
  }

  free(node);
  node = NULL;

  return 1;
}

int
delete_head(struct node **list) {
  struct node *old_head = *list;
  
  if (*list == NULL)
    return 0;

  *list = (*list)->next;
  return free_node(old_head);
}

int
delete_node(struct node **list, int n) {
  struct node *tmp = NULL;
  struct node *node_to_delete = NULL;

  if ((*list)->data == n) {
    return delete_head(list);
  }

  for (tmp = *list; tmp->next != NULL && tmp->next->data != n; tmp = tmp->next);

  if (tmp->next == NULL)
    return 0;

  node_to_delete = tmp->next;
  tmp->next = node_to_delete->next;

  return free_node(node_to_delete);
}

int
delete_tail(struct node **list) {
  struct node *new_tail = NULL;
  struct node *old_tail = NULL;

  for (new_tail = *list; new_tail->next != NULL && new_tail->next->next != NULL; new_tail = new_tail->next);

  old_tail = new_tail->next;
  new_tail->next = NULL;

  return free_node(old_tail);
}

int
free_list(struct node **list) {
  struct node *tmp;

  if (*list == NULL) {
    fprintf(stderr, "Illegal free attempt : list is NULL\n");
    return 0;
  }

  do {
    tmp = (*list)->next;
    free_node(*list);
    *list = tmp;
  } while (tmp != NULL);

  return 1;
}

void
disp_list(struct node *list) {
  for (; list != NULL; list = list->next) {
    printf("%d", list->data);
    if (list->next != NULL)
      printf(" -> ");
  }
  printf("\n");
}
//this is the optimized nethod for detection of loop in the linked list//
void detectanddelete(struct node* head_ref)
{
    if(head_ref==NULL||head_ref->next==NULL)
        return;
    struct node* fast=head_ref;
    struct node* slow=head_ref;
    slow=slow->next;
    fast=fast->next->next;
    while(fast&&fast->next)
    {
        if(slow==fast)
            break;
        slow=slow->next;
        fast=fast->next->next;
    }
    if(slow==fast)
    {
        slow=head_ref;
        while(slow->next!=fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=NULL;
    }



};

int
main(int argc, char *argv[]) {
  struct node *list;
  int i;

  /* 4 -> 3 -> 2 -> 1 -> 0 */
  for (i = 0; i < 5; i++)
    add_as_head(&list, i);

  /* 4 -> 3 -> 2 -> 1 -> 0 -> 99 */
  add_as_tail(&list, 99);

  /* 4 -> 3 -> 2 -> 1 -> 0 */
  delete_node(&list, 99);

  /* 3 -> 2 -> 1 -> 0 */
  delete_head(&list);
  
  /* 3 -> 1 -> 0 */
  delete_node(&list, 2);

  /* 3 -> 1 */
  delete_tail(&list);
  
  disp_list(list);

  free_list(&list);

  return EXIT_SUCCESS;
}
