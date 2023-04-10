#include <cmath>
#include <cstdint>
#include <iostream>

#include "AdConstants.h"
#include "AdFunctions.h"


float Ad::Utils::kph_to_mps(const float kph)

{
    return kph / 3.6F;
}


Ad::Types::VehicleType Ad::Data::init_ego_vehicle()
{

    const auto ego_vehicle = Ad::Types::VehicleType{.id =(int32_t)(Ad::Constants::EGO_VEHICLE_ID),
                                            .lane = (Ad::Types::LaneAssociationType::CENTER),
                                            .speed = Ad::Utils::kph_to_mps(135.0F),
                                            .distance = 0.0F};
    return ego_vehicle;
}


void Ad::Visualize::print_vehicle(const Ad::Types::VehicleType vehicle)
{
    std::cout << "ID: " << vehicle.id << '\n';
    std::cout << "Speed (m/s): " << vehicle.speed << '\n';
    std::cout << "Distance (m): " << vehicle.distance << '\n';
    std::cout << "Lane: " << static_cast<std::int32_t>(vehicle.lane) << '\n';

}
