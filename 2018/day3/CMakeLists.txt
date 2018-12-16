set(SOURCE_FILES fabric_map.hh fabric_map.cc fabric_claim.cc fabric_claim.hh)

add_executable(fabric_map_tests fabric_map_tests.cc ${SOURCE_FILES})
add_executable(fabric_claim_tests fabric_claim_tests.cc ${SOURCE_FILES})

add_executable(day3_part1 part1.cc ${SOURCE_FILES})
add_executable(day3_part2 part2.cc ${SOURCE_FILES})
