#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <cmath>
#include <time.h>
#include <iomanip>
#include "sitoDynamiczne.h"


using namespace std;


cSito::cSito(long long aRoz)
{
    mTab = new cPunkt[aRoz]; //dynamiczna alokacja pamieci i definicja tablicy
    mRozmiar = aRoz;

    for(int i=0; i<aRoz; i++) //wypelnienie
    {
        mTab[i].setIndeks(i);
    }
}

cSito::~cSito()
{
    delete mTab; //usuniecie tablicy poprzez wskaznik
}

void cSito::wyswietl() const
{
    if(mCzyOdsiane == false)
    {
        cout<<"Najpierw musisz odsiac liczby!"<<endl;
        return;
    }

    HANDLE hOut; //ustawianie koloru wyswietlania liczb;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );

    for(int i=0; i<mRozmiar; i++)
    {
        if(i>0 && i%10 == 0)
            cout<<endl;

        if(mTab[i].getCzyWykreslone() == true)
            SetConsoleTextAttribute( hOut, BACKGROUND_RED | BACKGROUND_INTENSITY); //czerwone tlo
        else
            SetConsoleTextAttribute( hOut, BACKGROUND_GREEN | BACKGROUND_INTENSITY); //zielone jasne tlo

        cout<<mTab[i].mIndeks<<"\t";

        SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE ); //normalne tlo poprzez ustawienie bialego koloru czcionki
    }
}

void cSito::odsiej()
{
    clock_t start, stop; //mierzenie cykli procesora

    start = clock();

    mTab[0].wykresl(); //0 ani 1 nie sa liczbami pierwszymi
    mTab[1].wykresl();

    for(int i=2; i<=sqrt(mRozmiar); i++)
    {
        if(mTab[i].getCzyWykreslone() == false)
            for(int j=2*i; j<mRozmiar; j+=i) //wykresla wielokrotnosci i poczawszy od 2i
                mTab[j].wykresl();
    }
    stop = clock();
    mCzyOdsiane = true; //ustawienie flagi
    double czas = (stop-start)/static_cast<double>(CLOCKS_PER_SEC);

    cout<<"Czas odsiewania: "<<czas<<endl;
}

void cSito::zmien_rozmiar(long long aRoz)
{
    delete mTab;
    mTab = new cPunkt[aRoz];
    mRozmiar = aRoz;

    for(int i=0; i<aRoz; i++) //wypelnienie
    {
        mTab[i].setIndeks(i);
    }
    mCzyOdsiane = false; //po zmianie sita trzeba znow odsiac
}

void cSito::sprawdz(int x)
{
    if(mCzyOdsiane == false)
    {
        cout<<"Najpierw musisz odsiac liczby!"<<endl;
        return;
    }

    if(mTab[x].getCzyWykreslone() == true)
        cout<<"To nie jest liczba pierwsza"<<endl;
    else
        cout<<"To jest liczba pierwsza"<<endl;
}
