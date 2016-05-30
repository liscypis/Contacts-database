#include "baza_kontaktow.h"

void print_list(struct User_Node * FrontUserList, struct telephone_nr * FrontTelList, struct email_node *FrontEmailList)
{
    struct telephone_nr *TempTel=FrontTelList;
    struct email_node *TempEm=FrontEmailList;
    int data;
    for (; NULL != FrontUserList ; FrontUserList = FrontUserList -> next )
    {
        puts("##############################");
        printf ("ID  [%u]\nImie:            %s\nNazwisko:        %s\nMiasto:          %s\nUlica:           %s\nNumer domu:      %hu\nKod pocztowy:    %s\nPoczta:          %s\n",
                FrontUserList->ID, FrontUserList->name, FrontUserList->surname, FrontUserList -> city,
                FrontUserList->street, FrontUserList->house_number, FrontUserList->postal_code,
                FrontUserList->post_office);
        data=FrontUserList->ID;
        puts("Numery telefonow:");
        for (FrontTelList=TempTel; NULL != FrontTelList ; FrontTelList = FrontTelList -> next )
        {
            if(FrontTelList->ID_tel==data)
            {
                printf ("                 %lu\n", FrontTelList->tel_nr);

            }
        }
        puts ("Adresy email:");
        for (FrontEmailList=TempEm; NULL != FrontEmailList ; FrontEmailList = FrontEmailList -> next )
        {
            if(FrontEmailList->ID_email==data)
            {
                printf ("                 %s\n",FrontEmailList->em);

            }
        }
    }
}
void print_person_by_id(struct User_Node * FrontUserList, struct telephone_nr * FrontTelList, struct email_node *FrontEmailList, int data)
{
    for (; NULL != FrontUserList ; FrontUserList = FrontUserList -> next)
    {
        if(FrontUserList->ID==data)
            printf ("ID  [%u]\nImie:          %s\nNazwisko:      %s\nMiasto:        %s\nUlica:         %s\nNumer domu:    %hu\nKod pocztowy:  %s\nPoczta:        %s\n",
                    FrontUserList->ID, FrontUserList->name, FrontUserList->surname, FrontUserList -> city,
                    FrontUserList->street, FrontUserList->house_number, FrontUserList->postal_code,
                    FrontUserList->post_office);
    }
    puts("Nr telefonow:");
    for (; NULL != FrontTelList ; FrontTelList = FrontTelList -> next )
    {
        if(FrontTelList->ID_tel==data)
            printf("               %lu\n", FrontTelList->tel_nr);
    }
    puts("Adresy email:");
    for (; NULL != FrontEmailList ; FrontEmailList = FrontEmailList -> next )
    {
        if(FrontEmailList->ID_email==data)
            printf("               %s\n", FrontEmailList->em);
    }
}
void print_person_by_name_or_surname(struct User_Node * FrontUserList, struct telephone_nr * FrontTelList, struct email_node *FrontEmailList, char data[], unsigned short int what)
{
    int tempID;
    for (; NULL != FrontUserList ; FrontUserList = FrontUserList -> next)
    {
        if(what==1)
        {
            if(strcmp(FrontUserList->name,data)==0)
            {
                puts("##############################");
                printf ("ID  [%u]\nImie:          %s\nNazwisko:      %s\nMiasto:        %s\nUlica:         %s\nNumer domu:    %hu\nKod pocztowy:  %s\nPoczta:        %s\n",
                        FrontUserList->ID, FrontUserList->name, FrontUserList->surname, FrontUserList -> city,
                        FrontUserList->street, FrontUserList->house_number, FrontUserList->postal_code,
                        FrontUserList->post_office);
                tempID = FrontUserList->ID;
            }

        }
        if(what==2)
        {
            if(strcmp(FrontUserList->surname,data)==0)
            {
                puts("##############################");
                printf ("ID  [%u]\nImie:          %s\nNazwisko:      %s\nMiasto:        %s\nUlica:         %s\nNumer domu:    %hu\nKod pocztowy:  %s\nPoczta:        %s\n",
                        FrontUserList->ID, FrontUserList->name, FrontUserList->surname, FrontUserList -> city,
                        FrontUserList->street, FrontUserList->house_number, FrontUserList->postal_code,
                        FrontUserList->post_office);
                tempID = FrontUserList->ID;
            }
        }

    }
    puts("Nr telefonow:");
    for (; NULL != FrontTelList ; FrontTelList = FrontTelList -> next )
    {
        if(FrontTelList->ID_tel==tempID)
            printf("               %lu\n", FrontTelList->tel_nr);
    }
    puts("Adresy email:");
    for (; NULL != FrontEmailList ; FrontEmailList = FrontEmailList -> next )
    {
        if(FrontEmailList->ID_email==tempID)
            printf("               %s\n", FrontEmailList->em);
    }
}
void edit_person (struct User_Node * FrontUserList, struct telephone_nr * FrontTelList, struct email_node *FrontEmailList, unsigned short int data )
{
    unsigned short int choice;
    unsigned long int tel_num;
    char email[40];
    char pom[20];
    unsigned int good=1,HouseNr,good2=1;
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
                print_person_by_id(FrontUserList,temp_tel,temp_email,data); //wyswietlenie edytowanego uzytwonika
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
                    do
                    {
                        printf("Podaj nowe imie: \n");
                        scanf("%s",pom);
                        good=check_string(pom);
                        if(good==0)
                            puts("Wprowadzone imie jest niepoprawne");
                    }
                    while(good==0);
                    ChangeToupper(pom);
                    strcpy(FrontUserList->name,pom);
                    break;
                case 2:
                    do
                    {
                        printf("Podaj nowe nazwisko: \n");
                        scanf("%s",pom);
                        good=check_string(pom);
                        if(good==0)
                            puts("Wprowadzone nazwisko jest niepoprawne");
                    }
                    while(good==0);
                    ChangeToupper(pom);
                    strcpy(FrontUserList->surname,pom);
                    break;
                case 3:
                    do
                    {
                        printf("Podaj miasto: \n");
                        scanf("%s",pom);
                        good=check_string(pom);
                        if(good==0)
                            puts("Wprowadzone miasto jest niepoprawne");
                    }
                    while(good==0);
                    ChangeToupper(pom);
                    strcpy(FrontUserList->city,pom);
                    break;
                case 4:
                    do
                    {
                        printf("Podaj nowa ulice: \n");
                        scanf("%s",pom);
                        good=check_string(pom);
                        if(good==0)
                            puts("Wprowadzona nazwa ulicy jest niepoprawna");
                    }
                    while(good==0);
                    ChangeToupper(pom);
                    strcpy(FrontUserList->street,pom);
                    break;
                case 5:
                    printf("Podaj numer domu: \n");
                    while(scanf("%u", &HouseNr) != 1) //dopóki nie uda siê wczytaæ
                    {
                        puts("Niepoprawny format, podaj numer domu jeszcze raz:");
                        fflush(stdin);
                    }
                    FrontUserList->house_number=HouseNr;
                    break;
                case 6:
                    do
                    {


                        printf("Podaj kod pocztowy (00-000):\n");
                        scanf("%s",pom);
                        good=check_postal_code(pom);
                        if(good==0)
                            puts("Wprowadzony kod jest nie poprawny");
                        strcpy(FrontUserList->postal_code,pom);
                    }
                    while(good==0);
                    break;
                case 7:
                    do
                    {
                        printf("Podaj poczte: \n");
                        scanf("%s",pom);
                        good=check_string(pom);
                        if(good==0)
                            puts("Wprowadzona nazwa poczty jest niepoprawna");
                    }
                    while(good==0);
                    ChangeToupper(pom);
                    strcpy(FrontUserList->post_office,pom);
                    break;
                case 8:
                    FrontTelList=temp_tel;
                    unsigned long int pomtel;
                    puts("Ktory numer chcesz edytowac? (podaj caly numer telefonu)");
                    while(scanf("%lu", &tel_num) != 1  || tel_exist(FrontTelList,tel_num)==0) //dopóki nie uda siê wczytaæ
                    {
                        puts("Niepoprawny wybor lub nie ma takiego numeru, podaj nr jeszcze raz:");
                        fflush(stdin);
                    }
                    puts("Podaj nowy numer:");
                    while(scanf("%lu", &pomtel) != 1 || pomtel<=0 ||  pomtel>999999999) //dopóki nie uda siê wczytaæ
                    {
                        puts("Niepoprawny format, podaj nr jeszcze raz:");
                        fflush(stdin);
                    }
                    for(; NULL != FrontTelList; FrontTelList = FrontTelList ->next)
                    {
                        if(FrontTelList->tel_nr==tel_num)
                        {
                        FrontTelList->tel_nr=pomtel;
                        break;
                        }

                    }
                    break;
                case 9:
                    FrontEmailList=temp_email;
                    puts("Ktory email chcesz edytowac? (podaj caly email)");
                    do
                    {
                        scanf("%s",email);
                        good=email_exist(FrontEmailList,email);
                        if(good==0)
                            puts("Podany email nie istnieje, podaj jeszcze raz:");
                    }
                    while(good==0);
                    puts("Podaj nowy email");
                    do
                    {
                        for (; NULL != FrontEmailList ; FrontEmailList = FrontEmailList -> next)
                        {

                            if(strcmp(FrontEmailList->em,email)==0)
                            {
                                scanf("%s",email);
                                good2=check_email(email);
                                if(good2==0)
                                    puts("Wprowadzone email jest niepoprawny");
                                break;
                            }
                        }
                    }
                    while(good2==0);
                    ChangeToupper(email); //zamiena na du¿e litery
                    strcpy(FrontEmailList->em, email);
                    break;
                case 10:
                    printf("Koniec edycji\n");
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
        if(isalnum(array[i])!=0 && isdigit(array[i])==0)
        {
        }
        else
        {
            k=0;
        }
    }
    if(k==0)return 0;
    return 1;
}
int check_email(char array[])
{
    int i,k=1,m=1;
    for(i=0; i<strlen(array); ++i)
    {
        if((array[i])=='@') k=0;
        if((array[i])=='.') m=0;
    }
    if(k==1 || m==1)return 0;
    else
        return 1;
}
int user_exist(struct User_Node * FrontUserList,int data)
{
    for (; NULL != FrontUserList ; FrontUserList = FrontUserList -> next)
        if(FrontUserList->ID==data)
        {
            return 1;
            break;
        }
    return 0;
}
int tel_exist(struct telephone_nr * FrontTelList,int data)
{
    for (; NULL != FrontTelList ; FrontTelList = FrontTelList -> next)
        if(FrontTelList->tel_nr==data)
        {
            return 1;
            break;
        }
    return 0;
}
int email_exist(struct email_node * FrontEmailList,char data[])
{
    for (; NULL != FrontEmailList ; FrontEmailList = FrontEmailList -> next)
        if(strcmp(FrontEmailList->em,data)==0)
        {
            return 1;
            break;
        }
    return 0;
}
int name_exist(struct User_Node * FrontUserList,char data[])
{
    for (; NULL != FrontUserList ; FrontUserList = FrontUserList -> next)
        if(strcmp(FrontUserList->name,data)==0)
        {
            return 1;
            break;
        }
    return 0;
}
int surname_exist(struct User_Node * FrontUserList,char data[])
{
    for (; NULL != FrontUserList ; FrontUserList = FrontUserList -> next)
        if(strcmp(FrontUserList->surname,data)==0)
        {
            return 1;
            break;
        }
    return 0;
}


