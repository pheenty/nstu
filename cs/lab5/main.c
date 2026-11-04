// built with meson, check the repo

#include <GL/glut.h>
#include <math.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

constexpr GLint INIT_WINDOW_WIDTH = 1000;
constexpr GLint INIT_WINDOW_HEIGHT = 1000;

constexpr unsigned int SEED = 65;
constexpr float TARGET_FPS = 64;
constexpr size_t BALL_COUNT = 10;

constexpr float FORCE_K = 1000;
constexpr float FORCE_R02 = 1e5;
constexpr float MIN_PAIR_DISTANCE_2 = 10;

constexpr size_t CIRCLE_SEGMENTS = 16;
constexpr float BALL_RADIUS = 15;
constexpr float BG_R = .2f;
constexpr float BG_G = .2f;
constexpr float BG_B = .2f;
constexpr float BALL_R = .9f;
constexpr float BALL_G = .9f;
constexpr float BALL_B = .9f;

typedef struct {
  float x, y, vx, vy;
} Ball;

// have to do global state cuz glut owns the loop and only gives callbacks
static GLint WINDOW_WIDTH = INIT_WINDOW_WIDTH;
static GLint WINDOW_HEIGHT = INIT_WINDOW_HEIGHT;
// technically soa would be better here but it's negligible on actual values
static Ball BALLS[BALL_COUNT];

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
  glClearColor(BG_R, BG_G, BG_B, 1);
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(BALL_R, BALL_G, BALL_B);

  for (Ball *ball = BALLS; ball < BALLS + BALL_COUNT; ball++) {
    glBegin(GL_TRIANGLE_FAN);

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

void on_keyboard(unsigned char key, int, int) {
  constexpr unsigned char ESCAPE = '\033';
  if (key == ESCAPE)
    exit(EXIT_SUCCESS);
}

void on_timer(int) {
  step_physics();
  glutPostRedisplay();

  glutTimerFunc(1000 / TARGET_FPS, on_timer, 0);
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  glutCreateWindow("balls");

  srand(SEED);
  init_balls();
  on_reshape(WINDOW_WIDTH, WINDOW_HEIGHT);

  glutDisplayFunc(on_display);
  glutReshapeFunc(on_reshape);
  glutKeyboardFunc(on_keyboard);
  glutTimerFunc(1000 / TARGET_FPS, on_timer, 0);

  glutMainLoop();

  // glut shouldn't leave the loop
  return EXIT_FAILURE;
}
