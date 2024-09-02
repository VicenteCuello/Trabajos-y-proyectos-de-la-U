#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
/*WIDTH = ANCHO
  HEIGHT = ALTO*/
typedef struct{
  double x;
  double y;
  double xVel;
  double ancho;
  double alto;
  SDL_Surface* image;
}PLAYER;

typedef struct{
  double x;
  double y;
  double r;
  double xVel;
  double yVel;
  double ancho;
  double alto;
  double centroX;
  double centroY;
  SDL_Surface* image;
}BALL;

typedef struct{
  double x;
  double y;
  double ancho;
  double alto;
  int fila;
  int columna;
  SDL_Surface* image;
}BLOQUE;

const int SCREEN_WIDTH = 720;
const int SCREEN_HEIGHT = 480;
const int BARRERA_W = 720;
const int BARRERA_H = 480;

SDL_Window* Window = NULL;
SDL_Surface* Surface = NULL;
SDL_Event event;
SDL_Renderer* renderer = NULL;
SDL_Surface* BallSurface = NULL;
SDL_Surface* PaletaSurface = NULL;
SDL_Surface* BrickRojoSurface = NULL;
SDL_Surface* BrickAzulSurface = NULL;
SDL_Surface* BrickAmarilloSurface = NULL;
SDL_Surface* BrickVerdeSurface = NULL;
SDL_Surface* MenuSurface = NULL;
SDL_Surface* ConfigSurface = NULL;
SDL_Surface* GameFondoSurface = NULL;
Mix_Music *backgroundSound = NULL;
Mix_Music *backgroundSound2 = NULL;
Mix_Music *backgroundSound3 = NULL;
Mix_Chunk *SonidoBloque = NULL;
Mix_Chunk *SonidoPaleta = NULL;
int BALL_W = 20; //ancho de pelota
int BALL_H = 20; //largo de pelota
int PLAYER_W = 100; //ancho de jugador
int PLAYER_H = 20; //largo de jugador
const double BRICK_W = 50; //ancho de los bloques
const double BRICK_H = 30;//largo de los bloques
int FILAS = (BARRERA_H / 3) / (BRICK_H + 2);
int COLUMNAS =  (BARRERA_W - 5) / (BRICK_W + 5);
int BRICKROTO = 0;
int PUNTAJE = 0;
int MAX_SCORE = 0;
int VIDAS = 3;
int state = 1;
bool quit = false;
unsigned int TICK_INTERVAL = 30;
bool **Bloque;
unsigned time_left(void);
static Uint32 next_time;
TTF_Font *Font = NULL;
TTF_Font *FontMini = NULL;
SDL_Color TextColor = {255, 255, 255};
SDL_Surface *MenuText = NULL;
SDL_Surface *ConfigText = NULL;
SDL_Surface *GameStartText = NULL;
SDL_Surface *PointsText = NULL;
SDL_Surface *MaxPointsText = NULL;
SDL_Surface *VidasText = NULL;

