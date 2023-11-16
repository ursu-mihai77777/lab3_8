#include <iostream>
using namespace std;

class Results
{
    float x1;
    float x2;

public:
    Results(float x1, float x2)
    {
        this->x1 = x1;
        this->x2 = x2;
    }

    float getX1() { return this->x1; };
    float getX2() { return this->x2; };
};

class Equation2
{
    float a;
    float b;
    float c;

public:
    Equation2(float a, float b, float c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    Results* solve()
    {
        const float delta = (b * b) - (4 * a * c);
        if (delta < 0) return NULL;
        const float x1 = (-b + sqrt(delta)) / (2 * a);
        const float x2 = (-b - sqrt(delta)) / (2 * a);
        return new Results(x1, x2);
    }
};

int main()
{
    Equation2* equation2 = new Equation2(3, -4, 1);

    Results* results = equation2->solve();
    if (!results)
    {
        cout << "There are no solutions for X";
        return -1;
    }
    cout << "x1=" <<results->getX1() << endl;
    cout << "x2=" << results->getX2();
    return 0;
}
