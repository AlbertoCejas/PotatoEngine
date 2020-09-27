from   conans       import ConanFile, CMake, tools
from   conans.tools import download, unzip
import os

class Project(ConanFile):
    name            = "Potato Engine"
    description     = "Conan package for Potato Engine."
    version         = "0.0.1"                
    url             = "PROJECT_URL_HERE"
    settings        = "arch", "build_type", "compiler", "os"
    generators      = "cmake"
    requires        = (("doctest/2.3.4@bincrafters/stable"),
                       ("glfw/3.3.2"),
                       ("entt/3.5.2"),
                       ("imgui-docking/19-07-2020@ithyx/experimental"))

    def imports(self):
       self.copy("*.dylib*", dst="", src="lib")
       self.copy("*.dll"   , dst="", src="bin")

    def source(self):
        zip_name = "%s.zip" % self.version
        download ("%s/archive/%s" % (self.url, zip_name), zip_name, verify=False)
        unzip    (zip_name)
        os.unlink(zip_name)

    def build(self):
        cmake = CMake(self)
        self.run("cmake %s-%s %s" % (self.name, self.version, cmake.command_line))
        self.run("cmake --build . %s" % cmake.build_config)

    def package(self):
        self.copy("*.dylib*", dst="lib", keep_path=False)
        self.copy("*.so*"   , dst="lib", keep_path=False)
        self.copy("*.dll"   , dst="bin", keep_path=False)
        self.copy("*.exe"   , dst="bin", keep_path=False)
