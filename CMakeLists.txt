cmake_minimum_required(VERSION 3.0)

project(leftCtrl2shiftCtrl)

add_executable(leftCtrl2shiftCtrl leftCtrl2shiftCtrl.c)
target_compile_options(leftCtrl2shiftCtrl PRIVATE -Wall -Wextra)

install(TARGETS leftCtrl2shiftCtrl RUNTIME DESTINATION bin)
