# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/esp/Espressif/frameworks/esp-idf-v5.2.2/components/bootloader/subproject"
  "D:/esp/siri/voltage_monitoring/build/bootloader"
  "D:/esp/siri/voltage_monitoring/build/bootloader-prefix"
  "D:/esp/siri/voltage_monitoring/build/bootloader-prefix/tmp"
  "D:/esp/siri/voltage_monitoring/build/bootloader-prefix/src/bootloader-stamp"
  "D:/esp/siri/voltage_monitoring/build/bootloader-prefix/src"
  "D:/esp/siri/voltage_monitoring/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/esp/siri/voltage_monitoring/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/esp/siri/voltage_monitoring/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
