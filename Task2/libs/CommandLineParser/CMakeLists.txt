set(LIBRARY_NAME CommandLineParser)
set(LIBRARY_HEADERS_DIR include)
set(LIBRARY_HEADERS include/commandLineParser.h)
set(LIBRARY_SOURCE src/commandLineParser.cpp)

set(Boost_INCLUDE_DIR C:/Users/Yana228/boost_1_80_0)
set(Boost_LIBRARY_DIR C:/Users/Yana228/boost_1_80_0/stage/lib)

FIND_PACKAGE(Boost 1.80.0)

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_HEADERS} ${LIBRARY_SOURCE})
target_include_directories(${LIBRARY_NAME} PUBLIC ${LIBRARY_HEADERS_DIR})
target_link_libraries(${LIBRARY_NAME} PUBLIC ${LINK_LIBRARY} ${Boost_LIBRARIES})

