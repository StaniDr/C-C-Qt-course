#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <algorithm>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //---------- метод для передачи  ----------
            connect(ui->GLASS,SIGNAL(signalGlassRepaint()), this, SLOT(slotFrame()),Qt::QueuedConnection);

    createMenuBar();


     ui->GLASS->repaint();
}

MainWindow::~MainWindow()
{
    delete ui;
}

static bool compareF(const QPointF& first, const QPointF& second)
{
    if (first.y() < second.y())
    {
        return true;
    }
    else if (first.y() > second.y())
    {
        return false;
    }
    else
    {
        if (first.x() < second.x())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

}



void MainWindow::slotUpdateButton()
{

    QFile file1("file1.dat");
    QString str = "";

    if (!file1.open(QIODevice::WriteOnly))
    {
        qDebug() << "Ошибка открытия файла для записи";
    }
    else {

        QTextStream out(&file1);
        for(int i = 0; i < ui->Radius_Edit->value(); i++)
        {
            int w = QRandomGenerator::global()->bounded(200);
            int y = QRandomGenerator::global()->bounded(800);
            str.clear();
            str.append(QString::number(w+100));
            str.append(",");
            str.append(QString::number(y+40));
            str.append('\n');

            out << str;

        }
    }

    file1.close();

    //----------------------------------

   // QFile file(filePath);
    QList<QPointF> pointsList; // Список, который будем возвращать

    if ( !file1.open(QFile::ReadOnly | QFile::Text) ) {
        qDebug() << "Ошибка открытия файла для чтения";
    } else {
        // Создаём поток для извлечения данных из файла
        QTextStream in(&file1);
        ui->GLASS->vec.clear();
        // Считываем данные до конца файла
        while (!in.atEnd())
        {
            // ... построчно
            QString line = in.readLine();
            QStringList coordinateStrList = line.split(','); // Разделяем строку на список чисел, получится два числа
           // qDebug() << "line = " << line;
            // Если строка была заполнена, то
            if (coordinateStrList.length() > 0)
            {
                // то формируем точку
                QPointF point(coordinateStrList.at(0).toDouble(), coordinateStrList.at(1).toDouble());
                pointsList.append(point);  // и добавляем её в список
                ui->GLASS->vec.push_back(point);
            }
        }
        file1.close();
    }

std::sort(ui->GLASS->vec.begin(), ui->GLASS->vec.end(), compareF);

ui->GLASS->repaint();

int max_x = 0;
int max_y = 0;

int min_x = 800;
int min_y = 0;

 for(int i =0; i<ui->GLASS->vec.size();i++)
 {
     if (ui->GLASS->vec[i].rx() > max_x)
     {
         max_x = ui->GLASS->vec[i].rx();
         max_y = ui->GLASS->vec[i].ry();
      }

     if (ui->GLASS->vec[i].rx() < min_x)
     {
         min_x = ui->GLASS->vec[i].rx();
         min_y = ui->GLASS->vec[i].ry();
      }

 }

ui->P_X_MAX->setValue(max_y);
ui->P_Y_MAX->setValue(max_x);

ui->P_X_MIN->setValue(min_y);
ui->P_Y_MIN->setValue(min_x);


}

void MainWindow::about()
{

    QMessageBox::about(this, tr("About Points"),
            tr("<p>The <b>Points</b> how to calculate points of tangents to a circle,  "
               "aentered in a corner, constructed on three points."
               "Author - Drobot Stanislav"));

}

void MainWindow::createMenuBar()
{

    QAction *quitAction = new QAction(tr("&Quit"), this);
    QAction *aboutAction = new QAction(tr("&About"), this);
    QAction *aboutQtAction = new QAction(tr("&About Qt"), this);

    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(quitAction);

    QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutQtAction);

    connect(quitAction, &QAction::triggered, this, &MainWindow::close);
    connect(aboutAction, &QAction::triggered, this, &MainWindow::about);
    connect(aboutQtAction, &QAction::triggered, qApp, &QApplication::aboutQt);
}

void MainWindow::paintEvent(QPaintEvent*)
{

}

void MainWindow::slotColor()
{
    ui->GLASS->cpen = QColorDialog::getColor(Qt::blue);
}

void MainWindow::slotFrame()
{

}
