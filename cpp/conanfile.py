from conan import ConanFile
from conan.tools.cmake import CMakeDeps, CMakeToolchain


class CucumberMessages(ConanFile):
    settings = "os", "compiler", "build_type", "arch"

    def requirements(self):
        self.requires("nlohmann_json/3.12.0")

    def build_requirements(self):
        self.test_requires("gtest/1.17.0")

    def generate(self):
        cmake_deps = CMakeDeps(self)
        cmake_deps.generate()

        cmake_toolchain = CMakeToolchain(self)
        cmake_toolchain.user_presets_path = False
        cmake_toolchain.generate()
