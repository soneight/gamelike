#include "app.hxx"
// launcher
void son8::main( [[maybe_unused]] Args args ) {
   APP_ASSERT_MSG( args.size( ) == 1, "argc must contain one argument" );
   Exit::Edit::success( );
}

// GNU Affero General Public License v3.0 or later
// NO WARRANTY OF ANY KIND more details at <https://www.gnu.org/licenses/>
// SPDX-License-Identifier: AGPL-3.0-or-later
// app: `gamelike` Resemble Role Playing Games
// Ⓒ Copyright (C) 2026 Oleg'Ease'Kharchuk ᦒ
