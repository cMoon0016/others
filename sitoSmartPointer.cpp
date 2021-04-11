#include <cmath>
#include <time.h>
#include <iomanip>
#include <memory>
#include <iostream>
#include <windows.h>

#include "sitoSmartPointer.h"
#include "cSito.h"

using namespace std;


cSitoSmartPointer::cSitoSmartPointer(long long aRoz)
{
    shared_ptr<cPunkt[]> p(new cPunkt[aRoz]);
    mPtr = p;
    mRozmiar = aRoz;

    for(int i=0; i<aRoz; i++) //wypelnienie
    {
        mPtr[i].setIndeks(i);
    }
}

cSitoSmartPointer::~cSitoSmartPointer()
{

}

void cSitoSmartPointer::wyswietl() const
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

        if(mPtr[i].getCzyWykreslone() == true)
            SetConsoleTextAttribute( hOut, BACKGROUND_RED | BACKGROUND_INTENSITY); //czerwone tlo
        else
            SetConsoleTextAttribute( hOut, BACKGROUND_GREEN | BACKGROUND_INTENSITY); //zielone jasne tlo

        cout<<mPtr[i].mIndeks<<"\t";

        SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE ); //normalne tlo poprzez ustawienie bialego koloru czcionki
    }
}

void cSitoSmartPointer::odsiej()
{
    clock_t start, stop; //mierzenie cykli procesora

    start = clock();

    mPtr[0].wykresl(); //0 ani 1 nie sa liczbami pierwszymi
    mPtr[1].wykresl();

    for(int i=2; i<=sqrt(mRozmiar); i++)
    {
        if(mPtr[i].getCzyWykreslone() == false)
            for(int j=2*i; j<mRozmiar; j+=i) //wykresla wielokrotnosci i poczawszy od 2i
                mPtr[j].wykresl();
    }
    stop = clock();
    mCzyOdsiane = true; //ustawienie flagi
    double czas = (stop-start)/static_cast<double>(CLOCKS_PER_SEC);

    cout<<"Czas odsiewania: "<<czas<<endl;
}

void cSitoSmartPointer::zmien_rozmiar(long long aRoz)
{
    mPtr = nullptr;
    mRozmiar = aRoz;
    shared_ptr<cPunkt[]> p(new cPunkt[aRoz]);
    mPtr = p;

    for(int i=0; i<aRoz; i++) //wypelnienie
    {
        mPtr[i].setIndeks(i);
    }
    mCzyOdsiane = false; //po zmianie sita trzeba znow odsiac
}

void cSitoSmartPointer::sprawdz(int aX)
{
    if(mCzyOdsiane == false)
    {
        cout<<"Najpierw musisz odsiac liczby!"<<endl;
        return;
    }

    if(mPtr[aX].getCzyWykreslone() == true)
        cout<<"To nie jest liczba pierwsza"<<endl;
    else
        cout<<"To jest liczba pierwsza"<<endl;
}
