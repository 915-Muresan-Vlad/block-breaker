#ifndef START_H
#define START_H

#include <QWidget>

namespace Ui {
class StartingPage;
}

class StartingPage : public QWidget
{
    Q_OBJECT

public:
    explicit StartingPage(QWidget *parent = nullptr);
    ~StartingPage();

private:
    Ui::StartingPage *ui;
};

#endif // START_H
