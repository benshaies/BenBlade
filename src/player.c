#include "player.h"
#include "math.h"
#include "stdio.h"



void playerInit(Player *player, int playerNum){
    player->radius = 50.0f;
    player->spin = 0.0f;
    player->number = playerNum;
    player->speed = 5;
    player->distanceFromCenter = 400;

    if(player->number == 1){
        player->keyLeft = KEY_A;
        player->keyRight = KEY_D;
        player->pos = (Vector2){500, 750};
        player->col = BLUE;
    }
    else if(player->number == 2){
        player->keyLeft = KEY_LEFT;
        player->keyRight = KEY_RIGHT;
        player->pos = (Vector2){500, 250};
        player->col = RED;
    }

    player->angle = 0;

    
}


void updatePlayer(Player *player){
    player->pos.x = 500 + player->distanceFromCenter * cos(player->angle);
    player->pos.y = 500 + player->distanceFromCenter * sin(player->angle);

    player->distanceFromCenter -= 1;
    player->angle -= player->speed * GetFrameTime();

    if(IsKeyPressed(player->keyRight)){
        player->speed = 5;
    }
    else if (IsKeyPressed(player->keyLeft)){
        player->speed = -5;
    }


}

void playerCollisions(Player *player){

}

void drawPlayer(Player *player){
    DrawCircleV(player->pos, player->radius, player->col);
}