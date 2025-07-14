#include "FramelessWindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

FramelessWindow::FramelessWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
    resize(800, 600);

    // Title bar setup
    QWidget *titleBar = new QWidget();
    titleBar->setFixedHeight(40);

    QLabel *title = new QLabel("Unet");
    title->setStyleSheet("font-weight: bold; padding-left: 10px;");

    QPushButton *minimizeButton = new QPushButton("-");
    QPushButton *closeButton = new QPushButton("×");
    QPushButton *maximizeButton = new QPushButton("+");
    minimizeButton->setFixedSize(30, 30);
    closeButton->setFixedSize(30, 30);
    maximizeButton->setFixedSize(30, 30);
    minimizeButton->setStyleSheet("background: none;");
    closeButton->setStyleSheet("background: none;");
    maximizeButton->setStyleSheet("background: none;");

    connect(minimizeButton, &QPushButton::clicked, this, &QMainWindow::showMinimized);
    connect(closeButton, &QPushButton::clicked, this, &QMainWindow::close);
    connect(maximizeButton, &QPushButton::clicked, this, &QMainWindow::showMaximized);

    QHBoxLayout *titleLayout = new QHBoxLayout();
    titleLayout->addWidget(title);
    titleLayout->addStretch();
    titleLayout->addWidget(minimizeButton);
    titleLayout->addWidget(closeButton);
    titleLayout->addWidget(maximizeButton);
    titleLayout->setContentsMargins(0, 0, 0, 0);
    titleBar->setLayout(titleLayout);

    // Main content
    QLabel *label = new QLabel("This is the Unet App!");
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 24px; padding: 20px;");

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(titleBar);
    mainLayout->addWidget(label);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    QWidget *central = new QWidget();
    central->setLayout(mainLayout);
    setCentralWidget(central);
}

void FramelessWindow::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        dragStartPosition = event->globalPosition().toPoint() - frameGeometry().topLeft();
        event->accept();
    }
}

void FramelessWindow::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton) {
        move(event->globalPosition().toPoint() - dragStartPosition);
        event->accept();
    }
}

void FramelessWindow::toggleMaximize() {
    if (isMaximized())
        showNormal();
    else {
        showMaximized();
    }
}