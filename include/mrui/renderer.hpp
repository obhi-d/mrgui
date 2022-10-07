
#pragma once

#include <mrui/atlas.hpp>
#include <mrui/types.hpp>

namespace mrui
{

class draw
{
  uint32_t vertex_start = 0;
  uint32_t vertex_count = 0;
  image_l  image        = 0;
};

using draw_list = std::vector<draw>;

class renderer
{};

} // namespace mrui