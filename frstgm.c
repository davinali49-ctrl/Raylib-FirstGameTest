#include "raylib.h"

int main(void)
{
    InitWindow(800, 450, "first game");
    SetTargetFPS(30);

    Vector2 playerPos = {380, 380};
    float playerSpeed = 300.0f;

    Vector2 enemyPos = {200, 0};
    float enemySpeed = 200.0f;

    int score = 0;

    while (!WindowShouldClose())
    { 
        float dt = GetFrameTime();

        if (IsKeyDown(KEY_A)) playerPos.x -= playerSpeed * dt;
        if (IsKeyDown(KEY_D)) playerPos.x += playerSpeed * dt;

        enemyPos.y += enemySpeed * dt;
        
        if (enemyPos.y > 450)
        {
            enemyPos.y = 0;
            enemyPos.x = GetRandomValue(0,760);
            score++;
        }


        Rectangle player = { playerPos.x, playerPos.y, 40, 40};
        Rectangle enemy = { enemyPos.x, enemyPos.y, 40, 40};

        if (CheckCollisionRecs(player, enemy))
        {
            BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Yahaha Kalah", 280, 200, 40, BLACK);
            EndDrawing();

            WaitTime(10);
            break;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangleV(playerPos, (Vector2){40, 40}, BLUE);
        DrawRectangleV(enemyPos, (Vector2){40, 40}, RED);
        DrawText(TextFormat("Score: %d", score), 10, 10, 20, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}