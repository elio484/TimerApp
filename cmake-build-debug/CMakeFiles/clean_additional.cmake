# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/TimerApp_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/TimerApp_autogen.dir/ParseCache.txt"
  "CMakeFiles/TimerTests_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/TimerTests_autogen.dir/ParseCache.txt"
  "TimerApp_autogen"
  "TimerTests_autogen"
  )
endif()
