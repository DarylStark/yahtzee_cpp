#include <iostream>
#include "yahtzee/dieset.h"

int main()
{
    int turns = 0;
    int lowest = 999;
    int highest = 0;
    double total = 0;
    for (int z = 0; z < 1000; z++)
    {
        yahtzee::DieSet x;
        for (int j = 0; j < 500; j++)
        {
            x.roll();
            for (int i = 0; i < 5; i++)
            {
                if (x[i].get_last_value() == 3)
                {
                    x.lock(i);
                }
            }
            if (x.get_specific_count(3) == 5)
            {
                total += j + 1;
                turns++;
                if (j + 1 > highest)
                    highest = j + 1;
                if (j + 1 < lowest)
                    lowest = j + 1;
                break;
            }
        }
    }

    std::cout << "Turns:   " << turns << std::endl;
    std::cout << "Total:   " << total << std::endl;
    std::cout << "Mean:    " << (total / turns) << std::endl;
    std::cout << "Lowest:  " << lowest << std::endl;
    std::cout << "Highest: " << highest << std::endl;

    return 0;
}