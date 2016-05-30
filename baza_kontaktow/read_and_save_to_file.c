#include "baza_kontaktow.h"

/**
    @file read_and_save_to_file.c
    \brief Przechowuje funkcję do odczytu i zapisu plików.
*/

/**
    * \fn void save(FILE *file,FILE *file2,FILE *file3, struct User_Node * FrontUserList, struct telephone_nr * FrontTelList, struct email_node *FrontEmailList)
    * \brief Procedura zapisuje dane z 3 różnych list do 3 różnych plików.
    * \param FrontUserList wskaźnik na początek listy User_Node.
    * \param FrontTelList wskaźnik na początek listy telephone_nr.
    * \param FrontEmailList wskaźnik na początek listy email_node.
    * \param file wskaźnik na plik
    * \param file2 wskaźnik na plik
    * \param file3 wskaźnik na plik
*/
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
        fprintf(file2,"\n%u\t", FrontTelList->ID_tel);
        fprintf(file2,"%lu", FrontTelList->tel_nr);
    }
    for (; NULL != FrontEmailList ; FrontEmailList = FrontEmailList -> next )
    {
        fprintf(file3,"\n%u\t", FrontEmailList->ID_email);
        fprintf(file3,"%s", FrontEmailList->em);
    }

    if(fclose(file) || fclose(file2) || fclose(file3))
    {
        printf("Blad zamkniecia pliku");
    }
}
// odczyt uzytkonikow z pliku
/**
    * \fn struct User_Node *read(FILE *file, struct User_Node * FrontUserList)
    * \brief Funkcja odczytuje dane z pliku USERS.txt i zapisuje je w liście User_Node
    * \param FrontUserList wskaźnik na początek listy User_Node.
    * \param file wskaźnik na plik
    * \return FrontUserList zwraca wskażnik na początek listy
*/
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
            fscanf(file,"%u",&new_node->house_number);
            fscanf(file,"%s",new_node->postal_code);
            fscanf(file,"%s",new_node->post_office);

            new_node -> next = NULL ;
            FrontUserList=new_node;
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
                fscanf(file,"%u",&new_node->house_number);
                fscanf(file,"%s",new_node->postal_code);
                fscanf(file,"%s",new_node->post_office);

                new_node -> next = NULL ;
            }
        }
    }

    if(fclose(file))
    {
        printf("Blad zamkniecia pliku");
    }
    return FrontUserList;
}
//Odczyt telefontow z pliku
/**
    * \fn struct telephone_nr *readTelephone(FILE *file2, struct telephone_nr * FrontTelList)
    * \brief Funkcja odczytuje dane z pliku TELEPGONE.txt i zapisuje je w liście telephone_nr
    * \param FrontTelList wskaźnik na początek listy telephone_nr.
    * \param file2 wskaźnik na plik
    * \return FrontTelList zwraca wskażnik na początek listy
*/
struct telephone_nr *readTelephone(FILE *file2, struct telephone_nr * FrontTelList)
{
    struct telephone_nr *new_node = (struct telephone_nr *)malloc (sizeof (struct telephone_nr));
    file2=fopen("TELEPHONE.txt","r");
    if(file2==NULL)
    {
        printf("Blad odczytu pliku");
        exit(0);
    }

    while(feof(file2) == 0)
    {
        if (NULL != new_node && FrontTelList==NULL)
        {
            fscanf(file2,"%u",&new_node->ID_tel);
            NumID=new_node->ID_tel;
            fscanf(file2,"%lu",&new_node->tel_nr);

            new_node -> next = NULL ;
            FrontTelList=new_node;
        }
        else
        {
            struct telephone_nr *wsk=FrontTelList; //Ustawienie wskaŸnika roboczego na pierwszym elemencie listy
            struct telephone_nr *new_node = (struct telephone_nr *)malloc (sizeof (struct telephone_nr));
            while (wsk->next != NULL)
            {
                wsk = wsk->next; // przesuwamy wsk a¿ znajdziemy ostatni element
            }
            if (NULL != new_node)
            {
                wsk->next = new_node; // w pole next ostatniego elementu listy wpisaæ adres nowo przydzielonego obszaru
                fscanf(file2,"%u",&new_node->ID_tel);
                NumID=new_node->ID_tel;
                fscanf(file2,"%lu",&new_node->tel_nr);

                new_node -> next = NULL ;
            }
        }
    }

    if(fclose(file2))
    {
        printf("Blad zamkniecia pliku");
    }
    return FrontTelList;
}
// odczyt adresow email z pliku
/**
    * \fn struct email_node *readEmail(FILE *file3, struct email_node * FrontEmailList)
    * \brief Funkcja odczytuje dane z pliku EMAIL.txt i zapisuje je w liście email_node
    * \param FrontEmailList wskaźnik na początek listy email_node.
    * \param file3 wskaźnik na plik
    * \return FrontEmailList zwraca wskażnik na początek listy
*/
struct email_node *readEmail(FILE *file3, struct email_node * FrontEmailList)
{
    struct email_node *new_node = (struct email_node *)malloc (sizeof (struct email_node));
    file3=fopen("EMAIL.txt","r");
    if(file3==NULL)
    {
        printf("Blad odczytu pliku");
        exit(0);
    }

    while(feof(file3) == 0)
    {
        if (NULL != new_node && FrontEmailList==NULL)
        {
            fscanf(file3,"%u",&new_node->ID_email);
            NumID=new_node->ID_email;
            fscanf(file3,"%s",new_node->em);
            new_node -> next = NULL ;
            FrontEmailList=new_node;
        }
        else
        {
            struct email_node *wsk=FrontEmailList; //Ustawienie wskaŸnika roboczego na pierwszym elemencie listy
            struct email_node *new_node = (struct email_node *)malloc (sizeof (struct email_node));
            while (wsk->next != NULL)
            {
                wsk = wsk->next; // przesuwamy wsk a¿ znajdziemy ostatni element
            }
            if (NULL != new_node)
            {
                wsk->next = new_node; // w pole next ostatniego elementu listy wpisaæ adres nowo przydzielonego obszaru
                fscanf(file3,"%u",&new_node->ID_email);
                NumID=new_node->ID_email;
                fscanf(file3,"%s",new_node->em);
                new_node -> next = NULL ;
            }
        }
    }

    if(fclose(file3))
    {
        printf("Blad zamkniecia pliku");
    }
    return FrontEmailList;
}

