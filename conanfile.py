# Based on https://github.com/conan-io/examples2/blob/8c5987f9756aa1b55f79e4eeb6e2577c4a7afcea/tutorial/creating_packages/preparing_the_build/conanfile.py

from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout
from conan.tools.scm import Git


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

    def source(self):
        git = Git(self)
        git.clone(url="https://github.com/ReactorScram/strzcpy.git", target=".")
        git.checkout("baa2f0845d6b5ee7bb6c399d0f8290ee938dcb5e")

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
