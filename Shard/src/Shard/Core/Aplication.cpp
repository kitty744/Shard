#include "Application.h"
#include "Log.h"
#include "Input.h"
#include "KeyCodes.h"
#include <GLFW/glfw3.h>

namespace Shard
{

    Application *Application::s_Instance = nullptr;

    Application::Application()
    {
        SHARD_CORE_ASSERT(!s_Instance, "Application already exists!");
        s_Instance = this;

        m_Window = std::unique_ptr<Window>(new Window(WindowProps()));
        m_Window->SetEventCallback(SHARD_BIND_EVENT_FN(Application::OnEvent));
    }

    Application::~Application()
    {
    }

    void Application::OnEvent(Event &e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(SHARD_BIND_EVENT_FN(Application::OnWindowClose));

        SHARD_CORE_TRACE("{0}", e);
    }

    bool Application::OnWindowClose(WindowCloseEvent &e)
    {
        m_Running = false;
        return true;
    }

    void Application::Run()
    {
        SHARD_CORE_INFO("Application running!");

        while (m_Running)
        {
            if (Input::IsKeyPressed(SHARD_KEY_ESCAPE))
            {
                SHARD_CORE_INFO("Escape pressed! Closing...");
                m_Running = false;
            }

            glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            m_Window->OnUpdate();
        }
    }

}