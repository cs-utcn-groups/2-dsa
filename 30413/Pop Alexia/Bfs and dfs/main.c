#include <stdio.h>
#include <stdlib.h>

int q[20],top=-1,front=-1,rear=-1,a[20][20],vis[20],stack[20];
void push(int item)
{
    if(top==19)
        printf("Stack overflow ");
    else
        stack[++top]=item;
}
int pop()
{
    int k;
    if(top==-1)
        return(0);
    else
    {
        k=stack[top--];
        return(k);
    }
}
void add(int item)
{
    if(rear==19)
        printf("Queue full");
    else
    {
        if(rear==-1)
        {
            q[++rear]=item;
            front++;
        }
        else
            q[++rear]=item;
    }
}
int delete()
{
    int k;
    if((front>rear)||(front==-1))
        return(0);
    else
    {
        k=q[front++];
        return(k);
    }
}

void bfs(int s,int n)
{
    int p,i;
    add(s);
    vis[s]=1;
    p=delete();
    if(p!=0) printf(" %d",p);
    while(p!=0)
    {
        for(i=1; i<=n; i++)
            if((a[p][i]!=0)&&(vis[i]==0))
            {
                add(i);
                vis[i]=1;
            }
        p=delete();
        if(p!=0)
            printf(" %d ",p);
    }
    for(i=1; i<=n; i++)
        if(vis[i]==0)
            bfs(i,n);
}



void dfs(int s,int n)
{
    int i,k;
    push(s);
    vis[s]=1;
    k=pop();
    if(k!=0)
        printf(" %d ",k);
    while(k!=0)
    {
        for(i=1; i<=n; i++)
            if((a[k][i]!=0)&&(vis[i]==0))
            {
                push(i);
                vis[i]=1;
            }
        k=pop();
        if(k!=0)
            printf(" %d ",k);
    }
    for(i=1; i<=n; i++)
        if(vis[i]==0)
            dfs(i,n);
}

int main()
{
    int n,i,s,j;
    char c;
    printf("DFS or BFS?\n");
    scanf("%c",&c);
    printf("Enter number of vertices ");
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            printf("Enter 1 if %d has a node with %d else 0 ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    printf("The Adjacency Matrix is\n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            printf(" %d",a[i][j]);
        }
        printf("\n");
    }
    for(i=1; i<=n; i++) vis[i]=0;

    if(c=='b'||c=='B')
    {
        printf("Enter the source vertex for bfs :");
        scanf("%d",&s);
        bfs(s,n);
    }
    else if(c=='d'||c=='D')
    {
        printf("Enter source vertex for dfs :");
        scanf("%d",&s);
        dfs(s,n);
    }
    else printf("There are only two options!!!");
    return 0;
}



