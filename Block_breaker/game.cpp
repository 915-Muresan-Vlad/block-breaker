#include "game.h"
#include "ball.h"
#include "paddle.h"
#include "block.h"
#include "ui_game.h"
#include <QMessageBox>
#include <QAction>

extern Game *game;

Game::Game(QWidget *parent) :
    QGraphicsView(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    resize(1000, 600);

    ui->label->hide();
    ui->ExitBtn->hide();
    ui->TryAgainbtn->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->Score_lbl->hide();

    scene = new QGraphicsScene(0,50, 900, 500);

    setScene(scene);

    // set mouse tracking
    setMouseTracking(true);

    QAction* actRestart = new QAction(tr("restart"), this);
    QAction* actExit   = new QAction(tr("Iesire"), this);

    setContextMenuPolicy(Qt::ActionsContextMenu);
    addAction(actRestart);
    addAction(actExit);

    connect(actExit, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(actRestart, SIGNAL(triggered()), this, SLOT(restart()));
}

Game::~Game()
{
    delete ui;
}

void Game::Start()
{
    score = 0;
    ball = new Ball();
    ball->setPos(200, 500);
    scene->addItem(ball);

    paddle = new Paddle();
    paddle->setPos(300, 580);
    scene->addItem(paddle);
    paddle->grabMouse();

    createBlockGrid();
}

void Game::GameOver()
{
    ui->TitleLbl->setText("GAME OVER");
    ui->TitleLbl->show();

    ui->TryAgainbtn->show();
    ui->ExitBtn->show();

    ui->DescriptionLbl->setText("You lost");
    ui->DescriptionLbl->show();
}

void Game::createBlockCol(double x)
{
    for (size_t i = 0, n = 8; i < n; ++i)
    {

        Block* block = new Block(i);
        block->setPos(x, i*27);                   // 2 pixeli de spatiu intre blocuri + inaltimea blocului(25)
        scene->addItem(block);
    }
}

void Game::createBlockGrid()
{
    for (size_t i = 0, n = 9; i < n; ++i)
        createBlockCol(i*102);
}

void Game::changeScore()
{
    if (score != 72)
        ui->Score_lbl->setNum(score);
    else
    {
        ball->ySpeed = 0;
        ball->xSpeed = 0;
        ui->TitleLbl->setText("WINNER WINNER CHICKEN \n DINNER");
        ui->TitleLbl->show();

        ui->TryAgainbtn->show();
        ui->ExitBtn->show();

        ui->DescriptionLbl->setText("You won!");
        ui->DescriptionLbl->show();
    }
}

void Game::restart()
{
    ui->TitleLbl->hide();
    ui->DescriptionLbl->hide();
    ui->ExitBtn->hide();
    ui->TryAgainbtn->hide();

    ball->~Ball();
    paddle->~Paddle();
    score = 0;
    game->Start();
}

void Game::on_startbtn_clicked()
{
    ui->startbtn->hide();
    ui->TitleLbl->hide();
    ui->DescriptionLbl->hide();

    ui->label->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->label_4->show();
    ui->label_5->show();
    ui->Score_lbl->show();

    game->Start();
}



void Game::on_InfoBtn_clicked()
{
    QMessageBox msg;
    msg.setText("joc retro Atari Breakout \n\n Lucrare de atestat realizata de: \n Muresan Vlad \n CNLR Bistrita 2020");
    msg.exec();
}

void Game::on_ExitBtn_clicked()
{
    exit(0);
}

void Game::on_TryAgainbtn_clicked()
{
    ui->TitleLbl->hide();
    ui->ExitBtn->hide();
    ui->TryAgainbtn->hide();
    game->restart();
}
