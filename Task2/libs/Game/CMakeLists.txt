set(LIBRARY_NAME Game)
set(LIBRARY_HEADERS_DIR include)
set(LIBRARY_HEADERS include/game.h)
set(LIBRARY_SOURCE src/game.cpp)

set(TEST_LIBRARY_NAME game_tests)
set(TEST_SOURCE test/game_tests.cpp)

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_HEADERS} ${LIBRARY_SOURCE})
target_include_directories(${LIBRARY_NAME} PUBLIC ${LIBRARY_HEADERS_DIR} ${CMAKE_BINARY_DIR}/libs/Mode ${CMAKE_BINARY_DIR}/libs/GameData
        ${CMAKE_BINARY_DIR}/libs/CommandLineParser)

target_link_directories(${LIBRARY_NAME} PUBLIC  ${CMAKE_BINARY_DIR}/libs/Mode ${CMAKE_BINARY_DIR}/libs/GameData ${CMAKE_BINARY_DIR}/libs/CommandLineParser)
target_link_libraries(${LIBRARY_NAME} PUBLIC Mode GameData CommandLineParser)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(${TEST_LIBRARY_NAME} ${TEST_SOURCE})
target_link_libraries(${TEST_LIBRARY_NAME} gtest_main ${LIBRARY_NAME})