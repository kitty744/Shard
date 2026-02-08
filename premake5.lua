workspace "Shard"
    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Shard Engine project
project "Shard"
    location "Shard"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "shpch.h"
    pchsource "Shard/src/shpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor",
        "/usr/include"
    }

    links
    {
        "glfw",
        "GL",
        "GLU",
        "X11",
        "pthread",
        "Xrandr",
        "Xi",
        "dl",
        "spdlog",
        "fmt"
    }

    filter "system:linux"
        systemversion "latest"

        defines
        {
            "SHARD_PLATFORM_LINUX",
            "SHARD_BUILD_DLL"
        }

    filter "configurations:Debug"
        defines "SHARD_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "SHARD_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "SHARD_DIST"
        runtime "Release"
        optimize "on"

-- Sandbox project
project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Shard/src",
        "Shard/vendor",
        "/usr/include"
    }

    links
    {
        "Shard",
        "spdlog",
        "fmt"
    }

    filter "system:linux"
        systemversion "latest"

        defines
        {
            "SHARD_PLATFORM_LINUX"
        }

        linkoptions { "-Wl,-rpath,$$ORIGIN/../Shard" }

    filter "configurations:Debug"
        defines "SHARD_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "SHARD_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "SHARD_DIST"
        runtime "Release"
        optimize "on"