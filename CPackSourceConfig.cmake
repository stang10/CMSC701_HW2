# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


set(CPACK_BUILD_SOURCE_DIRS "/Users/samanthatang/Documents/UMD/Grad_School/Spring_2023/701/Samantha Tang HW2/Attempt2;/Users/samanthatang/Documents/UMD/Grad_School/Spring_2023/701/Samantha Tang HW2/Attempt2")
set(CPACK_CMAKE_GENERATOR "Unix Makefiles")
set(CPACK_COMPONENTS_ALL "")
set(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
set(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_FILE "/usr/local/Cellar/cmake/3.25.0/share/cmake/Templates/CPack.GenericDescription.txt")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_SUMMARY "CMSC701_Project1 built using CMake")
set(CPACK_DMG_SLA_USE_RESOURCE_FILE_LICENSE "ON")
set(CPACK_GENERATOR "TGZ;TBZ2;ZIP")
set(CPACK_IGNORE_FILES "/CVS/;/build/;/\\.build/;/\\.svn/;~$")
set(CPACK_INSTALLED_DIRECTORIES "/Users/samanthatang/Documents/UMD/Grad_School/Spring_2023/701/Samantha Tang HW2/Attempt2;/")
set(CPACK_INSTALL_CMAKE_PROJECTS "")
set(CPACK_INSTALL_PREFIX "/usr/local")
set(CPACK_MODULE_PATH "/Users/samanthatang/Documents/UMD/Grad_School/Spring_2023/701/Samantha Tang HW2/Attempt2/sdsl-lite/external/libdivsufsort/CMakeModules")
set(CPACK_NSIS_DISPLAY_NAME "CMSC701_Project1 2.0.2")
set(CPACK_NSIS_INSTALLER_ICON_CODE "")
set(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES")
set(CPACK_NSIS_PACKAGE_NAME "CMSC701_Project1 2.0.2")
set(CPACK_NSIS_UNINSTALL_NAME "Uninstall")
set(CPACK_OBJDUMP_EXECUTABLE "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/objdump")
set(CPACK_OSX_SYSROOT "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX13.1.sdk")
set(CPACK_OUTPUT_CONFIG_FILE "/Users/samanthatang/Documents/UMD/Grad_School/Spring_2023/701/Samantha Tang HW2/Attempt2/CPackConfig.cmake")
set(CPACK_PACKAGE_CONTACT "yuta.256@gmail.com")
set(CPACK_PACKAGE_DEFAULT_LOCATION "/")
set(CPACK_PACKAGE_DESCRIPTION_FILE "/Users/samanthatang/Documents/UMD/Grad_School/Spring_2023/701/Samantha Tang HW2/Attempt2/sdsl-lite/external/libdivsufsort/README.md")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A lightweight suffix sorting library")
set(CPACK_PACKAGE_FILE_NAME "libdivsufsort-2.0.1-13-g0f24acd")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "CMSC701_Project1 2.0.2")
set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "CMSC701_Project1 2.0.2")
set(CPACK_PACKAGE_NAME "CMSC701_Project1")
set(CPACK_PACKAGE_RELOCATABLE "true")
set(CPACK_PACKAGE_VENDOR "Yuta Mori")
set(CPACK_PACKAGE_VERSION "2.0.2")
set(CPACK_PACKAGE_VERSION_MAJOR "2")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "2")
set(CPACK_RESOURCE_FILE_LICENSE "/Users/samanthatang/Documents/UMD/Grad_School/Spring_2023/701/Samantha Tang HW2/Attempt2/sdsl-lite/external/libdivsufsort/LICENSE")
set(CPACK_RESOURCE_FILE_README "/usr/local/Cellar/cmake/3.25.0/share/cmake/Templates/CPack.GenericDescription.txt")
set(CPACK_RESOURCE_FILE_WELCOME "/usr/local/Cellar/cmake/3.25.0/share/cmake/Templates/CPack.GenericWelcome.txt")
set(CPACK_RPM_PACKAGE_SOURCES "ON")
set(CPACK_SET_DESTDIR "OFF")
set(CPACK_SOURCE_GENERATOR "TGZ;TBZ2;ZIP")
set(CPACK_SOURCE_IGNORE_FILES "/CVS/;/build/;/\\.build/;/\\.svn/;~$")
set(CPACK_SOURCE_INSTALLED_DIRECTORIES "/Users/samanthatang/Documents/UMD/Grad_School/Spring_2023/701/Samantha Tang HW2/Attempt2;/")
set(CPACK_SOURCE_OUTPUT_CONFIG_FILE "/Users/samanthatang/Documents/UMD/Grad_School/Spring_2023/701/Samantha Tang HW2/Attempt2/CPackSourceConfig.cmake")
set(CPACK_SOURCE_PACKAGE_FILE_NAME "libdivsufsort-2.0.1-13-g0f24acd")
set(CPACK_SOURCE_STRIP_FILES "")
set(CPACK_SOURCE_TOPLEVEL_TAG "Darwin-x86_64-Source")
set(CPACK_STRIP_FILES "")
set(CPACK_SYSTEM_NAME "Darwin-x86_64")
set(CPACK_THREADS "1")
set(CPACK_TOPLEVEL_TAG "Darwin-x86_64-Source")
set(CPACK_WIX_SIZEOF_VOID_P "8")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "/Users/samanthatang/Documents/UMD/Grad_School/Spring_2023/701/Samantha Tang HW2/Attempt2/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()
