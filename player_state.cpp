#include "player_state.h"
#include <cassert>
#include <sstream>

std::string to_str(player_state this_player_state)
{
  switch (this_player_state)
  {
  case player_state::dead:
    return "dead";
  case player_state::stunned:
    return "stunned";

  default:
    assert(this_player_state == player_state::active);
    return "active";
  }
}


void test_player_state()
{
  #ifndef NDEBUG // no tests in release
  assert(player_state::active != player_state::stunned);
  {
    assert(player_state::dead != player_state::stunned &&
              player_state::dead != player_state::active);
  }




  #define FIX_ISSUE_276
  #ifdef FIX_ISSUE_276
  // Conversion to string
  {
    assert(to_str(player_state::active) == "active");
    assert(to_str(player_state::dead) == "dead");
    assert(to_str(player_state::stunned) == "stunned");
  }
  #endif // FIX_ISSUE_276
  #endif
}