void menu(){
  bool quitMenu = false;
  SDL_Rect PosicionTexto;

  while (!quitMenu) {
    while (SDL_PollEvent(&event) != 0){
      switch (event.type) {
        case SDL_QUIT:
          quit = true;
          quitMenu = true;
          break;
        case SDL_KEYDOWN:
          switch (event.key.keysym.sym) {
            case SDLK_ESCAPE:
              quit = true;
              quitMenu = true;
              break;

            case SDLK_o:
              state = 2;
              quitMenu= true;
              break;

            case SDLK_RETURN:
              state = 3;
              quitMenu = true;
              break;
          }
      }
    }
    SDL_BlitSurface(MenuSurface, NULL ,Surface ,NULL);
    PosicionTexto.x = (BARRERA_W / 2) - (265);
    PosicionTexto.y = BARRERA_H / 2;

    if (SDL_BlitSurface(MenuText, NULL, Surface, &PosicionTexto) < 0) {
      printf("SDL could not blit! SDL Error: %s\n", SDL_GetError());
      quit = true;
      quitMenu = true;
    }
    SDL_UpdateWindowSurface(Window);
    SDL_Delay(time_left());
    next_time += TICK_INTERVAL;

  }
}
void menu2(){
  bool quitConfig = false;
  SDL_Rect PosicionTexto;

  while (!quitConfig) {
    while (SDL_PollEvent(&event) != 0){
      switch (event.type) {
        case SDL_QUIT:
          quit = true;
          quitConfig = true;
          break;

        case SDL_KEYDOWN:
          switch (event.key.keysym.sym) {
            case SDLK_ESCAPE:
              quit = false;
              quitConfig = true;
              state = 1;
              break;

            case SDLK_o:
              state = 2;
              quitConfig = true;
              break;
          }
      }
    }
    SDL_BlitSurface(ConfigSurface, NULL ,Surface ,NULL);
    PosicionTexto.x = (BARRERA_W / 2) - 170;
    PosicionTexto.y = BARRERA_H / 2;

    if (SDL_BlitSurface(ConfigText, NULL, Surface, &PosicionTexto) < 0) {
      printf("SDL could not blit! SDL Error: %s\n", SDL_GetError());
      quit = true;
      quitConfig = true;
    }
    SDL_UpdateWindowSurface(Window);
    SDL_Delay(time_left());
    next_time += TICK_INTERVAL;

  }
}
bool iniciar(){
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL couldn't init video, error: %s\n", SDL_GetError());
    return false;
  }
  else{
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
      printf("SDL couldn't init audio, error: %s\n", SDL_GetError());
      return false;
    }
    else{
      Window = SDL_CreateWindow("breakout", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
      if (Window == NULL) {
        printf("SDL couldn't init window, error: %s\n", SDL_GetError());
        return false;
      }
      else{
        renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_SOFTWARE);
        Surface = SDL_GetWindowSurface(Window);
        if (Surface == NULL) {
          printf("SDL couldn't init surface, error: %s\n", SDL_GetError());
          return false;
        }
        if (renderer == NULL) {
          printf("SDL couldn't init renderer, error: %s\n", SDL_GetError());
          return false;
        }
        else{
          if(!(IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) & (IMG_INIT_JPG | IMG_INIT_PNG))) {
              printf("SDL couldn't initialize image loading, error: %s\n", IMG_GetError() );
              return false;
          }
          if(TTF_Init() == -1){
              printf("SDL couldn't initialize the true-type font, error: %s\n", TTF_GetError());
              return false;
          }
        }
      }
    }

  }

  Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

  return true;
}
void liberar(){
  SDL_FreeSurface(BallSurface);
  SDL_FreeSurface(PaletaSurface);
  SDL_FreeSurface(BrickRojoSurface);
  SDL_FreeSurface(BrickVerdeSurface);
  SDL_FreeSurface(BrickAmarilloSurface);
  SDL_FreeSurface(BrickAzulSurface);
  SDL_FreeSurface(MenuSurface);
  SDL_FreeSurface(ConfigSurface);
  SDL_FreeSurface(GameFondoSurface);
  GameFondoSurface = NULL;
  MenuSurface = NULL;
  BallSurface = NULL;
  PaletaSurface = NULL;
  BrickRojoSurface = NULL;
  BrickVerdeSurface = NULL;
  BrickAmarilloSurface = NULL;
  BrickAzulSurface = NULL;
  for(int i=0; i<COLUMNAS; i++){
    free(Bloque[i]);
  }
  free(Bloque);
  TTF_CloseFont(Font);
  Font = NULL;
  SDL_DestroyRenderer(renderer);
  renderer = NULL;
  SDL_DestroyWindow(Window);
  Window = NULL;
  TTF_Quit();
  IMG_Quit();
  SDL_Quit();
}
unsigned time_left(void) {
    unsigned now = SDL_GetTicks();
    return (next_time <= now) ? 0 : next_time - now;
}
bool cargarTodo(){
  MenuSurface = IMG_Load("./imagenes/fondomenu.png");
  ConfigSurface = IMG_Load("./imagenes/fondogame.png");
  GameFondoSurface = IMG_Load("./imagenes/fondogame.png");
  BallSurface = IMG_Load("./imagenes/ball.png");
  PaletaSurface = IMG_Load("./imagenes/platform.png");
  BrickRojoSurface = IMG_Load("./imagenes/rojo.png");
  BrickVerdeSurface = IMG_Load("./imagenes/verde.png");
  BrickAzulSurface = IMG_Load("./imagenes/azul.png");
  BrickAmarilloSurface = IMG_Load("./imagenes/amarillo.png");
  char str[30] = " ";
  char str2[30] = " ";
  char str3[30] = " ";
  Font = TTF_OpenFont("./fuentes/font.ttf", 28);
  FontMini = TTF_OpenFont("./fuentes/font.ttf", 15);
  MenuText = TTF_RenderText_Solid(FontMini, "Presiona ENTER", TextColor);
  ConfigText = TTF_RenderText_Solid (Font, "configuracion", TextColor);
  GameStartText = TTF_RenderText_Solid(FontMini, "Presiona espacio", TextColor);
  PointsText = TTF_RenderText_Solid(FontMini,str2, TextColor);
  MaxPointsText = TTF_RenderText_Solid(FontMini,str3, TextColor);
  VidasText = TTF_RenderText_Solid(FontMini, str, TextColor);
  SDL_Surface *tmp = TTF_RenderText_Blended(FontMini, str, TextColor);
  SDL_BlitSurface(tmp, NULL, Surface, NULL);
  SDL_Surface *tmp2 = TTF_RenderText_Blended(FontMini, str2, TextColor);
  SDL_BlitSurface(tmp2, NULL, Surface, NULL);
  backgroundSound = Mix_LoadMUS("./audio/comfort-zone-main-menu-sonic-mania-ost.mp3");
  backgroundSound2 = Mix_LoadMUS("./audio/super-street-fighter-ii-ost-guile-theme.mp3");
  backgroundSound3 = Mix_LoadMUS("./audio/f1-theme-8-bit-version.mp3");
  SonidoBloque = Mix_LoadWAV("./audio/destruccionbloque.wav");
  SonidoPaleta = Mix_LoadWAV("./audio/paletagolpe.wav");

  return true;
}
PLAYER crearPaleta(double posX, double posY, double xVel, double ancho, double alto, SDL_Surface *image){
    PLAYER player;

    player.x = posX;
    player.y = posY;
    player.xVel = xVel;
    player.ancho = ancho;
    player.alto = alto;
    player.image = image;

    return player;
}
BALL crearBall(double ancho, double alto, SDL_Surface *image){
  BALL ball;

  ball.r = 10;
  ball.xVel = 0;
  ball.yVel = 0;
  ball.ancho = ancho;
  ball.alto = alto;
  ball.image = image;

  return ball;
}
BLOQUE crearBrick(double posX, double posY, double ancho, double alto, int fila, int columna, SDL_Surface *image){
    BLOQUE brick;

    brick.x = posX;
    brick.y = posY;
    brick.ancho = ancho;
    brick.alto = alto;
    brick.image = image;
    brick.fila = fila;
    brick.columna = columna;

    return brick;
}
void colisionPaleta(PLAYER *player) {
    if (!((player->x + player->ancho + player->xVel > BARRERA_W) || (player->x + player->xVel < 0))) {
      player->x += player->xVel;
    }
}
void colisionBall(BALL *ball) {
  ball->x += ball->xVel;
  ball->y += ball->yVel;

  ball->centroX = ball->x + ball->ancho/2;
  ball->centroY = ball->y + ball->alto/2;

  if ((ball->x + ball->ancho > BARRERA_W) || (ball->x < 0.0)) {
    ball->xVel = -ball->xVel;
    ball->x += ball->xVel;
  }
  if (ball->y <= 0.0) {
    ball->yVel = -ball->yVel;
    ball->y += ball->yVel;
  }
  if (ball->y + ball->alto >= BARRERA_H) {
    VIDAS--;
    ball->y = (BARRERA_H / 2);
    ball->x = (BARRERA_W / 2);
    ball->xVel = 0.0; ball->yVel = 0.0;
  }
}
void rebotePaleta(BALL *ball, PLAYER *player){
  int xColision, yColision;

  if (ball->centroX < player->x){
    xColision = player->x;
  }
  else if (ball->centroX > player->x + player->ancho){
    xColision = player->x + player->ancho;
  }
  else{
    xColision = ball->centroX;
  }
  if (ball->centroY < player->y) {
    yColision = player->y;
  }
  else if (ball->centroY > player->y + player->alto) {
    yColision = player->y + player->alto;
  }
  else{
    yColision = ball->centroY;
  }

  if (SDL_pow((ball->centroX - xColision), 2) + SDL_pow((ball->centroY - yColision), 2) < SDL_pow(ball->r, 2)) {
    Mix_PlayChannel(-1, SonidoPaleta, 0);
    double dist = (player->x+(player->ancho/2))-(ball->centroX+(10/2));
    double ang = dist/(player->ancho/2);
    double valorebote = ang* ((5*3.14)/12);
    double c=cos(valorebote);
    double s=sin(valorebote);
    double xVel=10.0, yVel=10.0;
    ball->yVel=-yVel*c;
    ball->xVel=xVel*-s;
  }
}
void colisionBloque(BALL *ball, BLOQUE *brick){

  int xColision, yColision;
  int arribaOabajo, izqOder;
  int colisonLados;
  bool corner = true;
  ball->centroX = ball->x + ball->ancho/2;
  ball->centroY = ball->y + ball->alto/2;

  if (ball->centroX < brick->x){
    xColision = brick->x;
    izqOder = 0;
    colisonLados = 1;
  }
  else if (ball->centroX > brick->x + brick->ancho){
    xColision = brick->x + brick->ancho;
    izqOder = 1;
    colisonLados = 1;
  }
  else{
    xColision = ball->centroX;
    corner = false;
    colisonLados = 0;
  }


  if (ball->centroY < brick->y) {
    yColision = brick->y;
    arribaOabajo = 0;
    colisonLados = 0;
  }
  else if (ball->centroY > brick->y + brick->alto) {
    yColision = brick->y + brick->alto;
    arribaOabajo = 1;
    colisonLados = 0;
  }
  else{
    yColision = ball->centroY;
    corner = false;
    colisonLados = 1;
  }

  if (SDL_pow((ball->centroX - xColision), 2) + SDL_pow((ball->centroY - yColision), 2) < SDL_pow(ball->r, 2)) {
    Mix_PlayChannel(-1, SonidoBloque, 0);
    if (corner) {
      if ((arribaOabajo == 1 && ball->yVel < 0 ) || (arribaOabajo == 0 && ball->yVel > 0)) {
        ball->yVel = -ball->yVel;
        ball->y += ball->yVel;
      }
      if ((izqOder == 1 && ball->xVel < 0) || (izqOder == 0 && ball->xVel > 0)) {
        ball->xVel = -ball->xVel;
        ball->x += ball->xVel;
      }
    }
    else{
      switch (colisonLados) {
        case 0:
          ball->yVel = -ball->yVel;
          ball->y += ball->yVel;

          break;

        case 1:
          ball->xVel = -ball->xVel;
          ball->x += ball->xVel;

          break;
      }
    }
    Bloque[brick->columna][brick->fila] = true;
    if(Bloque[brick->columna][brick->fila] = true){
      BRICKROTO++;
      PUNTAJE++;
    }
    if(PUNTAJE > MAX_SCORE){
      MAX_SCORE = PUNTAJE;
    }
    printf("brickroto:%d\npuntaje: %d\nvidas: %d\ntotal bloques: %d\n",BRICKROTO, PUNTAJE, VIDAS,(COLUMNAS*FILAS));
    printf("columnas: %d\nfilas:%d\n\n",COLUMNAS,FILAS);
  }
    bool gameWin = false;
    if(BRICKROTO == FILAS*COLUMNAS){
      BRICKROTO = 0;
      gameWin = true;
    }
}
void juego(){
  bool quitGame = false;
  bool gameStart = false;
  bool gameWin = false;
  bool quitConfig = false;
  int filas, columnas;
  BALL ball;
  SDL_Rect ballSrcRect, ballDstRect;
  PLAYER player;
  SDL_Rect playerSrcRect, playerDstRect;
  BLOQUE brick;
  SDL_Rect brickSrcRect, brickDstRect;
  SDL_Rect PosicionTexto;
  SDL_Surface *colorBrickSurface = NULL;

  player = crearPaleta((BARRERA_W - PLAYER_W) / 2, BARRERA_H - 50.0, 0.0, PLAYER_W, PLAYER_H, PaletaSurface);
  ball = crearBall(BALL_W, BALL_H, BallSurface);

  Bloque = malloc(COLUMNAS * sizeof(bool*));
  for (columnas = 0; columnas < COLUMNAS; columnas++){
    Bloque[columnas] = malloc(FILAS * sizeof(bool));
  }
    for (columnas = 0; columnas < COLUMNAS; columnas++) {
      for (filas = 0; filas < FILAS; filas++) {
          Bloque[columnas][filas] = false;
      }
    }

  while (!quitGame) {
    while (SDL_PollEvent(&event) != 0) {
      switch (event.type) {

        case SDL_QUIT:
          quit = true;
          quitGame = true;
          break;
        case SDL_KEYDOWN:

          switch (event.key.keysym.sym) {
            case SDLK_ESCAPE:
              quitGame = true;
              state = 1;
              break;

            case SDLK_LEFT:
              player.xVel = -10;

              break;
            case SDLK_RIGHT:
              player.xVel = 10;

              break;

            case SDLK_SPACE:
              gameStart = true;
              if (ball.xVel == 0 && ball.yVel == 0) {
                ball.xVel = 9.0;
                ball.yVel = -9.0;
              }

              break;

            case SDLK_UP:
              TICK_INTERVAL -= 5;
              if (TICK_INTERVAL <= 0) {
                TICK_INTERVAL = 1;
              }

              break;
            case SDLK_DOWN:
              TICK_INTERVAL += 5;
              break;
          }
          break;

        case SDL_KEYUP:
          switch (event.key.keysym.sym) {
            case SDLK_RIGHT: case SDLK_LEFT:
              player.xVel = 0.0;

              break;
          }
      }

  }
    SDL_BlitSurface(GameFondoSurface, NULL ,Surface ,NULL);
    colisionPaleta(&player);

    playerSrcRect.x = 0; playerSrcRect.y = 0;
    playerSrcRect.w = player.ancho;
    playerSrcRect.h = player.alto;

    playerDstRect.x = player.x;
    playerDstRect.y = player.y;

    if(SDL_BlitSurface(player.image, &playerSrcRect, Surface, &playerDstRect) < 0 ) {
        printf("SDL could not blit! SDL Error: %s\n", SDL_GetError());
        quit = true;
        quitGame = true;
    }
    if (ball.xVel == 0 && ball.yVel == 0){
      ball.x = player.x + (player.ancho/2) - (ball.ancho/2);
      ball.y = player.y - player.alto;

      PosicionTexto.x = BARRERA_W / 2 - 100;
      PosicionTexto.y = BARRERA_H / 2 + 50;

      if (SDL_BlitSurface(GameStartText, NULL, Surface, &PosicionTexto) < 0) {
        printf("SDL could not blit! SDL Error: %s\n", SDL_GetError());
        quit = true;
        quitGame = true;
      }
    }
    else{
      colisionBall(&ball);
      rebotePaleta(&ball, &player);
    }

    ballSrcRect.x = 0; ballSrcRect.y = 0;
    ballSrcRect.w = ball.ancho;
    ballSrcRect.h = ball.alto;
    ballDstRect.x = ball.x;
    ballDstRect.y = ball.y;

    if(SDL_BlitSurface(ball.image, &ballSrcRect, Surface, &ballDstRect) < 0 ) {
        printf("SDL could not blit! SDL Error: %s\n", SDL_GetError());
        quit = true;
        quitGame = true;
    }
    char str[30] = "";
    sprintf(str, "VIDAS %d",VIDAS);
    char str2[30] = "";
    sprintf(str2, "PUNTAJE %d",PUNTAJE);
    char str3[30] = "";
    sprintf(str3, "MAX SCORE %d",MAX_SCORE);
    SDL_Surface *tmp = TTF_RenderText_Blended(FontMini,str,TextColor);
    PosicionTexto.x = BARRERA_W - 500;
    PosicionTexto.y = BARRERA_H - 470;
    SDL_BlitSurface(tmp, NULL, Surface, &PosicionTexto);
    SDL_Surface *tmp2 = TTF_RenderText_Blended(FontMini,str2,TextColor);
    PosicionTexto.x = BARRERA_W - 700;
    PosicionTexto.y = BARRERA_H - 470;
    SDL_BlitSurface(tmp2, NULL, Surface, &PosicionTexto);
    SDL_Surface *tmp3 = TTF_RenderText_Blended(FontMini,str3,TextColor);
    PosicionTexto.x = BARRERA_W - 300;
    PosicionTexto.y = BARRERA_H - 470;
    SDL_BlitSurface(tmp3, NULL, Surface, &PosicionTexto);

    for (columnas = 0; columnas < COLUMNAS; columnas++) {
      for (filas = 0; filas < FILAS; filas++) {

        if (Bloque[columnas][filas] == false) {
          switch ((filas % 4)) {
            case 0:
              colorBrickSurface = BrickRojoSurface;
              break;

            case 1:
              colorBrickSurface = BrickVerdeSurface;
              break;

            case 2:
              colorBrickSurface = BrickAzulSurface;
              break;

            case 3:
              colorBrickSurface = BrickAmarilloSurface;
              break;
            }

          brick = crearBrick((columnas * (BRICK_W + 5) + 5), (filas * (BRICK_H + 5)) + BARRERA_H/12 , BRICK_W, BRICK_H, filas, columnas, colorBrickSurface);
          colorBrickSurface = NULL;
          brickSrcRect.x = 0; brickSrcRect.y = 0;
          brickSrcRect.w = brick.ancho;
          brickSrcRect.h = brick.alto;
          brickDstRect.x = brick.x;
          brickDstRect.y = brick.y;

          if (SDL_BlitSurface(brick.image, &brickSrcRect, Surface, &brickDstRect)){
            printf("SDL could not blit! SDL Error: %s\n", SDL_GetError());
            quit = true;
            quitGame = true;
          }
          if (gameStart) {
            colisionBloque(&ball, &brick);

            if (PUNTAJE == COLUMNAS * FILAS){
              gameWin = true;
            }
            if(gameWin){
              state = 3;
              PUNTAJE = 0;
              BRICKROTO = 0;
              VIDAS = 3;
              quitGame = true;
            }
            if(VIDAS == 0){
              PUNTAJE = 0;
              BRICKROTO = 0;
              VIDAS = 3;
              quitGame = true;
            }
          }
        }
      }
    }

    SDL_UpdateWindowSurface(Window);
    SDL_Delay(time_left());
    next_time += TICK_INTERVAL;
  }
}
int main(int argc, char *args[]) {

  if (!iniciar() || !cargarTodo()) {
    printf("SDL didn't init properly\n");
  }
  else{

    while (!quit) {
      switch (state) {
        case 1:
          Mix_PlayMusic(backgroundSound3, -1);
          menu();
          break;

        case 2:
          Mix_PlayMusic(backgroundSound, -1);
          menu2();
          break;

        case 3:
          Mix_PlayMusic(backgroundSound2, -1);
          juego();
          break;
      }
    }
  }

  liberar();
  return 0;
}
