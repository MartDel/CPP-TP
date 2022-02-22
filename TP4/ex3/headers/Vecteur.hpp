#include "Point2D.hpp"

class Vecteur {
    private:
        float x, y;

    public:
        Vecteur(const Point2D&, const Point2D&);
        float getX() const { return x; }
        void setX(const float& _x) { x = _x; }
        float getY() const { return y; }
        void setY(const float& _y) { y = _y; }

        void print(const string&) const;

        bool operator==(const Vecteur&) const;
        Vecteur operator+(const Vecteur&) const;
        Vecteur operator*(const float&) const;
};
