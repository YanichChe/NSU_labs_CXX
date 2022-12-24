set(LIBRARY_NAME commandLineParser)
set(LIBRARY_HEADERS_DIR include)
set(LIBRARY_HEADERS include/commandLineParser.h)
set(LIBRARY_SOURCE src/commandLineParser.cpp)

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_HEADERS} ${LIBRARY_SOURCE})
target_include_directories(${LIBRARY_NAME} PUBLIC ${LIBRARY_HEADERS_DIR})

target_link_libraries(${LIBRARY_NAME} PUBLIC ${LINK_LIBRARY} )

##### BOOST SETTINGS ######################################################

set(Boost_INCLUDE_DIR c:/mingw/include/)
set(Boost_LIBRARY_DIR c:/mingw/lib/)
find_package(Boost COMPONENTS program_options REQUIRED)
target_include_directories(${LIBRARY_NAME} PUBLIC  ${Boost_INCLUDE_DIR})
target_link_libraries(${LIBRARY_NAME} ${Boost_LIBRARIES})