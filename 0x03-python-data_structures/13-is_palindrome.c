#include <stdlib.h>

typedef struct listint_s {
  int n;
  struct listint_s *next;
} listint_t;

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 *
 * @head: pointer to the head of the singly linked list
 * Return: 1 if the list is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head) {
  listint_t *slow = *head, *fast = *head;
  listint_t *prev = NULL, *current = NULL;

  // Find the middle node of the list
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  // If the list has an odd number of nodes, skip the middle node
  if (slow->next) {
    slow = slow->next;
  }

  // Reverse the second half of the list
  current = slow;
  while (current) {
    prev = current->next;
    current->next = *head;
    *head = current;
    current = prev;
  }

  // Check if the reversed list is identical to the original list
  while (*head && slow) {
    if ((*head)->n != slow->n) {
      return 0;
    }

    *head = (*head)->next;
    slow = slow->next;
  }

  // Restore the original list
  current = *head;
  *head = NULL;
  while (current) {
    prev = current->next;
    current->next = *head;
    *head = current;
    current = prev;
  }

  return 1;
}

