#include "findmodel.hpp"

#include <QDebug>
#include <QDir>
#include <QDirIterator>
#include <QVBoxLayout>
#include <QWidget>

#include "../log/logger.h"

FindModel::FindModel(QString path, QDialog* parent)
    : QDialog(parent), m_currentdir(path) {
  auto vert_layout = new QVBoxLayout;
  m_combo = new QComboBox;

  vert_layout->addWidget(m_combo);
  //  this->setLayout(vert_layout);
  //  this->resize(100, 45);

  m_combo->setCurrentIndex(-1);

  connect(m_combo, &QComboBox::currentTextChanged, this,
          &FindModel::updateModel);
  index = -1;
  find();
}

FindModel::~FindModel() {
  //  if (counter_file) {
  //    delete counter_file;
  //    counter_file = nullptr;
  //  }
}

void FindModel::updateIndex(int i) {
  if (i != index) {
    index = i;
    qDebug() << i;
  }
}

void FindModel::updateModel(const QString& t) {
#if LOGGER_UI
  LOG(DEBUG, "return model")
  qDebug() << "value selected " << t;
  qDebug() << "associated model " << m_list_model.indexOf(t);
#endif
              model_name = t;
}

int FindModel::count() { return m_list_model.size(); }

QString FindModel::getModelPath() {
#if LOGGER_UI
  LOG(DEBUG, "return model")
  qDebug() << "value selected " << index;
  qDebug() << "associated model " << m_list_model.contains(model_name);
#endif
  return m_list_model.at(index);
}

void FindModel::find() {
#if LOGGER_UI
  LOG(DEBUG, "searching for *.tflite models in directory:")
  qDebug() << QDir(m_currentdir).absolutePath();
#endif
  auto dir = QDir(m_currentdir);
  QStringList filter;
  filter << QString("*.tflite");
  dir.setFilter(QDir::Files);
  QFileInfoList entries = dir.entryInfoList();
  for (auto it = entries.begin(); it != entries.end(); ++it) {
    m_list_model << it->absoluteFilePath();
    m_combo->addItem(it->completeBaseName());
  }
  switch (entries.size()) {
    case 0: {
      qDebug() << "error no model";
      std::abort();
    }
    case 1:
      m_combo->setCurrentIndex(0);
      break;
    default:
      m_combo->setCurrentIndex(-1);
  }
}


////////////////////////////////////////////////////////////////////////////////
/// Layout
////////////////////////////////////////////////////////////////////////////////



