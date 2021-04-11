#ifndef CSITO_H_INCLUDED
#define CSITO_H_INCLUDED

//Klasa abstrakcyjna

class cPunkt
{
    public:
        int mIndeks;
        bool mCzyWykreslone = false;

    public:
        void wykresl()
        {
            mCzyWykreslone = true;
        };

        int getIndeks()const
        {
            return mIndeks;
        }

        bool getCzyWykreslone() const
        {
            return mCzyWykreslone;
        }

        void setIndeks(int i)
        {
            mIndeks = i;
        }
};

class cSitoAbstrakcyjne
{
    protected:
        long long mRozmiar;
        bool mCzyOdsiane = false; //zapobiega wyswietleniu przed odsianiem

    public:
        virtual void odsiej()= 0;
        virtual void wyswietl() const = 0;
        virtual void sprawdz(int aX) = 0;
        virtual void zmien_rozmiar(long long aRoz) = 0;

};

#endif // CSITO_H_INCLUDED
