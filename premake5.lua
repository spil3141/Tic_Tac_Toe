-- premake5.lua

workspace "Tic_Tac_Toe"
    architecture "x64"
    startproject "Tic_Tac_Toe_Client"

   configurations 
   { 
       "Debug",
       "Release",
   }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


project "Tic_Tac_Toe_Client"
    location "Tic_Tac_Toe_Client"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    { 
        "%{wks.location}/%{prj.name}/src/**.h",
        "%{wks.location}/%{prj.name}/src/**.cpp" 
    }

    removefiles 
    {
        "%{wks.location}/%{prj.name}/src/Junk/**.cpp",
        "%{wks.location}/%{prj.name}/src/Junk/**.h"
    }

    includedirs
    {
        "%{wks.location}/%{prj.name}/src",
        "%{wks.location}/vendor/Tiny/includes",
        "%{wks.location}/vendor/Tiny/vendor/spdlog/include",
        "%{wks.location}/vendor/Tiny/vendor/ImGui",
        "%{wks.location}/vendor/Tiny/vendor/glm/include",
        "%{wks.location}/vendor/Tiny/vendor/asio-1.18.0/include"
    }

    libdirs 
    { 
        "%{wks.location}/vendor/Tiny/libs",
    }

    links {
        "Tiny",
        "Glad",
        "GLFW",
        "ImGui"
    }

    filter "system:windows"
        systemversion "latest"

        defines 
        {
            "T_PLATFORM_WINDOWS",
        }


    filter "configurations:Debug"
        defines "T_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "T_RELEASE"
        optimize "On"

project "Tic_Tac_Toe_Server"
    location "Tic_Tac_Toe_Server"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    { 
        "%{wks.location}/%{prj.name}/src/**.h",
        "%{wks.location}/%{prj.name}/src/**.cpp" 
    }

    removefiles 
    {
        "%{wks.location}/%{prj.name}/src/Junk/**.cpp",
        "%{wks.location}/%{prj.name}/src/Junk/**.h"
    }

    includedirs
    {
        "%{wks.location}/%{prj.name}/src",
        "%{wks.location}/vendor/Tiny/includes",
        "%{wks.location}/vendor/Tiny/vendor/spdlog/include",
        "%{wks.location}/vendor/Tiny/vendor/ImGui",
        "%{wks.location}/vendor/Tiny/vendor/glm/include",
        "%{wks.location}/vendor/Tiny/vendor/asio-1.18.0/include"
    }

    libdirs 
    { 
        "%{wks.location}/vendor/Tiny/libs",
    }

    links {
        "Tiny",
        "Glad",
        "GLFW",
        "ImGui"
    }

    filter "system:windows"
        systemversion "latest"

        defines 
        {
            "T_PLATFORM_WINDOWS",
        }


    filter "configurations:Debug"
        defines "T_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "T_RELEASE"
        optimize "On"

