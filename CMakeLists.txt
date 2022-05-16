cmake_minimum_required()

set(PROJECT_NAME OpenGLgame)

add_subdirectory(OpenGLgameCore)
add_subdirectory(OpenGLgameEditor)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT OpenGLgameEditor) 