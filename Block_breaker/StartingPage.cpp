include "StartingPage.h"
#include "ui_startingpage.h"

StartingPage::StartingPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StaringPage)
{
    ui->setupUi(this);
}

StartingPage::~StartingPage()
{
    delete ui;
}
