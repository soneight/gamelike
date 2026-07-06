#ifndef APP_HXX
#define APP_HXX
// son8
#include <son8/main.hxx>
// std
#include <cassert>
// special app debug assert macros
#ifndef APP_DEBUG
#define APP_ASSERT( check ) ( (void)0 )
#define APP_ASSERT_MSG( check, msg ) ( (void)0 )
#else
#define APP_ASSERT( check ) assert( check )
#define APP_ASSERT_MSG( check, msg ) assert( check && msg )
#endif//APP_DEBUG

namespace app {

} // namespace app

#endif//APP_HXX

// GNU Affero General Public License v3.0 or later
// NO WARRANTY OF ANY KIND more details at <https://www.gnu.org/licenses/>
// SPDX-License-Identifier: AGPL-3.0-or-later
// app: `gamelike` Resemble Role Playing Games
// Ⓒ Copyright (C) 2026 Oleg'Ease'Kharchuk ᦒ
