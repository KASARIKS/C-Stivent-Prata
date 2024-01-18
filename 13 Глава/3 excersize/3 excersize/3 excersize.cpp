#include <iostream>
#include "DMA.h"

int main()
{
    using namespace DMA;
    using std::cout;
    using std::endl;

    baseDMA shirt("Portabelly", 8);
    lacksDMA ballon("red", "Blimpo", 4);
    hasDMA map("Mercator", "Buffalo Keys", 5);
    cout << shirt << endl;
    cout << ballon << endl;
    cout << map << endl;
    lacksDMA ballon2(ballon);
    hasDMA map2;
    map2 = map;
    cout << ballon2 << endl;
    cout << map2 << endl;
}
