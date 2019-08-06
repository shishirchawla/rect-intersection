#define NUM_TESTS 14

Rect tests[NUM_TESTS][2] = {
  // two separate rects
  {
    {
      .p1 = {-8, 2},
      .p2 = {-5, 0}
    },
    {
      .p1 = {1, 1},
      .p2 = {2, 0}
    }
  },
  // rects connected on a corner
  {
    {
      .p1 = {-8, 2},
      .p2 = {-5, 0}
    },
    {
      .p1 = {-5, 0},
      .p2 = {0, -2}
    }
  },
  // r2 starts at the right edge of r1
  {
    {
      .p1 = {-8, 2},
      .p2 = {-5, 0}
    },
    {
      .p1 = {-5, 2},
      .p2 = {-1, 0}
    }
  },
  // r2 starts at the bottom edge of r1
  {
    {
      .p1 = {-8, 2},
      .p2 = {-5, 0}
    },
    {
      .p1 = {-8, 0},
      .p2 = {-1, -2}
    }
  },
  // r1 = r2
  {
    {
      .p1 = {1, 1},
      .p2 = {2, 0}
    },
    {
      .p1 = {1, 1},
      .p2 = {2, 0}
    }
  },
  // r1 contains r2
  {
    {
      .p1 = {-5, 4},
      .p2 = {5, -4}
    },
    {
      .p1 = {-3, 2},
      .p2 = {3, -2}
    }
  },
  // intersecting pair 1
  {
    {
      .p1 = {1, 4},
      .p2 = {8, 0}
    },
    {
      .p1 = {-10, 2},
      .p2 = {8, 0}
    }
  },
  // intersecting pair 2
  {
    {
      .p1 = {-5, 2},
      .p2 = {8, -2}
    },
    {
      .p1 = {-1, 4},
      .p2 = {5, -4}
    }
  },
  // line (left edge)
  {
    {
      .p1 = {1, 4},
      .p2 = {8, 0}
    },
    {
      .p1 = {1, 4},
      .p2 = {1, 0}
    }
  },
  // line (right edge)
  {
    {
      .p1 = {1, 4},
      .p2 = {8, 0}
    },
    {
      .p1 = {8, 3},
      .p2 = {8, 0}
    }
  },
  // line (top edge)
  {
    {
      .p1 = {1, 4},
      .p2 = {8, 0}
    },
    {
      .p1 = {1, 4},
      .p2 = {3, 4}
    }
  },
  // line (bottom edge)
  {
    {
      .p1 = {1, 4},
      .p2 = {8, 0}
    },
    {
      .p1 = {1, 0},
      .p2 = {5, 0}
    }
  },
  // line (point)
  {
    {
      .p1 = {1, 4},
      .p2 = {8, 0}
    },
    {
      .p1 = {2, 3},
      .p2 = {2, 3}
    }
  },
  // line (in between)
  {
    {
      .p1 = {1, 4},
      .p2 = {8, 0}
    },
    {
      .p1 = {4, 3},
      .p2 = {4, 0}
    }
  }
};
