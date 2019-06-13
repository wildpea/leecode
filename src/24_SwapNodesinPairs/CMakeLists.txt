cmake_minimum_required (VERSION 3.4)

set(TARGET lee)
project (${TARGET})
aux_source_directory(. DIR_SRCS)

set(SERVERS_ROOT $ENV{SERVERS_ROOT})

include_directories(
    /usr/local/include/
    ${SERVERS_ROOT}/server/common
    ${SERVERS_ROOT}/dependencies/include
)

link_directories(
    /usr/local/lib
    ${SERVERS_ROOT}/dependencies/lib
)

# 指定生成目标
add_executable(${TARGET} ${DIR_SRCS})
target_compile_features(${TARGET} PRIVATE cxx_range_for)

TARGET_LINK_LIBRARIES(
    ${TARGET}
    libgtest.a
    libgflags.a
    libglog.a
)