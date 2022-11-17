#include <cmath>
#include <cstdint>
#include <iostream>

#include "AdConstants.h"
#include "AdFunctions.h"

namespace
{
void init_vehicle(Ad::Types::VehicleType &vehicle,
                  const std::int32_t id,
                  const float speed_kph,
                  const float distance_m,
                  const Ad::Types::LaneAssociationType lane)
{
    vehicle.id = id;
    vehicle.speed_mps = Ad::Utils::kph_to_mps(speed_kph);
    vehicle.distance_m = distance_m;
    vehicle.lane = lane;
}
} // namespace

namespace Ad
{

namespace Utils
{

float kph_to_mps(const float kph)
{
    return kph / 3.6F;
}

} // namespace Utils

namespace Data
{

Ad::Types::VehicleType init_ego_vehicle()
{
    return Ad::Types::VehicleType{
        .id = Ad::Constants::EGO_VEHICLE_ID,
        .lane = Ad::Types::LaneAssociationType::CENTER,
        .speed_mps = Ad::Utils::kph_to_mps(135.0F),
        .distance_m = 0.0F,
    };
}

Ad::Types::NeighborVehiclesType init_vehicles()
{
    auto vehicles = Ad::Types::NeighborVehiclesType{};

    init_vehicle(vehicles.vehicles_left_lane[0],
                 0,
                 130.0F,
                 80.0F,
                 Ad::Types::LaneAssociationType::LEFT);
    init_vehicle(vehicles.vehicles_left_lane[1],
                 1,
                 80.0F,
                 -20.0F,
                 Ad::Types::LaneAssociationType::LEFT);
    init_vehicle(vehicles.vehicles_center_lane[0],
                 2,
                 80.0F,
                 50.0F,
                 Ad::Types::LaneAssociationType::CENTER);
    init_vehicle(vehicles.vehicles_center_lane[1],
                 3,
                 120.0F,
                 -50.0F,
                 Ad::Types::LaneAssociationType::CENTER);
    init_vehicle(vehicles.vehicles_right_lane[0],
                 4,
                 110.0F,
                 30.0F,
                 Ad::Types::LaneAssociationType::RIGHT);
    init_vehicle(vehicles.vehicles_right_lane[1],
                 5,
                 90.0F,
                 -30.0F,
                 Ad::Types::LaneAssociationType::RIGHT);

    return vehicles;
}

} // namespace Data

namespace Visualize
{

void print_vehicle(const Ad::Types::VehicleType vehicle)
{
    std::cout << "ID: " << vehicle.id << '\n';
    std::cout << "Speed (m/s): " << vehicle.speed_mps << '\n';
    std::cout << "Distance (m): " << vehicle.distance_m << '\n';
    std::cout << "Lane: " << static_cast<std::int32_t>(vehicle.lane) << '\n';
}

void print_neighbor_vehicles(const Ad::Types::NeighborVehiclesType &vehicles)
{
    print_vehicle(vehicles.vehicles_left_lane[0]);
    print_vehicle(vehicles.vehicles_left_lane[1]);
    print_vehicle(vehicles.vehicles_center_lane[0]);
    print_vehicle(vehicles.vehicles_center_lane[1]);
    print_vehicle(vehicles.vehicles_right_lane[0]);
    print_vehicle(vehicles.vehicles_right_lane[1]);
}

void print_scene(const Ad::Types::VehicleType &ego_vehicle,
                 const Ad::Types::NeighborVehiclesType &vehicles)
{
    std::cout << "    \t   L     C     R  \n";

    auto left_idx = std::size_t{0};
    auto center_idx = std::size_t{0};
    auto right_idx = std::size_t{0};

    const auto offset_m = std::uint32_t{20};
    const auto view_range_m =
        static_cast<std::int32_t>(Ad::Constants::VIEW_RANGE_M);

    for (auto i = view_range_m; i >= -view_range_m; i -= offset_m)
    {
        const auto range_m = static_cast<float>(i);

        const auto *left_vehicle =
            (left_idx < Ad::Constants::NUM_VEHICLES_ON_LANE)
                ? &vehicles.vehicles_left_lane[left_idx]
                : nullptr;
        const auto *center_vehicle =
            (center_idx < Ad::Constants::NUM_VEHICLES_ON_LANE)
                ? &vehicles.vehicles_center_lane[center_idx]
                : nullptr;
        const auto *right_vehicle =
            (right_idx < Ad::Constants::NUM_VEHICLES_ON_LANE)
                ? &vehicles.vehicles_right_lane[right_idx]
                : nullptr;

        auto left_string = std::string{"   "};
        auto center_string = std::string{"   "};
        auto right_string = std::string{"   "};

        if ((range_m >= ego_vehicle.distance_m) &&
            (ego_vehicle.distance_m > (range_m - offset_m)))
        {
            center_string[1] = 'E';
        }

        if ((left_vehicle != nullptr) &&
            (range_m >= left_vehicle->distance_m) &&
            (left_vehicle->distance_m > (range_m - offset_m)))
        {
            left_string[1] = 'V';
            left_idx++;
        }
        else if ((left_vehicle != nullptr) &&
                 (std::abs(left_vehicle->distance_m) >
                  Ad::Constants::VIEW_RANGE_M))
        {
            left_idx++;
        }

        if ((center_vehicle != nullptr) &&
            (range_m >= center_vehicle->distance_m) &&
            (center_vehicle->distance_m > (range_m - offset_m)))
        {
            center_string[1] = 'V';
            center_idx++;
        }
        else if ((center_vehicle != nullptr) &&
                 (std::abs(center_vehicle->distance_m) >
                  Ad::Constants::VIEW_RANGE_M))
        {
            center_idx++;
        }

        if ((right_vehicle != nullptr) &&
            (range_m >= right_vehicle->distance_m) &&
            (right_vehicle->distance_m > (range_m - offset_m)))
        {
            right_string[1] = 'V';
            right_idx++;
        }
        else if ((right_vehicle != nullptr) &&
                 (std::abs(right_vehicle->distance_m) >
                  Ad::Constants::VIEW_RANGE_M))
        {
            right_idx++;
        }

        std::cout << i << "\t| " << left_string << " | " << center_string
                  << " | " << right_string << " | \n";
    }
}

} // namespace Visualize

} // namespace Ad
