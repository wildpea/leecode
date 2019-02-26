cmake_minimum_required (VERSION 3.4)

set(TARGET lee)
project (${TARGET})
aux_source_directory(. DIR_SRCS)

set(PROJECT_ROOT $ENV{WILDPEA_SERVER})

include_directories(
    ${PROJECT_ROOT}/dependencies/include
)

link_directories(
    ${PROJECT_ROOT}/dependencies/lib
)

# 指定生成目标
add_executable(${TARGET} ${DIR_SRCS})
target_compile_features(${TARGET} PRIVATE cxx_range_for)

TARGET_LINK_LIBRARIES(
    ${TARGET}
    libgtest.a
)