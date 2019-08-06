#define TRUE 1
#define FALSE 0

#define DRAW_X_MIN -15
#define DRAW_X_MAX 15
#define DRAW_Y_MIN -5
#define DRAW_Y_MAX 5

typedef struct Point {
  int x;
  int y;
} Point;

typedef struct Rect {
  struct Point p1; // top left
  struct Point p2; // bottom right
} Rect;

typedef struct Pair {
  int x1;
  int x2;
} Pair;

typedef struct Range {
  Pair x; // min and max x
  Pair y; // min and max y
} Range;


// Utility functions
int min(int a, int b)
{
  return a < b ? a : b;
}
