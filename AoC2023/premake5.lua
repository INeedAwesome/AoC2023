project "AoC2023"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++20"
   staticruntime "off"

   files { "src/**.h", "src/**.cpp" }

   includedirs
   {
      "src/"
   }

   targetdir ("../bin/" .. outputdir .. "-%{prj.name}")
   objdir ("../bin-int/" .. outputdir .. "-%{prj.name}")

   filter "system:windows"
      systemversion "latest"
      defines { "AC_PLATFORM_WINDOWS" }
   filter "system:linux"
      systemversion "latest"
      defines { "AC_PLATFORM_LINUX" }

   filter "configurations:Debug"
      defines { "AC_DEBUG" }
      runtime "Debug"
      symbols "On"

   filter "configurations:Release"
      defines { "AC_RELEASE" }
      runtime "Release"
      optimize "On"
      symbols "On"

   filter "configurations:Dist"
      kind "WindowedApp"
      defines { "AC_DIST" }
      runtime "Release"
      optimize "Speed"
      symbols "Off"
