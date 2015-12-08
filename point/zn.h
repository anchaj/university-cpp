#ifndef ZN_h
#define ZN_h


class Zn{
public:
    Zn(int a, int n);
    int getN() const;
    int getLiczba() const;

    friend const Zn& operator++(Zn&);
    friend const Zn& operator++(Zn&,int);
    friend Zn operator+(const Zn&,const Zn&);
    operator int() { return liczba;}
private:
    const int n;
    int liczba;
};
#endif // Polynomial_h

