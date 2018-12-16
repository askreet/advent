set(SOURCE_FILES box_id.h)

include_directories(BEFORE ../libs/)

add_executable(day2_part1 part1.cc ${SOURCE_FILES})
add_executable(day2_part2 part2.cc ${SOURCE_FILES})
add_executable(box_id_test box_id_test.cc)