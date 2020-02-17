#ifndef FINDMODEL_HPP
#define FINDMODEL_HPP

#include <QComboBox>
#include <QDialog>
#include <QProgressDialog>

class FindModel : public QDialog {
  Q_OBJECT
 public:
  explicit FindModel(QString path, QDialog *parent = nullptr);
  ~FindModel();

  int count();
  QString getModelPath();
 private slots:

  void updateIndex(int i);
  void updateModel(const QString &t);
 signals:

 private:
  void find();
  QComboBox *m_combo{nullptr};
  QString m_currentdir;
  QStringList m_list_model;
  QString model_name;
  int counter_file;
  int index;
};

#endif // FINDMODEL_HPP
