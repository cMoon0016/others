#ifndef SITOSMARTPOINTER_H_INCLUDED
#define SITOSMARTPOINTER_H_INCLUDED

#include "sitoDynamiczne.h"
#include "cSito.h"
#include <memory>

class cSitoSmartPointer :public cSitoAbstrakcyjne
{
    private:
        std::shared_ptr<cPunkt[]> mPtr;


    public:
        explicit cSitoSmartPointer(long long aRoz);
        ~cSitoSmartPointer();
        virtual void odsiej();
        virtual void wyswietl() const;
        virtual void sprawdz(int aX);
        virtual void zmien_rozmiar(long long aRoz);

};


#endif // SITOSMARTPOINTER_H_INCLUDED
