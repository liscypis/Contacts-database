#include<stdio.h>
#include<stdlib.h>
#include<string.h>

unsigned int NumID; //deklaracja zmiennej ID

struct User_Node
{
    unsigned int ID;
    char name[20];
    char surname[40];
    char city[40];
    char street[40];
    unsigned short int house_number;
    char postal_code[7];
    char post_office[30];
    struct User_Node *next;
};
struct telephone_nr
{
    unsigned int ID_tel;
    unsigned int tel_nr;
    struct telephone_nr *next;
};

struct email_node
{
    unsigned int ID_email;
    char em[40];
    struct email_node *next;
};


struct telephone_nr * CreatePhoneList(struct telephone_nr *FrontTelList)
{
    struct telephone_nr *new_node = (struct telephone_nr *)malloc (sizeof (struct telephone_nr));
    if (NULL != new_node)
    {
        new_node->ID_tel=NumID;
        scanf("%u",&new_node->tel_nr);
        new_node ->next=NULL;
    }
    FrontTelList=new_node;
    return FrontTelList;
}

struct telephone_nr * InsertTelNum(struct telephone_nr *FrontTelList)
{
    struct telephone_nr *new_node = (struct telephone_nr *)malloc (sizeof (struct telephone_nr));
    struct telephone_nr *wsk=FrontTelList; //Ustawienie wskaŸnika roboczego na pierwszym elemencie listy

    while (wsk->next != NULL)
    {
        wsk = wsk->next; // przesuwamy wsk a¿ znajdziemy ostatni element
    }
    if (NULL != new_node)
    {
        wsk->next = new_node;  // w pole next ostatniego elementu listy wpisaæ adres nowo przydzielonego obszaru
        new_node->ID_tel=NumID;
        scanf("%u",&new_node->tel_nr);// przypisanie wartosci
        new_node->next=NULL; //przypisanie wartosci NULL dla ostatniego elementu listy
    }
    return FrontTelList;
}


struct email_node * CreateEmalList(struct email_node *FrontEmailList)
{
    struct email_node *new_node = (struct email_node *)malloc (sizeof (struct email_node));
    if (NULL != new_node)
    {
        new_node->ID_email=NumID;
        scanf("%s",new_node->em);
        new_node ->next=NULL;
    }
    FrontEmailList=new_node;
    return FrontEmailList;
}

struct email_node * InsertEmail(struct email_node *FrontEmailList)
{
    struct email_node *new_node = (struct email_node *)malloc (sizeof (struct email_node));
    struct email_node *wsk;
    wsk=FrontEmailList; //Ustawienie wskaŸnika roboczego na pierwszym elemencie listy

    while (wsk->next != NULL)
    {
        wsk = wsk->next; // przesuwamy wsk a¿ znajdziemy ostatni element
    }
    if (NULL != new_node)
    {
        wsk->next = new_node;  // w pole next ostatniego elementu listy wpisaæ adres nowo przydzielonego obszaru
        new_node->ID_email=NumID;
        scanf("%s",new_node->em);// przypisanie wartosci
        new_node->next=NULL; //przypisanie wartosci NULL dla ostatniego elementu listy
    }
    return FrontEmailList;
}

struct User_Node *create_list(struct User_Node *FrontUserList)
{
    struct User_Node *new_node = (struct User_Node *)malloc (sizeof (struct User_Node));
    if (NULL != new_node)
    {
        new_node->ID = NumID;

        printf("\nPodaj imie: \n");
        scanf("%s",new_node->name);

        /*   printf("Podaj nazwisko: \n");
           scanf("%s",nowy->surname);

           printf("Podaj miasto:\n");
           scanf("%s",nowy->city);

           printf("Podaj ulice:\n");
           scanf("%s",nowy->street);

           printf("Podaj numer domu: \n");
           scanf("%hu",&nowy->house_number);

           printf("Podaj kod pocztowy:\n");
           scanf("%s",nowy->postal_code);

           printf("Podaj poczte:\n");
           scanf("%s",nowy->post_office);

           printf("Podaj email:\n");
           scanf("%s",nowy->email);*/

        new_node -> next = NULL ;
        FrontUserList=new_node;

    }
    return FrontUserList;
}

