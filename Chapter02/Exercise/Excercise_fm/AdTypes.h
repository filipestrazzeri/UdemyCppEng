#pragma once

#include <cstdint>

#include "AdConstants.h"


// Namespace: Ad::Types
namespace Ad
{

namespace Types
{

    enum class LaneAssociationType
    {
        UNKNOWN,
        LEFT,
        CENTER,
        RIGHT

    };

    struct VehicleType
    {
        std::int32_t id;
        LaneAssociationType lane;
        float speed = {}; // meters p/s
        float distance = {}; // meters

    };


} // namespace Ad
} // namespace Types
