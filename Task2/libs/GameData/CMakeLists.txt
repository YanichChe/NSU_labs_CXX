set(LIBRARY_NAME GameData)
set(LIBRARY_HEADERS_DIR include)
set(LIBRARY_HEADERS include/gameData.h)
set(LIBRARY_SOURCE src/gameData.cpp)

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_HEADERS} ${LIBRARY_SOURCE})
target_include_directories(${LIBRARY_NAME} PUBLIC ${LIBRARY_HEADERS_DIR} ${CMAKE_SOURCE_DIR}/libs/Matrix/include)

target_link_directories(${LIBRARY_NAME} PUBLIC  ${CMAKE_BINARY_DIR}/libs/Matrix)
target_link_libraries(${LIBRARY_NAME} PUBLIC Matrix)