struct User_Node * InsertUser ( struct User_Node *FrontUserList  )
{
    struct User_Node * new_node = ( struct User_Node *)malloc ( sizeof ( struct User_Node ));
    struct User_Node *wsk=FrontUserList; //Ustawienie wskaŸnika roboczego na pierwszym elemencie listy
    while (wsk->next != NULL)
    {
        wsk = wsk->next; // przesuwamy wsk a¿ znajdziemy ostatni element
    }
    if ( NULL != new_node )
    {
        wsk->next = new_node; // w pole next ostatniego elementu listy wpisaæ adres nowo przydzielonego obszaru
        new_node->ID = ++NumID;

        printf("\nPodaj imiea: \n");
        scanf("%s",new_node->name);

        /* printf("Podaj nazwisko: \n");
         scanf("%s",new_node->surname);

         printf("Podaj miasto:\n");
         scanf("%s",new_node->city);

         printf("Podaj ulice:\n");
         scanf("%s",new_node->street);

         printf("Podaj numer domu: \n");
         scanf("%hu",&new_node->house_number);

         printf("Podaj kod pocztowy:\n");
         scanf("%s",new_node->postal_code);

         printf("Podaj poczte:\n");
         scanf("%s",new_node->post_office);

         printf("Podaj numer telefonu:\n");
         scanf("%u",&new_node->telephone_nr);

         printf("Podaj email:\n");
         scanf("%s",new_node->email);*/

        new_node -> next = NULL ;
    }
    return FrontUserList;
}
struct User_Node * DeleteUserNode ( struct User_Node *FrontUserList , int data )
{
    if ( NULL == FrontUserList )
        return NULL ;
    struct User_Node * prev = FrontUserList; //zapiosanie we wskaŸniku lokalnymnext adresu pierwszego elementu listy
    struct User_Node * temp = FrontUserList; //zapiosanie we wskaŸniku lokalnymnext adresu pierwszego elementu listy

    while(temp!=NULL)
    {
        if(temp-> ID == data)
            //usuwamy pierwszy element listy
            if(temp==FrontUserList)
            {
                FrontUserList=FrontUserList->next; // zapisane adredu nastepnego elementu (drugiego)
                free(temp);
                temp = FrontUserList;
                prev = FrontUserList;
            }
        //usuwamy element ze srodka listy lub konca
            else
            {
                prev -> next = temp -> next; //wskaznikowi poprzedniego elementu przypisujemy adres nastepnego
                free(temp); //
                temp = prev->next; //przechodzi do nastepnego elementu listy
            }
        else
        {
            prev = temp; // przechowuje wartosc temp, czyli poprzednia
            temp = temp -> next; // przechodzi do nastepnego elementu
        }

    }
    return FrontUserList;
}
struct email_node * DeleteEmailNode ( struct email_node *FrontEmailList , int data )
{
    if ( NULL == FrontEmailList )
        return NULL ;
    struct email_node * prev = FrontEmailList; //zapiosanie we wskaŸniku lokalnymnext adresu pierwszego elementu listy
    struct email_node * temp = FrontEmailList; //zapiosanie we wskaŸniku lokalnymnext adresu pierwszego elementu listy

    while(temp!=NULL)
    {
        if(temp-> ID_email == data)
            //usuwamy pierwszy element listy
            if(temp==FrontEmailList)
            {
                FrontEmailList=FrontEmailList->next; // zapisane adredu nastepnego elementu (drugiego)
                free(temp);
                temp = FrontEmailList;
                prev = FrontEmailList;
            }
        //usuwamy element ze srodka listy lub konca
            else
            {
                prev -> next = temp -> next; //wskaznikowi poprzedniego elementu przypisujemy adres nastepnego
                free(temp); //
                temp = prev->next; //przechodzi do nastepnego elementu listy
            }
        else
        {
            prev = temp; // przechowuje wartosc temp, czyli poprzednia
            temp = temp -> next; // przechodzi do nastepnego elementu
        }

    }
    return FrontEmailList;
}
struct telephone_nr * DeleteTelNode ( struct telephone_nr *FrontTelList , int data )
{
    if ( NULL == FrontTelList )
        return NULL ;
    struct telephone_nr * prev = FrontTelList; //zapiosanie we wskaŸniku lokalnymnext adresu pierwszego elementu listy
    struct telephone_nr * temp = FrontTelList; //zapiosanie we wskaŸniku lokalnymnext adresu pierwszego elementu listy

