#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node * next;
} nodeT;

nodeT * first, * last;
int nodesNumber;

void initialize ()
{
    first = NULL;
    last = NULL;
}

void addFirst (int data)
{
    if (first == NULL)
    {
        first = (nodeT*) malloc (sizeof (nodeT));
        first->data = data;
        first->next = NULL;
        last = first;
    }
    else
    {
        nodeT * newElement = (nodeT*) malloc (sizeof (nodeT));
        newElement->data = data;
        newElement->next = first;
        first = newElement;
    }
    nodesNumber++;
}

void addLast (int data)
{
    if (first == NULL)
    {
        first = (nodeT*) malloc (sizeof (nodeT));
        first->data = data;
        first->next = NULL;
        last = first;
    }
    else
    {
        nodeT * newElement = (nodeT*) malloc (sizeof (nodeT));
        newElement->data = data;
        newElement->next = NULL;
        last->next = newElement;
        last = newElement;
    }
    nodesNumber++;
}

void deleteFirst (FILE * fout)
{
    if (first == NULL)
    {
        fprintf (fout, "The list is empty.\n");
    }
    else
    {
        nodeT * newNode = first;
        first = first->next;
        free (newNode);
        nodesNumber--;
    }
}

void deleteLast (FILE * fout)
{
    if (first == NULL)
    {
        fprintf (fout, "The list is empty.\n");
    }
    else
    {
        if (first == last)
        {
            free (first);
            initialize ();
        }
        else
        {
            nodeT * currentNode = first;
            while (currentNode->next != last)
            {
                currentNode = currentNode->next;
            }
            currentNode->next = NULL;
            free (last);
            last = currentNode;
        }
        nodesNumber--;
    }
}

void doom (FILE * fout)
{
    if (first != NULL)
    {
        nodeT * currentElement = first;
        while (currentElement != NULL)
        {
            first = first->next;
            free (currentElement);
            currentElement = first;
        }
    }
    nodesNumber = 0;
    fprintf (fout, "The list is cleared.\n");
}

void deleteData (int data)
{
    nodeT * currentElement = first, * previousElement = first;
    while (currentElement != NULL)
    {
        if (currentElement->data == data)
        {
            if (currentElement == first)
            {
                first = first->next;
            }
            else
            {
                if (currentElement == last)
                {
                    last = previousElement;
                    last->next = NULL;
                }
                else
                {
                    previousElement->next = currentElement->next;
                }
            }
            previousElement = currentElement;
            currentElement = currentElement->next;
            free (previousElement);
            previousElement = currentElement;
            nodesNumber--;
        }
        else
        {
            previousElement = currentElement;
            currentElement = currentElement->next;
        }
    }
}

void print (FILE * fout)
{
    if (first == NULL)
    {
        fprintf (fout, "The list is empty.\n");
    }
    else
    {
        nodeT * currentElement = first;
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
    if (first == NULL)
    {
        fprintf (fout, "The list is empty.\n");
    }
    else
    {
        nodeT * currentElement = first;
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

void printLast (int number, FILE * fout)
{
    if (first == NULL)
    {
        fprintf (fout, "The list is empty.\n");
    }
    else
    {
        nodeT * currentElement = first;
        int index = 1;
        while (currentElement != NULL)
        {
            if (nodesNumber - index < number)
            {
                fprintf (fout, "%d ", currentElement->data);
            }
            currentElement = currentElement->next;
            index++;
        }
    }
    fprintf (fout, "\n");
}

int isDigit (char c)
{
    return c >= '0' && c <= '9';
}

void readInstructions ()
{
    FILE * fin = fopen ("input.dat", "r");
    FILE * fout = fopen ("output.dat", "w");
    char * s = (char*) malloc (sizeof (char) * 15), * token;
    int data;
    while (fgets (s, 15, fin))
    {
        token = strtok (s, " ");
        int len = strlen (token);
        if (token[len - 1] == '\n')
        {
            token[len - 1] = '\0';
        }
        data = 0;
        if (strcmp (token, "AF") == 0)
        {
            token = strtok (NULL, " ");
            int i = 0;
            while (i < strlen (token) - 1&& isDigit (token[i]))
            {
                data = data * 10 + token[i] - '0';
                i++;
            }
            addFirst (data);
        }
        else
        {
            if (strcmp (token, "AL") == 0)
            {
                token = strtok (NULL, " ");
                int i = 0;
                while (i < strlen (token) - 1&& isDigit (token[i]))
                {
                    data = data * 10 + token[i] - '0';
                    i++;
                }
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
                                token = strtok (NULL, " ");
                                int i = 0;
                                while (i < strlen (token) - 1&& isDigit (token[i]))
                                {
                                    data = data * 10 + token[i] - '0';
                                    i++;
                                }
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
                                        token = strtok (NULL, " ");
                                        int i = 0;
                                        while (i < strlen (token) - 1&& isDigit (token[i]))
                                        {
                                            data = data * 10 + token[i] - '0';
                                            i++;
                                        }
                                        printFirst (data, fout);
                                    }
                                    else
                                    {
                                        if (strcmp (token, "PRINT_L") == 0)
                                        {
                                            token = strtok (NULL, " ");
                                            int i = 0;
                                            while (i < strlen (token) - 1&& isDigit (token[i]))
                                            {
                                                data = data * 10 + token[i] - '0';
                                                i++;
                                            }
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
    nodesNumber = 0;
    readInstructions ();

    return 0;
}
