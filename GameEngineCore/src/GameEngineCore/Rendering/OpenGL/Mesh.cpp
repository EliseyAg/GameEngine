#include "Mesh.hpp"
#include "ShaderProgram.hpp"
#include "VertexBuffer.hpp"
#include "VertexArray.hpp"
#include "IndexBuffer.hpp"
#include "Texture2D.hpp"
#include "Renderer_OpenGL.hpp"

namespace EliseyAgGameEngine {

	GLfloat pos_norm_uv[] = {
		//    position             normal            UV                  index

		// FRONT
		-1.0f, -1.f, -1.f,    -1.f,  0.f,  0.f,     0.f, 0.f,              // 0
		-1.0f,  1.f, -1.f,    -1.f,  0.f,  0.f,     1.f, 0.f,              // 1
		-1.0f,  1.f,  1.f,    -1.f,  0.f,  0.f,     1.f, 1.f,              // 2
		-1.0f, -1.f,  1.f,    -1.f,  0.f,  0.f,     0.f, 1.f,              // 3

		// BACK                                  
		 1.0f, -1.f, -1.f,     1.f,  0.f,  0.f,     1.f, 0.f,              // 4
		 1.0f,  1.f, -1.f,     1.f,  0.f,  0.f,     0.f, 0.f,              // 5
		 1.0f,  1.f,  1.f,     1.f,  0.f,  0.f,     0.f, 1.f,              // 6
		 1.0f, -1.f,  1.f,     1.f,  0.f,  0.f,     1.f, 1.f,              // 7

		 // RIGHT
		 -1.0f,  1.f, -1.f,     0.f,  1.f,  0.f,    0.f, 0.f,              // 8
		  1.0f,  1.f, -1.f,     0.f,  1.f,  0.f,    1.f, 0.f,              // 9
		  1.0f,  1.f,  1.f,     0.f,  1.f,  0.f,    1.f, 1.f,              // 10
		 -1.0f,  1.f,  1.f,     0.f,  1.f,  0.f,    0.f, 1.f,              // 11

		 // LEFT
		 -1.0f, -1.f, -1.f,     0.f, -1.f,  0.f,    1.f, 0.f,              // 12
		  1.0f, -1.f, -1.f,     0.f, -1.f,  0.f,    0.f, 0.f,              // 13
		  1.0f, -1.f,  1.f,     0.f, -1.f,  0.f,    0.f, 1.f,              // 14
		 -1.0f, -1.f,  1.f,     0.f, -1.f,  0.f,    1.f, 1.f,              // 15

		 // TOP
		 -1.0f, -1.f,  1.f,     0.f,  0.f,  1.f,    0.f, 0.f,              // 16
		 -1.0f,  1.f,  1.f,     0.f,  0.f,  1.f,    1.f, 0.f,              // 17
		  1.0f,  1.f,  1.f,     0.f,  0.f,  1.f,    1.f, 1.f,              // 18
		  1.0f, -1.f,  1.f,     0.f,  0.f,  1.f,    0.f, 1.f,              // 19

		  // BOTTOM
		  -1.0f, -1.f, -1.f,    0.f,  0.f, -1.f,    0.f, 1.f,              // 20
		  -1.0f,  1.f, -1.f,    0.f,  0.f, -1.f,    1.f, 1.f,              // 21
		   1.0f,  1.f, -1.f,    0.f,  0.f, -1.f,    1.f, 0.f,              // 22
		   1.0f, -1.f, -1.f,    0.f,  0.f, -1.f,    0.f, 0.f,              // 23
	};

	GLuint indices[] = {
		0,   1,  2,  2,  3,  0, // front
		4,   5,  6,  6,  7,  4, // back
		8,   9, 10, 10, 11,  8, // right
		12, 13, 14, 14, 15, 12, // left
		16, 17, 18, 18, 19, 16, // top
		20, 21, 22, 22, 23, 20  // bottom
	};

	Mesh::Mesh() {

	}
}
