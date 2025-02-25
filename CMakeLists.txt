# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(BitDog-SensorMatrix C CXX ASM)

# Inicializa o SDK do Raspberry Pi Pico
pico_sdk_init()

# Adiciona opções de compilação
add_compile_options(-Wall -Werror -Wno-unused-variable)

# Adiciona o executável
add_executable(BitDog-SensorMatrix 
    BitDog-SensorMatrix.c 
    sensores.c
)

pico_set_program_name(BitDog-SensorMatrix "BitDog-SensorMatrix")
pico_set_program_version(BitDog-SensorMatrix "1.0")

# Habilita saída via UART e USB
pico_enable_stdio_uart(BitDog-SensorMatrix 1)
pico_enable_stdio_usb(BitDog-SensorMatrix 1)

# Adiciona as bibliotecas padrão à compilação
target_link_libraries(BitDog-SensorMatrix
    pico_stdlib
    hardware_adc
    hardware_rtc
    pico_time
    pico_util
    hardware_gpio
    hardware_i2c
)

# Adiciona os diretórios de inclusão padrão à compilação
target_include_directories(BitDog-SensorMatrix PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

# Gera os arquivos binários adicionais (UF2, etc.)
pico_add_extra_outputs(BitDog-SensorMatrix)