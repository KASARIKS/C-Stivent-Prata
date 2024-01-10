#include <iostream>
#include "Stonewt.h"
#include <vector>

int main()
{
    const int count_stonewts = 6;
    std::vector<Stonewt> stonewts;
    stonewts.push_back(Stonewt(10, 8));
    stonewts.push_back(Stonewt(12, 2));
    stonewts.push_back(Stonewt(14, 4));

    Stonewt reference(11, 0);

    for (int i = 0; i < count_stonewts - 3; ++i) 
    {
        std::cout << "Input stonewt " << i + 1 << ": ";
        int stone;
        if (!(std::cin >> stone))
            stone = 0;
        stonewts.push_back(Stonewt(stone, 0));
    }

    int count_special_stonewts = 0;
    Stonewt max = stonewts[0];
    Stonewt min = stonewts[0];

    for (int i = 0; i < count_stonewts; ++i) {
        if (stonewts[i] >= reference)
            count_special_stonewts++;
        if (stonewts[i] > max)
            max = stonewts[i];
        if (stonewts[i] < min)
            min = stonewts[i];
    }

    std::cout << "Count of stonewts: " << count_special_stonewts << std::endl;
    max.show_lbs();
    min.show_lbs();
}