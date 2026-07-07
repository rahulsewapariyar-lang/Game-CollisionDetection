#include "../include/Update.h"

void Update(Ball& ball)
{
    ball.position.x += ball.velocity.x;
    ball.position.y += ball.velocity.y;
}
