
# rcam

cmake_minimum_required(VERSION 3.2)

# this one is important
SET(CMAKE_SYSTEM_NAME Linux)
#this one not so much
SET(CMAKE_SYSTEM_VERSION 1)

# specify the cross compiler
SET(CMAKE_C_COMPILER
$ENV{HOME}/development/pi/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin/arm-linux-gnueabihf-gcc)

SET(CMAKE_CXX_COMPILER
$ENV{HOME}/development/pi/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin/arm-linux-gnueabihf-g++)

SET(CMAKE_FIND_ROOT_PATH $ENV{HOME}/development/pi/rootfs)
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# where is the target environment
# SET(CMAKE_FIND_ROOT_PATH
# /home/lbarnett/development/pi/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64)

SET(COMPILE_DEFINITIONS -Werror)

include_directories(/home/lbarnett/development/pi/userland/host_applications/linux/libs/bcm_host/include)
include_directories(/home/lbarnett/development/pi/userland)
include_directories(/home/lbarnett/development/pi/userland/interface/vmcs_host/linux)
include_directories(/home/lbarnett/development/pi/userland/interface/vcos/pthreads)
include_directories(/home/lbarnett/development/pi/rcam)

link_directories(/home/lbarnett/development/pi/rootfs/opt/vc/lib)

set (COMMON_SOURCES
   RaspiCamControl.c
   RaspiCLI.c
   RaspiPreview.c)

add_executable(rcam  ${COMMON_SOURCES} rcam.c)

set (MMAL_LIBS mmal_core mmal_util mmal_vc_client)

target_link_libraries(rcam  ${MMAL_LIBS} vcos bcm_host)	

install(TARGETS rcam RUNTIME DESTINATION bin)
