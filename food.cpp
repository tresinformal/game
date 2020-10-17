#include "food.h"
#include <cassert>
#include <cmath>

food::food(const double x, const double y, const color &c)
    : f_x{x}, f_y{y}, m_color{c}
{
}

double food::get_x() const noexcept { return f_x; }
double food::get_y() const noexcept { return f_y; }

void test_food()
{

  {
    food f;
    assert(f.get_x() == 0.0);
    assert(f.get_y() == 0.0);
  }

  {
    food f{1.0,2.0};
    assert(f.get_x() == 1.0);
    assert(f.get_y() == 2.0);
  }

  // X and Y work as expected
  {
    const double x{12.34};
    const double y{23.45};
    const food f(x, y);
    assert(std::abs(f.get_x() - x) < 0.00001);
    assert(std::abs(f.get_y() - y) < 0.00001);
  }
}
