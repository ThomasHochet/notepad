cmake_minimum_required(VERSION 3.24)
project(notepad)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")

set(SDL2_INCLUDE_DIR SDL2/include)
set(SDL2_LIB_DIR SDL2/lib/x64)

set(IMGUI_SOURCES
        imgui/imgui.h
        imgui/imgui.cpp
        imgui/imgui_demo.cpp
        imgui/imgui_draw.cpp
        imgui/imgui_tables.cpp
        imgui/imgui_widgets.cpp
        imgui/imgui_impl_opengl3.h
        imgui/imgui_impl_opengl3_loader.h
        imgui/imgui_impl_opengl3.cpp
        imgui/imgui_impl_sdl2.h
        imgui/imgui_impl_sdl2.cpp)

set(PROJECTS_SOURCES
        Notepad/menu/Menu.cpp Notepad/menu/Menu.h Notepad/Notepad.cpp Notepad/Notepad.h Notepad/Textarea/Textarea.cpp Notepad/Textarea/Textarea.h)

# Add include directories for SDL2 and ImGui
include_directories(${SDL2_INCLUDE_DIR} imgui)

# Link SDL2 library directories
link_directories(${SDL2_LIB_DIR})

# Create a library for ImGui
add_library(imgui STATIC ${IMGUI_SOURCES})

# Add executable for your project
add_executable(notepad main.cpp ${PROJECTS_SOURCES})

# Link the ImGui library and SDL2 to the appSomething executable
target_link_libraries(notepad imgui SDL2main SDL2 opengl32)
