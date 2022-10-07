
#pragma once

#include <mrui/types.hpp>

namespace mrui
{
/// @brief Represents a 2D coordinate
/// Precision is guided by unit precision
/// Normalized floats are compressed as half
struct coord
{
  inline constexpr auto operator<=>(coord const&) noexcept = default;

  inline constexpr coord() : x(min_V), y(min_V) {}
  inline constexpr coord(unit xv, unit yv) : x(xv), y(yv) {}
  inline constexpr coord(unit v) : x(v), y(v) {}
  inline constexpr coord(normf xv, normf yv)
      : x(static_cast<unit>((float)xv * unit_range) + unit_min), y(static_cast<unit>((float)yv * unit_range) + unit_min)
  {}
  inline constexpr coord(normf v)
  {
    x = y = static_cast<unit>((float)xv * unit_range) + unit_min;
  }

  inline constexpr coord const& operator+=(coord const& c) noexcept
  {
    x += c.x;
    y += c.y;
    return *this;
  }

  inline constexpr coord const& operator-=(coord const& c) noexcept
  {
    x -= c.x;
    y -= c.y;
    return *this;
  }

  inline constexpr coord operator+(coord const& c) noexcept
  {
    return coord{x + c.x, y + c.y};
  }

  inline constexpr coord operator-(coord const& c) noexcept
  {
    return coord{x - c.x, y - c.y};
  }

  inline constexpr coord const& operator*=(coord const& c) noexcept
  {
    x *= c.x;
    y *= c.y;
    return *this;
  }

  inline constexpr coord const& operator/=(coord const& c) noexcept
  {
    x /= c.x;
    y /= c.y;
    return *this;
  }

  inline constexpr coord operator*(coord const& c) noexcept
  {
    return coord{x * c.x, y * c.y};
  }

  inline constexpr coord operator/(coord const& c) noexcept
  {
    return coord{x / c.x, y / c.y};
  }

  inline static constexpr unit  max_v   = unit_max;
  inline static constexpr unit  min_v   = unit_min;
  inline static constexpr unit  range_v = unit_max - unit_min;
  inline static constexpr coord max     = coord{unit_max};
  inline static constexpr coord min     = coord{unit_min};

  unit x = 0;
  unit y = 0;
};

} // namespace mrui