#include "add_removeElements.h"

void sort_list_by_name(struct User_Node *FrontUserList, unsigned int direction)
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
            strcpy(temp->name, FrontUserList->name);
        }
        else
        {
            while (pomtemp->next)
            {
                pomtemp = pomtemp->next;
            }
            temp=(struct User_Node*)malloc(sizeof(struct User_Node));
            pomtemp->next=temp;
            temp->next=NULL;
            strcpy(temp->name, FrontUserList->name);
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
                if (strcmp(FrontUserList->name, temp->name) <= 0)
                {
                    pom=FrontUserList;
                    strcpy(temp->name, FrontUserList->name);
                    FrontUserList=FrontUserList->next;
                    printf("%s\n",temp->name);

                }
                else  FrontUserList=FrontUserList->next;
            }
            else
            {
                if (strcmp(FrontUserList->name, temp->name) >= 0)
                {
                    pom=FrontUserList;
                    strcpy(temp->name, FrontUserList->name);
                    FrontUserList=FrontUserList->next;
                    printf("%s\n",temp->name);

                }
                else  FrontUserList=FrontUserList->next;
            }
        }
        //zapis do listy temp
        FrontUserList=pom;
        strcpy(temp->surname, FrontUserList->surname);
        strcpy(temp->city, FrontUserList->city);
        strcpy(temp->street, FrontUserList->street);
        temp->house_number=FrontUserList->house_number;
        strcpy(temp->postal_code, FrontUserList->postal_code);
        strcpy(temp->post_office, FrontUserList->post_office);
        temp->ID=FrontUserList->ID;
        if(direction==0)
            strcpy(FrontUserList->name, "XXXXXXXXXXXX" ); //najmniejszy element zostaje zamieniony na najwiekszy
        else
            strcpy(FrontUserList->name, "A" ); //najwiekszy element zostaje zamieniony na najmniejszy

    }
    temp=front_temp;
    FrontUserList=front_user;
    //skopiowanie posortowanej listy temp do listy FrontUserList
    while(temp!=NULL)
    {
        printf("\n%s",temp->surname);
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
////////////////////////////////////////////////////
/////////// SORTIWANIE PO NAZWISKU /////////////////
////////////////////////////////////////////////////
void sort_list_by_surname(struct User_Node *FrontUserList, unsigned int direction)
{
    unsigned int counter=0,i,j;
    struct User_Node *pom;
    struct User_Node *front_user=FrontUserList;//Ustawienie wskaŸnika roboczego na pierwszym elemencie listy
    struct User_Node *wsk=FrontUserList;
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
            strcpy(temp->surname, FrontUserList->surname);
        }
        else
        {
            while (pomtemp->next)
            {
                pomtemp = pomtemp->next;
            }
            temp=(struct User_Node*)malloc(sizeof(struct User_Node));
            pomtemp->next=temp;
            temp->next=NULL;
            strcpy(temp->surname, FrontUserList->surname);
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
                if (strcmp(FrontUserList->surname, temp->surname) <= 0)
                {
                    pom=FrontUserList;
                    strcpy(temp->surname, FrontUserList->surname);
                    FrontUserList=FrontUserList->next;
                    printf("%s\n",temp->surname);

                }
                else  FrontUserList=FrontUserList->next;
            }
            else
            {
                if (strcmp(FrontUserList->surname, temp->surname) >= 0)
                {
                    pom=FrontUserList;
                    strcpy(temp->surname, FrontUserList->surname);
                    FrontUserList=FrontUserList->next;
                    printf("%s\n",temp->surname);

                }
                else  FrontUserList=FrontUserList->next;
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
            strcpy(FrontUserList->surname, "XXXXXXXXXXXX" ); //najmniejszy element zostaje zamieniony na najwiekszy
        else
            strcpy(FrontUserList->surname, "A" ); //najwiekszy element zostaje zamieniony na najmniejszy

    }
    temp=front_temp;
    FrontUserList=front_user;
    //skopiowanie posortowanej listy temp do listy FrontUserList
    while(temp!=NULL)
    {
        printf("\n%s",temp->surname);
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
////////////////////////////////////////////////////
/////////// SORTIWANIE PO MIESCIE /////////////////
////////////////////////////////////////////////////
void sort_list_by_city(struct User_Node *FrontUserList, unsigned int direction)
{
    unsigned int counter=0,i,j;
    struct User_Node *pom;
    struct User_Node *front_user=FrontUserList;//Ustawienie wskaŸnika roboczego na pierwszym elemencie listy
    struct User_Node *wsk=FrontUserList;
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
            strcpy(temp->city, FrontUserList->city);
        }
        else
        {
            while (pomtemp->next)
            {
                pomtemp = pomtemp->next;
            }
            temp=(struct User_Node*)malloc(sizeof(struct User_Node));
            pomtemp->next=temp;
            temp->next=NULL;
            strcpy(temp->city, FrontUserList->city);
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
                if (strcmp(FrontUserList->city, temp->city) <= 0)
                {
                    pom=FrontUserList;
                    strcpy(temp->city, FrontUserList->city);
                    FrontUserList=FrontUserList->next;
                    printf("%s\n",temp->city);

                }
                else  FrontUserList=FrontUserList->next;
            }
            else
            {
                if (strcmp(FrontUserList->city, temp->city) >= 0)
                {
                    pom=FrontUserList;
                    strcpy(temp->city, FrontUserList->city);
                    FrontUserList=FrontUserList->next;
                    printf("%s\n",temp->city);

                }
                else  FrontUserList=FrontUserList->next;
            }
        }
        //zapis do listy temp
        FrontUserList=pom;
        strcpy(temp->name, FrontUserList->name);
        strcpy(temp->surname, FrontUserList->surname);
        strcpy(temp->street, FrontUserList->street);
        temp->house_number=FrontUserList->house_number;
        strcpy(temp->postal_code, FrontUserList->postal_code);
        strcpy(temp->post_office, FrontUserList->post_office);
        temp->ID=FrontUserList->ID;
        if(direction==0)
            strcpy(FrontUserList->city, "XXXXXXXXXXXX" ); //najmniejszy element zostaje zamieniony na najwiekszy
        else
            strcpy(FrontUserList->city, "A" ); //najwiekszy element zostaje zamieniony na najmniejszy

    }
    temp=front_temp;
    FrontUserList=front_user;
    //skopiowanie posortowanej listy temp do listy FrontUserList
    while(temp!=NULL)
    {
        printf("\n%s",temp->surname);
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
////////////////////////////////////////////////////
///////////// SORTIWANIE PO ULICY /////////////////
////////////////////////////////////////////////////
void sort_list_by_street(struct User_Node *FrontUserList, unsigned int direction)
{
    unsigned int counter=0,i,j;
    struct User_Node *pom;
    struct User_Node *front_user=FrontUserList;//Ustawienie wskaŸnika roboczego na pierwszym elemencie listy
    struct User_Node *wsk=FrontUserList;
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
            strcpy(temp->street, FrontUserList->street);
        }
        else
        {
            while (pomtemp->next)
            {
                pomtemp = pomtemp->next;
            }
            temp=(struct User_Node*)malloc(sizeof(struct User_Node));
            pomtemp->next=temp;
            temp->next=NULL;
            strcpy(temp->street, FrontUserList->street);
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
                if (strcmp(FrontUserList->street, temp->street) <= 0)
                {
                    pom=FrontUserList;
                    strcpy(temp->street, FrontUserList->street);
                    FrontUserList=FrontUserList->next;
                    printf("%s\n",temp->street);

                }
                else  FrontUserList=FrontUserList->next;
            }
            else
            {
                if (strcmp(FrontUserList->street, temp->street) >= 0)
                {
                    pom=FrontUserList;
                    strcpy(temp->street, FrontUserList->street);
                    FrontUserList=FrontUserList->next;
                    printf("%s\n",temp->street);

                }
                else  FrontUserList=FrontUserList->next;
            }
        }
        //zapis do listy temp
        FrontUserList=pom;
        strcpy(temp->name, FrontUserList->name);
        strcpy(temp->surname, FrontUserList->surname);
        strcpy(temp->city, FrontUserList->city);
        temp->house_number=FrontUserList->house_number;
        strcpy(temp->postal_code, FrontUserList->postal_code);
        strcpy(temp->post_office, FrontUserList->post_office);
        temp->ID=FrontUserList->ID;
        if(direction==0)
            strcpy(FrontUserList->street, "XXXXXXXXXXXX" ); //najmniejszy element zostaje zamieniony na najwiekszy
        else
            strcpy(FrontUserList->street, "A" ); //najwiekszy element zostaje zamieniony na najmniejszy

    }
    temp=front_temp;
    FrontUserList=front_user;
    //skopiowanie posortowanej listy temp do listy FrontUserList
    while(temp!=NULL)
    {
        printf("\n%s",temp->surname);
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
////////////////////////////////////////////////////
//////// SORTIWANIE PO KODZIE POCZTOWYM ////////////
////////////////////////////////////////////////////
void sort_list_by_postal_code(struct User_Node *FrontUserList, unsigned int direction)
{
    unsigned int counter=0,i,j;
    struct User_Node *pom;
    struct User_Node *front_user=FrontUserList;//Ustawienie wskaŸnika roboczego na pierwszym elemencie listy
    struct User_Node *wsk=FrontUserList;
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
            strcpy(temp->postal_code, FrontUserList->postal_code);
        }
        else
        {
            while (pomtemp->next)
            {
                pomtemp = pomtemp->next;
            }
            temp=(struct User_Node*)malloc(sizeof(struct User_Node));
            pomtemp->next=temp;
            temp->next=NULL;
            strcpy(temp->postal_code, FrontUserList->postal_code);
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
                if (strcmp(FrontUserList->postal_code, temp->postal_code) <= 0)
                {
                    pom=FrontUserList;
                    strcpy(temp->postal_code, FrontUserList->postal_code);
                    FrontUserList=FrontUserList->next;
                    printf("%s\n",temp->postal_code);

                }
                else  FrontUserList=FrontUserList->next;
            }
            else
            {
                if (strcmp(FrontUserList->postal_code, temp->postal_code) >= 0)
                {
                    pom=FrontUserList;
                    strcpy(temp->postal_code, FrontUserList->postal_code);
                    FrontUserList=FrontUserList->next;
                    printf("%s\n",temp->postal_code);

                }
                else  FrontUserList=FrontUserList->next;
            }
        }
        //zapis do listy temp
        FrontUserList=pom;
        strcpy(temp->name, FrontUserList->name);
        strcpy(temp->surname, FrontUserList->surname);
        strcpy(temp->city, FrontUserList->city);
        temp->house_number=FrontUserList->house_number;
        strcpy(temp->street, FrontUserList->street);
        strcpy(temp->post_office, FrontUserList->post_office);
        temp->ID=FrontUserList->ID;
        if(direction==0)
            strcpy(FrontUserList->postal_code, "XXXXXX" ); //najmniejszy element zostaje zamieniony na najwiekszy
        else
            strcpy(FrontUserList->postal_code, "0" ); //najwiekszy element zostaje zamieniony na najmniejszy

    }
    temp=front_temp;
    FrontUserList=front_user;
    //skopiowanie posortowanej listy temp do listy FrontUserList
    while(temp!=NULL)
    {
        printf("\n%s",temp->surname);
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
////////////////////////////////////////////////////
//////////// SORTIWANIE PO POCZCIE /////////////////
////////////////////////////////////////////////////
void sort_list(struct User_Node *FrontUserList, unsigned int direction, unsigned int what)
{
    unsigned int counter=0,i,j;
    struct User_Node *pom;
    struct User_Node *front_user=FrontUserList;//Ustawienie wskaŸnika roboczego na pierwszym elemencie listy
    struct User_Node *wsk=FrontUserList;
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
            if(what==5)strcpy(temp->postal_code, FrontUserList->postal_code);
            if(what==6)strcpy(temp->post_office, FrontUserList->post_office);
            if(what==7)temp->house_number=FrontUserList->house_number;
        }
        else
        {
            while (pomtemp->next)
            {
                pomtemp = pomtemp->next;
            }
            temp=(struct User_Node*)malloc(sizeof(struct User_Node));
            pomtemp->next=temp;
            temp->next=NULL;
            if(what==0)temp->ID=FrontUserList->ID;
            if(what==1)strcpy(temp->name, FrontUserList->name);
            if(what==2)strcpy(temp->surname, FrontUserList->surname);
            if(what==3)strcpy(temp->city, FrontUserList->city);
            if(what==4)strcpy(temp->street, FrontUserList->street);
            if(what==5)strcpy(temp->postal_code, FrontUserList->postal_code);
            if(what==6)strcpy(temp->post_office, FrontUserList->post_office);
            if(what==7)temp->house_number=FrontUserList->house_number;
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
                    if(temp->ID<=FrontUserList->ID)
                    {
                        pom=FrontUserList;
                        temp->ID=FrontUserList->ID;
                        FrontUserList=FrontUserList->next;
                    }
                    else  FrontUserList=FrontUserList->next;
                }
                if(what==1)
                {
                    if(strcmp(temp->name, FrontUserList->name)<= 0)
                    {
                        pom=FrontUserList;
                        strcpy(temp->name, FrontUserList->name);
                        FrontUserList=FrontUserList->next;
                    }
                    else  FrontUserList=FrontUserList->next;
                }
                if(what==2)
                {
                    if(strcmp(temp->surname, FrontUserList->surname)<= 0)
                    {
                        pom=FrontUserList;
                        strcpy(temp->surname, FrontUserList->surname);
                        FrontUserList=FrontUserList->next;
                    }
                    else  FrontUserList=FrontUserList->next;
                }
                if(what==3)
                {
                    if(strcmp(temp->city, FrontUserList->city)<= 0)
                    {
                        pom=FrontUserList;
                        strcpy(temp->city, FrontUserList->city);
                        FrontUserList=FrontUserList->next;
                    }
                    else  FrontUserList=FrontUserList->next;

                }
                if(what==4)
                {
                    if(strcmp(temp->street, FrontUserList->street)<= 0)
                    {
                        pom=FrontUserList;
                        strcpy(temp->street, FrontUserList->street);
                        FrontUserList=FrontUserList->next;
                    }
                    else  FrontUserList=FrontUserList->next;

                }
                if(what==5)
                {
                    if(strcmp(temp->postal_code, FrontUserList->postal_code)<= 0)
                    {
                        pom=FrontUserList;
                        strcpy(temp->postal_code, FrontUserList->postal_code);
                        FrontUserList=FrontUserList->next;
                    }
                    else  FrontUserList=FrontUserList->next;

                }
                if(what==6)
                {
                    if(strcmp(temp->post_office, FrontUserList->post_office)<= 0)
                    {   puts("dupa");
                        pom=FrontUserList;
                        strcpy(temp->post_office, FrontUserList->post_office);
                        FrontUserList=FrontUserList->next;
                    }
                    else  FrontUserList=FrontUserList->next;

                }
                if(what==7)
                {
                    if(temp->house_number<=FrontUserList->house_number)
                    {
                        pom=FrontUserList;
                        temp->house_number=FrontUserList->house_number;
                        FrontUserList=FrontUserList->next;
                    }
                    else  FrontUserList=FrontUserList->next;

                }
            }
            else
              {
                if(what==0)
                {
                    if(temp->ID>=FrontUserList->ID)
                    {
                        pom=FrontUserList;
                        temp->ID=FrontUserList->ID;
                        FrontUserList=FrontUserList->next;
                    }
                    else  FrontUserList=FrontUserList->next;
                }
                if(what==1)
                {
                    if(strcmp(temp->name, FrontUserList->name )>= 0)
                    {
                        pom=FrontUserList;
                        strcpy(temp->name, FrontUserList->name);
                        FrontUserList=FrontUserList->next;
                    }
                    else  FrontUserList=FrontUserList->next;
                }
                if(what==2)
                {
                    if(strcmp(temp->surname, FrontUserList->surname) >= 0)
                    {
                        pom=FrontUserList;
                        strcpy(temp->surname, FrontUserList->surname);
                        FrontUserList=FrontUserList->next;
                    }
                    else  FrontUserList=FrontUserList->next;
                }
                if(what==3)
                {
                    if(strcmp(temp->city, FrontUserList->city) >= 0)
                    {
                        pom=FrontUserList;
                        strcpy(temp->city, FrontUserList->city);
                        FrontUserList=FrontUserList->next;
                    }
                    else  FrontUserList=FrontUserList->next;

                }
                if(what==4)
                {
                    if(strcmp(temp->street, FrontUserList->street) >= 0)
                    {
                        pom=FrontUserList;
                        strcpy(temp->street, FrontUserList->street);
                        FrontUserList=FrontUserList->next;
                    }
                    else  FrontUserList=FrontUserList->next;

                }
                if(what==5)
                {
                    if(strcmp(temp->postal_code, FrontUserList->postal_code)>= 0)
                    {
                        pom=FrontUserList;
                        strcpy(temp->postal_code, FrontUserList->postal_code);
                        FrontUserList=FrontUserList->next;
                    }
                    else  FrontUserList=FrontUserList->next;

                }
                if(what==6)
                {
                    if(strcmp(temp->post_office, FrontUserList->post_office) >= 0)
                    {
                        pom=FrontUserList;
                        strcpy(temp->post_office, FrontUserList->post_office);
                        FrontUserList=FrontUserList->next;
                    }
                    else  FrontUserList=FrontUserList->next;

                }
                if(what==7)
                {
                    if(temp->house_number>=FrontUserList->house_number)
                    {
                        pom=FrontUserList;
                        temp->house_number=FrontUserList->house_number;
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
        strcpy(temp->postal_code, FrontUserList->postal_code);
        strcpy(temp->post_office, FrontUserList->post_office);
        temp->house_number=FrontUserList->house_number;
        temp->ID=FrontUserList->ID;
        if(direction==0)
        {
            if(what==0)FrontUserList->ID=-1;
            if(what==1)strcpy(FrontUserList->name, "XXXXXXXXXXXXX");
            if(what==2)strcpy(FrontUserList->surname, "XXXXXXXXXXXXX");
            if(what==3)strcpy(FrontUserList->city, "XXXXXXXXXXXXX");
            if(what==4)strcpy(FrontUserList->street, "XXXXXXXXXXXXX");
            if(what==5)strcpy(FrontUserList->postal_code, "XXXXXXXXXXXXX");
            if(what==6)strcpy(FrontUserList->post_office, "XXXXXXXXXXXXX" ); //najwiekszy element zostaje zamieniony na najmniejszy
            if(what==7)FrontUserList->house_number=1;
        }
        else
            if(what==0)FrontUserList->ID=99999;
            if(what==1)strcpy(FrontUserList->name, "A");
            if(what==2)strcpy(FrontUserList->surname, "A");
            if(what==3)strcpy(FrontUserList->city, "A");
            if(what==4)strcpy(FrontUserList->street, "A");
            if(what==5)strcpy(FrontUserList->postal_code, "A");
            if(what==6)strcpy(FrontUserList->post_office, "A" ); //najwiekszy element zostaje zamieniony na najmniejszy
            if(what==7)FrontUserList->house_number=999;

    }
    temp=front_temp;
    FrontUserList=front_user;
    //skopiowanie posortowanej listy temp do listy FrontUserList
    while(temp!=NULL)
    {
        printf("\n%s",temp->surname);
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



