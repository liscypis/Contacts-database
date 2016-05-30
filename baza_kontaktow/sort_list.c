#include "baza_kontaktow.h"

/**
    @file sort_list.c
    \brief Przechowuje funkcję do sortowania list
*/

/**
    * \fn void sort_list(struct User_Node *FrontUserList, unsigned int direction,unsigned int what)
    * \brief Procedura sortuje listę User_Node po wybranym polu i po wybranym kierunku
    * \param FrontUserList wskaźnik na początek listy User_Node.
    * \param direction przechowuje wyrób kierunku sortowania 0-rosnąco, 1-malejąco.
    * \param what przechowuje wyrób po którym polu chcemy sortować 0-numer,ID 1-imie,2-nazwisko,3-miasto,4-ulica,5-numer domu,6-kod pocztowy,7-poczta.
*/
void sort_list(struct User_Node *FrontUserList, unsigned int direction,unsigned int what)
{
    unsigned int counter=0,i,j;
    struct User_Node *pom;
    struct User_Node *front_user=FrontUserList;
    struct User_Node *wsk=FrontUserList; //Ustawienie wskaŸnika roboczego na pierwszym elemencie listy
    struct User_Node *temp=NULL, *pomtemp,*front_temp;
    while (wsk != NULL)
    {
        ++counter; // liczymy ile jest elementow w licie
        wsk = wsk->next;
    }
    for(i=0; i<counter; i++)
    {
        FrontUserList=front_user;
        if(temp==NULL)
        {
            temp=(struct User_Node*)malloc(sizeof(struct User_Node));
            front_temp=pomtemp=temp;
            temp->next=NULL;
            if(what==0)temp->ID=FrontUserList->ID;
            if(what==1)strcpy(temp->name, FrontUserList->name);
            if(what==2)strcpy(temp->surname, FrontUserList->surname);
            if(what==3)strcpy(temp->city, FrontUserList->city);
            if(what==4)strcpy(temp->street, FrontUserList->street);
            if(what==5)temp->house_number=FrontUserList->house_number;
            if(what==6)strcpy(temp->postal_code, FrontUserList->postal_code);
            if(what==7)strcpy(temp->post_office, FrontUserList->post_office);
        }
        else
        {
            while (pomtemp->next)
            {
                pomtemp = pomtemp->next;//szukamy ostatniego elementu listy
            }
            temp=(struct User_Node*)malloc(sizeof(struct User_Node));
            pomtemp->next=temp;
            temp->next=NULL;
            if(what==0)temp->ID=FrontUserList->ID;
            if(what==1)strcpy(temp->name, FrontUserList->name);
            if(what==2)strcpy(temp->surname, FrontUserList->surname);
            if(what==3)strcpy(temp->city, FrontUserList->city);
            if(what==4)strcpy(temp->street, FrontUserList->street);
            if(what==5)temp->house_number=FrontUserList->house_number;
            if(what==6)strcpy(temp->postal_code, FrontUserList->postal_code);
            if(what==7)strcpy(temp->post_office, FrontUserList->post_office);
        }
        ///////////////////////
        /// Szukanie minimum///
        ////////// || /////////
        /// Szukanie maximum///
        ///////////////////////

        for(j=0; j<counter; j++)
        {
            if(direction==0)
            {
                if(what==0)
                {
                    if (FrontUserList->ID<=temp->ID)
                    {
                        pom=FrontUserList;
                        temp->ID=FrontUserList->ID;
                        FrontUserList=FrontUserList->next;

                    }
                    else  FrontUserList=FrontUserList->next;
                }
                if(what==1)
                {
                    if (strcmp(FrontUserList->name, temp->name) <= 0)
                    {
                        pom=FrontUserList;
                        strcpy(temp->name, FrontUserList->name);
                        FrontUserList=FrontUserList->next;
                    }
                    else  FrontUserList=FrontUserList->next;
                }
                if(what==2)
                {
                    if (strcmp(FrontUserList->surname, temp->surname) <= 0)
                    {
                        pom=FrontUserList;
                        strcpy(temp->surname, FrontUserList->surname);
                        FrontUserList=FrontUserList->next;
                    }
                    else  FrontUserList=FrontUserList->next;
                }
                if(what==3)
                {
                    if (strcmp(FrontUserList->city, temp->city) <= 0)
                    {
                        pom=FrontUserList;
                        strcpy(temp->city, FrontUserList->city);
                        FrontUserList=FrontUserList->next;

                    }
                    else  FrontUserList=FrontUserList->next;
                }
                if(what==4)
                {
                    if (strcmp(FrontUserList->street, temp->street) <= 0)
                    {
                        pom=FrontUserList;
                        strcpy(temp->street, FrontUserList->street);
                        FrontUserList=FrontUserList->next;

                    }
                    else  FrontUserList=FrontUserList->next;
                }
                if(what==5)
                {
                    if (FrontUserList->house_number<=temp->house_number)
                    {
                        pom=FrontUserList;
                        temp->house_number=FrontUserList->house_number;
                        FrontUserList=FrontUserList->next;
                    }
                    else  FrontUserList=FrontUserList->next;
                }
                if(what==6)
                {
                    if (strcmp(FrontUserList->postal_code, temp->postal_code) <= 0)
                    {
                        pom=FrontUserList;
                        strcpy(temp->postal_code, FrontUserList->postal_code);
                        FrontUserList=FrontUserList->next;
                    }
                    else  FrontUserList=FrontUserList->next;
                }
                if(what==7)
                {
                    if (strcmp(FrontUserList->post_office, temp->post_office) <= 0)
                    {
                        pom=FrontUserList;
                        strcpy(temp->post_office, FrontUserList->post_office);
                        FrontUserList=FrontUserList->next;
                    }
                    else  FrontUserList=FrontUserList->next;
                }

            }
            else if(direction==1)
            {
                if(what==0)
                {
                    if (FrontUserList->ID>=temp->ID)
                    {
                        pom=FrontUserList;
                        temp->ID=FrontUserList->ID;
                        FrontUserList=FrontUserList->next;

                    }
                    else  FrontUserList=FrontUserList->next;
                }
                if(what==1)
                {
                    if (strcmp(FrontUserList->name, temp->name) >= 0)
                    {
                        pom=FrontUserList;
                        strcpy(temp->name, FrontUserList->name);
                        FrontUserList=FrontUserList->next;
                    }
                    else  FrontUserList=FrontUserList->next;
                }
                if(what==2)
                {
                    if (strcmp(FrontUserList->surname, temp->surname) >= 0)
                    {
                        pom=FrontUserList;
                        strcpy(temp->surname, FrontUserList->surname);
                        FrontUserList=FrontUserList->next;
                    }
                    else  FrontUserList=FrontUserList->next;
                }
                if(what==3)
                {
                    if (strcmp(FrontUserList->city, temp->city) >= 0)
                    {
                        pom=FrontUserList;
                        strcpy(temp->city, FrontUserList->city);
                        FrontUserList=FrontUserList->next;
                    }
                    else  FrontUserList=FrontUserList->next;
                }
                if(what==4)
                {
                    if (strcmp(FrontUserList->street, temp->street) >= 0)
                    {
                        pom=FrontUserList;
                        strcpy(temp->street, FrontUserList->street);
                        FrontUserList=FrontUserList->next;
                    }
                    else  FrontUserList=FrontUserList->next;
                }
                if(what==5)
                {
                    if (FrontUserList->house_number>=temp->house_number)
                    {
                        pom=FrontUserList;
                        temp->house_number=FrontUserList->house_number;
                        FrontUserList=FrontUserList->next;
                    }
                    else  FrontUserList=FrontUserList->next;
                }
                if(what==6)
                {
                    if (strcmp(FrontUserList->postal_code, temp->postal_code) >= 0)
                    {
                        pom=FrontUserList;
                        strcpy(temp->postal_code, FrontUserList->postal_code);
                        FrontUserList=FrontUserList->next;
                    }
                    else  FrontUserList=FrontUserList->next;
                }
                if(what==7)
                {
                    if (strcmp(FrontUserList->post_office, temp->post_office) >= 0)
                    {
                        pom=FrontUserList;
                        strcpy(temp->post_office, FrontUserList->post_office);
                        FrontUserList=FrontUserList->next;
                    }
                    else  FrontUserList=FrontUserList->next;
                }
            }
        }
        //zapis do listy temp
        FrontUserList=pom;
        strcpy(temp->name, FrontUserList->name);
        strcpy(temp->surname, FrontUserList->surname);
        strcpy(temp->city, FrontUserList->city);
        strcpy(temp->street, FrontUserList->street);
        temp->house_number=FrontUserList->house_number;
        strcpy(temp->postal_code, FrontUserList->postal_code);
        strcpy(temp->post_office, FrontUserList->post_office);
        temp->ID=FrontUserList->ID;
        if(direction==0)
        {
            FrontUserList->ID=9999;
            strcpy(FrontUserList->name, "xxxxxxxxxxxx" ); //najmniejszy element zostaje zamieniony na najwiekszy
            strcpy(FrontUserList->surname, "xxxxxxxxxxxx" );
            strcpy(FrontUserList->city, "xxxxxxxxxxxx" );
            strcpy(FrontUserList->street, "xxxxxxxxxxxx" );
            FrontUserList->house_number=9999;
            strcpy(FrontUserList->postal_code, "xxxxxxxxxxxx" );
            strcpy(FrontUserList->post_office, "xxxxxxxxxxxx" );
        }
        else
        {
            FrontUserList->ID=-1;
            strcpy(FrontUserList->name, "" ); //najwiekszy element zostaje zamieniony na najmniejszy
            strcpy(FrontUserList->surname, "" );
            strcpy(FrontUserList->city, "" );
            strcpy(FrontUserList->street, "" );
            FrontUserList->house_number=0;
            strcpy(FrontUserList->postal_code, "" );
            strcpy(FrontUserList->post_office, "" );
        }


    }
    temp=front_temp;
    FrontUserList=front_user;
    //skopiowanie posortowanej listy temp do listy User_node
    while(temp!=NULL)
    {
        strcpy(FrontUserList->name, temp->name);
        strcpy(FrontUserList->surname, temp->surname);
        strcpy(FrontUserList->city, temp->city);
        strcpy(FrontUserList->street, temp->street);
        FrontUserList->house_number=temp->house_number;
        strcpy(FrontUserList->postal_code, temp->postal_code);
        strcpy(FrontUserList->post_office, temp->post_office);
        FrontUserList->ID=temp->ID;
        temp=temp->next;
        FrontUserList=FrontUserList->next;
    }
    remove_list(&temp);
}


