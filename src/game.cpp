#include "game.h"
#include "blocks.h"

Game::Game(QWidget *parent) : QWidget(parent)
{
    Blocks* blocks = new Blocks(2);
    setLayout(blocks);
}
