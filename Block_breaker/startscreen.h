#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <QWidget>

namespace Ui {
class StartScreen;
}

class StartScreen : public QWidget
{
    Q_OBJECT
public:
    explicit StartScreen(QWidget *parent = nullptr);

signals:

private:
    Ui::StartScreen *ui;

};

#endif // STARTSCREEN_H
