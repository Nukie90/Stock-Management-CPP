cmake_minimum_required(VERSION 3.10)

project(Stock_management)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS SvgWidgets)
qt_standard_project_setup()

set(SOURCES
    main.cpp
    src/item.cpp
    src/product.cpp
    src/service.cpp
    src/storage.cpp
    src/invoice.cpp
)

add_executable(project ${SOURCES})

include_directories(include)


target_link_libraries(project PRIVATE Qt6::Widgets)
target_link_libraries(project PRIVATE Qt6::SvgWidgets)

set_target_properties(
    ${TARGETS}
    PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO)

foreach(T IN LISTS TARGETS)
    if (MSVC)
        target_compile_options(${T} PRIVATE /Wall /WX)
    else()
        target_compile_options(${T} PRIVATE -Wall -Wextra)
    endif()
endforeach()