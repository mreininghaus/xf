CMAKE_MINIMUM_REQUIRED(VERSION 3.17)

project(xf LANGUAGES C VERSION 0.1)

include(GNUInstallDirs)

add_executable(xf main.c)
target_compile_definitions(xf PRIVATE "_GNU_SOURCE")

install(TARGETS xf)
include(CPack)
