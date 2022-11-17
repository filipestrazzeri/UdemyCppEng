#include <cstring>
#include <iostream>
#include <numeric>

#include "AdFunctions.hpp"
#include "AdTypes.hpp"

int main()
{
    auto ego_vehicle = Ad::Data::init_ego_vehicle();
    Ad::Visualize::print_vehicle(ego_vehicle);

    return 0;
}
