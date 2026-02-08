#pragma once

#include "Core.h"
#include "Window.h"

#include "../Events/Event.h"
#include "../Events/ApplicationEvent.h"

#include <memory>

namespace Shard
{

    class SHARD_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
        void OnEvent(Event &e);

    private:
        bool OnWindowClose(WindowCloseEvent &e);

    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

    // To be defined in CLIENT
    Application *CreateApplication();

}