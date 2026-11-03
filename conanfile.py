# Based on https://github.com/conan-io/examples2/blob/8c5987f9756aa1b55f79e4eeb6e2577c4a7afcea/tutorial/creating_packages/preparing_the_build/conanfile.py

from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout
from conan.tools.files import apply_conandata_patches, get
from conan.tools.scm import Git

required_conan_version = ">=2.1"


class helloRecipe(ConanFile):
    name = "strzcpy"
    version = "1.0.0"

    license = "GPL-2.0-only"
    author = "ReactorScram"
    url = "https://github.com/ReactorScram/strzcpy"
    description = "strzcpy copies a string, or crashes your program"
    topics = ("strcpy", "safety")

    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}

    exports_sources = "CMakeLists.txt", "src/*", "include/*"

    generators = "CMakeDeps"

    def layout(self):
        cmake_layout(self)

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["strzcpy"]