    while(temp!=NULL)
    {
        if(temp-> ID_tel == data)
            //usuwamy pierwszy element listy
            if(temp==FrontTelList)
            {
                FrontTelList=FrontTelList->next; // zapisane adredu nastepnego elementu (drugiego)
                free(temp);
                temp = FrontTelList;
                prev = FrontTelList;
            }
        //usuwamy element ze srodka listy lub konca
            else
            {
                prev -> next = temp -> next; //wskaznikowi poprzedniego elementu przypisujemy adres nastepnego
                free(temp); //
                temp = prev->next; //przechodzi do nastepnego elementu listy
            }
        else
        {
            prev = temp; // przechowuje wartosc temp, czyli poprzednia
            temp = temp -> next; // przechodzi do nastepnego elementu
        }

    }
    return FrontTelList;
}
void print_list2(struct telephone_nr * FrontTelList)
{
    for (; NULL != FrontTelList ; FrontTelList = FrontTelList -> next )
        printf ("ID [%d] %d",FrontTelList->ID_tel,FrontTelList->tel_nr);
}
void print_list(struct User_Node * FrontUserList, struct telephone_nr * FrontTelList, struct email_node *FrontEmailList)
{
    int data;
    for (; NULL != FrontUserList ; FrontUserList = FrontUserList -> next )
    {
        printf ("ID[%d] \nImie:%s",FrontUserList->ID, FrontUserList->name);
        data=FrontUserList->ID;
        for (; NULL != FrontTelList ; FrontTelList = FrontTelList -> next )
        {
            if(FrontTelList->ID_tel==data)
            {
                printf ("\nNumer telefonu:%d", FrontTelList->tel_nr);
                break;
            }
        }
        for (; NULL != FrontEmailList ; FrontEmailList = FrontEmailList -> next )
        {
            if(FrontEmailList->ID_email==data)
            {
                printf ("\nAdres email:%s \n\n", FrontEmailList->em);
                break;
            }

        }

        /* printf ("%d %4s %4s %4s %4s %4hu %4s %4s %4u %4s",
                 FrontUserList->ID, FrontUserList->name, FrontUserList->surname, FrontUserList -> city,
                 FrontUserList->street, FrontUserList->house_number, FrontUserList->postal_code,
                 FrontUserList->post_office, FrontUserList->telephone_nr, FrontUserList->email);*/
    }

}
void print_person(struct User_Node * FrontUserList, struct telephone_nr * FrontTelList, struct email_node *FrontEmailList, int data)
{
    for (; NULL != FrontUserList ; FrontUserList = FrontUserList -> next )
    {
        if(FrontUserList->ID==data)
            printf ("\n\nID[%d]\nImie:%s\n",FrontUserList->ID, FrontUserList->name);
    }
    puts("\nNumery telefonow:");
    for (; NULL != FrontTelList ; FrontTelList = FrontTelList -> next )
    {
        if(FrontTelList->ID_tel==data)
            printf ("%d \n", FrontTelList->tel_nr);
    }
    puts("\nAdresy email:");
    for (; NULL != FrontEmailList ; FrontEmailList = FrontEmailList -> next )
    {
        if(FrontEmailList->ID_email==data)
            printf ("%s \n", FrontEmailList->em);
    }
}
void edit_person (struct User_Node * FrontUserList, struct telephone_nr * FrontTelList, struct email_node *FrontEmailList, unsigned short int data )
{
    unsigned short int choice;
    unsigned int tel_num;
    struct telephone_nr * temp_tel = FrontTelList; ////zapiosanie we wskaŸniku lokalnym temp_tel adresu pierwszego elementu listy
  // struct email_node * temp_email = FrontEmailList;
    for (; NULL != FrontUserList; FrontUserList = FrontUserList -> next)
    {
        if(FrontUserList->ID==data)
        {

            while(choice!=10)
            {
                system("cls");
                printf("############ EDYCJA KONTAKTU ##############");
                print_person(FrontUserList,temp_tel,FrontEmailList,data);
                puts("\n");
                puts("Co chcesz zmienic?");
                puts("1.Imie");
                /*puts("2.Nazwisko");
                puts("3.Miasto");
                puts("4.Ulica");
                puts("5.Numer domu");
                puts("6.Kod pocztowy");
                puts("7.Poczta"); */
                puts("8.Telefon");
                puts("9.Email");
                puts("10.Koniec edycji");

                scanf("%hu",&choice);
                switch(choice)
                {
                case 1:
                    puts("Podaj nowe imie:");
                    scanf("%s",FrontUserList->name);
                    break;
                case 2:

                    break;
                case 3:
                    break;
                case 4:

                    break;
                case 5:

                    break;
                case 6:

                    break;
                case 7:

                    break;
                case 8:
                    FrontTelList=temp_tel; //ustawienie FrontTelList na pierwszy element listy
                    puts("Ktory numer chcesz edytowac (podaj caly numer telefonu)");
                    scanf("%u",&tel_num);
                    puts("Podaj nowy numer:");
                    for (; NULL != FrontTelList ; FrontTelList = FrontTelList -> next )
                    {
                        if(FrontTelList->ID_tel==data && FrontTelList->tel_nr==tel_num)
                        {
                            scanf("%u",&FrontTelList->tel_nr);
                            break;
                        }
                    }
                    break;
                case 9:

                    break;
                case 10:
                    printf("Koniec edycji");
                    break;
                default:
                    puts("Nie ma takiej opcji");
                    break;

                }
                getchar();
                getchar();
                system("cls");

            }
        }
    }
}

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
        puts("6.WYJSCIE i USUNIECIE LISTY");

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
