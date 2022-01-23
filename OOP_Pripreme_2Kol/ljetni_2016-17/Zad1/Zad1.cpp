#include <algorithm>
#include "Header.h"
using namespace std;


int main()
{
    std::ostream_iterator < double > os(std::cout, ":");
    Array <double, 16> a(1);
    a[0] = a[1] = 3.14;
    std::copy(a.begin(), a.end(), os);
}


