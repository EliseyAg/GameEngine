#include "Window.hpp"
#include "OpenGLgameCore/Log.hpp"
#include "OpenGLgameCore/Event.hpp"
<<<<<<< HEAD
#include "Modules/UIModule.hpp"
#include "Rendering/OpenGL/Renderer_OpenGL.hpp"

#include <GLFW/glfw3.h>

namespace Engine {
=======
#include "OpenGLgameCore/Camera.hpp"
#include "Rendering/OpenGL/ShaderProgram.hpp"
#include "Rendering/OpenGL/VertexBuffer.hpp"
#include "Rendering/OpenGL/VertexArray.hpp"
#include "Rendering/OpenGL/IndexBuffer.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm/mat3x3.hpp>
#include <glm/glm/trigonometric.hpp>

#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_opengl3.h>
#include <imgui/backends/imgui_impl_glfw.h>

namespace Engine {

    static bool s_GLFW_initialized = false;

    GLfloat positions_colors2[] = {
       -0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,
       -0.5f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f,
        0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f
    };

    GLuint indices[] = {
    0, 1, 2, 3, 2, 1
    };

    const char* vertex_shader =
        R"(
				#version 460
				layout(location = 0) in vec3 vertex_position;
				layout(location = 1) in vec3 vertex_color;
				uniform mat4 model_matrix;
				uniform mat4 view_projection_matrix;
				out vec3 color;
				void main() {
				   color = vertex_color;
				   gl_Position = view_projection_matrix * model_matrix * vec4(vertex_position, 1.0);
				}
			)";

    const char* fragment_shader =
        R"(
				#version 460
				in vec3 color;
				out vec4 frag_color;
				void main() {
				  frag_color = vec4(color, 1.0);
				}
			)";

    std::unique_ptr<ShaderProgram> p_shader_program;
    std::unique_ptr<VertexBuffer> p_positions_colors_vbo;
    std::unique_ptr<IndexBuffer> p_index_buffer;
    std::unique_ptr<VertexArray> p_vao;
    float scale[3] = { 1.f, 1.f, 1.f };
    float rotate = 0.f;
    float translate[3] = { 0.f, 0.f, 0.f };

    float camera_position[3] = { 0.f, 0.f, 1.f };
    float camera_rotation[3] = { 0.f, 0.f, 1.f };
    bool perspective_camera = false;
    Camera camera;

>>>>>>> 1ed6159dea207cdcda968d6b2b3f61b5c1b28db1
    Window::Window(std::string title, const unsigned int width, const unsigned int height)
        : m_data({ std::move(title), width, height })
    {
        int resultCode = init();
<<<<<<< HEAD
=======

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui_ImplOpenGL3_Init();
        ImGui_ImplGlfw_InitForOpenGL(m_pWindow, true);
>>>>>>> 1ed6159dea207cdcda968d6b2b3f61b5c1b28db1
    }

    Window::~Window()
    {
        shutdown();
    }

    int Window::init()
    {
        LOG_INFO("Creating window '{0}' with size {1}x{2}", m_data.title, m_data.width, m_data.height);

<<<<<<< HEAD
        glfwSetErrorCallback([](int error_code, const char* description)
            {
            LOG_CRITICAL("GLFW error: {0}", description);
        });

        if (!glfwInit())
        {
            LOG_CRITICAL("Can't initialize GLFW!");
            return -1;
=======
        if (!s_GLFW_initialized)
        {
            if (!glfwInit())
            {
                LOG_CRITICAL("Can't initialize GLFW!");
                return -1;
            }
            s_GLFW_initialized = true;
>>>>>>> 1ed6159dea207cdcda968d6b2b3f61b5c1b28db1
        }

        m_pWindow = glfwCreateWindow(m_data.width, m_data.height, m_data.title.c_str(), nullptr, nullptr);
        if (!m_pWindow)
        {
            LOG_CRITICAL("Can't create window {0} with size {1}x{2}", m_data.title, m_data.width, m_data.height);
<<<<<<< HEAD
            return -2;
        }

        if (!Renderer_OpenGL::init(m_pWindow))
        {
            LOG_CRITICAL("Failed to initialize OpenGL renderer");
=======
            glfwTerminate();
            return -2;
        }

        glfwMakeContextCurrent(m_pWindow);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            LOG_CRITICAL("Failed to initialize GLAD");
>>>>>>> 1ed6159dea207cdcda968d6b2b3f61b5c1b28db1
            return -3;
        }

        glfwSetWindowUserPointer(m_pWindow, &m_data);

        glfwSetWindowSizeCallback(m_pWindow,
            [](GLFWwindow* pWindow, int width, int height)
            {
                WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(pWindow));
                data.width = width;
                data.height = height;
<<<<<<< HEAD
=======

>>>>>>> 1ed6159dea207cdcda968d6b2b3f61b5c1b28db1
                EventWindowResize event(width, height);
                data.eventCallbackFn(event);
            }
        );

        glfwSetCursorPosCallback(m_pWindow,
            [](GLFWwindow* pWindow, double x, double y)
            {
                WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(pWindow));
<<<<<<< HEAD
=======

>>>>>>> 1ed6159dea207cdcda968d6b2b3f61b5c1b28db1
                EventMouseMoved event(x, y);
                data.eventCallbackFn(event);
            }
        );

        glfwSetWindowCloseCallback(m_pWindow,
            [](GLFWwindow* pWindow)
            {
                WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(pWindow));
<<<<<<< HEAD
=======

>>>>>>> 1ed6159dea207cdcda968d6b2b3f61b5c1b28db1
                EventWindowClose event;
                data.eventCallbackFn(event);
            }
        );

        glfwSetFramebufferSizeCallback(m_pWindow,
            [](GLFWwindow* pWindow, int width, int height)
            {
<<<<<<< HEAD
                Renderer_OpenGL::set_viewport(width, height);
            }
        );

        UIModule::on_window_create(m_pWindow);
