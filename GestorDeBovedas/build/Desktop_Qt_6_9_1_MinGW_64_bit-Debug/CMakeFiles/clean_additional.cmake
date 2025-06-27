# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\GestorDeBovedas_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\GestorDeBovedas_autogen.dir\\ParseCache.txt"
  "GestorDeBovedas_autogen"
  )
endif()
