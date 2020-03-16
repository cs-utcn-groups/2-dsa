#include "header.h"

void initNodes()
{
//    firstCountry=(node **) malloc(sizeof(node *) * MAXIMUM_NR_OF_COUNTRIES);
//    lastCountry=(node **) malloc(sizeof(node *) * MAXIMUM_NR_OF_COUNTRIES);

    for(int i=0; i<nrOfCountries; i++)
    {
        firstCountry[i]=NULL;
        lastCountry[i]=NULL;
    }
}

void readInput(FILE *f,FILE *o)
{
    fscanf(f,"%d",&nrOfSentinels);

    for(int i=0; i<nrOfSentinels; i++)
    {
        int a;
        fscanf(f,"%d",&a);
        totalDefenseSentinels+=a;
        addElementAtEndSentinels(a);
        // addElementAtEnd(firstSentinel,lastSentinel,a);
    }

    fscanf(f,"%d",&nrOfCountries);

    char *lineToRead=(char *) malloc (MAXIMUM_LENGTH_LINE);
    int a;
    for(int i=0; i<nrOfCountries; i++)
    {
        fscanf(f,"%s",lineToRead);
        strcpy(country[i].name,lineToRead);
        // printf("%s\n",lineToRead);

        while((fscanf(f,"%d", &a) == 1))
        {
            country[i].totalDmgCountry+=a;
            country[i].totalWaves++;
            addElementAtEndCountry(a,i);
            // printf("%d\n",a);
        }

        totalDmgCountries+=country[i].totalDmgCountry;

        if(country[i].totalDmgCountry>maxDmg)
        {
            maxDmg=country[i].totalDmgCountry;
            strongestCountryIndex=i;
        }

        if(country[i].totalDmgCountry<minDmg)
        {
            minDmg=country[i].totalDmgCountry;
            weakestCountryIndex=i;
        }
    }
}

void initInfoCountry()
{
    totalDmgCountry=(int *) malloc(sizeof(int) * nrOfCountries);
    totalWavesCountry=(int *) malloc(sizeof(int) * nrOfCountries);
}
void addElementAtEndSentinels(int data)
{
    if(firstSentinel==NULL)
    {
        firstSentinel=(node *) malloc(sizeof(node));
        firstSentinel->info=data;
        firstSentinel->next=lastSentinel;
        lastSentinel=firstSentinel;
    }

    else
    {
        node * element=(node *) malloc(sizeof(node));
        element->next = NULL;
        element->info = data;
        lastSentinel->next = element;
        lastSentinel = element;
    }
}

void addElementAtEndCountry(int data,int index)
{
    if(firstCountry[index]==NULL)
    {
        firstCountry[index]=(node *) malloc(sizeof(node));
        firstCountry[index]->info=data;
        firstCountry[index]->next=lastCountry[index];
        lastCountry[index]=firstCountry[index];
    }

    else
    {
        node * element=(node *) malloc(sizeof(node));
        element->next = NULL;
        element->info = data;
        lastCountry[index]->next = element;
        lastCountry[index] = element;
    }
}

void PRINT_ALL(node * first, node * last,FILE *o)
{
    if(first==NULL || last==NULL)
    {
        fprintf(o,"List is emtpy\n");
        return;
    }

    node * element=first;

    while(element!=NULL)
    {
        fprintf(o,"%d ",element->info);
        element=element->next;
    }
    fprintf(o,"\n");
}

int accessWaveFromCountry(int wave, int countryIndex)
{
    node * element=firstCountry[countryIndex];

    for(int i=0; i<wave; i++)
    {
        element=element->next;
    }

    return element->info;
}

void attackSuccededTask(FILE * o)
{
    if(totalDmgCountries>=totalDefenseSentinels) /// we won
    {
        int * sentinels=NULL;
        sentinels=assignValuesToSentinelsArray(sentinels);
        int currentSentinel=0;

        for(int i=0; i<nrOfCountries; i++)
        {
            for(int j=0; j<country[i].totalWaves; j++)
            {
                sentinels[currentSentinel]-=accessWaveFromCountry(j,i);
                if(sentinels[currentSentinel]<=0)
                {
                    currentSentinel++;

                    if(currentSentinel<nrOfSentinels-1)
                    {
                        sentinels[currentSentinel]-=abs(sentinels[currentSentinel-1]);
                    }

                    else
                    {
                        fprintf(o,"The tyrant was killed!\nLast hit was done by: %s\n",country[i].name);
                        return;
                    }
                }
            }
        }
    }

    else
    {
        fprintf(o,"The communist bastard won the battle\n");
        return;
    }

}

void outputStrongestAndWeakest(FILE *o)
{
    fprintf(o,"The strongest country was: %s\n",country[strongestCountryIndex].name);
    fprintf(o,"The weakest country was: %s\n",country[weakestCountryIndex].name);
}

void computeWhoCouldWinAlone(FILE *o)
{
    if(maxDmg>totalDefenseSentinels)
    {
        fprintf(o,"%s could have defeated by itself the communist garbage\n",country[strongestCountryIndex].name);
    }

    else
    {
        int * sentinels=NULL;
        sentinels=assignValuesToSentinelsArray(sentinels);
        int currentSentinel=0;
        int copyOfCurrentSentinelValue=0;

        for(int i=0; i<country[strongestCountryIndex].totalWaves; i++)
        {
            sentinels[currentSentinel]-=accessWaveFromCountry(i,strongestCountryIndex);

            if(sentinels[currentSentinel]<=0)
            {
                currentSentinel++;
                copyOfCurrentSentinelValue=sentinels[currentSentinel];
                sentinels[currentSentinel]-=abs(sentinels[currentSentinel-1]);
            }
        }

        fprintf(o,"No country could have defeated all the sentinels.\n");
        fprintf(o,"%s could have brought down the first %d sentinels and would have had chipped off %d life points from sentinel %d\n",
                country[strongestCountryIndex].name,currentSentinel,copyOfCurrentSentinelValue-sentinels[currentSentinel],currentSentinel+1);
    }
}

int * assignValuesToSentinelsArray(int * v)
{
    v=(int *) malloc(sizeof(int) * nrOfSentinels);

    node * element=firstSentinel;
    int index=0;

    while(element!=NULL)
    {
        v[index++]=element->info;
        element=element->next;
    }

    return v;
}

void initCountries()
{
    country=(countries *) malloc(sizeof(countries) * MAXIMUM_NR_OF_COUNTRIES);

    for(int i=0; i<MAXIMUM_NR_OF_COUNTRIES; i++)
    {
        country[i].name=(char *) malloc(MAXIMUM_LENGTH_COUNTRY_NAME);
        country[i].totalDmgCountry=country[i].totalWaves=0;
    }
}
node ** aaa;
int main()
{
    FILE *f=fopen("input.dat","r");
    FILE *o=fopen("output.dat","w+");

  ///  initCountries(firstCountry,lastCountry);


    initCountries();

    readInput(f,o);

    attackSuccededTask(o);
    outputStrongestAndWeakest(o);
    computeWhoCouldWinAlone(o);

    return 0;
}
