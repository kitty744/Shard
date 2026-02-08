#include "Application.h"
#include "Log.h"

#include <GLFW/glfw3.h>

namespace Shard
{

    Application::Application()
    {
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

        while (m_Running)
        {
            glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            m_Window->OnUpdate();
        }
    }

}