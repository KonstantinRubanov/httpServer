#include <QJsonObject>

#include "ControllerAbstract.h"

  ControllerAbstract::ControllerAbstract(QObject * parent) : stefanfrings::HttpRequestHandler(parent)
  {
     _ControllerName_str = "ControllerDevice";
  }

  ControllerAbstract::~ControllerAbstract()
  {

  }

