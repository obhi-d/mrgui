#pragma once
#include <mrui/coord.hpp>

namespace mrui
{
  struct rect
  {
    constexpr inline coord center() const
    {
      return min + (size / 2);
    }

    coord min;
    coord size;
  };
}