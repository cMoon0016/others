#ifndef CSITO_H_INCLUDED
#define CSITO_H_INCLUDED

//Klasa abstrakcyjna

class cPunkt
{
    public:
        int mIndeks;
        bool mCzyWykreslone = false;

    public:
        void wykresl();
        int getIndeks()const;
        bool getCzyWykreslone() const;
        void setIndeks(int i);

};

class cSitoAbstrakcyjne
{
    public:
        virtual void odsiej()= 0;
        virtual void wyswietl() const = 0;
        virtual void sprawdz(int aX) = 0;
        virtual void zmien_rozmiar(int aRoz) = 0;

};

void cPunkt::wykresl()
{
    mCzyWykreslone = true;
}

int cPunkt::getIndeks()const
{
    return mIndeks;
}

void cPunkt::setIndeks(int i)
{
    mIndeks = i;
}

bool cPunkt::getCzyWykreslone() const
{
    return mCzyWykreslone;
}


#endif // CSITO_H_INCLUDED
