#include "../../src/coordinator/coordinator.hpp"

/*
  This robot code create one device ( so one module in sasiae ) 
  and transfers messages to GUI passing by coordinator in order to test :
  - a module send a message to the robot code which tranfers it to the 
  appropriate device.
  - a device send a message to the coordinator which tranfers it to the 
  appropriate module.
  - these changes are visible in the physical world ( _scene ).

FIRST : acceleration ordered by robot code to a device.
  
 */

