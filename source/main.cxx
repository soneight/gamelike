#include "app.hxx"
// `son8`
#include <son8/main.hxx>
// NOTE: to use `gl* and GL_* c-entities` define macro below
#define SON8_OVERGLAD_INCLUDE_DEPRECATED
#include <son8/overglad/v1_1.hxx>
#include <glfw/son8.hxx>
#include <son8/core/alias.hxx>
#include <son8/cxx/atom.hxx> // thread
#include <son8/cxx/file.hxx> // cerr
#include <son8/cxx/flow.hxx> // exception
// launcher
void son8::main( APP_SKIP Args args ) try {
   APP_ASSERT_MSG( args.size( ) == 1, "argc must contain one argument" );
   namespace gl = son8::overglad;
   namespace gle = gl::enums;
   using namespace core;
   using namespace cxx::chrono_literals;
   using Cfg = windowed::Config;
   using OpenGL = windowed::OpenGL;
   using Thread = cxx::thread;
   Cfg windowConfig{ Cfg::Version{ OpenGL::Vx010100 }, Cfg::LingerUS{ 468 } };
   app::Window window{ windowConfig };

   static Ref< app::Window > refWindow = window;
   glfwSetKeyCallback( window, []( APP_SKIP Ptr< GLFWwindow > w, int key, APP_SKIP int scancode, int action, int mods ) {
      switch ( mods ) {
      case GLFW_MOD_CONTROL: {
         if ( key == GLFW_KEY_ESCAPE and action == GLFW_PRESS ) refWindow.close( );
      } break;
         default: break;
      }
   });

   Thread draw{ [&window]( ) {
      static constexpr Size Vertices_Count = 3;
      static constexpr Size Vertices_Per = 2;
      static constexpr Size Colors_Per = 3;
      static constexpr Size Colors_Size = Colors_Per * Vertices_Count;
      static constexpr Size Vertices_Size = Vertices_Count * Vertices_Per;
      Flat< GLfloat, Vertices_Size > vertexData{{
         0.f, 0.f,
         1.f, 0.f,
         .5f, 1.0f
      }};
      Flat< GLubyte, Colors_Size > colorData{{
         255, 0, 0,
         0, 255, 0,
         0, 0, 255
      }};

      window.run_swap( [&verts = vertexData,&colors = colorData]( ) {
         gl::clear_color( 0.125f );
         gl::clear( gle::Clearbit::Color );
         gl::load_identity( );
         gl::ortho(-.2, 1.2,-.2, 1.2, -1., 1. );
         gl::enable( gle::ClientState::Vertex );
         gl::enable( gle::ClientState::Color );
         gl::vertex_pointer( 2, GL_FLOAT, 0, verts.data( ) );
         gl::color_pointer( 3, GL_UNSIGNED_BYTE, 0, colors.data( ) );
         gl::draw_arrays( (GLenum)gle::Draw::Triangles, 0, Vertices_Count );
         gl::disable( gle::ClientState::Color );
         gl::disable( gle::ClientState::Vertex );
         assert( not gl::get_error( ) && "app: gl get error triggered" );
      });
   }};

   window.run_poll( []( ) -> void {

   });

   draw.join( );
   Exit::Edit::success( );
} catch ( core::Ref< cxx::exception > e ) {
   std::cerr << "gamelike: std::exception: " << e.what( ) << '\n';
} catch ( ... ) {
   std::cerr << "gamelike: ... exception" << '\n';
   throw;
}

// GNU Affero General Public License v3.0 or later
// NO WARRANTY OF ANY KIND more details at <https://www.gnu.org/licenses/>
// SPDX-License-Identifier: AGPL-3.0-or-later
// app: `gamelike` Resemble Role Playing Games
// Ⓒ Copyright (C) 2026 Oleg'Ease'Kharchuk ᦒ
