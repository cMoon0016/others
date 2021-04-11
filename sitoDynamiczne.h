#ifndef SITO_H_INCLUDED
#define SITO_H_INCLUDED

#include "cSito.h"

class cSito :public cSitoAbstrakcyjne
{
    private:
        cPunkt* mTab;

    public:
        explicit cSito(long long roz);
        ~cSito();
        void odsiej();
        void wyswietl() const;
        void sprawdz(int x);
        void zmien_rozmiar(long long roz);

};


#endif // SITO_H_INCLUDED
