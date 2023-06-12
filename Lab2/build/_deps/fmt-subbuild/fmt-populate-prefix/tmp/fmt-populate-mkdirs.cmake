# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/Lab2/build/_deps/fmt-src"
  "D:/Lab2/build/_deps/fmt-build"
  "D:/Lab2/build/_deps/fmt-subbuild/fmt-populate-prefix"
  "D:/Lab2/build/_deps/fmt-subbuild/fmt-populate-prefix/tmp"
  "D:/Lab2/build/_deps/fmt-subbuild/fmt-populate-prefix/src/fmt-populate-stamp"
  "D:/Lab2/build/_deps/fmt-subbuild/fmt-populate-prefix/src"
  "D:/Lab2/build/_deps/fmt-subbuild/fmt-populate-prefix/src/fmt-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/Lab2/build/_deps/fmt-subbuild/fmt-populate-prefix/src/fmt-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/Lab2/build/_deps/fmt-subbuild/fmt-populate-prefix/src/fmt-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
