add_library(strategy INTERFACE)
target_include_directories(strategy INTERFACE include/strategy)

add_library(strategyFactory STATIC src/strategyFactory.cpp)

target_include_directories(
        strategyFactory PUBLIC
        include/strategyFactory
        include/strategy
        ${CMAKE_SOURCE_DIR}/libs/Matrix/include/matrix)

set(STRATEGIES
        alwaysCooperate
        alwaysDefect
        softGrudger
        pavlov
        random
        titForTat
        )

foreach(STRATEGY ${STRATEGIES})
    add_library(${STRATEGY} STATIC
            src/${STRATEGY}.cpp)
    target_include_directories(${STRATEGY} PUBLIC
            include/${STRATEGY}
            include/strategy)
    target_link_libraries(${STRATEGY}
            INTERFACE strategy)
    target_include_directories(strategyFactory PUBLIC
            include/${STRATEGY})
endforeach(STRATEGY)

target_link_libraries(strategyFactory
        PUBLIC Matrix
        PUBLIC ${STRATEGIES}
        INTERFACE strategy)

set(Boost_INCLUDE_DIR c:/mingw/include/)
set(Boost_LIBRARY_DIR c:/mingw/lib/)
find_package(Boost COMPONENTS container REQUIRED)
target_include_directories(pavlov PUBLIC  ${Boost_INCLUDE_DIR})

target_link_libraries(pavlov PUBLIC strategyFactory)
target_link_libraries(pavlov PUBLIC  ${Boost_LIBRARIES})

####### GOOGLE TESTS ##################################################################################
set(TEST_LIBRARY_NAME strategy_tests)
set(TEST_SOURCE test/strategy_tests.cpp)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(${TEST_LIBRARY_NAME} ${TEST_SOURCE})
target_link_libraries(${TEST_LIBRARY_NAME} gtest_main ${LIBRARY_NAME})

