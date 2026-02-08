#include <Shard.h>

class ExampleLayer : public Shard::Layer
{
public:
    ExampleLayer()
        : Layer("Example")
    {
    }

    void OnUpdate() override
    {
        // Check input every frame
        if (Shard::Input::IsKeyPressed(SHARD_KEY_SPACE))
            SHARD_INFO("Space bar is pressed!");
    }

    void OnEvent(Shard::Event &event) override
    {
        SHARD_TRACE("{0}", event);
    }
};

class Sandbox : public Shard::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
    }

    ~Sandbox()
    {
    }
};

Shard::Application *Shard::CreateApplication()
{
    return new Sandbox();
}