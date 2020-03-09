#include <stdio.h>
#include <stdlib.h>
#include "head.h"

void initialize()
{
   first = NULL;
   last = NULL;
};
void addelementf(int data)
{
   if (first == NULL)
   {
      first = (NodeT*)malloc(sizeof(NodeT));
      first->next = last;
      first->data = data;
      last = first;
   }
   else
   {
      NodeT* newElement = (NodeT*)malloc(sizeof(NodeT));
      last->next = newElement;
      newElement->next = NULL;
      newElement->data = data;
      last = newElement;
   }

};
void addelementi(int data)
{
   if (first == NULL)
   {
      first = (NodeT*)malloc(sizeof(NodeT));
      first->next = last;
      first->data = data;
      last = first;
   }
   else
   {
      NodeT* newElement = (NodeT*)malloc(sizeof(NodeT));
      newElement->next = first;
      newElement->data = data;
      first = newElement;
   }


};
void eraseelement(int data)
{
   NodeT* currentElement = first;
   NodeT* previousElement = first;
   while (currentElement != NULL)
   {
      if (currentElement->data == data)
      {
         if (currentElement == first)
         {
            first = first->next;
         }
         else if (currentElement == last)
         {
            last = previousElement;
            last->next = NULL;
         }
         else
         {
            previousElement->next = currentElement->next;
         }
         previousElement = currentElement;
         currentElement = currentElement->next;
         free(previousElement);
         previousElement = currentElement;

      }
      else
      {
         previousElement = currentElement;
         currentElement = currentElement->next;
      }
   }
};
void erasei()
{
   if (first == NULL) {
      return;
   }
   NodeT* currentElement;
   currentElement = first->next;
   free(first);
   first = currentElement;
   printf("%d ", currentElement->data);
};
void erasef()
{
   if (first == NULL) {
      return;
   }
   NodeT* currentElement = first;
   while (currentElement->next != last)
   {
      currentElement = currentElement->next;

   }
   currentElement->next = NULL;
   free(last);
   last = currentElement;

};
void print()
{
   FILE* g = fopen("output.dat.txt", "a");
   if (first == NULL)
   {
      printf("List is empty!\n");
   }
   else
   {
      NodeT* currentElement = first;
      while (currentElement != NULL)
      {
         fprintf(g, "%d ", currentElement->data);
         currentElement = currentElement->next;
      }
      fprintf(g, "\n");

   }
};
void eraseall()
{
   NodeT* currentElement = first;
   while (currentElement != NULL)
   {
      first = first->next;
      currentElement->next = NULL;
      free(currentElement);
      currentElement = first;

   }
};

void printix(int x)
{
   FILE* g = fopen("output.dat.txt", "a");
   int i = 0;
   NodeT* currentElement = first;
   for (i = 0; i < x; i++)
   {
      fprintf(g, "%d ", currentElement->data);
      currentElement = currentElement->next;
   }
   fprintf(g, "\n");
};
void printfx(int x)
{
   FILE* g = fopen("output.dat.txt", "a");
   int i = 0;
   NodeT* currentElement = first;
   while (currentElement != NULL)
   {
      i++;
      currentElement = currentElement->next;
   }
   int j = 0;
   currentElement = first;
   while (j < i - x)
   {
      currentElement = currentElement->next;
      j++;
   }
   while (currentElement != NULL)
   {
      fprintf(g, "%d ", currentElement->data);
      currentElement = currentElement->next;
   }
   fprintf(g, "\n");
};
