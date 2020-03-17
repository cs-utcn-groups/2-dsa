#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node * next, * previous;
} nodeT;

typedef struct
{
    nodeT * first;
    nodeT * last;
    int size;
} sen;

sen sentinel;

void initialize ()
{
    sentinel.first = sentinel.last = NULL;
}

void addFirst (int data)
{
    if (sentinel.first == NULL)
    {
        sentinel.first = (nodeT*) malloc (sizeof (nodeT));
        sentinel.first->data = data;
        sentinel.first->previous = sentinel.first->next = NULL;
        sentinel.last = sentinel.first;
    }
    else
    {
        nodeT * newElement = (nodeT*) malloc (sizeof (nodeT));
        newElement->data = data;
        newElement->previous = NULL;
        newElement->next = sentinel.first;
        sentinel.first->previous = newElement;
        sentinel.first = newElement;
    }
    sentinel.size++;
}

void addLast (int data)
{
    if (sentinel.first == NULL)
    {
        sentinel.first = (nodeT*) malloc (sizeof (nodeT));
        sentinel.first->data = data;
        sentinel.first->previous = sentinel.first->next = NULL;
        sentinel.last = sentinel.first;
    }
    else
    {
        nodeT * newElement = (nodeT*) malloc (sizeof (nodeT));
        newElement->data = data;
        newElement->next = NULL;
        newElement->previous = sentinel.last;
        sentinel.last->next = newElement;
        sentinel.last = newElement;
    }
    sentinel.size++;
}

void deleteFirst (FILE * fout)
{
    if (sentinel.first == NULL)
    {
        fprintf (fout, "The list is empty.\n");
    }
    else
    {
        if (sentinel.first == sentinel.last)
        {
            free (sentinel.first);
            initialize ();
        }
        else
        {
            nodeT * newNode = sentinel.first;
            sentinel.first = sentinel.first->next;
            sentinel.first->previous = NULL;
            free (newNode);
        }
        sentinel.size--;
    }
}

void deleteLast (FILE * fout)
{
    if (sentinel.first == NULL)
    {
        fprintf (fout, "The list is empty.\n");
    }
    else
    {
        if (sentinel.first == sentinel.last)
        {
            free (sentinel.last);
            initialize ();
        }
        else
        {
            nodeT * newNode = sentinel.last;
            sentinel.last = sentinel.last->previous;
            sentinel.last->next = NULL;
            free (newNode);
        }
        sentinel.size--;
    }
}

void deleteData (int data)
{
    nodeT * currentElement = sentinel.first, * previousElement = sentinel.first;
    while (currentElement != NULL)
    {
        if (currentElement->data == data)
        {
            if (currentElement == sentinel.first)
            {
                 sentinel.first = sentinel.first->next;
                 sentinel.first->previous = NULL;
            }
            else
            {
                if (currentElement == sentinel.last)
                {
                    sentinel.last = sentinel.last->previous;
                    sentinel.last->next = NULL;
                }
                else
                {
                    previousElement->next = currentElement->next;
                    currentElement->next->previous = previousElement;
                }
            }
            previousElement = currentElement;
            currentElement = currentElement->next;
            free (previousElement);
            previousElement = currentElement;
            sentinel.size--;
        }
        else
        {
            previousElement = currentElement;
            currentElement = currentElement->next;
        }

    }
}

void doom (FILE * fout)
{
    if (sentinel.first == NULL)
    {
        fprintf (fout, "The list is empty.\n");
    }
    else
    {
        nodeT * currentElement = sentinel.first;
        while (currentElement != NULL)
        {
            sentinel.first = sentinel.first->next;
            free (currentElement);
            currentElement = sentinel.first;
        }
        fprintf (fout, "The list is cleared.\n");
        sentinel.size = 0;
    }
}

void print (FILE * fout)
{
    if (sentinel.first == NULL)
    {
        fprintf (fout, "The list is empty.\n");
    }
    else
    {
        nodeT * currentElement = sentinel.first;
        while (currentElement != NULL)
        {
            fprintf (fout, "%d ", currentElement->data);
            currentElement = currentElement->next;
        }
        fprintf (fout, "\n");
    }
}

void printFirst (int number, FILE * fout)
{
    if (sentinel.first == NULL)
    {
        fprintf (fout, "The list is empty.\n");
    }
    else
    {
        nodeT * currentElement = sentinel.first;
        int index = 1;
        while (currentElement != NULL && index <= number)
        {
            fprintf (fout, "%d ", currentElement->data);
            currentElement = currentElement->next;
            index++;
        }
        fprintf (fout, "\n");
    }
}

void printLast(int number, FILE * fout)
{
    if (sentinel.last == NULL)
    {
        fprintf (fout, "The list is empty.\n");
    }
    else
    {
        nodeT * currentElement = sentinel.first;
        int index = 1;
        while (currentElement != NULL)
        {
            if (sentinel.size - index < number)
            {
                fprintf (fout, "%d ", currentElement->data);
            }
            currentElement = currentElement->next;
            index++;
        }
        fprintf (fout, "\n");
    }
}

void readInstructions (FILE * fin, FILE * fout)
{
    char * s = (char*) malloc (sizeof (char) * 15);
    char * token;
    int data;
    while (fgets (s, 15, fin))
    {
        token = strtok (s, " \n");
        if (strcmp (token, "AF") == 0)
        {
            token = strtok (NULL, " \n");
            data = atoi (token);
            addFirst (data);
        }
        else
        {
            if (strcmp (token, "AL") == 0)
            {
                token = strtok (NULL, " \n");
                data = atoi (token);
                addLast (data);
            }
            else
            {
                if (strcmp (token, "DF") == 0)
                {
                    deleteFirst (fout);
                }
                else
                {
                    if (strcmp (token, "DL") == 0)
                    {
                        deleteLast (fout);
                    }
                    else
                    {
                        if (strcmp (token, "DOOM_THE_LIST") == 0)
                        {
                            doom (fout);
                        }
                        else
                        {
                            if (strcmp (token, "DE") == 0)
                            {
                                token = strtok (NULL, "\n");
                                data = atoi (token);
                                deleteData (data);
                            }
                            else
                            {
                                if (strcmp (token, "PRINT_ALL") == 0)
                                {
                                    print (fout);
                                }
                                else
                                {
                                    if (strcmp (token, "PRINT_F") == 0)
                                    {
                                        token = strtok (NULL, " \n");
                                        data = atoi (token);
                                        printFirst (data, fout);
                                    }
                                    else
                                    {
                                        if (strcmp (token, "PRINT_L") == 0)
                                        {
                                            token = strtok (NULL, " \n");
                                            data = atoi (token);
                                            printLast (data, fout);
                                        }
                                        else
                                        {
                                            fprintf (fout, "Unknown instruction.\n");
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    FILE * fin = fopen ("input.dat", "r");
    FILE * fout = fopen ("output.dat", "w");
    initialize ();
    sentinel.size = 0;
    readInstructions (fin, fout);

    fclose (fin);
    fclose (fout);
    return 0;
}
