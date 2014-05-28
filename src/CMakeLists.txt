rock_library(raw_io
    SOURCES Dummy.cpp
    HEADERS Dummy.hpp)

rock_executable(raw_io_bin Main.cpp
    DEPS raw_io)

