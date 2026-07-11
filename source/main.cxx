#include "app.hxx"
// `son8`
#include <son8/main.hxx>
#include <glad/son8.hxx>
#include <glfw/son8.hxx>
// `std`
#include <son8/cxx/atom.hxx> // thread
#include <son8/cxx/file.hxx> // cerr
#include <son8/cxx/flow.hxx> // exception
// launcher
void son8::main( APP_SKIP Args args ) try {
   APP_ASSERT_MSG( args.size( ) == 1, "argc must contain one argument" );
   using namespace core;
   using namespace std::chrono_literals;
   using Cfg = windowed::Config;
   using OpenGL = windowed::OpenGL;
   Cfg windowConfig{ Cfg::Version{ OpenGL::Vx010100 } };
   app::Window window{ windowConfig };

   static Ref< app::Window > windowRef = window;
   glfwSetKeyCallback( window, []( APP_SKIP Ptr< GLFWwindow > w, int key, APP_SKIP int scancode, int action, int mods ) {
      switch ( mods ) {
      case GLFW_MOD_CONTROL: {
         if ( key == GLFW_KEY_ESCAPE and action == GLFW_PRESS ) windowRef.close( );
      } break;
         default: break;
      }
   });

   std::thread draw{ [&window]( ) {
      window.run_swap( []( ) {
         glClearColor( .125f, .125f, .125f, 1.f );
         glClear( GL_COLOR_BUFFER_BIT );
      });
   }};

   window.run_poll( []( ) -> void {
      std::this_thread::sleep_for( 1ms );
   });

   draw.join( );
   Exit::Edit::success( );
} catch ( core::Ref< cxx::exception > e ) {
   std::cerr << "gamelike: cxx::exception: " << e.what( ) << '\n';
} catch ( ... ) {
   std::cerr << "gamelike: ... exception" << '\n';
   throw;
}

// GNU Affero General Public License v3.0 or later
// NO WARRANTY OF ANY KIND more details at <https://www.gnu.org/licenses/>
// SPDX-License-Identifier: AGPL-3.0-or-later
// app: `gamelike` Resemble Role Playing Games
// Ⓒ Copyright (C) 2026 Oleg'Ease'Kharchuk ᦒ
