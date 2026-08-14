from conan import ConanFile
from conan.errors import ConanInvalidConfiguration
from conan.tools.build import can_run, check_min_cppstd
from conan.tools.cmake import CMake, CMakeDeps, CMakeToolchain, cmake_layout
import os

class CucumberMessages(ConanFile):
    name = "cucumber_messages"
    version = "0.1.0"
    package_type = "library"

    license = "MIT"
    url = "https://github.com/cucumber/messages"
    homepage = "https://github.com/cucumber/messages"
    description = "Cucumber Messages for C++"
    topics = ("cucumber", "messages", "bdd", "json")

    settings = "os", "arch", "compiler", "build_type"
    options = {
        "shared": [True, False],
        "fPIC": [True, False],
    }
    default_options = {
        "shared": False,
        "fPIC": True,
    }

    def set_version(self):
        version_file = os.path.join(self.recipe_folder, "VERSION")
        if os.path.exists(version_file):
            with open(version_file, "r", encoding="utf-8") as f:
                self.version = f.readline().strip()

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def _build_tests(self):
        # Unit tests read the repo-root testdata/ folder, which is not part of
        # the exported package, so only build them when that folder is present.
        if self.conf.get("tools.build:skip_test", default=False):
            return False
        return os.path.isdir(os.path.join(self.source_folder, os.pardir, "testdata"))

    def requirements(self):
        self.requires("nlohmann_json/3.12.0")

    def build_requirements(self):
        if not self.conf.get("tools.build:skip_test", default=False):
            self.test_requires("gtest/1.17.0")

    def validate(self):
        check_min_cppstd(self, 17)

    def layout(self):
        cmake_layout(self)

    def generate(self):
        cmake_deps = CMakeDeps(self)
        cmake_deps.generate()

        cmake_toolchain = CMakeToolchain(self)
        cmake_toolchain.user_presets_path = False
        cmake_toolchain.cache_variables["CUCUMBER_MESSAGES_BUILD_TESTS"] = self._build_tests()
        cmake_toolchain.cache_variables["CMAKE_CXX_STANDARD"] = "17"
        cmake_toolchain.cache_variables["CMAKE_CXX_STANDARD_REQUIRED"] = True
        cmake_toolchain.cache_variables["CMAKE_CXX_EXTENSIONS"] = False
        cmake_toolchain.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        if self._build_tests() and can_run(self):
            cmake.ctest()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.set_property("cmake_file_name", "cucumber_messages")
        self.cpp_info.set_property("cmake_target_name", "cucumber::messages")
        self.cpp_info.libs = ["cucumber_messages"]


    exports_sources = (
        "CMakeLists.txt",
        "VERSION",
        "README.md",
        "cmake/*",
        "include/*",
        "src/*",
        # "test/*",
        # "./../testdata/*",
        # "test_install/*",
    )
