#ifndef baza_kontaktow_h
#define baza_kontaktow_h
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/**
    @file baza_kontaktow.h
    \brief Przechowuje struktury i naglówki funkcji.
*/

/**
    \var NumID
    \brief globalna zmienna ID
*/
unsigned int NumID; //deklaracja globalnej zmiennej ID

FILE *file; /*!< Wskaznik na plik */
FILE *file2; /*!< Wskaznik na plik */
FILE *file3; /*!< Wskaznik na plik */
/**
    \struct User_Node
    \brief Struktura przechowuje dane uzytkownika i wskaznik na nastepny element.
*/
struct User_Node
{
    int ID; /*!< Pole przechowuje ID */
    char name[15]; /*!< Pole przechowuje imie */
    char surname[20]; /*!< Pole przechowuje nazwisko */
    char city[40]; /*!< Pole przechowuje nazwe miasta */
    char street[40]; /*!< Pole przechowuje nazwe ulicy */
    unsigned int house_number; /*!< Pole przechowuje numer domu */
    char postal_code[8]; /*!< Pole przechowuje kod pocztowy */
    char post_office[30]; /*!< Pole przechowuje nazwe poczty */
    struct User_Node *next; /*!<  wskaznik na nastepny element w liscie */
};
/**
    \struct telephone_nr
    \brief Struktura przechowuje numery telefonów uzytkownika i wskaznik na nastepny element.
*/
struct telephone_nr
{
    unsigned int ID_tel; /*!< Pole przechowuje ID numeru telefonu */
    unsigned long int tel_nr; /*!< Pole przechowuje numer telefonu */
    struct telephone_nr *next; /*!<  wskaznik na nastepny element w liscie */
};
/**
    \struct email_node
    \brief Struktura przechowuje adresy email uzytkownika i wskaznik na nastepny element.
*/
struct email_node
{
    unsigned int ID_email; /*!< Pole przechowuje ID adresu e-mail  */
    char em[40]; /*!< Pole przechowuje adres  e-mail  */
    struct email_node *next; /*!<  wskaznik na nastepny element w liscie */
};


//tworzy liste i element do listy
struct telephone_nr * CreatePhoneList(struct telephone_nr *FrontTelList);
//dodaje element do listy
struct telephone_nr * InsertTelNum(struct telephone_nr *FrontTelList);
//tworzy liste i element do listy
struct email_node * CreateEmalList(struct email_node *FrontEmailList);
//dodaje element do listy
struct email_node * InsertEmail(struct email_node *FrontEmailList);
//tworzy liste i element do listy
struct User_Node *create_list(struct User_Node *FrontUserList);
//dodaje element do listy
struct User_Node * InsertUser ( struct User_Node *FrontUserList  );
//usuwa element z listy
struct User_Node * DeleteUserNode ( struct User_Node *FrontUserList , int data );
struct email_node * DeleteEmailNode ( struct email_node *FrontEmailList , int data );
struct telephone_nr * DeleteTelNode ( struct telephone_nr *FrontTelList , int data );
//wyswietlanie
void print_list(struct User_Node * FrontUserList, struct telephone_nr * FrontTelList, struct email_node *FrontEmailList);
void print_person_by_id(struct User_Node * FrontUserList, struct telephone_nr * FrontTelList, struct email_node *FrontEmailList, int data);
void print_person_by_name_or_surname(struct User_Node * FrontUserList, struct telephone_nr * FrontTelList, struct email_node *FrontEmailList, char data[], unsigned short int what);
//edycja
void edit_person (struct User_Node * FrontUserList, struct telephone_nr * FrontTelList, struct email_node *FrontEmailList, unsigned short int data);
//zapis
void save(FILE *file,FILE *file2,FILE *file3, struct User_Node * FrontUserList, struct telephone_nr * FrontTelList, struct email_node *FrontEmailList);
//odczyt uzytkownikow z pliku
struct User_Node *read(FILE *file, struct User_Node * FrontUserList);
//odczyt telefonow z pliku
struct telephone_nr *readTelephone(FILE *file2, struct telephone_nr * FrontTelList);
//odczyt adresow email z pliku
struct email_node *readEmail(FILE *file3, struct email_node * FrontEmailList);
// sortowanie listy
void sort_list(struct User_Node *FrontUserList,unsigned int direction,unsigned int what);
// sortowanie pod tel
void sort_list_by_tel(struct telephone_nr *FrontTelList, struct User_Node *FrontUserList,unsigned int direction);
// sortowanie pod emailu
void sort_list_by_email(struct email_node *FrontEmailList, struct User_Node *FrontUserList,unsigned int direction);
//zamiana na du¿e
void ChangeToupper(char array[]);
//sprawdzanie kodu
int check_postal_code(char array[]);
//sprawdzanie stringow
int check_string(char array[]);
//sprawdzanie poprawnosci emaila
int check_email(char array[]);
//spradza czy jest taki uzytkownic
int user_exist(struct User_Node * FrontUserList,int data);
//sprawdza czy jest taki nr tel
int tel_exist(struct telephone_nr * FrontTelList,int data);
//sprawdza czy jest taki emial
int email_exist(struct email_node * FrontEmailList,char data[]);
//sprawdza czy jest takie imie
int name_exist(struct User_Node * FrontUserList,char data[]);
//sprawdza czy jest takie nazwisko
int surname_exist(struct User_Node * FrontUserList,char data[]);
//usuwanie listy
void remove_list ( struct User_Node ** temp );
void remove_tel_list ( struct telephone_nr ** temp );
void remove_email_list ( struct email_node ** temp );

#endif

