
#pragma once
#include <span>
#include <cstddef>
#include <mrui/rect.hpp>

namespace mrui
{

struct image
{
  using link = mrui::link<image>;
  rect region;
};

using image_l = image::link;

enum class format
{
  gray,
  rgba
};

class atlas
{
public:
  
  using link = mrui::link<atlas>;

  /// @brief Add an image to the atlast but discard the image specific info
  /// @param size The size of the image
  /// @param data Image pixel data
  /// @return Image rectangle
  image add(coord size, std::span<uint8_t const> data);
  /// @brief Add an image to the atlas and store its region information
  /// @remarks The image info can be later retrieved by the image link from context
  /// @param size Image size
  /// @param data Image pixel data
  /// @return Image link
  image::link add_named_image(coord size, std::span<uint8_t const> data);

private:
  /// @brief Self link
  link self;
  /// @brief Named images
  std::vector<image> images;
  /// @brief atlas pixel format
  format             pixel_format;
};
using atlas_l = atlas::link;
} // namespace mrui