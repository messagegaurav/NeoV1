cmake_minimum_required(VERSION 3.10)
project(NeoV1)

set(CMAKE_CXX_STANDARD 14)

# Add the include and src directories for header search paths
include_directories(${CMAKE_SOURCE_DIR}/include)

# List all source files except Main.cpp
set(SRC_FILES
    src/AbstractFactoryMethod.cpp
    src/AdapterDesign.cpp
    src/BuilderClass.cpp
    src/MoveCtr.cpp
    src/ObjectRelations.cpp
    src/ObserverPattern.cpp
    src/SingletonPattern.cpp
    src/timer.cpp
)

# Create a directory for libraries if it doesn't exist
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/library)
file(MAKE_DIRECTORY ${LIBRARY_OUTPUT_PATH})

# Build a shared library and place it in the library folder
add_library(designPatternlib SHARED ${SRC_FILES})
set_target_properties(designPatternlib PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${LIBRARY_OUTPUT_PATH}
)

# Build the main executable from Main.cpp
add_executable(main src/Main.cpp)

# Link the shared library to the main executable
target_link_libraries(main designPatternlib)

# Ensure the runtime linker can find the .so at runtime (for build/run in place)
set_target_properties(main PROPERTIES
    BUILD_RPATH ${LIBRARY_OUTPUT_PATH}
    INSTALL_RPATH ${LIBRARY_OUTPUT_PATH}
)




