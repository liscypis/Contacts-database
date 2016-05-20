#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "add_removeElements.h"


void remove_list ( struct User_Node ** FrontUserList )
{
    struct User_Node * next = NULL ;
    while ( NULL != * FrontUserList )
    {
        next = (* FrontUserList ) ->next ;
        free (* FrontUserList );
        * FrontUserList = next ;
    }
}

int main()
{
    struct User_Node *FrontUserList=NULL;
    struct telephone_nr *FrontTelList=NULL;
    struct email_node *FrontEmailList=NULL;

    for(;;)
    {
        printf("Baza kontaktow v1.0\n\n");
        puts("#################### MENU #################");
        puts("1.Dodaj osobe");
        puts("2.Usun osobe");
        puts("3.Edytuj osobe");
        puts("4.Wyswietl baze");
        puts("5.Wyswietl kontakt");
        puts("6.ZAPIS DO PLIKU");
        puts("7.WYJSCIE i USUNIECIE LISTY");

        unsigned short int choice,tel,HowManyEmail;
        int i,j;
        scanf("%hu",&choice);
        switch(choice)
        {
        case 1:
            if(FrontUserList==NULL)
                FrontUserList=create_list(FrontUserList);
            else
                FrontUserList=InsertUser(FrontUserList);

            printf("Ile numerow telefonow chcesz podac?:\n");
            scanf("%hu",&tel);
            for(i=0; i<tel; i++)
            {
                if(FrontTelList==NULL)
                    FrontTelList=CreatePhoneList(FrontTelList);
                else
                    FrontTelList=InsertTelNum(FrontTelList);
            }
            printf("Ile adresow emial chcesz podac?:\n");
            scanf("%hu",&HowManyEmail);
            for(j=0; j<HowManyEmail; j++)
            {
                if(FrontEmailList==NULL)
                    FrontEmailList=CreateEmalList(FrontEmailList);
                else
                    FrontEmailList=InsertEmail(FrontEmailList);
            }
            break;
        case 2:
            printf("Ktora osobe chcesz usunac (Podaj ID):");
            unsigned short int i;
            scanf("%hu",&i);
            FrontUserList=DeleteUserNode(FrontUserList,i);
            FrontEmailList=DeleteEmailNode(FrontEmailList,i);
            FrontTelList=DeleteTelNode(FrontTelList,i);
            break;
        case 3:
            printf("Ktora osobe chcesz edytowac (Podaj ID):");
            unsigned short int j;
            scanf("%hu",&j);
            edit_person(FrontUserList,FrontTelList,FrontEmailList,j);
            break;
        case 4:
            print_list(FrontUserList,FrontTelList,FrontEmailList);

            break;
        case 5:
            printf("Jaki kontakt chcesz wyswietlic(Podaj ID)");
            unsigned short int choice1;
            scanf("%hu",&choice1);
            print_person(FrontUserList,FrontTelList,FrontEmailList,choice1);
            break;
        case 6:
            save(file, FrontUserList,FrontTelList,FrontEmailList);
            break;
        case 7:
             //remove_list(&FrontUserList);
            exit(0);
            break;
        default:
            break;

        }
        getchar();
        getchar();
        system("cls");
    }



    return 0;
}
