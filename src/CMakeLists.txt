# Collect all cpp files in src/
file(GLOB SRC_FILES *.cpp)

# Create the executable with all source files
add_executable(
    ${PROJECT_NAME} 
    ${SRC_FILES}
    ${CMAKE_SOURCE_DIR}/include/VideoWidget.h
    ${CMAKE_SOURCE_DIR}/include/Landing.h
)

# Include headers
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)

# Link libraries
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Qt6::Widgets
        opencv::opencv
)
