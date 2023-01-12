#pragma once
#include <memory>
#include <GLFW/glfw3.h>

namespace EliseyAgGameEngine {

	class ShaderProgram;
	class VertexBuffer;
	class VertexArray;
	class IndexBuffer;
	class Texture2D;
	class Renderer_OpenGL;

	class Mesh {

	public:
		Mesh();

	private:
		std::unique_ptr<ShaderProgram> p_shader_program;
		std::unique_ptr<VertexBuffer> p_cube_positions_colors_vbo;
		std::unique_ptr<IndexBuffer> p_cube_index_buffer;
		std::unique_ptr<VertexArray> p_cube_vao;
	};
}
