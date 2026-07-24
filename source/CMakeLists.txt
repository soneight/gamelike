set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS OFF )
# app
add_executable( ${APP} )
target_sources( ${APP} PRIVATE main.cxx )
target_compile_options( ${APP} PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/utf-8 /permissive- /Zc:__cplusplus> )
# son8 libraries
include( FetchContent )
# -- core library for aliases
message( STATUS "${APP}: FetchContent `soneight/core_lib`" )
fetchcontent_declare(
   son8__core_lib
   GIT_REPOSITORY https://github.com/soneight/core_lib.git
   GIT_TAG        85a4e685d0e5b245f8cbb94e625a8ab1365c5f16 # v0.0.5
)
fetchcontent_makeavailable( son8__core_lib )
message( STATUS "${APP}: found `son8__core_lib` target" )
# -- main function wrapper
message( STATUS "${APP}: FetchContent `soneight/mainland`" )
fetchcontent_declare(
   son8__mainland
   GIT_REPOSITORY https://github.com/soneight/mainland.git
   GIT_TAG        8145becfc18b4c5968ddd61d19540d5a64ec282f # v0.1.1
)
fetchcontent_makeavailable( son8__mainland )
message( STATUS "${APP}: found `son8__mainland` target" )
# -- `OpenGL` wrapper depends on `GLAD` loader
# ---- NOTE: must be before `windowed` as it includes earlier versions
# ---- \ of `overglad` so it needs to be overwritten for later version
message( STATUS "${APP}: FetchContent `soneight/overglad`" )
fetchcontent_declare(
   son8__overglad
   GIT_REPOSITORY https://github.com/soneight/overglad.git
   GIT_TAG        868a2184b623e64911782db19242c293d4d52f6a # v0.8.2
)
fetchcontent_makeavailable( son8__overglad )
message( STATUS "${APP}: found `son8__windowed` target" )
# -- window creation depends on `GLFW` library
message( STATUS "${APP}: FetchContent `soneight/windowed`" )
fetchcontent_declare(
   son8__windowed
   GIT_REPOSITORY https://github.com/soneight/windowed.git
   GIT_TAG        8bedc378ec08500981f1d27dd302c4fce0c5f9d9 # v0.6.1
)
fetchcontent_makeavailable( son8__windowed )
message( STATUS "${APP}: found `son8__windowed` target" )
# linking
target_link_libraries( ${APP} PRIVATE son8::core_lib son8::mainland son8::overglad son8::windowed glfw::son8 )

# GNU Affero General Public License v3.0 or later
# NO WARRANTY OF ANY KIND more details at <https://www.gnu.org/licenses/>
# SPDX-License-Identifier: AGPL-3.0-or-later
# app: `gamelike` Resemble Role Playing Games
# Ⓒ Copyright (C) 2026 Oleg'Ease'Kharchuk ᦒ
