cmake_minimum_required(VERSION 3.21)
project(PGameMenu VERSION 0.0.1 LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)


add_executable(GameMenu main.cpp GameMenu.cpp GameMenu.h AssetManager.cpp AssetManager.h Animator.cpp Animator.h openal32.dll )


add_custom_command(TARGET GameMenu POST_BUILD
                   
                   COMMAND ${CMAKE_COMMAND}
                   ARGS -E copy_directory
                        ${PROJECT_SOURCE_DIR}/audio
                        $<TARGET_FILE_DIR:GameMenu>/audio
                   VERBATIM)
add_custom_command(TARGET GameMenu POST_BUILD                
                   COMMAND ${CMAKE_COMMAND}
                   ARGS -E copy_directory
                        ${PROJECT_SOURCE_DIR}/font
                        $<TARGET_FILE_DIR:GameMenu>/font
                   VERBATIM)
add_custom_command(TARGET GameMenu POST_BUILD                
                   COMMAND ${CMAKE_COMMAND}
                   ARGS -E copy_directory
                        ${PROJECT_SOURCE_DIR}/image
                        $<TARGET_FILE_DIR:GameMenu>/image
                   VERBATIM)
				   
add_custom_command(
  TARGET GameMenu POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy 
    ${PROJECT_SOURCE_DIR}/openal32.dll
    $<TARGET_FILE_DIR:GameMenu>/openal32.dll)

target_link_libraries(GameMenu PRIVATE sfml-graphics sfml-system sfml-window sfml-audio )

target_compile_features(GameMenu PRIVATE cxx_std_14)

if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET GameMenu POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:GameMenu> $<TARGET_FILE_DIR:GameMenu> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS GameMenu)

# Директория с СMakeLists.txt
# cmake -S . -B build
# cmake --build build --config Release
# cmake --build build --config Debug
# Для запуска проекта выбрать активный проект