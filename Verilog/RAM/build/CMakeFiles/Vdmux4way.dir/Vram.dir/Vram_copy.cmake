# Verilated -*- CMake -*-
# DESCRIPTION: Verilator output: CMake include script with class lists
#
# This CMake script lists generated Verilated files, for including in higher level CMake scripts.
# This file is meant to be consumed by the verilate() function,
# which becomes available after executing `find_package(verilator).

### Constants...
set(PERL "perl" CACHE FILEPATH "Perl executable (from $PERL, defaults to 'perl' if not set)")
set(PYTHON3 "python3" CACHE FILEPATH "Python3 executable (from $PYTHON3, defaults to 'python3' if not set)")
set(VERILATOR_ROOT "/usr/local/share/verilator" CACHE PATH "Path to Verilator kit (from $VERILATOR_ROOT)")
set(VERILATOR_SOLVER "" CACHE STRING "Default SMT solver for constrained randomization (from $VERILATOR_SOLVER)")

### Compiler flags...
# User CFLAGS (from -CFLAGS on Verilator command line)
set(Vram_USER_CFLAGS )
# User LDLIBS (from -LDFLAGS on Verilator command line)
set(Vram_USER_LDLIBS )

### Switches...
# SystemC output mode?  0/1 (from --sc)
set(Vram_SC 0)
# Coverage output mode?  0/1 (from --coverage)
set(Vram_COVERAGE 0)
# Timing mode?  0/1
set(Vram_TIMING 0)
# Threaded output mode?  1/N threads (from --threads)
set(Vram_THREADS 1)
# VCD Tracing output mode?  0/1 (from --trace)
set(Vram_TRACE_VCD 0)
# FST Tracing output mode? 0/1 (from --trace-fst)
set(Vram_TRACE_FST 0)

### Sources...
# Global classes, need linked once per executable
set(Vram_GLOBAL "${VERILATOR_ROOT}/include/verilated.cpp" "${VERILATOR_ROOT}/include/verilated_threads.cpp" )
# Generated module classes, non-fast-path, compile with low/medium optimization
set(Vram_CLASSES_SLOW "/home/raine/FromTheTransistor/Verilog/RAM/build/CMakeFiles/Vdmux4way.dir/Vram.dir/Vram___024root__Slow.cpp" "/home/raine/FromTheTransistor/Verilog/RAM/build/CMakeFiles/Vdmux4way.dir/Vram.dir/Vram___024root__DepSet_h122528d8__0__Slow.cpp" "/home/raine/FromTheTransistor/Verilog/RAM/build/CMakeFiles/Vdmux4way.dir/Vram.dir/Vram___024root__DepSet_h06552b65__0__Slow.cpp" )
# Generated module classes, fast-path, compile with highest optimization
set(Vram_CLASSES_FAST "/home/raine/FromTheTransistor/Verilog/RAM/build/CMakeFiles/Vdmux4way.dir/Vram.dir/Vram.cpp" "/home/raine/FromTheTransistor/Verilog/RAM/build/CMakeFiles/Vdmux4way.dir/Vram.dir/Vram___024root__DepSet_h122528d8__0.cpp" "/home/raine/FromTheTransistor/Verilog/RAM/build/CMakeFiles/Vdmux4way.dir/Vram.dir/Vram___024root__DepSet_h06552b65__0.cpp" )
# Generated support classes, non-fast-path, compile with low/medium optimization
set(Vram_SUPPORT_SLOW "/home/raine/FromTheTransistor/Verilog/RAM/build/CMakeFiles/Vdmux4way.dir/Vram.dir/Vram__Syms.cpp" )
# Generated support classes, fast-path, compile with highest optimization
set(Vram_SUPPORT_FAST )
# All dependencies
set(Vram_DEPS "/home/raine/FromTheTransistor/Verilog/RAM/ram.v" "/usr/local/share/verilator/include/verilated_std.sv" "/usr/local/share/verilator/include/verilated_std_waiver.vlt" )
# User .cpp files (from .cpp's on Verilator command line)
set(Vram_USER_CLASSES )
