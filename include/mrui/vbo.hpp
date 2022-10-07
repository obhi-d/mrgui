#include <mrui/coord.hpp>
#include <vector>

namespace mrui
{
struct vertex
{
  constexpr void translate(coord const by)
  {
    pos += by;
  }

  coord          pos;
  coord          uv;
};

class vbo
{
public:
private:

  std::vector<vertex> vertices;
};
} // namespace mrui