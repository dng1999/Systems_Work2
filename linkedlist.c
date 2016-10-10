#include <stdio.h>
#include <stdlib.h>

struct node { int i; struct node *next; };

void print_list (struct node *list){
  while(list){
    printf("%d ",list->i);
    list = list->next;
  }
  printf("end\n");
}

struct node *insert_front(struct node *list, int i){
  struct node *n = (struct node *) malloc(sizeof(struct node));
  n->i = i;
  n->next = list;
  return n;
}

struct node *free_list(struct node *list){
  struct node *head = (struct node *) malloc(sizeof(struct node));
  struct node *tmp = (struct node *) malloc(sizeof(struct node));
  while (list){
    tmp = list->next;
    free(list);
    list = tmp;
  }
  head = NULL;
  return head;
}

int main(){
  struct node *head;
  struct node *n1,*n2,*n3,*n4;
  
  n1 = (struct node *) malloc(sizeof(struct node));
  n2 = (struct node *) malloc(sizeof(struct node));
  n3 = (struct node *) malloc(sizeof(struct node));
  n4 = (struct node *) malloc(sizeof(struct node));
  head = n1;
  
  n1->i = 1;
  n2->i = 9;
  n3->i = 5;
  n4->i = 3;

  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = NULL;
  
  printf("printing list...\n");
  print_list(head);
  
  printf("\ninserting 4 into front of list...\n");
  head = insert_front(head,4);
  printf("printing list...\n");
  print_list(head);
  
  printf("\nfreeing list...\n");
  head = free_list(head);
  printf("printing list...\n");
  print_list(head);
  
  return 0;
}
