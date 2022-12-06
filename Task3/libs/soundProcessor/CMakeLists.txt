set(LIBRARY_NAME soundProcessor)
set(LIBRARY_HEADERS_DIR include)
set(LIBRARY_HEADERS include/soundProcessor.h)
set(LIBRARY_SOURCE src/soundProcessor.cpp)

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_HEADERS} ${LIBRARY_SOURCE})
target_include_directories(${LIBRARY_NAME} PUBLIC ${LIBRARY_HEADERS_DIR} ${CMAKE_SOURCE_DIR}/libs/WAV/include
        ${CMAKE_SOURCE_DIR}/libs/converter/include)
target_link_libraries(${LIBRARY_NAME} PUBLIC ${LINK_LIBRARY} WAV converter)
