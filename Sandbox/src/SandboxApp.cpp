#include <Shard.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class ExampleLayer : public Shard::Layer
{
public:
    ExampleLayer() : Layer("Example") {}

    void OnUpdate(Shard::Timestep ts) override
    {
    }
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