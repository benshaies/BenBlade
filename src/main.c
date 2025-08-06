#include "raylib.h"
#include "player.h"

const int screenWidth = 1000;
const int screenHeight = 1000;

//Player variables
Player player1;
Player player2;

void draw(){
    BeginDrawing();

    ClearBackground(RAYWHITE);

    //Draw Basic Stadium
    DrawCircle(500, 500, 500, GRAY);
    DrawCircleLinesV((Vector2){500, 500}, 500, BLACK);
    DrawCircleLinesV((Vector2){500, 500}, 499, BLACK);
    DrawCircleLinesV((Vector2){500, 500}, 498, BLACK);
    DrawCircleLinesV((Vector2){500, 500}, 497, BLACK);

    //Draw players
    drawPlayer(&player1);
    drawPlayer(&player2);

    EndDrawing();
}

void init(){
    InitWindow(screenWidth, screenHeight, "BenBlade");  
    SetTargetFPS(60);

    playerInit(&player1, 1);
    playerInit(&player2, 2);
}

int main(void){

    init();
    while (!WindowShouldClose()){
        draw();
        updatePlayer(&player1);
        updatePlayer(&player2);
    }

    CloseWindow();
    return 0;
}