/**
    * \fn void sort_list_by_tel(struct telephone_nr *FrontTelList, struct User_Node *FrontUserList,unsigned int direction)
    * \brief Procedura sortuje listę telephone_nr po wybranym kierunku i sortuje listę User_Node po odpowiednum ID telefonów
    * \param FrontTelList wskaźnik na początek listy telephone_nr.
    * \param FrontUserList wskaźnik na początek listy User_Node.
    * \param direction przechowuje wyrób kierunku sortowania 0-rosnąco, 1-malejąco.
*/
void sort_list_by_tel(struct telephone_nr *FrontTelList, struct User_Node *FrontUserList,unsigned int direction)
{
    unsigned int counter=0,i,j;
    struct User_Node *front_user=FrontUserList;
    struct User_Node *temp_user=NULL, *pomtemp_user,*front_temp_user;
    //////
    struct telephone_nr *pom;
    struct telephone_nr *front_tel=FrontTelList;
    struct telephone_nr *wsk=FrontTelList; //Ustawienie wskaŸnika roboczego na pierwszym elemencie listy
    struct telephone_nr *temp=NULL, *pomtemp,*front_temp;
    while (wsk != NULL)
    {
        ++counter; // liczymy ile jest elementow w licie
        wsk = wsk->next;
    }
    int tab[counter]; // przechowuje jakie id już wystapily
    for(i=0; i<counter; i++)
    {
        FrontTelList=front_tel;//ustawienie wskaznika na pierwszy element listy
        if(temp==NULL)
        {
            temp=(struct telephone_nr*)malloc(sizeof(struct telephone_nr));
            front_temp=pomtemp=temp;
            temp->next=NULL;
            temp->tel_nr=FrontTelList->tel_nr;
        }
        else
        {
            while (pomtemp->next)
            {
                pomtemp = pomtemp->next;//szukamy ostatniego elementu listy
            }
            temp=(struct telephone_nr*)malloc(sizeof(struct telephone_nr));
            pomtemp->next=temp;
            temp->next=NULL;
            temp->tel_nr=FrontTelList->tel_nr;
        }
        ///////////////////////
        /// Szukanie minimum///
        ////////// || /////////
        /// Szukanie maximum///
        ///////////////////////

        for(j=0; j<counter; j++)
        {
            if(direction==0)
            {
                    if (FrontTelList->tel_nr<=temp->tel_nr)
                    {
                        pom=FrontTelList;
                        temp->tel_nr=FrontTelList->tel_nr;
                        FrontTelList=FrontTelList->next;

                    }
                    else  FrontTelList=FrontTelList->next;
            }
            else if(direction==1)
            {
                    if (FrontTelList->tel_nr>=temp->tel_nr)
                    {
                        pom=FrontTelList;
                        temp->tel_nr=FrontTelList->tel_nr;
                        FrontTelList=FrontTelList->next;

                    }
                    else  FrontTelList=FrontTelList->next;
            }
        }


        //zapis do listy temp
        FrontTelList=pom;
        temp->ID_tel=FrontTelList->ID_tel;
        temp->tel_nr=FrontTelList->tel_nr;
        tab[i]=temp->ID_tel; //zapisanie ID zeby wiedziec jakie juz wysapilo
        //printf("zawartosc tab %d\n ",tab[i]);
        //posortowanie listy user_node po id tel
            int k,bylo=0;
                    for(k=0;k<i;k++)
                    {
                        if(tab[k]==tab[i])
                            bylo=1;
                    }
                   // printf("%d",bylo);
    if(bylo==0)
    {
        for(FrontUserList=front_user; FrontUserList!=NULL; FrontUserList =FrontUserList->next)
        {
            if(FrontUserList->ID==temp->ID_tel)
            {
                if(temp_user==NULL)
                {

                    temp_user=(struct User_Node*)malloc(sizeof(struct User_Node));
                    front_temp_user=pomtemp_user=temp_user;
                    temp_user->next=NULL;
                    temp_user->ID=FrontUserList->ID;
                    strcpy(temp_user->name, FrontUserList->name);
                    strcpy(temp_user->surname, FrontUserList->surname);
                    strcpy(temp_user->city, FrontUserList->city);
                    strcpy(temp_user->street, FrontUserList->street);
                    temp_user->house_number=FrontUserList->house_number;
                    strcpy(temp_user->postal_code, FrontUserList->postal_code);
                    strcpy(temp_user->post_office, FrontUserList->post_office);
                }
                else
                {
                    while (pomtemp_user->next)
                    {
                        pomtemp_user = pomtemp_user->next;//szukamy ostatniego elementu listy
                    }

                    temp_user=(struct User_Node*)malloc(sizeof(struct User_Node));
                    pomtemp_user->next=temp_user;
                    temp_user->next=NULL;
                    temp_user->ID=FrontUserList->ID;
                    strcpy(temp_user->name, FrontUserList->name);
                    strcpy(temp_user->surname, FrontUserList->surname);
                    strcpy(temp_user->city, FrontUserList->city);
                    strcpy(temp_user->street, FrontUserList->street);
                    temp_user->house_number=FrontUserList->house_number;
                    strcpy(temp_user->postal_code, FrontUserList->postal_code);
                    strcpy(temp_user->post_office, FrontUserList->post_office);
                }
            }
        }
    }


        if(direction==0)
        {
            FrontTelList->tel_nr=999999999;
        }
        else
        {
            FrontTelList->tel_nr=0;
        }
}

    temp_user=front_temp_user;
    FrontUserList=front_user;
    //skopiowanie posortowanej listy temp_user do listy User_node
    while(temp_user!=NULL)
    {
        strcpy(FrontUserList->name, temp_user->name);
        strcpy(FrontUserList->surname, temp_user->surname);
        strcpy(FrontUserList->city, temp_user->city);
        strcpy(FrontUserList->street, temp_user->street);
        FrontUserList->house_number=temp_user->house_number;
        strcpy(FrontUserList->postal_code, temp_user->postal_code);
        strcpy(FrontUserList->post_office, temp_user->post_office);
        FrontUserList->ID=temp_user->ID;
        temp_user=temp_user->next;
        FrontUserList=FrontUserList->next;
    }
    remove_list(&temp_user);

    temp=front_temp;
    FrontTelList=front_tel;
    //skopiowanie posortowanej listy temp do listy User_node
    while(temp!=NULL)
    {

        FrontTelList->ID_tel=temp->ID_tel;
        FrontTelList->tel_nr=temp->tel_nr;
        temp=temp->next;
        FrontTelList=FrontTelList->next;
    }
    remove_tel_list(&temp);
}

