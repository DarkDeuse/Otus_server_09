cmake_minimum_required(VERSION 3.2) 


set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(server VERSION ${PROJECT_VESRION})
configure_file(version.h.in version.h)

add_executable(server main.cpp)
set_target_properties(server PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQIRED ON)
target_link_libraries(server PRIVATE boost_system
printer filePrinter consolePrinter libinterpret libasync clientServer )

add_subdirectory (${PROJECT_SOURCE_DIR}/libs)

if(MSVC)
	target_compile_options(server PRIVATE /W4)
else()
	target_compile_options(server PRIVATE -Wall -Wextra -Werror)
endif()



install(TARGETS server RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})

set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})

include(CPack)