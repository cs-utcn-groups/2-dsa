#include<stdlib.h>
#include<string.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node * next;
} nodeN;

nodeN * first , * last;

FILE * out;

void addLast ( int a ) {
    if( first != NULL ) {
        nodeN * newN; ///the new node
        newN = ( nodeN * ) malloc (  sizeof( nodeN )  );
        last -> next = newN;
        newN -> next = NULL;
        newN -> data = a;
        last = newN;
    } else {
        first = ( nodeN * ) malloc (  sizeof( nodeN )  );
        first -> data = a;
        first -> next = last;
        last = first;
    }
}

void addFirst ( int a ) {
    if ( first != NULL ) {
        nodeN * newN; /// new node
        newN = ( nodeN * ) malloc ( sizeof ( nodeN )  );
        newN -> data = a;
        newN -> next = first;
        first = newN;
    } else {
        first = ( nodeN * ) malloc ( sizeof ( nodeN )  );
        first -> data = a;
        first -> next = last;
        last = first;
    }
}

void printAll (  ) {
    nodeN * n; ///the current node

    if( first != NULL )
    {
        n = first;
        while ( n != NULL ) {
            fprintf( out , "%d " , n -> data );
            n = n -> next;
        }
        fprintf( out ,"\n" );
    } else {
        fprintf( out , "The list is empty!\n" );
    }
}

void printFirst ( int a ) {
    nodeN * n; ///the current node

    if( first != NULL )
    {
        n = first;
        int i = 0;
        while ( n != NULL && i < a )
        {
            fprintf( out , "%d " , n -> data );
            n = n -> next;
            i++;
        }
        fprintf( out , "\n" );
    } else {
        fprintf( out , "The list is empty!\n" );
    }
}

void printLast ( int a ) {
    nodeN * n; ///the current node

    if( first != NULL )
    {
        n = first;
        int nrN = 0; /// the number of nodes

        while( n != NULL ) {
            nrN++;
            n = n -> next;
        }

        n = first;
        int i = 0;
        while ( n != NULL ) {
            if ( i < nrN - a )
            {
                n = n -> next;
                i++;
            } else {
                fprintf ( out , "%d " , n -> data );
                n = n -> next;
            }
        }

        fprintf ( out , "\n" );
    } else {
        fprintf ( out , "The list is empty!\n" );
    }
}

void deleteLast (  ) {
    nodeN * n = first; ///the current node
    nodeN * penN = NULL; /// penultimul nod

    if ( n != NULL ) {
        while ( n != last ) {
            penN = n;
            n = n -> next;
        }
        if ( n != first ) {
            penN -> next = NULL;
            last = penN;
        } else {
            first = NULL;
            last = NULL;
        }
        free( n );
    }
}

void deleteFirst (  ) {
    nodeN * n = first; ///the current node
    if ( first != NULL ) {
        first = first -> next;
        free ( n );
    } else {
        last = NULL;
    }
}

void deleteAll (  ) {
    nodeN * n = first; ///the current node
    while ( n != NULL )
    {
        first = first -> next;
        free ( n );
        n = first;
    }
}

void deleteElement ( int a ) {
    nodeN * n = first; /// the current element
    nodeN * prevN = first; /// the previous element

    while ( n != NULL ) {
        if ( n -> data == a ) {
            prevN = n;
            n = n -> next;
        } else {
            if ( n == first ) {
                first = first -> next;
            } else if ( n == last ) {
                last = prevN;
                last -> next = NULL;
            } else {
                prevN -> next = n -> next;
            }
            prevN = n;
            n = n -> next;
            free ( prevN );
            prevN = n;
        }
    }
}

int main (  ) {
    out = fopen ( "C:/Users/coman/OneDrive/Desktop/assignments_y1_s2/output.txt" , "w" );
    if ( out == NULL ) {
        printf ( "Could not open the file" );
        return 0;
    }

    FILE * in;
    in = fopen ( "C:/Users/coman/OneDrive/Desktop/assignments_y1_s2/input.txt" , "r" );
    if ( in == NULL ) {
        printf ( "Error" );
        exit(1);
    }

    first = NULL;
    last = NULL;

    int a;
    char * text;
    text = ( char * ) malloc ( 10 * sizeof( char ) );

    while ( fscanf ( in , "%s" , text ) > 0 ) {
        if ( strcmp ( text , "AF" ) == 0 ) {
            fscanf ( in , "%d" , &a );
            addFirst ( a );
        }

        if ( strcmp ( text , "DF" ) == 0 ) {
            fscanf ( in , "%d" , &a );
            addLast ( a );
        }

        if ( strcmp ( text , "DL" ) == 0 ) {
            deleteFirst (  );
        }

        if ( strcmp ( text , "AF" ) == 0 ) {
            deleteLast (  );
        }

        if ( strcmp ( text , "DOOM_THE_LIST" ) == 0 ) {
            deleteAll (  );
        }

        if ( strcmp ( text , "DE" ) == 0 ) {
            fscanf ( in , "%d" , &a );
            deleteElement ( a );
        }

        if ( strcmp ( text , "PRINT_ALL" ) == 0 ) {
            printAll (  );
        }

        if ( strcmp ( text , "PRINT_F" ) == 0 ) {
            fscanf ( in , "%d" , &a );
            printFirst( a );
        }

        if ( strcmp ( text , "PRINT_L" ) == 0 ) {
            fscanf ( in , "%d" , &a );
            printLast ( a );
        }
    }

    free ( text );
    fclose ( in );
    fclose ( out );

    return 0;
}











