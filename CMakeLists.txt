cmake_minimum_required(VERSION 3.17)
project(CPP_YANDEX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

add_executable(main main.cpp)

add_executable(CPP_YANDEX
#        main.cpp
#        white_belt/1_week/train_exercise/even_numbers.cpp
#        white_belt/1_week/train_exercise/second_occurence.cpp
#        white_belt/1_week/greatest_common_divisor.cpp
#        white_belt/1_week/binary_numbers.cpp
#        white_belt/2_week/train_exercise/factorial.cpp
#        white_belt/2_week/train_exercise/palindrome.cpp
#        white_belt/2_week/train_exercise/selection_palindromes.cpp
#        white_belt/2_week/train_exercise/maximizer.cpp
#        white_belt/2_week/train_exercise/move_strings.cpp
#        white_belt/2_week/train_exercise/sequence_reversal.cpp
#        white_belt/2_week/train_exercise/sequence_reversal_2.cpp
#        white_belt/2_week/train_exercise/average_temperature.cpp
#        white_belt/2_week/queueing.cpp
#        white_belt/2_week/monthly_affairs.cpp
#        white_belt/2_week/map/train_exercise/anagrams.cpp
#        white_belt/2_week/map/train_exercise/directory_capitals.cpp
#        white_belt/2_week/map/bus_stops_1.cpp
#        white_belt/2_week/map/bus_stops_2.cpp
#        white_belt/2_week/set/train_exercise/number_unique_rows.cpp
#        white_belt/2_week/set/train_exercise/set_map_values.cpp
#        white_belt/2_week/set/synonyms.cpp
#        white_belt/2_week/set/bus_stops_3.cpp
#        white_belt/3_week/algorithms/sorting_integers_modulo.cpp
#        white_belt/3_week/algorithms/case_insensitive_sorting.cpp
#        white_belt/3_week/structures_and_classes/train_exercise/sorted_strings.cpp
#        white_belt/3_week/structures_and_classes/first_and_last_names_1.cpp
#        white_belt/3_week/structures_and_classes/first_and_last_names_2.cpp
#        white_belt/3_week/constructors/train_exercise/string.cpp
#        white_belt/3_week/constructors/first_and_last_names_3.cpp
#        white_belt/3_week/constructors/Initialization_methods.cpp
        white_belt/4_week/structures_and_classes/struct_LectureTitle.cpp)

add_executable(bus_stops_1 white_belt/2_week/map/bus_stops_1.cpp)

add_executable(reversFunction white_belt/4_week/structures_and_classes/reversFunction.cpp)
add_executable(reversFunctionWithOthersOperat white_belt/4_week/structures_and_classes/reversFunctionWithOthersOperat.cpp)
add_executable(filestreamPart1 white_belt/4_week/structures_and_classes/filestreamPart1.cpp)
add_executable(filestreamPart2 white_belt/4_week/structures_and_classes/filestreamPart2.cpp)
add_executable(AccurateOutput white_belt/4_week/structures_and_classes/accurateOutput.cpp)
add_executable(readAndOutTable white_belt/4_week/structures_and_classes/readAndOutTable.cpp)
add_executable(listStudents white_belt/4_week/structures_and_classes/listStudents.cpp)
add_executable(rational_interface white_belt/4_week/operator_overloading/01/rational_interface.cpp)
add_executable(rational_eq_add_sub white_belt/4_week/operator_overloading/02/rational_eq_add_sub.cpp)
add_executable(rational_mult_div white_belt/4_week/operator_overloading/03/rational_mult_div.cpp)
add_executable(rational_io white_belt/4_week/operator_overloading/04/rational_io.cpp)
add_executable(rational_map white_belt/4_week/operator_overloading/05/rational_map.cpp)
add_executable(EnsureEqual white_belt/4_week/throw/EnsureEqual.cpp)
add_executable(rational_throw white_belt/4_week/throw/rational_throw.cpp)
add_executable(Calculator_of_ordinary_fractions white_belt/4_week/throw/Calculator_of_ordinary_fractions.cpp)
add_executable(TimeServer white_belt/4_week/throw/TimeServer.cpp)
add_executable(solution white_belt/5_week/solution.cpp)
add_executable(Matrix yellow_belt/1_week/test_white_belt/Matrix.cpp)
add_executable(average_temperature_2 yellow_belt/1_week/Integer_types/average_temperature_2.cpp)
add_executable(block_weight yellow_belt/1_week/Integer_types/block_weight.cpp)
add_executable(base_regions yellow_belt/1_week/tuples_and_pairs/base_regions.cpp)
add_executable(task_tracker yellow_belt/1_week/tuples_and_pairs/task_tracker.cpp)
add_executable(sqrt_all yellow_belt/1_week/temlate_func/sqrt_all.cpp)
add_executable(GetRefStrict yellow_belt/1_week/temlate_func/GetRefStrict.cpp)
add_executable(decom_bus_stops_1 yellow_belt/2_week/decom_bus_stops_1.cpp)
add_executable(test_equation yellow_belt/2_week/test_equation.cpp)
add_executable(test_rational yellow_belt/2_week/test_rational.cpp)
add_executable(test_palindrome yellow_belt/2_week/test_palindrome.cpp)
