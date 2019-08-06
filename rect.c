#include <stdlib.h>
#include <stdio.h>
#include "rect.h"
#include "tests.h"

Range rectToRange(Rect rect)
{
  Range r = {
    .x = { rect.p1.x, rect.p2.x },
    .y = { rect.p2.y, rect.p1.y }
  };
  return r;
}

Rect rangeToRect(Range range)
{
  Rect r = {
    .p1 = {range.x.x1, range.y.x2},
    .p2 = {range.x.x2, range.y.x1}
  };
  return r;
}

// intersect function
int checkBounds1D(Pair r1, Pair r2, Pair *r3)
{
  if (r2.x1 < r1.x1) {
    // r2.x2 must be greater than r1.x1 to intersect
    if (r2.x2 > r1.x1) {
      // calc intersection points
      r3->x1 = r1.x1;
      r3->x2 = min(r2.x2, r1.x2);
      return TRUE;
    } else {
      return FALSE;
    }
  } else if (r2.x1 < r1.x2) {
    // at this point we know that r2.x1 >= r1.x1, so r2.x1 must be less than
    // r1.x2 in order to intersect

    // Edge case: check if r2 is on the edge, i.e., r2.x1 == r1.x1 and r2 or
    // r1 has 0 width
    if (r2.x1 == r1.x1 && (r2.x2 == r2.x1 || r1.x2 == r1.x1)) {
      return FALSE;
    } else {
      // calc intersection points
      r3->x1 = r2.x1;
      r3->x2 = min(r2.x2, r1.x2);
      return TRUE;
    }
  }

  return FALSE;
}

int intersect(Rect rect1, Rect rect2, Rect *rect3)
{
  // Convert from rect to range
  Range r1 = rectToRange(rect1);
  Range r2 = rectToRange(rect2);

  // Range for intersection rectangle
  Range r3;

  int itrResult;
  // check if the x range intersects
  itrResult = checkBounds1D(r1.x, r2.x, &(r3.x));
  if (!itrResult) {
    return FALSE;
  }
  // check if the y range intersects
  itrResult = checkBounds1D(r1.y, r2.y, &(r3.y));
  if (!itrResult) {
    return FALSE;
  }

  // convert range back to rect
  Rect resultRect = rangeToRect(r3);
  rect3->p1 = resultRect.p1;
  rect3->p2 = resultRect.p2;

  return TRUE;
}

void printResult(Rect rect1, Rect rect2, Rect itrRect, int result)
{
  printf("\nRect1: [(%d, %d), (%d, %d)], Rect2: [(%d, %d), (%d, %d)],\
    Result: %d; Intersection point 1: (%d, %d); Intersection point 2: (%d, %d);\n",
    rect1.p1.x, rect1.p1.y, rect1.p2.x, rect1.p2.y,
    rect2.p1.x, rect2.p1.y, rect2.p2.x, rect2.p2.y,
    result,
    itrRect.p1.x, itrRect.p1.y, itrRect.p2.x, itrRect.p2.y);

  for (int y = DRAW_Y_MAX; y >= DRAW_Y_MIN; y--) {
    for (int x = DRAW_X_MIN; x <= DRAW_X_MAX; x++) {
      Range itrRange = rectToRange(itrRect);
      Range rect1Range = rectToRange(rect1);
      Range rect2Range = rectToRange(rect2);
      if (x == 0 && y == 0) {
        printf("@");
      }
      else if (result && x >= itrRange.x.x1 && x <= itrRange.x.x2
          && y >= itrRange.y.x1 && y <= itrRange.y.x2) {
        printf("|");
      }
      else if (x >= rect1Range.x.x1 && x <= rect1Range.x.x2
          && y >= rect1Range.y.x1 && y <= rect1Range.y.x2) {
        printf("1");
      }
      else if (x >= rect2Range.x.x1 && x <= rect2Range.x.x2
          && y >= rect2Range.y.x1 && y <= rect2Range.y.x2) {
        printf("2");
      }
      else {
        printf(".");
      }
    }
    printf("\n");
  }
  printf("\n");
}

int main(int argc, char *argv[])
{
  Rect itrRect;
  int result;

  for (int i = 0; i < NUM_TESTS; i++) {
    Rect rect1 = tests[i][0];
    Rect rect2 = tests[i][1];

    // check if rects intersect
    printf("Test %d\n", i+1);
    result = intersect(rect1, rect2, &itrRect);
    printResult(rect1, rect2, itrRect, result);

    // check in the reverse order as well
    printf("Test %d (reverse rects)\n", i+1);
    result = intersect(rect2, rect1, &itrRect);
    printResult(rect2, rect1, itrRect, result);
  }

  return 0;
}
