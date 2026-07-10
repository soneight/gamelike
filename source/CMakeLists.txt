set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS OFF )
# app
add_executable( ${APP} )
target_sources( ${APP} PRIVATE main.cxx )
target_compile_options( ${APP} PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/utf-8 /permissive- /Zc:__cplusplus> )
# son8 libraries
include( FetchContent )

message( STATUS "${APP}: FetchContent `soneight/mainland`" )
fetchcontent_declare(
   son8__mainland
   GIT_REPOSITORY https://github.com/soneight/mainland.git
   GIT_TAG        06e8a764454a7d245628a25e775324a0a40fc92a # v0.1.0
)
fetchcontent_makeavailable( son8__mainland )
message( STATUS "${APP}: found `son8__mainland` target" )

message( STATUS "${APP}: FetchContent `soneight/windowed`" )
fetchcontent_declare(
   son8__windowed
   GIT_REPOSITORY https://github.com/soneight/windowed.git
   GIT_TAG        7d868530179b93cafeb189847e3a9a0adecf3fd2 # v0.5.0
)
fetchcontent_makeavailable( son8__windowed )
message( STATUS "${APP}: found `son8__windowed` target" )

target_link_libraries( ${APP} PRIVATE son8::mainland son8::windowed glfw::son8 )

# GNU Affero General Public License v3.0 or later
# NO WARRANTY OF ANY KIND more details at <https://www.gnu.org/licenses/>
# SPDX-License-Identifier: AGPL-3.0-or-later
# app: `gamelike` Resemble Role Playing Games
# Ⓒ Copyright (C) 2026 Oleg'Ease'Kharchuk ᦒ
