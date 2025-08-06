#ifndef PLAYER_H
#define PLAYER_H
#include <raylib.h>

typedef struct{
    Vector2 pos;
    float radius;
    float spin, speed;
    int number, keyRight, keyLeft;
    Color col;
    float angle;
    float distanceFromCenter;
}Player;

void playerInit(Player *player, int playerNum);

void updatePlayer(Player *player);

void playerCollisions(Player *player);

void drawPlayer(Player *player);

#endif