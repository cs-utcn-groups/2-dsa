#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXX 55
#define INT_MAX 2147483647

int sentinelsNo, countriesNo, totalSentinelsDamage, damage, strong, weak, oneCountry, iStrong;

typedef struct node
{
    int damage;
    struct node * next;
} nodeT;

typedef struct
{
    nodeT * first, * last, * current;
} country;

nodeT * firstSen, * lastSen;
country * countriesWaves;

char ** countries, * strongest, * weakest, * winningCountry;

void initialize (nodeT * first, nodeT * last)
{
    first = NULL;
    last = NULL;
}

void readSentinels (FILE * fin)
{
    fscanf (fin, "%d\n", &sentinelsNo);
    int x;
    totalSentinelsDamage = 1;
    initialize (firstSen, lastSen);
    for (int i = 0; i < sentinelsNo; i++)
    {
        fscanf (fin, "%d ", &x);
        totalSentinelsDamage += x;
        if (firstSen == NULL)
        {
            firstSen = (nodeT*) malloc (sizeof (nodeT));
            firstSen->next = NULL;
            firstSen->damage = x;
            lastSen = firstSen;
        }
        else
        {
            nodeT * newSentinel = (nodeT*) malloc (sizeof (nodeT));
            newSentinel->next = NULL;
            newSentinel->damage = x;
            lastSen->next = newSentinel;
            lastSen = newSentinel;
        }
    }
    fscanf (fin, "\n");
}

void readCountries (FILE * fin)
{
    fscanf (fin, "%d\n", &countriesNo);
    int totalDamage = 0;
    oneCountry = 0;
    strongest = (char*) malloc (sizeof (char) * 25);
    weakest = (char*) malloc (sizeof (char) * 25);
    winningCountry = (char*) malloc (sizeof (char) * 25);
    countriesWaves = (country*) malloc (sizeof (country) * countriesNo);
    countries = (char**) malloc (sizeof (char*) * countriesNo);
    char * token, * s = (char*) malloc (sizeof (char) * MAXX);
    int dam;
    for (int i = 0; i < countriesNo; i++)
    {
        totalDamage = 0;
        countries[i] = (char*) malloc (sizeof (char) * 25);
        fgets (s, MAXX, fin);
        token = strtok (s, " ");
        strcpy (countries[i], token);
        token = strtok (NULL, " ");
        countriesWaves[i].first = NULL;
        countriesWaves[i].last = NULL;
        while (token != NULL)
        {
            dam = atoi (token);
            if (countriesWaves[i].first == NULL)
            {
                countriesWaves[i].first = (nodeT*) malloc (sizeof (nodeT));
                countriesWaves[i].first->next = NULL;
                countriesWaves[i].first->damage = dam;
                countriesWaves[i].last = countriesWaves[i].first;
            }
            else
            {
                nodeT * newWave = (nodeT*) malloc (sizeof (nodeT));
                newWave->next = NULL;
                newWave->damage = dam;
                countriesWaves[i].last->next = newWave;
                countriesWaves[i].last = newWave;
            }
            totalDamage += dam;

            if (totalDamage > strong)
            {
                strong = totalDamage;
                strcpy (strongest, countries[i]);
                if (totalDamage >= totalSentinelsDamage)
                {
                    oneCountry = 1;
                    strcpy (winningCountry, countries[i]);
                }
                iStrong = i;
            }
            else
            {
                if (totalDamage < weak)
                {
                    weak = totalDamage;
                    strcpy (weakest, countries[i]);
                }
            }
            token = strtok (NULL, " ");
        }
    }
}

int allNull ()
{
    for (int i = 0; i < countriesNo; i++)
    {
        if (countriesWaves[i].current != NULL)
        {
            return 0;
        }
    }
    return 1;
}

void execute (FILE * fout)
{
    for (int i = 0; i < countriesNo; i++)
    {
        countriesWaves[i].current = countriesWaves[i].first;
    }
    int killed = 0;
    while (damage < totalSentinelsDamage && ! allNull ())
    {
        for (int i = 0; i < countriesNo && killed == 0; i++)
        {
            if (countriesWaves[i].current != NULL)
            {
                damage += countriesWaves[i].current->damage;
                countriesWaves[i].current = countriesWaves[i].current->next;
                if (damage >= totalSentinelsDamage)
                {
                    killed = 1;
                    fprintf (fout, "The tyrant was killed!\nThe last hit was done by: %s\n", countries[i]);
                }
            }
        }
    }
    if (killed == 0)
    {
        fprintf (fout, "The tyrant was not killed!\n");
    }
}

void printStrongAndWeak (FILE * fout)
{
    fprintf (fout, "The strongest country was: %s.\nThe weakest country was: %s.\n", strongest, weakest);
}

void oneCanDoIt (FILE * fout)
{
    if (oneCountry == 1)
    {
        fprintf (fout, "%s could have defeated all the sentinels by itself.\n", winningCountry);
    }
    else
    {
        fprintf (fout, "No country could have defeated all the sentinels.\n");
        nodeT * q = firstSen;
        int dmg = 0, index = 0;
        while (q != NULL && dmg <= strong)
        {
            dmg += q->damage;
            if (dmg <= strong)
            {
                index++;
                q = q->next;
            }
        }
        dmg -= q->damage;
        if (index > 0)
        {
            fprintf (fout, "%s could have brought down the first %d sentinels and would have chipped of %d life points from sentinel %d.\n", countries[iStrong], index, strong - dmg, index + 1);
        }
    }
}

int main ()
{
    FILE * fin = fopen ("input1.dat", "r");
    FILE * fout = fopen ("output1.dat", "w");
    damage = 0;
    strong = 0;
    weak = INT_MAX;
    readSentinels (fin);
    readCountries (fin);
    execute (fout);
    printStrongAndWeak (fout);
    oneCanDoIt (fout);

    return 0;
}
