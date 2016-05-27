#include "add_removeElements.h"

void sortowanie_listy(struct User_Node *FrontUserList, unsigned int direction)
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


