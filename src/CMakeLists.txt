set(HEADERS "${CMAKE_SOURCE_DIR}/include/attacks.hpp" "${CMAKE_SOURCE_DIR}/include/bitboard.hpp")

add_library(dumm_lib attacks.cpp ${HEADERS})

target_include_directories(dumm_lib PUBLIC ../include)

target_compile_features(dumm_lib PUBLIC cxx_std_17)
target_compile_options(dumm_lib PUBLIC -Wall -Wextra -pedantic)
