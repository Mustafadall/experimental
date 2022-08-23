#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMenu>
#include <QTranslator>
#include <QApplication>
#include <QStyleFactory>
#include <QGraphicsEffect>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setHidden(true);

    menu = new QMenu(this);
    menu->addAction(QString("En"), this, SLOT(change_lang_to_en()));
    menu->addAction(QString("Fr"), this, SLOT(change_lang_to_fr()));
    menu->setPalette(this->palette());

    ui->changeLang->setMenu(menu);
}

MainWindow::~MainWindow()
{
    if (menu) {
        delete menu;
    }
    delete ui;
}


void MainWindow::change_lang_to_en()
{
    if (!mTranslator.isEmpty()) {
        QApplication::instance()->removeTranslator(&mTranslator);
        ui->retranslateUi(this);
    }
}

void MainWindow::change_lang_to_fr()
{
    if (mTranslator.load("french.qm", ":/app/res/lang/")) {
        QApplication::instance()->installTranslator(&mTranslator);
        ui->retranslateUi(this);
    }
}

void MainWindow::on_chooseButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this);
    if (filename != nullptr) {
        QFile file(filename);
        if (file.open(QIODevice::ReadOnly| QIODevice::Text)) {
            ui->textEdit->setText(QString(file.readAll()));
            ui->chooseFrame->setHidden(true);
            ui->textEdit->setHidden(false);
        }
    }
}

void MainWindow::on_changeLang_clicked()
{
    ui->changeLang->showMenu();
}

