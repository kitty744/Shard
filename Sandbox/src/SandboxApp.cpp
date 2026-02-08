#include <Shard.h>

class ExampleLayer : public Shard::Layer
{
public:
    ExampleLayer()
        : Layer("Example"), m_Position(0.0f)
    {
    }

    void OnUpdate(Shard::Timestep ts) override
    {
        // Frame-independent movement!
        if (Shard::Input::IsKeyPressed(SHARD_KEY_A))
            m_Position -= m_Speed * ts;

        if (Shard::Input::IsKeyPressed(SHARD_KEY_D))
            m_Position += m_Speed * ts;

        // Log FPS every second
        m_Timer += ts;
        if (m_Timer >= 1.0f)
        {
            SHARD_INFO("FPS: {0} | Position: {1}", 1.0f / ts, m_Position);
            m_Timer = 0.0f;
        }
    }

    void OnEvent(Shard::Event &event) override
    {
        // Events still work!
    }

private:
    float m_Position = 0.0f;
    float m_Speed = 100.0f; // 100 units per second
    float m_Timer = 0.0f;
};

class Sandbox : public Shard::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
    }
};

Shard::Application *Shard::CreateApplication()
{
    return new Sandbox();
}