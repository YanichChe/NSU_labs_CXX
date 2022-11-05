set(LIBRARY_NAME CommandLineParser)
set(LIBRARY_HEADERS_DIR include)
set(LIBRARY_HEADERS include/commandLineParser.h)
set(LIBRARY_SOURCE src/commandLineParser.cpp)

set(BOOST_INCLUDE_LIBRARIES thread filesystem system program_options)
set(BOOST_ENABLE_CMAKE ON)

message(STATUS "Start download boost")
include(FetchContent)
FetchContent_Declare(
        Boost
        URL https://codeload.github.com/boostorg/boost/zip/refs/heads/master
        GIT_TAG boost-1.80.0
)
FetchContent_MakeAvailable(Boost)
message(STATUS "End download boost")

target_link_libraries(${LIBRARY_NAME} PRIVATE Boost::filesystem Boost::program_options)

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_HEADERS} ${LIBRARY_SOURCE})
target_include_directories(${LIBRARY_NAME} PUBLIC ${LIBRARY_HEADERS_DIR})
target_link_libraries(${LIBRARY_NAME} PUBLIC ${LINK_LIBRARY})

