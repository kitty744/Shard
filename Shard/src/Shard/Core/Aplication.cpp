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

    void Application::PushLayer(Layer *layer)
    {
        m_LayerStack.PushLayer(layer);
    }

    void Application::PushOverlay(Layer *overlay)
    {
        m_LayerStack.PushOverlay(overlay);
    }

    void Application::OnEvent(Event &e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(SHARD_BIND_EVENT_FN(Application::OnWindowClose));

        // Propagate events through layers (back to front)
        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
        {
            (*--it)->OnEvent(e);
            if (e.Handled)
                break;
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent &e)
    {
        m_Running = false;
        return true;
    }

    void Application::Run()
    {

        float lastFrameTime = 0.0f;

        while (m_Running)
        {
            float time = (float)glfwGetTime();
            Timestep timestep = time - lastFrameTime;
            lastFrameTime = time;

            glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            // Update all layers with delta time
            for (Layer *layer : m_LayerStack)
                layer->OnUpdate(timestep);

            m_Window->OnUpdate();
        }
    }

}