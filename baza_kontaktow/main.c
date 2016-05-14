#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int i;
//Typ bazowy i wskaŸnik listy
struct sll_node
{
    int data;
    int ID;
    char name[20];
    char surname[40];
    char city[40];
    char street[40];
    unsigned short int house_number;
    char postal_code[7];
    char post_office[30];
    struct sll_node *next;
};
struct telephone_nr
{
    unsigned int tel_nr;
    struct telephone_nr *next;
};
struct email
{
    unsigned int emial;
    struct emial *next3;
};
struct telephone_nr * CreatePhoneList(struct telephone_nr *front2)
{
    struct telephone_nr *new_node2 = (struct telephone_nr *)malloc (sizeof (struct telephone_nr));


    if (NULL != new_node2)
    {
        scanf("%u",&new_node2->tel_nr);
        new_node2 ->next=NULL;
    }


    return new_node2;
}

struct telephone_nr * InsertTelNum(struct telephone_nr *front2)
{
    struct telephone_nr *new_node2 = (struct telephone_nr *)malloc (sizeof (struct telephone_nr));


    if (NULL != new_node2)
    {

        scanf("%u",&new_node2->tel_nr);
        new_node2 ->next=NULL;
    }
    front2->next=new_node2;
    return front2;
}

struct sll_node *create_list(struct sll_node *front)
{
    struct sll_node *new_node = (struct sll_node *)malloc (sizeof (struct sll_node));
    if (NULL != new_node)
    {
        new_node->ID = i;

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
        front=new_node;

    }
    return front;
}


struct sll_node * find_spot ( struct sll_node *front)
{
    struct sll_node * prev = NULL ;
    while (( NULL != front ))
    {
        prev = front ;
        front = front -> next ;
    }
    return prev ;
}

void insert_after ( struct sll_node *node , struct sll_node * new_node )
{
    new_node -> next = node -> next ;
    node -> next = new_node ;
}

void insert_back ( struct sll_node *back , struct sll_node * new_node )
{
    back -> next = new_node ;
}

struct sll_node * insert_node ( struct sll_node *front  )
{
    if ( NULL == front )
        return NULL;

    struct sll_node * new_node = ( struct sll_node *)malloc ( sizeof ( struct sll_node ));
    if ( NULL != new_node )
    {
        new_node->ID = ++i;

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

        struct sll_node * node = find_spot (front);
        insert_back (node , new_node );

    }
    return front;
}

struct sll_node * delete_front ( struct sll_node * front )
{
    struct sll_node * next = front -> next ;
    free ( front );
    return next ;
}

struct sll_node * find_prev_node ( struct sll_node *front , int data )
{
    struct sll_node * prev = NULL ;
    while (( NULL != front ) && (front -> ID != data ))
    {
        prev = front ;
        front = front -> next ;
    }
    return prev ;
}
void delete_after ( struct sll_node * node )
{
    struct sll_node * next = node -> next ;
    if ( NULL != next )
    {
        node -> next = next -> next ;
        free ( next );
    }

}

struct sll_node * delete_node ( struct sll_node *front , int data )
{
    if ( NULL == front )
        return NULL ;

    if (front -> ID == data )
        return delete_front ( front );

    struct sll_node * prev = find_prev_node (front , data );
    delete_after ( prev );
    return front ;
}
void print_list2 ( struct telephone_nr * front2 )
{
    for (; NULL != front2 ; front2 = front2 -> next )
        printf ("%d ",front2->tel_nr);
}
void print_list ( struct sll_node * front )
{
    for (; NULL != front ; front = front -> next )
        printf ("%d %4s ",front->ID, front->name);
    /* printf ("%d %4s %4s %4s %4s %4hu %4s %4s %4u %4s",
             front->ID, front->name, front->surname, front -> city,
             front->street, front->house_number, front->postal_code,
             front->post_office, front->telephone_nr, front->email);*/

}
void print_person ( struct sll_node * front, int data )
{
    for (; NULL != front ; front = front -> next )
    {
        if(front->ID==data)
            printf ("%d %4s ",front->ID, front->name);

    }
}
void edit_person ( struct sll_node * front, unsigned short int data )
{
    unsigned short int choice;
    for (; NULL != front ; front = front -> next )
    {
        if(front->ID==data)
        {
            puts("Jakie pole chcesz edytowac?");
            while(choice!=10)
            {
                puts("############ EDYCJA KONTAKTU ##############");
                puts("1.Imie");
                puts("2.Nazwisko");
                puts("3.Miasto");
                puts("4.Ulica");
                puts("5.Numer domu");
                puts("6.Kod pocztowy");
                puts("7.Poczta");
                puts("8.Telefon");
                puts("9.Email");
                puts("10.Koniec edycji");

                scanf("%hu",&choice);
                switch(choice)
                {
                case 1:
                    scanf("%s",front->name);
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
                    exit(0);
                    break;
                case 7:

                    break;
                case 8:

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

void remove_list ( struct sll_node ** front )
{
    struct sll_node * next = NULL ;
    while ( NULL != * front )
    {
        next = (* front ) ->next ;
        free (* front );
        * front = next ;
    }
}

int main()
{
    struct sll_node *front=NULL;
    struct telephone_nr *front2=NULL;
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

        unsigned short int choice,tel;
        scanf("%hu",&choice);
        switch(choice)
        {
        case 1:
            if(front==NULL)
                front=create_list(front);
            else
                front=insert_node(front);

            printf("Ile numerow telefonow chcesz podac?:\n");
            scanf("%hu",&tel);
            for(i=0; i<tel; i++)
            {
                if(front2==NULL)
                    front2=CreatePhoneList(front2);
                else
                    front2=InsertTelNum(front2);

                }
            break;
        case 2:
            printf("Ktora osobe chcesz usunac (Podaj ID):");
            unsigned short int i;
            scanf("%hu",&i);
            front=delete_node(front,i);
            break;
        case 3:
            printf("Ktora osobe chcesz edytowac (Podaj ID):");
            unsigned short int j;
            scanf("%hu",&j);
            edit_person(front,j);
            break;
        case 4:
            print_list2(front2);
            break;
        case 5:
            printf("Jaki kontakt chcesz wyswietlic(Podaj ID)");
            unsigned short int choice1;
            scanf("%hu",&choice1);
            print_person(front,choice1);
            break;
        case 6:
            remove_list(&front);
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
