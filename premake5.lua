workspace "AoC2023"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "AoC2023"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "AoC2023"