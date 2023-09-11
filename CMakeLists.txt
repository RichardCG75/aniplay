cmake_minimum_required(VERSION 3.18)

project(aniplay)

add_executable(aniplay aniplay.c)

# Find GTK4 using pkg-config
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)

# Add include directories and compiler options
target_include_directories(aniplay PRIVATE ${GTK4_INCLUDE_DIRS})
target_compile_options(aniplay PRIVATE ${GTK4_CFLAGS_OTHER})

# Link against GTK4 libraries
target_link_libraries(aniplay PRIVATE ${GTK4_LIBRARIES})