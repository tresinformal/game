#include "action_type.h"
#include<assert.h>
void test_action_type()
{
  assert(to_str_act_type(action_type::turn_left) != to_str_act_type(action_type::turn_right));
  assert(to_str_act_type(action_type::accelerate) != to_str_act_type(action_type::brake));
}

const std::string to_str_act_type(action_type this_action_type){

    switch (this_action_type)
{
    case action_type::turn_left:   return "turn_left";
    case action_type::turn_right:   return "turn_right";
    case action_type::accelerate:   return "accelerate";
    case action_type::brake:   return "brake";
}
}