#pragma once
#include "../ds/ds.h"
#include "../utils/helper.h"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>
#define WIN_HEIGHT 800
#define WIN_WIDTH 1400
#define KEYSTROKE_BACKSPACE 8

#define BUTTON_PANEL_LENGTH 3
#define BUTTON_PANEL_LABELS                                                    \
  { "Create", "Manage", "Link" }
typedef enum { NONE, MOUSE_DOWN, MOUSE_UP } MouseMovement;
typedef enum { SQUARE_QUAD } SUPPORTED_QUAD_TYPES;
typedef enum { BUTTON_PANEL_QUAD, BUTTON_PANEL_SELECT } BUTTON_PANEL_TYPES;

typedef struct {
  Coordinate start_coordinate;
  Coordinate active_coordinate;
  SDL_Rect active_select;
  MouseMovement mouse_movement;
  int is_lcontrol_key_active;
  int is_lshift_key_active;
} SelectState;

typedef struct {
  Coordinate position;
  Coordinate dimension;
  SDL_Surface *sdl_surface;
  SDL_Texture *sdl_texture;
  int id;
} TextPanel;

typedef enum {
  PanelActionSquare,
  PanelActionSelect,
  PanelActionNone
} PanelActiveAction;

typedef struct {
  TextPanel button_panel[BUTTON_PANEL_LENGTH];
  int active_panel_id;
  int panel_max_height;
} Panel;

typedef struct {
  SDL_Rect *source;
  Coordinate *source_coordinate;
  SDL_Rect *destination;
  Coordinate *inactive_destination;
  int destination_id;
} QuadLink;

typedef struct {
  Coordinate position;
  Coordinate dimension;
  int id;
  SDL_Rect *rect;
  char *description;
  MyArray *text_panels;
  TextPanel *text_panel;
  MyArray *quad_links;
} Square;

typedef struct {
  SDL_Renderer *renderer;
  SDL_Window *window;
  TTF_Font *font;
} SDLInstance;

typedef struct {
  SelectState select_state;
  Panel panel;
  SDLInstance sdl_instance;
  MyArray *squares;
  int active_selected_quad;
} MyState;
