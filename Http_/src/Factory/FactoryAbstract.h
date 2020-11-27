#ifndef FACTORYABSTRACT_H
#define FACTORYABSTRACT_H

#include <QObject>
#include <QMap>



class FactoryAbstract : public QObject
{
  Q_OBJECT
  Q_DISABLE_COPY(FactoryAbstract)

public:

  typedef QObject* (*CreateControllerMethod)();

  FactoryAbstract(QObject * parent = Q_NULLPTR);

  void AddController_v(const QString & Name_str, CreateControllerMethod Method_o);

  QMap<QString, CreateControllerMethod> _CreateControllerMethod_map;  ///< @brief Хранилище фабричных методов


protected:
  };

#endif // FACTORYABSTRACT_H
