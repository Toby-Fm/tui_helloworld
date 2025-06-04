cmake_minimum_required(VERSION 3.31)
project(tui_helloworld)

set(CMAKE_CXX_STANDARD 20)

# --- Fetch FTXUI --------------------------------------------------------------
include(FetchContent)

set(FETCHCONTENT_UPDATES_DISCONNECTED ON)
set(FETCHCONTENT_QUIET OFF)

FetchContent_Declare(ftxui
    GIT_REPOSITORY https://github.com/arthursonzogni/ftxui.git
    GIT_TAG        v5.0.0
    GIT_PROGRESS   TRUE
    GIT_SHALLOW    TRUE
    EXCLUDE_FROM_ALL
)
FetchContent_MakeAvailable(ftxui)
# ------------------------------------------------------------------------------

add_executable(tui_helloworld src/main.cpp)
target_include_directories(tui_helloworld PRIVATE src)

target_link_libraries(tui_helloworld
    PRIVATE ftxui::screen
    PRIVATE ftxui::dom
)