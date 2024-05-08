#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef enum
{
    q0,q1,q2,q3,q4,q5
}etat;

int deplace[5][3] =
{
    //{C, L, not}
    {1, 3, 5}, //q0
    {2, 5, 5}, //q1
    {1, 5, 5}, //q2
    {4, 4, 5}, //q3
    {3, 3, 5}, //q4
    {5, 5, 5}  //q5
};

bool chiffre(char ch)
{
    return (ch>='0' && ch<='9');
}

bool letter(char ch)
{
    return ((ch>='A' && ch<='Z') || (ch>='a' && ch<='z'));
}

etat transition(etat current,char mot)
{
    int i;
    if(chiffre(mot))
    {
        i=0;
    }
    else if(letter(mot))
    {
        i=1;
    }
    else
    {
        i=2;
    }
    return (etat)deplace[current][i];
}

int main()
{
    etat current=q0;
    char ch;
    char word[1000];
    int j=1;
    FILE *file=fopen("test.txt","r");

    if(file==NULL)
    {
        printf("ERROR");
        return 1;
    }

    while((ch=fgetc(file)) != EOF)
    {
        if(ch == ' ' || ch == '.' || ch == ',' || ch == '\n' || ch == '\t' || ch == '/' || ch == '\\' || ch == '-' || ch == '_')
        {
            if(strlen(word)>0)
            {
                int i=0;
                char e;
                printf("Word %d : %s\n",j,word);
                j++;

                while(word[i] != '\0')
                {
                    if(chiffre(word[i]))
                    {
                        e = 'C';
                    }
                    else if(letter(word[i]))
                    {
                        e = 'L';
                    }
                    else
                    {
                        e = 'Not Defined Symbol';
                    }

                    printf("\n q%d --> q%d with %c",current,transition(current,word[i]),e);
                    current=transition(current,word[i]);
                    i++;
                    if(current==q5)
                    {
                        printf("\nRefuser\n");
                        break;
                    }
                }

                if(current==q2 || current==q4)
                {
                    printf("\nAccepter\n");
                }
                else
                {
                    printf("\nRefuser\n");
                }
                current=q0;
                memset(word,0,sizeof(word));
            }
        }
        else
        {
            strncat(word,&ch,1);
        }
    }
    fclose(file);
    return 0;
}
