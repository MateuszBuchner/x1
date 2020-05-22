#include <iostream>
#include <fstream>
using namespace std;

fstream plik_dane;
struct obiekt_komputer
{
    char tytul[25];
    char procesor[50];
    char karta_graficzna[50];
};

void szukajWszystkichFraz( string szukanaFraza )
{
    ifstream plik_dane;
    plik_dane.open( "konfiguratory.txt", ios::in );
    string tekst;
    do {
        getline( plik_dane, tekst );
       
        if( tekst.find( szukanaFraza ) != std::string::npos )
        {
            for( int i = 0; i < 7; i++ )
            {
                cout << "\t" << tekst << endl;
                getline( plik_dane, tekst );
            }
            return;
        }
    } while( !plik_dane.eof() );
    plik_dane.close();
}
int main( int argc, char ** argv ) {
    cout << "================================" << endl;
    cout << "Dodaj swoj zestaw pc do rejestru" << endl;
    cout << "================================" << endl;

    int wybor;
    int n, koniec;
    koniec = 1;
    string szukane, podane; 
   
    start:
    cout << "\t=== MENU === " << endl << endl;
    cout << "1 Dodaj swoj konfigurator pc" << endl;
    cout << "2 Wyszukiwanie komputera w bazie" << endl;
    cout << "3 Zamknij program" << endl << endl;
   
    cout << endl;
    do
    {
        cout << "Wprowadz operacje " << endl << endl;
        cout << "=> ";
        cin >> wybor;
       
        if( wybor > 3 )
        {
        	cout << "=======================================" << endl << endl;
            cout << "Wybierz opcje w przedziale 1/3" << endl;
            cout << "=======================================" << endl << endl;
        }
        else
       
        switch( wybor )
        {
        case 1:
        	cout << "===========================" << endl ;
            cout << "Dodawanie konfiguratowa pc" << endl << endl ;
            obiekt_komputer obiekt_konfigu;
            cout << "Podaj glowna nazwe konfiga " << endl;
            cout << "=>";
            cin >> obiekt_konfigu.tytul;
            cout << endl;
            cout << "Podaj procesor " << endl;
            cout << "=>";
            cin >> obiekt_konfigu.procesor;
            cout << endl;
            cout << "Podaj karte graficzna " << endl;
            cout << "=>";
            cin >> obiekt_konfigu.karta_graficzna;
            cout << endl;
           
            system( "cls" );
           
            cout << "===========================" << endl;
            cout << "Dodano nastepujacy zestaw:" << endl;
            cout << "Nazwa: " << obiekt_konfigu.tytul << endl;
            cout << "Procesor: " << obiekt_konfigu.procesor << endl;
            cout << "Karta graficzna: " << obiekt_konfigu.karta_graficzna << endl;
            cout << "===========================" << endl;
            plik_dane.open( "konfiguratory.txt", ios::app | ios::ate );
           
            if( plik_dane.good() == true )
            {
                ofstream plik_dane;
                plik_dane.open( "konfiguratory.txt", ios::app | ios::ate | ios::out );
               
                plik_dane << obiekt_konfigu.tytul << "\n";
                plik_dane << obiekt_konfigu.procesor << "\n";
                plik_dane << obiekt_konfigu.karta_graficzna << "\n";
               
                plik_dane.close();
            } else cout << "PLIK!!" << endl;
           
            goto start;
            break;
        case 2:
            cout << "Wybrales wyszukiwanie cfg" << endl;
            cout << "===========================" << endl << endl;
            cout << "Podaj Tytul do wyszukania" << endl;
            cin >> podane;
            system( "cls" );
            cout << "================" << endl;
            cout << "Wyszukiwany CFG " << podane<< endl;
            cout << "================" << endl << endl;
            cout << "Znalezione configi to: " << endl << endl;
            szukajWszystkichFraz( podane );
            goto start;
            break;
           
        case 3:
            system( "cls" );
            cout << endl;
            cout << "Nacisnij enter aby wyjsc" << endl;
            koniec = 0;
            break;
        }
    } while( koniec != 0 );
   
    return 0;
}
