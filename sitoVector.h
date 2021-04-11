#ifndef SITOVECTOR_H_INCLUDED
#define SITOVECTOR_H_INCLUDED

#include "sitoDynamiczne.h"
#include "cSito.h"
#include <vector>

class cSitoVector :public cSitoAbstrakcyjne
{
    private:
        std::vector<cPunkt> mVec;

    public:
        explicit cSitoVector(long long aRoz);
        ~cSitoVector();
        virtual void odsiej();
        virtual void wyswietl() const;
        virtual void sprawdz(int aX);
        virtual void zmien_rozmiar(long long aRoz);

};



#endif // SITOVECTOR_H_INCLUDED
