#pragma once

#include <cstdint>
#include <limits>
#include <mrui/config.hpp>
#include <cassert>
#include <cmath>

namespace mrui
{

using unit   = int16_t;

inline constexpr unit unit_max = std::numeric_limits<unit>::max();
inline constexpr unit unit_min = std::numeric_limits<unit>::min();
inline constexpr unit unit_range = unit_max - unit_min;

struct nocheck
{};

// Normalized float value
struct normf
{
  inline constexpr normf() = default;
  inline constexpr normf(float v) : value(std::clamp(v, 0.f, 1.f)) {}
  inline constexpr normf(float v, nocheck) : value(v) {}
  inline constexpr normf(unit v) : value((float)(v + unit_min) / (float)unit_range) {}

  inline constexpr operator float() const noexcept
  {
    return value;
  }

  inline constexpr normf max = 1.0f;
  inline constexpr normf min = 0.0f;

  float value = 0.0f;
};

template <typename T>
struct link
{
  constexpr link() noexcept = default;
  constexpr link(uint32_t v) noexcept : reserved(v) {}

  constexpr operator uint32_t() const noexcept
  {
    return reserved;
  }

  constexpr operator bool() const noexcept
  {
    return reserved != 0;
  }

  constexpr auto operator<=>(link const&) const noexcept = default;

  uint32_t reserved = 0;
};

} // namespace mrui