#include "testanswerschooser.h"
#include "ui_testanswerschooser.h"

TestAnswersChooser::TestAnswersChooser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestAnswersChooser)
{
    ui->setupUi(this);
}

TestAnswersChooser::~TestAnswersChooser()
{
    delete ui;
}
