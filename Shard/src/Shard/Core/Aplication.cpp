#include "Application.h"
#include "Log.h"
#include <GLFW/glfw3.h>

namespace Shard
{

    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(new Window(WindowProps()));
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {

        while (m_Running)
        {
            // Clear the screen with a color
            glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            m_Window->OnUpdate();

            // Check if window should close
            if (glfwWindowShouldClose((GLFWwindow *)m_Window->GetNativeWindow()))
            {
                m_Running = false;
            }
        }
    }

}