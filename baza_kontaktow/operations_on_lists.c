#include "baza_kontaktow.h"

void print_list(struct User_Node * FrontUserList, struct telephone_nr * FrontTelList, struct email_node *FrontEmailList)
{
    struct telephone_nr *TempTel=FrontTelList;
    struct email_node *TempEm=FrontEmailList;
    int data;
    for (; NULL != FrontUserList ; FrontUserList = FrontUserList -> next )
    {
        printf ("ID  [%u]\nImie:           %s\nNazwisko:       %s\nMiasto:         %s\nUlica:          %s\nNumer domu:     %hu\nKod pocztowy:   %s\nPoczta:         %s\n",
                FrontUserList->ID, FrontUserList->name, FrontUserList->surname, FrontUserList -> city,
                FrontUserList->street, FrontUserList->house_number, FrontUserList->postal_code,
                FrontUserList->post_office);
        data=FrontUserList->ID;
        for (FrontTelList=TempTel; NULL != FrontTelList ; FrontTelList = FrontTelList -> next )
        {
            if(FrontTelList->ID_tel==data)
            {
                printf ("Numer telefonu: %d\n", FrontTelList->tel_nr);
                break;
            }
        }
        for (FrontEmailList=TempEm; NULL != FrontEmailList ; FrontEmailList = FrontEmailList -> next )
        {
            if(FrontEmailList->ID_email==data)
            {
                printf ("Adres email:    %s \n\n", FrontEmailList->em);
                break;
            }
        }
    }
}
void print_person(struct User_Node * FrontUserList, struct telephone_nr * FrontTelList, struct email_node *FrontEmailList, int data)
{
    for (; NULL != FrontUserList ; FrontUserList = FrontUserList -> next)
    {
        if(FrontUserList->ID==data)
            printf ("ID  [%u]\nImie:          %s\nNazwisko:      %s\nMiasto:        %s\nUlica:         %s\nNumer domu:    %hu\nKod pocztowy:  %s\nPoczta:        %s\n",
                    FrontUserList->ID, FrontUserList->name, FrontUserList->surname, FrontUserList -> city,
                    FrontUserList->street, FrontUserList->house_number, FrontUserList->postal_code,
                    FrontUserList->post_office);
    }
    puts("\nNr telefonow:");
    for (; NULL != FrontTelList ; FrontTelList = FrontTelList -> next )
    {
        if(FrontTelList->ID_tel==data)
            printf("               %u\n", FrontTelList->tel_nr);
    }
    puts("\nAdresy email:");
    for (; NULL != FrontEmailList ; FrontEmailList = FrontEmailList -> next )
    {
        if(FrontEmailList->ID_email==data)
            printf("               %s\n", FrontEmailList->em);
    }
}
void edit_person (struct User_Node * FrontUserList, struct telephone_nr * FrontTelList, struct email_node *FrontEmailList, unsigned short int data )
{
    unsigned short int choice;
    unsigned int tel_num;
    int temp;
    char email[40];
    struct telephone_nr * temp_tel = FrontTelList; ////zapisanie we wskazniku lokalnym "temp_tel" adresu pierwszego elementu listy "telephone_nr"
    struct email_node * temp_email = FrontEmailList;
    for (; NULL != FrontUserList; FrontUserList = FrontUserList -> next)
    {
        if(FrontUserList->ID==data)
        {

            while(choice!=10)
            {
                system("cls");
                printf("############ EDYCJA KONTAKTU ##############\n");
                print_person(FrontUserList,temp_tel,temp_email,data); //wyswietlenie edytowanego uzytwonika
                puts("\n");
                puts("Co chcesz zmienic?");
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
                    puts("Podaj nowe imie:");
                    scanf("%s",FrontUserList->name);
                    break;
                case 2:
                    puts("Podaj nowe nazwisko:");
                    scanf("%s",FrontUserList->surname);
                    break;
                case 3:
                    puts("Podaj nowe miasto:");
                    scanf("%s",FrontUserList->city);
                    break;
                case 4:
                    puts("Podaj nowa ulice:");
                    scanf("%s",FrontUserList->street);
                    break;
                case 5:
                    puts("Podaj nowy numer domu:");
                    scanf("%u",&FrontUserList->house_number);
                    break;
                case 6:
                    puts("Podaj nowy kod pocztowy:");
                    scanf("%s",FrontUserList->postal_code);
                    break;
                case 7:
                    puts("Podaj nowa poczte:");
                    scanf("%s",FrontUserList->post_office);
                    break;
                case 8:
                    puts("Ktory numer chcesz edytowac? (podaj caly numer telefonu)");
                    scanf("%u",&tel_num);
                    puts("Podaj nowy numer:");
                    for (FrontTelList=temp_tel; NULL != FrontTelList ; FrontTelList = FrontTelList -> next )
                    {
                        if(FrontTelList->ID_tel==data && FrontTelList->tel_nr==tel_num)
                        {
                            scanf("%u",&FrontTelList->tel_nr);
                            break;
                        }
                    }
                    break;
                case 9:
                    puts("Ktory email chcesz edytowac? (podaj caly emal )");
                    scanf("%s",email);
                    puts("Podaj nowy email:");
                    for (FrontEmailList=temp_email; NULL != FrontEmailList ; FrontEmailList = FrontEmailList -> next )
                    {
                        temp=strcmp(FrontEmailList->em,email);
                        if(FrontEmailList->ID_email==data && temp==0)
                        {
                            scanf("%s",FrontEmailList->em);
                            break;
                        }
                    }
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

void ChangeToupper(char array[])
{
    int i;
    for(i=0; i<strlen(array); ++i)
    {
        array[i]=toupper(array[i]);
    }
}
int check_postal_code(char array[])
{
    if(strlen(array)>6) return 0;
    if(isdigit(array[0])==0) return 0;
    if(isdigit(array[1])==0) return 0;
    if((array[2])!='-') return 0;
    if(isdigit(array[3])==0) return 0;
    if(isdigit(array[4])==0) return 0;
    if(isdigit(array[5])==0) return 0;
    else
        return 1;
}
int check_string(char array[])
{
    int i,k=1;
    for(i=0; i<strlen(array); ++i)
    {
        if(isalnum(array[i])!=0 && isdigit(array[i])==0){
        }
        else{
            k=0;
        }
    }
    if(k==0)return 0;
    return 1;
}