=======
                glViewport(0, 0, width, height);
            }
        );


        p_shader_program = std::make_unique<ShaderProgram>(vertex_shader, fragment_shader);
        if (!p_shader_program->isCompiled())
        {
            return false;
        }

        BufferLayout buffer_layout_1vec3
        {
            ShaderDataType::Float3
        };


        BufferLayout buffer_layout_2vec3
        {
            ShaderDataType::Float3,
            ShaderDataType::Float3
        };

        p_vao = std::make_unique<VertexArray>();
        p_positions_colors_vbo = std::make_unique<VertexBuffer>(positions_colors2, sizeof(positions_colors2), buffer_layout_2vec3);
        p_index_buffer = std::make_unique<IndexBuffer>(indices, sizeof(indices) / sizeof(GLuint));

        p_vao->add_vertex_buffer(*p_positions_colors_vbo);
        p_vao->set_index_buffer(*p_index_buffer);


        glm::mat3 mat_1(4, 0, 0, 2, 8, 1, 0, 1, 0);
        glm::mat3 mat_2(4, 2, 9, 2, 0, 4, 1, 4, 2);

        glm::mat3 result_mat = mat_1 * mat_2;

        LOG_INFO("");
        LOG_INFO("|{0:3} {1:3} {2:3}|", result_mat[0][0], result_mat[1][0], result_mat[2][0]);
        LOG_INFO("|{0:3} {1:3} {2:3}|", result_mat[0][1], result_mat[1][1], result_mat[2][1]);
        LOG_INFO("|{0:3} {1:3} {2:3}|", result_mat[0][2], result_mat[1][2], result_mat[2][2]);
        LOG_INFO("");

        glm::vec4 vec(1, 2, 3, 4);
        glm::mat4 mat_identity(1);

        glm::vec4 result_vec = mat_identity * vec;

        LOG_INFO("({0} {1} {2} {3})", result_vec.x, result_vec.y, result_vec.z, result_vec.w);
>>>>>>> 1ed6159dea207cdcda968d6b2b3f61b5c1b28db1

        return 0;
    }

    void Window::shutdown()
    {
<<<<<<< HEAD
        UIModule::on_window_close();
=======
>>>>>>> 1ed6159dea207cdcda968d6b2b3f61b5c1b28db1
        glfwDestroyWindow(m_pWindow);
        glfwTerminate();
    }

    void Window::on_update()
    {
<<<<<<< HEAD
=======
        glClearColor(m_background_color[0], m_background_color[1], m_background_color[2], m_background_color[3]);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGuiIO& io = ImGui::GetIO();
        io.DisplaySize.x = static_cast<float>(get_width());
        io.DisplaySize.y = static_cast<float>(get_height());

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        //ImGui::ShowDemoWindow();


        ImGui::Begin("Background Color Window");
        ImGui::ColorEdit4("Background Color", m_background_color);
        ImGui::SliderFloat3("scale", scale, 0.f, 2.f);
        ImGui::SliderFloat("rotate", &rotate, 0.f, 360.f);
        ImGui::SliderFloat3("translate", translate, -1.f, 1.f);

        ImGui::SliderFloat3("camera position", camera_position, -10.f, 10.f);
        ImGui::SliderFloat3("camera rotation", camera_rotation, 0, 360.f);
        ImGui::Checkbox("Perspective camera", &perspective_camera);

        p_shader_program->bind();

        glm::mat4 scale_matrix(scale[0], 0, 0, 0,
            0, scale[1], 0, 0,
            0, 0, scale[2], 0,
            0, 0, 0, 1);

        float rotate_in_radians = glm::radians(rotate);
        glm::mat4 rotate_matrix(cos(rotate_in_radians), sin(rotate_in_radians), 0, 0,
            -sin(rotate_in_radians), cos(rotate_in_radians), 0, 0,
                 0, 0, 1, 0,
                 0, 0, 0, 1);

        glm::mat4 translate_matrix(1, 0, 0, 0,
                                   0, 1, 0, 0,
                                   0, 0, 1, 0,
                                   translate[0], translate[1], translate[2], 1);

        glm::mat4 model_matrix = translate_matrix * rotate_matrix * scale_matrix;
        p_shader_program->setMatrix4("model_matrix", model_matrix);

        camera.set_position_rotation(glm::vec3(camera_position[0], camera_position[1], camera_position[2]),
                                     glm::vec3(camera_rotation[0], camera_rotation[1], camera_rotation[2]));
        camera.set_projection_mode(perspective_camera ? Camera::ProjectionMode::Perspective : Camera::ProjectionMode::Orthograthic);

        p_shader_program->setMatrix4("view_projection_matrix", camera.get_projection_matrix() * camera.get_view_matrix());

        p_vao->bind();
        glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(p_vao->get_indices_count()), GL_UNSIGNED_INT, nullptr);

        ImGui::End();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());


>>>>>>> 1ed6159dea207cdcda968d6b2b3f61b5c1b28db1
        glfwSwapBuffers(m_pWindow);
        glfwPollEvents();
    }

}