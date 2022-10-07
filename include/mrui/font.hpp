
#pragma once

#include <mrui/atlas.hpp>
#include <mrui/rect.hpp>
#include <acl/sparse_vector.hpp>

namespace mrui
{

class font
{
public:
  using link = mrui::link<font>;
private:

  struct glyph_traits
  {
    using size_type                              = std::uint32_t;
    static constexpr std::uint32_t pool_size     = 4096;
    static constexpr std::uint32_t idx_pool_size = 4096;
    static constexpr bool          assume_pod_v  = true;
  };

  using glyph_advance_table = acl::sparse_vector<unit, default_allocator<>, glyph_traits>;
  using glyph_rect_table = acl::sparse_vector<rect, default_allocator<>, glyph_traits>;
  atlas_l atlas;
  // Code point to glyph mapping
  glyph_advance_table advances;
  glyph_rect_table    uvs;
};

using font_l = font::link;
}