// built with meson, check the repo

#include <GL/glut.h>
#include <math.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct {
  float x, y, vx, vy;
} Ball;

typedef struct {
  float r, g, b;
} Rgb;

constexpr GLint INIT_WINDOW_WIDTH = 1000;
constexpr GLint INIT_WINDOW_HEIGHT = 1000;

constexpr unsigned int SEED = 65;
constexpr float TARGET_FPS = 64;
constexpr size_t BALL_COUNT = 10;

constexpr float FORCE_K = 1000;
constexpr float FORCE_R02 = 1e5;
constexpr float MIN_PAIR_DISTANCE_2 = 10;

constexpr size_t CIRCLE_SEGMENTS = 16;
constexpr float INIT_BALL_RADIUS = 15;
constexpr Rgb BG = {.2f, .2f, .2f};
constexpr Rgb BALL_INIT = {.9f, .9f, .9f};

// have to do global state cuz glut owns the loop and only gives callbacks
static GLint WINDOW_WIDTH = INIT_WINDOW_WIDTH;
static GLint WINDOW_HEIGHT = INIT_WINDOW_HEIGHT;
// technically soa would be better here but it's negligible on actual values
static Ball BALLS[BALL_COUNT];
static float BALL_RADIUS = INIT_BALL_RADIUS;
static Rgb BALL_COLOR = BALL_INIT;

float rand_range(float min, float max) {
  return min + ((float)rand() / RAND_MAX) * (max - min);
}

void init_balls() {
  for (size_t i = BALL_COUNT; i-- > 0;) {
    Ball *ball = &BALLS[i];

    // spawn fully inside
    ball->x = rand_range(BALL_RADIUS, WINDOW_WIDTH - BALL_RADIUS);
    ball->y = rand_range(BALL_RADIUS, WINDOW_HEIGHT - BALL_RADIUS);
    ball->vx = 0;
    ball->vy = 0;
  }
}

void apply_gravity() {
  for (Ball *fst = BALLS; fst < BALLS + BALL_COUNT; fst++)
    for (Ball *snd = BALLS; snd < fst; snd++) {
      float dx = fst->x - snd->x;
      float dy = fst->y - snd->y;

      float r2 = MAX(dx * dx + dy * dy, MIN_PAIR_DISTANCE_2);
      float force_per_unit = FORCE_K * (1 / r2 - 1 / FORCE_R02) / sqrtf(r2);

      float fx = dx * force_per_unit;
      float fy = dy * force_per_unit;

      fst->vx += fx;
      fst->vy += fy;
      // we only go through unique pairs so apply newton's third
      snd->vx -= fx;
      snd->vy -= fy;
    }
}

void apply_velocity() {
  for (Ball *ball = BALLS; ball < BALLS + BALL_COUNT; ball++) {
    ball->x += ball->vx;
    ball->y += ball->vy;
  }
}

void apply_wall_collisions() {
  for (Ball *ball = BALLS; ball < BALLS + BALL_COUNT; ball++) {
    if (ball->x < BALL_RADIUS) {
      ball->x = BALL_RADIUS;
      ball->vx *= -1;
    }

    if (ball->x > WINDOW_WIDTH - BALL_RADIUS) {
      ball->x = WINDOW_WIDTH - BALL_RADIUS;
      ball->vx *= -1;
    }

    if (ball->y < BALL_RADIUS) {
      ball->y = BALL_RADIUS;
      ball->vy *= -1;
    }

    if (ball->y > WINDOW_HEIGHT - BALL_RADIUS) {
      ball->y = WINDOW_HEIGHT - BALL_RADIUS;
      ball->vy *= -1;
    }
  }
}

void step_physics() {
  // no dt because again glut owns the loop
  apply_gravity();
  apply_velocity();
  apply_wall_collisions();
}

void on_display() {
  glClearColor(BG.r, BG.g, BG.b, 1);
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(BALL_COLOR.r, BALL_COLOR.g, BALL_COLOR.b);

  for (Ball *ball = BALLS; ball < BALLS + BALL_COUNT; ball++) {
    glBegin(GL_POLYGON);

    constexpr float SEGMENT_ANGLE = 6.2831853f / CIRCLE_SEGMENTS;
    for (size_t segment = CIRCLE_SEGMENTS; segment-- > 0;)
      glVertex2f(ball->x + cosf(segment * SEGMENT_ANGLE) * BALL_RADIUS,
                 ball->y + sinf(segment * SEGMENT_ANGLE) * BALL_RADIUS);

    glEnd();
  }

  glFinish();
}

void on_reshape(GLint w, GLint h) {
  WINDOW_WIDTH = MAX(w, 1);
  WINDOW_HEIGHT = MAX(h, 1);

  glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glOrtho(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT, -1, 1);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

typedef unsigned char key;
void on_keyboard(key code, int, int) {
  constexpr key ESCAPE = '\033';
  constexpr key PLUS = '=';
  constexpr key MINUS = '-';
  constexpr key R = 'r';
  constexpr key G = 'g';
  constexpr key B = 'b';

  float dump;

  switch (code) {
  case ESCAPE:
    exit(EXIT_SUCCESS);
    break;
  case PLUS:
    BALL_RADIUS += 1;
    break;
  case MINUS:
    BALL_RADIUS = MAX(BALL_RADIUS - 1, 1);
    break;
  case R:
    BALL_COLOR.r = modff(BALL_COLOR.r + 0.2, &dump);
    break;
  case G:
    BALL_COLOR.g = modff(BALL_COLOR.g + 0.2, &dump);
    break;
  case B:
    BALL_COLOR.b = modff(BALL_COLOR.b + 0.2, &dump);
    break;
  }
}

void on_timer(int) {
  step_physics();
  glutPostRedisplay();

  glutTimerFunc(1000 / TARGET_FPS, on_timer, 0);
}

int main(int argc, char *argv[]) {
  srand(SEED);
  init_balls();

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  glutCreateWindow("balls");
  glutDisplayFunc(on_display);
  glutReshapeFunc(on_reshape);
  glutKeyboardFunc(on_keyboard);
  glutTimerFunc(1000 / TARGET_FPS, on_timer, 0);
  glutMainLoop();

  // glut shouldn't leave the loop
  return EXIT_FAILURE;
}
