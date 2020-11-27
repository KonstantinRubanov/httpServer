#include "ControllerDevice.h"
#include <Exception>
#include <QDir>
#include <QCoreApplication>



ControllerDevice::ControllerDevice(QObject * parent) : ControllerAbstract(parent)
{
  _ControllerName_str = "ControllerAntivirus";
}

ControllerDevice::~ControllerDevice(){

}

void ControllerDevice::service(stefanfrings::HttpRequest & request, stefanfrings::HttpResponse & response){

    response.setHeader("Content-Type", "text/html; charset=utf-8");
    try{
      response.setStatus(200,"OK");
      QString GPSPageJs = QString(qApp->applicationDirPath() + "//forms//index.html").toUtf8();
      QFileInfo check_file(GPSPageJs);
      if (check_file.exists() && check_file.isFile()) {
        QFile f(GPSPageJs);
        if (f.open(QFile::ReadOnly | QFile::Text)){
          QTextStream in(&f);
           in.setAutoDetectUnicode(true);
           response.write(in.readAll().toUtf8());
           f.close();
        }
      }
   }
    catch(std::exception& e) {
      response.setStatus(500,"ERROR");
      response.write("error: " + QString(e.what()).toUtf8() + "\n\n");
      response.flush();
      qWarning(e.what());
    }
}


