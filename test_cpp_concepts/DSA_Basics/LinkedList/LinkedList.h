#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

extern struct node *head;

void deleteList(struct node *&head);
void revLinkedList(struct node *curr);
void revUptoKthNode(struct node *curr, int k);
struct node *revKthGroup(struct node *curr, int k);
bool findLoop(struct node *head);
struct node *returnStartOfCycle(struct node *head);
void removeNthNode(struct node *head, int n);
struct node *mergeTwoSortedLists(struct node *L1, struct node *L2);
bool checkPalindrome(struct node *head);

#endif