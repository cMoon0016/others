#include <iostream>
#include <windows.h>
#include "cSito.h"
#include "sitoVector.h"
#include "sitoSmartPointer.h"
#include "sitoDynamiczne.h"


using namespace std;

//function signatures
void menu();
cSitoAbstrakcyjne* fWyborPojemnika(cSito &, cSitoVector &, cSitoSmartPointer &);

int main()
{

    cSito sitoDynamiczne(1);
    cSitoVector sitoVec(1);
    cSitoSmartPointer sitoPtr(1);

    long long rozmiar;
    cout<<"SITO ERASTOTENESA"<<endl<<endl;
    cout<<"Jak duze ma byc sito? ";
    cin>>rozmiar;

    cSitoAbstrakcyjne *ptr;

    ptr = fWyborPojemnika(sitoDynamiczne, sitoVec, sitoPtr);
    ptr -> zmien_rozmiar(rozmiar);

    int decyzja;

    for(;;)
    {
        system("cls");
        menu();
        cin>>decyzja;

        switch(decyzja)
        {
        case 1:
            ptr -> odsiej();
            cout<<"Odsiano poprawnie sito"<<endl;
            break;

        case 2:
            ptr -> wyswietl();
            break;

        case 3:
            int liczba;
            cout<<"Podaj liczbe do sprawdzenia: ";
            cin>>liczba;
            ptr -> sprawdz(liczba);
            break;

        case 4:
            cout<<"Podaj nowy rozmiar sita: ";
            cin>>rozmiar;
            ptr -> zmien_rozmiar(rozmiar);
            cout<<"Zmieniono rozmiar sita"<<endl;
            break;

        case 5:
            ptr -> zmien_rozmiar(1); //ustawienie starego pojemnika znow na rozmiar 1;
            ptr = fWyborPojemnika(sitoDynamiczne, sitoVec, sitoPtr);
            ptr -> zmien_rozmiar(rozmiar);
            break;

        case 6:
            cout<<"Koniec dzialania programu"<<endl;
            system("pause");
            return 0;

        default:
            cout<<"Nie ma takiej opcji"<<endl;
        }
        system("pause");
    }

    return 0;
}

cSitoAbstrakcyjne* fWyborPojemnika(cSito &sitoDynamiczne, cSitoVector &sitoVec, cSitoSmartPointer &sitoPtr)
{
    int decyzja;
    cout<<endl;
    cout<<"Jakiego pojemnika chcesz uzywac?"<<endl;
    cout<<"1. Dynamiczna tablica"<<endl;
    cout<<"2. Vector"<<endl;
    cout<<"3. Smart Pointer"<<endl;
    cout<<"Decyzja: ";
    cin>>decyzja;

    if(decyzja == 1)
        return &sitoDynamiczne;
    else if(decyzja == 2)
        return &sitoVec;
    else if(decyzja == 3)
        return &sitoPtr;

}

void menu()
{
    cout<<"SITO ERASTOTENESA"<<endl;
    cout<<"1. ODSIEJ"<<endl;
    cout<<"2. WYSWIETL"<<endl;
    cout<<"3. SPRAWDZ"<<endl;
    cout<<"4. ZMIEN ROZMIAR SITA"<<endl;
    cout<<"5. ZMIEN POJEMNIK"<<endl;
    cout<<"6. KONIEC PRACY"<<endl;
    cout<<"Decyzja: ";
}
