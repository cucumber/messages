from conan import ConanFile
from conan.tools.build import can_run
from conan.tools.cmake import CMake, CMakeDeps, CMakeToolchain, cmake_layout

class TestPackageConan(ConanFile):
    settings = "os", "arch", "compiler", "build_type"

    def requirements(self):
        self.requires("nlohmann_json/[*]")
        self.requires("cucumber_messages/[*]")

    def build_requirements(self):
        self.test_requires("gtest/[*]")

    def layout(self):
        cmake_layout(self)

    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()

        cmake_toolchain = CMakeToolchain(self)
        cmake_toolchain.user_presets_path = False
        cmake_toolchain.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        if can_run(self):
            cmake.ctest()
