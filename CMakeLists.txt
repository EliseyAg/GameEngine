cmake_minimum_required()

set(PROJECT_NAME GameEngine)

add_subdirectory(GameEngineLibrary)
add_subdirectory(GameEngineEditor)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT GameEngineEditor) 