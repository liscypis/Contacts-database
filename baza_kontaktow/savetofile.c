#include "add_removeElements.h"

void save(FILE *file,FILE *file2,FILE *file3, struct User_Node * FrontUserList, struct telephone_nr * FrontTelList, struct email_node *FrontEmailList)
{
    file=fopen("USERS.txt","w");
    file2=fopen("TELEPHONE.txt","w");
    file3=fopen("EMAIL.txt","w");
    if(file==NULL || file2==NULL || file3==NULL)
    {
        printf("Blad odczytu pliku");
        exit(0);
    }

    for (; NULL != FrontUserList ; FrontUserList = FrontUserList -> next )
    {
        fprintf (file,"\n%u\n%s\n%s\n%s\n%s\n%hu\n%s\n%s",
                 FrontUserList->ID, FrontUserList->name, FrontUserList->surname, FrontUserList -> city,
                 FrontUserList->street, FrontUserList->house_number, FrontUserList->postal_code,
                 FrontUserList->post_office);
    }
    for (; NULL != FrontTelList ; FrontTelList = FrontTelList -> next )
    {
        fprintf(file2,"%u\t", FrontTelList->ID_tel);
        fprintf(file2,"%u\n", FrontTelList->tel_nr);
    }
    for (; NULL != FrontEmailList ; FrontEmailList = FrontEmailList -> next )
    {
        fprintf(file3,"%u\t", FrontEmailList->ID_email);
        fprintf(file3,"%s\n", FrontEmailList->em);
    }

    if(fclose(file) || fclose(file2) || fclose(file3))
    {
        printf("Blad zamkniecia pliku");
    }
}
// odczyt uzytkonikow z pliku
struct User_Node *read(FILE *file, struct User_Node * FrontUserList)
{
    struct User_Node *new_node = (struct User_Node *)malloc (sizeof (struct User_Node));
    file=fopen("USERS.txt","r");
    if(file==NULL)
    {
        printf("Blad odczytu pliku");
        exit(0);
    }

    while(feof(file) == 0)
    {
        if (NULL != new_node && FrontUserList==NULL)
        {
            fscanf(file,"%u",&new_node->ID);
            NumID=new_node->ID;
            fscanf(file,"%s",new_node->name);
            fscanf(file,"%s",new_node->surname);
            fscanf(file,"%s",new_node->city);
            fscanf(file,"%s",new_node->street);
            fscanf(file,"%hu",&new_node->house_number);
            fscanf(file,"%s",new_node->postal_code);
            fscanf(file,"%s",new_node->post_office);

            new_node -> next = NULL ;
            FrontUserList=new_node;
puts("hahahahahahahah111111");
        }
        else
        {
            struct User_Node *wsk=FrontUserList; //Ustawienie wskaŸnika roboczego na pierwszym elemencie listy
            struct User_Node *new_node = (struct User_Node *)malloc (sizeof (struct User_Node));
            while (wsk->next != NULL)
            {
                wsk = wsk->next; // przesuwamy wsk a¿ znajdziemy ostatni element
            }
            if (NULL != new_node)
            {
                wsk->next = new_node; // w pole next ostatniego elementu listy wpisaæ adres nowo przydzielonego obszaru
                fscanf(file,"%u",&new_node->ID);
                NumID=new_node->ID;
                fscanf(file,"%s",new_node->name);
                fscanf(file,"%s",new_node->surname);
                fscanf(file,"%s",new_node->city);
                fscanf(file,"%s",new_node->street);
                fscanf(file,"%hu",&new_node->house_number);
                fscanf(file,"%s",new_node->postal_code);
                fscanf(file,"%s",new_node->post_office);

                new_node -> next = NULL ;
puts("hahahahahahahah2222222");
            }
        }


    }

    if(fclose(file))
    {
        printf("Blad zamkniecia pliku");
    }
return FrontUserList;
}

