#ifndef FRAMELESSWINDOW_H
#define FRAMELESSWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>

class FramelessWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit FramelessWindow(QWidget *parent = nullptr);

public slots:
    void toggleMaximize();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    QPoint dragStartPosition;
};

#endif