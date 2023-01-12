cmake_minimum_required()

set(ENGINE_PROJECT_NAME GameEngineCore)

set(ENGINE_PUBLIC_INCLUDES
	includes/GameEngineCore/Application.hpp
	includes/GameEngineCore/Event.hpp
	includes/GameEngineCore/Log.hpp
	includes/GameEngineCore/Keys.hpp
	includes/GameEngineCore/Input.hpp
	includes/GameEngineCore/Camera.hpp
)

set(ENGINE_PRIVATE_INCLUDES
	src/GameEngineCore/Window.hpp
	src/GameEngineCore/Modules/UIModule.hpp
	src/GameEngineCore/Rendering/OpenGL/Mesh.hpp
	src/GameEngineCore/Rendering/OpenGL/ShaderProgram.hpp
	src/GameEngineCore/Rendering/OpenGL/VertexBuffer.hpp
	src/GameEngineCore/Rendering/OpenGL/VertexArray.hpp
	src/GameEngineCore/Rendering/OpenGL/IndexBuffer.hpp
	src/GameEngineCore/Rendering/OpenGL/Texture2D.hpp
	src/GameEngineCore/Rendering/OpenGL/Renderer_OpenGL.hpp
)
	
set(ENGINE_PRIVATE_SOURCES
	src/GameEngineCore/Application.cpp
	src/GameEngineCore/Window.cpp
	src/GameEngineCore/Input.cpp
	src/GameEngineCore/Camera.cpp
	src/GameEngineCore/Modules/UIModule.cpp
	src/GameEngineCore/Rendering/OpenGL/Mesh.cpp
	src/GameEngineCore/Rendering/OpenGL/ShaderProgram.cpp
	src/GameEngineCore/Rendering/OpenGL/VertexBuffer.cpp
	src/GameEngineCore/Rendering/OpenGL/VertexArray.cpp
	src/GameEngineCore/Rendering/OpenGL/IndexBuffer.cpp
	src/GameEngineCore/Rendering/OpenGL/Texture2D.cpp
	src/GameEngineCore/Rendering/OpenGL/Renderer_OpenGL.cpp
)

set(ENGINE_ALL_SOURCES
	${ENGINE_PUBLIC_INCLUDES}
	${ENGINE_PRIVATE_INCLUDES}
	${ENGINE_PRIVATE_SOURCES}
)

add_library(${ENGINE_PROJECT_NAME} STATIC
	${ENGINE_ALL_SOURCES}
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES
	${ENGINE_ALL_SOURCES}
)

target_include_directories(${ENGINE_PROJECT_NAME} PUBLIC includes)
target_compile_features(${ENGINE_PROJECT_NAME} PUBLIC cxx_std_17)

add_subdirectory(../external/glfw ${CMAKE_CURRENT_BINARY_DIR}/glfw)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE glfw)

add_subdirectory(../external/spdlog ${CMAKE_CURRENT_BINARY_DIR}/spdlog)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE spdlog)

add_subdirectory(../external/glad ${CMAKE_CURRENT_BINARY_DIR}/glad)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE glad)

add_subdirectory(../external/glm ${CMAKE_CURRENT_BINARY_DIR}/glm)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE glm)


set(IMGUI_INCLUDES
	../external/imgui/imgui.h
	../external/imgui/backends/imgui_impl_glfw.h
	../external/imgui/backends/imgui_impl_opengl3.h
)

set(IMGUI_SOURCES
	../external/imgui/imgui.cpp
	../external/imgui/backends/imgui_impl_glfw.cpp
	../external/imgui/backends/imgui_impl_opengl3.cpp
	../external/imgui/imgui_demo.cpp
	../external/imgui/imgui_tables.cpp
	../external/imgui/imgui_widgets.cpp
	../external/imgui/imgui_draw.cpp
)

add_library(ImGui STATIC
	${IMGUI_INCLUDES}
	${IMGUI_SOURCES}
)

target_include_directories(ImGui PUBLIC ../external)
target_include_directories(ImGui PUBLIC ../external/imgui)
target_link_libraries(ImGui PRIVATE glad glfw)

target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE ImGui)