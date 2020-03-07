#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

typedef struct _SENTINEL{
    int withstand;
    struct _SENTINEL *next;
}SENTINEL;

typedef  struct _WAVE{ ///YES, I know that it is the same as the Sentinel one
    int damage;         /// but I really wanted to have a different name
    struct  _WAVE *next;
}WAVE;

typedef  struct  _COUNTRY{
    char *name;
    struct  _COUNTRY *next;
    WAVE *FirstW,*LastW;
}COUNTRY;

int N,M,TheLongestWave=0,TotalPowerOfC=0;
SENTINEL *FirstS,*LastS;
COUNTRY *FirstC,*LastC;

void AddSentinel(int value)
{
    if(FirstS == NULL)
    {
        FirstS=(SENTINEL*)malloc(sizeof(SENTINEL));
        FirstS->withstand=value;
        FirstS->next=NULL;
        LastS=FirstS;
    } else
    {
        SENTINEL *NewSentinel=(SENTINEL*)malloc(sizeof(SENTINEL));
        NewSentinel->withstand=value;
        NewSentinel->next=NULL;
        LastS->next=NewSentinel;
        LastS=NewSentinel;
    }
}

void AddCountry( char *Name)
{
    if(FirstC == NULL)
    {
        FirstC=(COUNTRY*)malloc(sizeof(COUNTRY));
        FirstC->name=(char*)malloc(sizeof(char)*256);
        strcpy(FirstC->name,Name);
        FirstC->next=NULL;
        FirstC->FirstW=NULL;
        FirstC->LastW=NULL;
        LastC=FirstC;
    } else
    {
        COUNTRY *NewCountry=(COUNTRY*)malloc(sizeof(COUNTRY));
        NewCountry->name=(char*)malloc(sizeof(char)*256);
        strcpy(NewCountry->name,Name);
        NewCountry->next=NULL;
        NewCountry->FirstW=NULL;
        NewCountry->LastW=NULL;
        LastC->next=NewCountry;
        LastC=NewCountry;
    }
}

void AddWave( int Damage)
{
    if(LastC->FirstW == NULL)
    {
        LastC->FirstW=(WAVE*)malloc(sizeof(WAVE));
        LastC->FirstW->next=NULL;
        LastC->FirstW->damage=Damage;
        LastC->LastW=LastC->FirstW;
    } else
    {
        WAVE *NewWave=(WAVE*)malloc(sizeof(WAVE));
        LastC->LastW->next=NewWave;
        NewWave->next=NULL;
        NewWave->damage=Damage;
        LastC->LastW=NewWave;
    }

}


int GetWaveDamage(int nr,COUNTRY * C)
{
    WAVE *Wave=C->FirstW;
    for(int i=1;Wave&&i<nr;++i)
    {
        Wave=Wave->next;
    }
    if(Wave)
        return Wave->damage;
    return 0;
}

bool Attack(char *LastHitCountry)   //We'll return true if the tyrant is killed, and we'll return as a parameter the Country that had the last kit
{
    int NrOfWave=1;
    SENTINEL *Sentinel=FirstS;
    WAVE *Wave=FirstC->FirstW;
    COUNTRY *Country=FirstC;
    int WithStand=0;
    while(Sentinel != NULL )
    {
        WithStand+=Sentinel->withstand;
        while (WithStand>0)
        {
            WithStand-=GetWaveDamage(NrOfWave,Country);
            strcpy(LastHitCountry,Country->name);
            Country=Country->next;
            if(!Country)
            {
                Country=FirstC;
                if(++NrOfWave>TheLongestWave)
                    continue;
            }

        }
        Sentinel=Sentinel->next;
    }
    if(WithStand>0)
    {
        LastHitCountry=NULL;
        return false;
    }
    else
    {
        return true;
    }
}

int GetPower(WAVE *First)
{
    int Damage=0;
    WAVE *Wave=First;
    while (Wave)
    {
        Damage+=Wave->damage;
        Wave=Wave->next;
    }
    return Damage;
}

char * StrongestCountry (COUNTRY **C, int *Damage) ///Return the name of the Strongest Country, the pointer to the Contry as a parameter and the also the total damage of the Contry
{
    int max=0;
    char *s=(char*)malloc(sizeof(char)*256); /// s is the name of the Strongest Country
    COUNTRY *Country= FirstC;
    while(Country)
    {
        int Power=GetPower(Country->FirstW);
        if(Power>max)
        {
            max=Power;
            strcpy(s,Country->name);
            *C=Country;
            *Damage=Power;
        }
        Country=Country->next;
    }
    return  s;
}

char * WeakestCountry(void)
{
    int min=INT_MAX;
    char *s=(char*)malloc(sizeof(char)*256); /// s is the name of the Strongest Country
    COUNTRY *Country= FirstC;
    while(Country)
    {
        int Power=GetPower(Country->FirstW);
        if(Power<min)
        {
            min=Power;
            strcpy(s,Country->name);
        }
        Country=Country->next;
    }
    return  s;

}

int GetSentinelWithStand()
{
    int WithStand=0;
    SENTINEL * Sentinel=FirstS;
    while(Sentinel)
    {
        WithStand+=Sentinel->withstand;
        Sentinel=Sentinel->next;
    }
    return  WithStand;
}

int BeatingSentinelsAlone(int *x,WAVE *FirstWave)//return how many sentinels are defeated and how much damage was dealt to the next one
{
    SENTINEL *Sentinel=FirstS;
    WAVE *Wave=FirstWave;
    int nr=0;
    int a;
    while(TotalPowerOfC>0)
    {
        nr++;
        a=Sentinel->withstand;
        TotalPowerOfC-=Sentinel->withstand;
        Sentinel=Sentinel->next;
    }
    *x=TotalPowerOfC+a;
    return  nr-1;


}

int main() {
    FILE *f=fopen("input.dat","r");
    FILE *g=fopen("output.dat","w");
    fscanf(f,"%d",&N);
    for(int i=0,withstand;i<N;++i)
    {
        fscanf(f,"%d",&withstand);
        AddSentinel(withstand);
    }
    fscanf(f,"%d\n",&M);
    char *s=(char*)malloc(sizeof(char)*256);

    for(int i=0,k=0;i<M;++i,k=0) ///K is the longest wave for each country
    {
        fgets(s,256,f);
        char *p=strtok(s," \n");
        AddCountry(p);
        while (p=strtok(NULL," \n"))
        {
            AddWave(atoi(p));
            ++k;
        }
        if(k>TheLongestWave)
            TheLongestWave=k;
    }
    if(Attack(s)==1)
    {
        fprintf(g,"The tyrant was killed! \nThe last hit was done by:%s\n",s);
    } else
        fprintf(g,"Not defeated\n");
    COUNTRY *C=NULL;   ///Strongest Country
    fprintf(g,"The Strongest Country was:%s\n",StrongestCountry(&C,&TotalPowerOfC));
    fprintf(g,"The Weakest Country was:%s\n",WeakestCountry());
    int TotalWithtStand=GetSentinelWithStand();
    int x=0;
    if(TotalPowerOfC>=TotalWithtStand)
    {
        fprintf(g,"%s could have defeated all the sentinels by itself",C->name);
    } else
    {
        fprintf(g,"No country could have defeated all the sentinels");
        int NrOfSen=BeatingSentinelsAlone(&x,C->FirstW);
        fprintf(g,"%s could have brought down the first %d sentinels and would have had chipped off %d life points from sentinel %d.",C->name,NrOfSen,x,NrOfSen+1);
    }


    return 0;
}
