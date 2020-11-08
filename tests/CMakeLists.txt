add_executable(run_tests test_main.cpp attacks.cpp bitboard.cpp)
target_link_libraries(run_tests dumm_lib)

target_compile_features(run_tests PUBLIC cxx_std_17)
target_compile_options(run_tests PUBLIC -Wall -Wextra -pedantic)

add_test(NAME tests COMMAND run_tests)