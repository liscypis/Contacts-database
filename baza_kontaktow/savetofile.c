#include "add_removeElements.h"

void save(FILE *file, struct User_Node * FrontUserList, struct telephone_nr * FrontTelList, struct email_node *FrontEmailList)
{
    struct telephone_nr * temp_tel = FrontTelList; ////zapisanie we wskazniku lokalnym "temp_tel" adresu pierwszego elementu listy "telephone_nr"
    struct email_node * temp_email = FrontEmailList;
    unsigned int data;
    file=fopen("USERS.txt","w");
    if(file==NULL)
    {
        printf("Blad odczytu pliku");
        exit(0);
    }

    for (; NULL != FrontUserList ; FrontUserList = FrontUserList -> next )
    {
        data=FrontUserList->ID;
        fprintf (file,"*%u\n*%s\n*%s\n*%s\n*%s\n*%hu\n*%s\n*%s\n",
                 FrontUserList->ID, FrontUserList->name, FrontUserList->surname, FrontUserList -> city,
                 FrontUserList->street, FrontUserList->house_number, FrontUserList->postal_code,
                 FrontUserList->post_office);

        for (FrontTelList=temp_tel; NULL != FrontTelList ; FrontTelList = FrontTelList -> next )
        {
            if(FrontTelList->ID_tel==data)
                fprintf(file,"T\t%d\n", FrontTelList->tel_nr);
        }
        for (FrontEmailList=temp_email; NULL != FrontEmailList ; FrontEmailList = FrontEmailList -> next )
        {
            if(FrontEmailList->ID_email==data)
                fprintf(file,"E\t%s\n", FrontEmailList->em);
        }
    }
    if(fclose(file))
    {
        printf("Blad zamkniecia pliku");
    }
}
void read(FILE *file, struct User_Node * FrontUserList, struct telephone_nr * FrontTelList, struct email_node *FrontEmailList)
{
    struct telephone_nr * temp_tel = FrontTelList; ////zapisanie we wskazniku lokalnym "temp_tel" adresu pierwszego elementu listy "telephone_nr"
    struct email_node * temp_email = FrontEmailList;
    unsigned int data;
    file=fopen("USERS.txt","r");
    if(file==NULL)
    {
        printf("Blad odczytu pliku");
        exit(0);
    }

    while(feof(file) == 0)
    {
        for (; NULL != FrontUserList ; FrontUserList = FrontUserList -> next )
        {
            data=FrontUserList->ID;
            fscanf (file,"%u\n%s\n%s\n%s\n%s\n%hu\n%s\n%s\n",
                     FrontUserList->ID, FrontUserList->name, FrontUserList->surname, FrontUserList -> city,
                     FrontUserList->street, FrontUserList->house_number, FrontUserList->postal_code,
                     FrontUserList->post_office);

            for (FrontTelList=temp_tel; NULL != FrontTelList ; FrontTelList = FrontTelList -> next )
            {
                if(FrontTelList->ID_tel==data)
                    fscanf(file,"%d\n", FrontTelList->tel_nr);
            }
            for (FrontEmailList=temp_email; NULL != FrontEmailList ; FrontEmailList = FrontEmailList -> next )
            {
                if(FrontEmailList->ID_email==data)
                    fscanf(file,"%s\n", FrontEmailList->em);
            }
        }
    }

    if(fclose(file))
    {
        printf("Blad zamkniecia pliku");
    }
}

