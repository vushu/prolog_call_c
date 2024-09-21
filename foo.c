#include <SWI-Prolog.h>
#include <raylib.h>
#include <stdio.h>

static foreign_t pl_say_hello(term_t to) {
  char *a;
  if (PL_get_atom_chars(to, &a)) {
    printf("Hello, %s\n", a);
    PL_succeed;
  } else {
    PL_fail;
  }
}

static foreign_t pl_create_window(term_t name) {
  const int screenWidth = 800;
  const int screenHeight = 450;
  char *a;

  if (PL_get_atom_chars(name, &a)) {
    InitWindow(screenWidth, screenHeight, a);
  }

  SetTargetFPS(60); // Set our game to run at 60 frames-per-second
  //--------------------------------------------------------------------------------------

  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    // Update
    //----------------------------------------------------------------------------------
    // TODO: Update your variables here
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText("Congrats! You created your first window!", 190, 200, 20,
             LIGHTGRAY);

    EndDrawing();
    //----------------------------------------------------------------------------------
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  CloseWindow(); // Close window and OpenGL context
  //--------------------------------------------------------------------------------------
  PL_succeed;
}

install_t install_foo() {
  PL_register_foreign("say_hello", 1, pl_say_hello, 0);
  PL_register_foreign("create_window", 1, pl_create_window, 0);
}
