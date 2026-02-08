#pragma once

#include "Core.h"

#include <string>
#include <GLFW/glfw3.h>

namespace Shard
{

    struct WindowProps
    {
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        WindowProps(const std::string &title = "Shard Engine",
                    unsigned int width = 1280,
                    unsigned int height = 720)
            : Title(title), Width(width), Height(height)
        {
        }
    };

    class SHARD_API Window
    {
    public:
        Window(const WindowProps &props);
        ~Window();

        void OnUpdate();

        inline unsigned int GetWidth() const { return m_Data.Width; }
        inline unsigned int GetHeight() const { return m_Data.Height; }

        inline void *GetNativeWindow() const { return m_Window; }

    private:
        void Init(const WindowProps &props);
        void Shutdown();

    private:
        GLFWwindow *m_Window;

        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;
        };

        WindowData m_Data;
    };

}