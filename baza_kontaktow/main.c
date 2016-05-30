#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "baza_kontaktow.h"

int main()
{
    struct User_Node *FrontUserList=NULL;
    struct telephone_nr *FrontTelList=NULL;
    struct email_node *FrontEmailList=NULL;
    //odczyt danych z plikow
    if((file=fopen("USERS.txt","r"))==NULL || (file2=fopen("TELEPHONE.txt","r"))==NULL || (file3=fopen("EMAIL.txt","r"))==NULL) // sprawdzamy czy pliki istnieja
    {
        printf("Nie udalo sie otworzyc plikow\n");
    }
    else
    {
        FrontUserList=read(file,FrontUserList);
        FrontTelList=readTelephone(file2, FrontTelList);
        FrontEmailList=readEmail(file3, FrontEmailList);
    }
    for(;;)
    {
        printf("Baza kontaktow v1.27\n\n");
        puts("#################### MENU ####################");
        puts("1.Dodaj osobe");
        puts("2.Usun osobe");
        puts("3.Edytuj osobe");
        puts("4.Wyswietl baze");
        puts("5.Wyswietl kontakt");
        puts("6.ZAPIS DO PLIKU");
        puts("7.SORTOWANIE");
        puts("8.WYJSCIE i USUNIECIE LISTY");

        unsigned short int choice,tel,HowManyEmail;
        int i=0,j=0;
        unsigned int z,k; // do sortowanie
        scanf("%hu",&choice);
        switch(choice)
        {
        case 1:
            if(FrontUserList==NULL)
            {
                FrontUserList=create_list(FrontUserList);

            }
            else
                FrontUserList=InsertUser(FrontUserList);

            system("cls");
            puts("#### DODAWANIE UZYTWONIKA ####");
            printf("Ile numerow telefonow chcesz podac? MAX 10!:\n");
            while(scanf("%hu", &tel) != 1 || tel<=0 || tel>10) //dopóki nie uda się wczytać
            {
                puts("Niepoprawny wybor, podaj liczbe jeszcze raz:");
                fflush(stdin);
            }
            for(i=0; i<tel; i++)
            {
                if(FrontTelList==NULL)
                    FrontTelList=CreatePhoneList(FrontTelList);
                else
                    FrontTelList=InsertTelNum(FrontTelList);
            }

            system("cls");
            puts("#### DODAWANIE UZYTWONIKA ####");
            printf("Ile adresow email chcesz podac? MAX 10!:\n");
            while(scanf("%hu", &HowManyEmail) != 1 || HowManyEmail<=0 || HowManyEmail>10) //dopóki nie uda się wczytać
            {
                puts("Niepoprawny wybor, podaj liczbe jeszcze raz:");
                fflush(stdin);
            }
            for(j=0; j<HowManyEmail; j++)
            {
                if(FrontEmailList==NULL)
                    FrontEmailList=CreateEmalList(FrontEmailList);
                else
                    FrontEmailList=InsertEmail(FrontEmailList);
            }
            system("cls");
            puts("\n######DODAWANIE UZYTWONIKA ZAKONCZONE#######\n");
            puts("#### NACISNIJ ENTER ABY PRZEJSC DO MENU ####");
            break;
        case 2:
            if(FrontUserList==NULL)
            {
                puts("Lista jest pusta");
                break;
            }
            else
            {
                system("cls");
                unsigned short int i;
                print_list(FrontUserList,FrontTelList,FrontEmailList);
                printf("Ktora osobe chcesz usunac (Podaj ID):");
                while(scanf("%hu", &i) != 1 || i<0 || user_exist(FrontUserList,i)==0) //dopóki nie uda się wczytać
                {
                    puts("Niepoprawny wybor, podaj liczbe jeszcze raz:");
                    fflush(stdin);
                }
                FrontUserList=DeleteUserNode(FrontUserList,i);
                FrontEmailList=DeleteEmailNode(FrontEmailList,i);
                FrontTelList=DeleteTelNode(FrontTelList,i);
                puts("\n############### USUNIETO #################\n");
                puts("#### NACISNIJ ENTER ABY PRZEJSC DO MENU ####");
            }
            break;
        case 3:
            if(FrontUserList==NULL)
            {
                puts("Lista jest pusta");
                break;
            }
            else
            {
                printf("Ktora osobe chcesz edytowac (Podaj ID):");
                unsigned short int j;
                while(scanf("%hu", &j) != 1  || user_exist(FrontUserList,j)==0) //dopóki nie uda się wczytać
                {
                    puts("Niepoprawny wybor, podaj liczbe jeszcze raz:");
                    fflush(stdin);
                }
                edit_person(FrontUserList,FrontTelList,FrontEmailList,j);
            }
            break;
        case 4:
            if(FrontUserList==NULL)
            {
                puts("Lista jest pusta");
                break;
            }
            else
            {
                system("cls");
                print_list(FrontUserList,FrontTelList,FrontEmailList);
                puts("##############################");
                puts("\nNacisnij ENTER by kontynuowac");
            }
            break;
        case 5:
            if(FrontUserList==NULL)
            {
                puts("Lista jest pusta");
                break;
            }
            else
            {
                system("cls");
                unsigned short int choice1;
                puts("Po jakim polu chcesz wyszukac?");
                puts(" 0 - ID \n 1 - IMEIU\n 2 - NAZWISKU");
                printf("WYBOR: ");
                while(scanf("%hu", &choice1) != 1 || choice1<0 || choice1>2) //dopóki nie uda się wczytać
                {
                    puts("Niepoprawny wybor, podaj numer jeszcze raz:");
                    fflush(stdin);
                }

                if(choice1==0)
                {
                    system("cls");
                    puts("Podaj ID uzytkownika, ktorego chcesz wyswietlic:");
                    while(scanf("%d", &i) != 1 || user_exist(FrontUserList,i)==0) //dopóki nie uda się wczytać
                    {
                        puts("Nie znaleziono uzytkownika o podanym ID, podaj numer jeszcze raz:");
                        fflush(stdin);
                    }
                    print_person_by_id(FrontUserList,FrontTelList,FrontEmailList,i);
                }

                if(choice1==1)
                {
                    system("cls");
                    char name[30];
                    int good=0;
                    do
                    {
                        puts("Podaj imie uzytkownika, ktorego chcesz wyswietlic:");
                        scanf("%s",name);
                        good=check_string(name);
                        if(good==0)
                            puts("Wprowadzone imie jest niepoprawne");
                        ChangeToupper(name);
                    }
                    while(good==0 || name_exist(FrontUserList,name)==0);
                    print_person_by_name_or_surname(FrontUserList, FrontTelList, FrontEmailList, name ,choice1);
                }

                if(choice1==2)
                {
                    system("cls");
                    char surname[30];
                    int good=0;
                    do
                    {
                        puts("Podaj nazwisko uzytkownika, ktorego chcesz wyswietlic:");
                        scanf("%s",surname);
                        good=check_string(surname);
                        if(good==0)
                            puts("Wprowadzone imie jest niepoprawne");
                        ChangeToupper(surname);
                    }
                    while(good==0 || surname_exist(FrontUserList,surname)==0);
                    print_person_by_name_or_surname(FrontUserList, FrontTelList, FrontEmailList, surname, choice1);
                }
                puts("Nacisnij ENTER by kontynuowac");
            }
            break;
        case 6:
            if(FrontUserList==NULL)
            {
                puts("Lista jest pusta");
                break;
            }
            else
            {
                sort_list(FrontUserList,0,0);
                save(file,file2,file3, FrontUserList,FrontTelList,FrontEmailList);
                puts("ZAPISANO DANE DO PLIKOW");
                puts("Nacisnij ENTER by kontynuowac");
            }
            break;
        case 7:
            //########### SROTOWANIE#################
            if(FrontUserList==NULL)
            {
                puts("Lista jest pusta");
                break;
            }
            else
            {
                system("cls");
                puts("Po jakim polu chcesz sortowac?\n");
                puts(" 0- numer ID\n 1- imie\n 2- nazwisko\n 3- miasto\n 4- ulica\n 5- numer domu\n 6- kod pocztowy\n 7- poczta\n 8- numer telefonu\n 9- email\n");
                printf("Wybor: ");
                while(scanf("%u", &k) != 1 || k>9 || k<0) //dopóki nie uda się wczytać
                {
                    puts("Niepoprawny wybor, podaj numer jeszcze raz:");
                    fflush(stdin);
                }
                system("cls");
                puts("Jak chcesz posortowac liste?\n 0- rosnaco\n 1- malejaco\n");
                printf("Wybor: ");
                while(scanf("%u", &z) != 1 || z>1 || z<0) //dopóki nie uda się wczytać
                {
                    puts("Niepoprawny wybor, podaj numer jeszcze raz:");
                    fflush(stdin);
                }
                system("cls");
                if(k<=7)
                {
                    sort_list(FrontUserList,z,k);
                }
                else if(k==8)
                {
                    sort_list_by_tel(FrontTelList,FrontUserList,z);
                }
                else if(k==9)
                {
                    sort_list_by_email(FrontEmailList,FrontUserList,z);
                }

                puts("POSORTOWANO");
                puts("Nacisnij ENTER by wrocic do menu glownego");
            }
            break;
        case 8:
            remove_list(&FrontUserList);
            remove_tel_list(&FrontTelList);
            remove_email_list(&FrontEmailList);
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