// sortowanie po emailu
/**
    * \fn void sort_list_by_email(struct email_node *FrontEmailList, struct User_Node *FrontUserList,unsigned int direction)
    * \brief Procedura sortuje listę email_node po wybranym kierunku i sortuje listę User_Node po odpowiednum ID emaili
    * \param FrontEmailList wskaźnik na początek listy email_node.
    * \param FrontUserList wskaźnik na początek listy User_Node.
    * \param direction przechowuje wyrób kierunku sortowania 0-rosnąco, 1-malejąco.
*/
void sort_list_by_email(struct email_node *FrontEmailList, struct User_Node *FrontUserList,unsigned int direction)
{
    unsigned int counter=0,i,j;
    struct User_Node *front_user=FrontUserList;
    struct User_Node *temp_user=NULL, *pomtemp_user,*front_temp_user;
    //////
    struct email_node *pom;
    struct email_node *front_em=FrontEmailList;
    struct email_node *wsk=FrontEmailList; //Ustawienie wskaŸnika roboczego na pierwszym elemencie listy
    struct email_node *temp=NULL, *pomtemp,*front_temp;
    while (wsk != NULL)
    {
        ++counter; // liczymy ile jest elementow w licie
        wsk = wsk->next;
    }
    int tab[counter]; // przechowuje jakie id już wystapily
    for(i=0; i<counter; i++)
    {
        FrontEmailList=front_em;//ustawienie wskaznika na pierwszy element listy
        if(temp==NULL)
        {
            temp=(struct email_node*)malloc(sizeof(struct email_node));
            front_temp=pomtemp=temp;
            temp->next=NULL;
            strcpy(temp->em,FrontEmailList->em);
        }
        else
        {
            while (pomtemp->next)
            {
                pomtemp = pomtemp->next;//szukamy ostatniego elementu listy
            }
            temp=(struct email_node*)malloc(sizeof(struct email_node));
            pomtemp->next=temp;
            temp->next=NULL;
            strcpy(temp->em,FrontEmailList->em);
        }
        ///////////////////////
        /// Szukanie minimum///
        ////////// || /////////
        /// Szukanie maximum///
        ///////////////////////

        for(j=0; j<counter; j++)
        {
            if(direction==0)
            {
                    if ((strcmp(FrontEmailList->em, temp->em) <= 0 ))
                    {
                        pom=FrontEmailList;
                        strcpy(temp->em,FrontEmailList->em);
                        FrontEmailList=FrontEmailList->next;

                    }
                    else  FrontEmailList=FrontEmailList->next;
            }
            else if(direction==1)
            {
                    if ((strcmp(FrontEmailList->em, temp->em) >= 0))
                    {
                        pom=FrontEmailList;
                        strcpy(temp->em,FrontEmailList->em);
                        FrontEmailList=FrontEmailList->next;

                    }
                    else  FrontEmailList=FrontEmailList->next;
            }
        }


        //zapis do listy temp
        FrontEmailList=pom;
        temp->ID_email=FrontEmailList->ID_email;
        strcpy(temp->em,FrontEmailList->em);
        tab[i]=temp->ID_email;
        //printf("zawartosc tab %d\n ",tab[i]);
        //posortowanie listy user_node po id tel
            int k,bylo=0;
                    for(k=0;k<i;k++)
                    {
                        if(tab[k]==tab[i])
                            bylo=1;
                    }
                   // printf("%d",bylo);
    if(bylo==0)
    {
        for(FrontUserList=front_user; FrontUserList!=NULL; FrontUserList =FrontUserList->next)
        {
            if(FrontUserList->ID==temp->ID_email)
            {
                if(temp_user==NULL)
                {

                    temp_user=(struct User_Node*)malloc(sizeof(struct User_Node));
                    front_temp_user=pomtemp_user=temp_user;
                    temp_user->next=NULL;
                    temp_user->ID=FrontUserList->ID;
                    strcpy(temp_user->name, FrontUserList->name);
                    strcpy(temp_user->surname, FrontUserList->surname);
                    strcpy(temp_user->city, FrontUserList->city);
                    strcpy(temp_user->street, FrontUserList->street);
                    temp_user->house_number=FrontUserList->house_number;
                    strcpy(temp_user->postal_code, FrontUserList->postal_code);
                    strcpy(temp_user->post_office, FrontUserList->post_office);
                }
                else
                {
                    while (pomtemp_user->next)
                    {
                        pomtemp_user = pomtemp_user->next;//szukamy ostatniego elementu listy
                    }

                    temp_user=(struct User_Node*)malloc(sizeof(struct User_Node));
                    pomtemp_user->next=temp_user;
                    temp_user->next=NULL;
                    temp_user->ID=FrontUserList->ID;
                    strcpy(temp_user->name, FrontUserList->name);
                    strcpy(temp_user->surname, FrontUserList->surname);
                    strcpy(temp_user->city, FrontUserList->city);
                    strcpy(temp_user->street, FrontUserList->street);
                    temp_user->house_number=FrontUserList->house_number;
                    strcpy(temp_user->postal_code, FrontUserList->postal_code);
                    strcpy(temp_user->post_office, FrontUserList->post_office);
                }
            }
        }
    }


        if(direction==0)
        {
             strcpy(FrontEmailList->em, "xxxxxxxxxxxx");
        }
        else if (direction==1)
        {
            strcpy(FrontEmailList->em, "");
        }
}

    temp_user=front_temp_user;
    FrontUserList=front_user;
    //skopiowanie posortowanej listy temp_user do listy User_node
    while(temp_user!=NULL)
    {
        strcpy(FrontUserList->name, temp_user->name);
        strcpy(FrontUserList->surname, temp_user->surname);
        strcpy(FrontUserList->city, temp_user->city);
        strcpy(FrontUserList->street, temp_user->street);
        FrontUserList->house_number=temp_user->house_number;
        strcpy(FrontUserList->postal_code, temp_user->postal_code);
        strcpy(FrontUserList->post_office, temp_user->post_office);
        FrontUserList->ID=temp_user->ID;
        temp_user=temp_user->next;
        FrontUserList=FrontUserList->next;
    }
    remove_list(&temp_user);

    temp=front_temp;
    FrontEmailList=front_em;
    //skopiowanie posortowanej listy temp do listy User_node
    while(temp!=NULL)
    {
        FrontEmailList->ID_email=temp->ID_email;
        strcpy(FrontEmailList->em, temp->em);
        temp=temp->next;
        FrontEmailList=FrontEmailList->next;
    }
    remove_email_list(&temp);
}




