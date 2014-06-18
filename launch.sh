#! /bin/bash

rosservice call /physical_calculator/create_world "test"
rosservice call /physical_calculator/create_robot "miew" "ressources/stl/robot1.stl" 20.0 [0,10,0]
