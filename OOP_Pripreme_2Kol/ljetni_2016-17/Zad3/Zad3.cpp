/*. (10) Napišite interface za geometrijski lik te implementaciju za krug i kvadrat. U programu u listu pointera
na lik stavite jedan krug i jedan kvadrat i pozovite funkciju koja ispisuje ukupnu površinu svih likova.
Obavezno obrisati sve alocirane objekte.
*/
#include <iostream>
#include <algorithm>
using namespace std;
class Geometry {
public:
    virtual double surface() = 0;
};
class Circle : public Geometry {
    double r;
    const double pi = 3.14;
public:
    Circle(double rad) {
        r = rad;
    }
    double surface() {
        return(pow(r,2.0) * pi);
    }
};
class Square : public Geometry{
    double a;
public:
    Square(double a) {
        this->a = a;
    }
    double surface(){
        return pow(a, 2.0);
    }
};
int main()
{
    Geometry* lst[] = { new Circle(2.4), new Square(5.7)};
    double size = 0;
    for (auto el : lst) {
        size += el->surface();
    }
    cout << size << endl;
    for (auto el : lst) {
        delete el;
    }
}
