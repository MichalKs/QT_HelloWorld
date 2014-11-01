
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>

/**
 * @brief main
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {

  QApplication app(argc, argv);

  QWidget *window = new QWidget;
  window->setWindowTitle("Hello World App");

  QSpinBox *spinBox = new QSpinBox;
  QSlider *slider = new QSlider(Qt::Horizontal);

  spinBox->setRange(0, 500);
  slider->setRange(0, 500);

  QObject::connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
  QObject::connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));

  slider->setValue(50);

  QLabel *label = new QLabel("Hello QT!!!");
  QPushButton *quitButton = new QPushButton("Quit");
  QObject::connect(quitButton, SIGNAL(clicked()), &app, SLOT(quit()));

  QHBoxLayout *layout = new QHBoxLayout;
  layout->addWidget(label);
  layout->addWidget(spinBox);
  layout->addWidget(slider);
  layout->addWidget(quitButton);

  window->setLayout(layout);

  window->show();

  return app.exec();

}
