#include "header.c"

int main(int argc, char *argv[]) {
    NODE *root=NULL,p;
    FILE *f=fopen(argv[1],"r");
    char *s=(char*)malloc(sizeof(char)*2);
    while(fscanf(f,"%s",s)!=EOF)
    {
        switch (s[0]){
            case 'i':root=insert(s[1],root);break;
            case 'd':root=delete(s[1],root);break;
            case 'f':printf("%c was %s\n ",s[1],find(s[1],root)?"FOUND!":"NOT FOUND!");break;
            case 't':if(s[1]=='p') {
                        preorder(root);
                        printf("\n");
                    }
                    else if (s[1]=='P')
                    {
                        postorder(root);
                        printf("\n");
                    }
                         else
                         {
                             inorder(root);
                             printf("\n");
                          }
                break;
            case 'g':printf("%s is %c",s[1]=='m'?"Minimum":"Maximum",s[1]=='m'?gm(root)->Key:gM(root)->Key);             //  if(s[1]=='m')
                    break;                                                                                                       //                 printf("Minimum is %c\n",gm(root)->Key);
                                                                                                                                 //       else
                                                                                                                                 //              printf("Maximum is %c\n",gM(root)->Key);
            default:printf("WRONG INPUT LINE!\n");
                    break;


        }
    }
    return 0;
}
