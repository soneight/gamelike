set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS OFF )
# app
add_executable( ${APP} )
target_sources( ${APP} PRIVATE main.cxx )
target_compile_options( ${APP} PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/utf-8 /permissive- /Zc:__cplusplus> )

# GNU Affero General Public License v3.0 or later
# NO WARRANTY OF ANY KIND more details at <https://www.gnu.org/licenses/>
# SPDX-License-Identifier: AGPL-3.0-or-later
# app: `gamelike` Resemble Role Playing Games
# Ⓒ Copyright (C) 2026 Oleg'Ease'Kharchuk ᦒ
