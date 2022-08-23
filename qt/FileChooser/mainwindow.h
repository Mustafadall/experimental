#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTranslator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_chooseButton_clicked();
    void on_changeLang_clicked();
    void change_lang_to_en();
    void change_lang_to_fr();

private:
    Ui::MainWindow *ui;
    QMenu *menu ;
    QTranslator mTranslator;
};
#endif // MAINWINDOW_H
