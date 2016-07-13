#ifndef _DEFINE_H_
    #define _DEFINE_H_

//BlockID

enum {
    BLOCK_ERROR = -1,
    BLOCK_NONE,
    BLOCK_RED,
    BLOCK_GREEN,
    BLOCK_BLUE,
    BLOCK_ORANGE,
    BLOCK_PURPLE,
    BLOCK_AZURE,
    BLOCK_YELLOW
};

//FigureID

enum {
    FIGURE_NONE = -1,
    FIGURE_I,
    FIGURE_J,
    FIGURE_L,
    FIGURE_O,
    FIGURE_S,
    FIGURE_Z,
    FIGURE_T
};

//RotationFrameID

enum {
    ROTATION_FRAME_NONE = -1,
    ROTATION_FRAME_1,
    ROTATION_FRAME_2,
    ROTATION_FRAME_3,
    ROTATION_FRAME_4
};

#define FIGURE_ID_MAX          FIGURE_T         //This value depends on FigureID enum. Look at the top.
#define ROTATION_FRAME_ID_MAX  ROTATION_FRAME_4 //This value depends on RotationFrameID enum. Look at the top.
#define BLOCK_ID_MAX           BLOCK_YELLOW     //This value depends on BlockID enum. Look at the top.

#define DESK_WIDTH      10
#define DESK_HEIGHT     20

#define FIGURE_WIDTH     4
#define FIGURE_HEIGHT    4

#define FIGURE_RESET_POSITION_ROW -4
#define FIGURE_RESET_POSITION_COL 3

#define BLOCK_SIZE 20

typedef struct {
    int col;
    int row;
    int w;
    int h;
} SRect;

#endif
