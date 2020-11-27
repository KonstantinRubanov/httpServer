/**
  @file
  @author Stefan Frings
*/

#include "requesthandler.h"
#include "staticfilecontroller.h"
#include "filelogger.h"
#include "osdsapi.h"
#include "ControllerDevice.h"




/** Logger class */
extern FileLogger* logger;

template <class T>
QObject* CreateInterfaceHandler(){
     return new T;
}


RequestHandler::RequestHandler(QObject* parent)
    :HttpRequestHandler(parent)
{
    qWarning()<<"::InitializeDataBase_sv->";
    FactoryAbstractPtr = new FactoryAbstract(this);
    FactoryAbstractPtr->AddController_v(QString("/device"), CreateInterfaceHandler<ControllerDevice>);

}

void RequestHandler::service(HttpRequest& request, HttpResponse& response)
{
  QByteArray path=request.getPath();
  qDebug("Conroller: path=%s",path.data());

  qWarning()<<"Conroller: path=%s",path.data();

  try{
    /*
    // Set a response header
    response.setHeader("Content-Type", "text/html; charset=ISO-8859-1");

    // Return a simple HTML document
    response.write("<html><body>Hello World</body></html>",true);

    */
    stefanfrings::HttpRequestHandler* tmpObj = nullptr;

    {
      std::lock_guard<RecursiveBenaphore> lock(mutex_);

      if(QString(path).length() && FactoryAbstractPtr->_CreateControllerMethod_map.contains(QString(path)))
        //tmpObj = dynamic_cast<stefanfrings::HttpRequestHandler*>(new ControllerDevice(this));
         tmpObj = dynamic_cast<stefanfrings::HttpRequestHandler*>((FactoryAbstractPtr->_CreateControllerMethod_map[QString(path)])());
    }

    if(tmpObj)
      tmpObj->service(request, response);
    else{

        response.setStatus(200,"OK");
        /*
         // Set a response header
        response.setHeader("Content-Type", "text/html; charset=ISO-8859-1");
        // Return a simple HTML document
        response.write("<html><body>Unknown controller!</body></html>",true);
        */
        osdsapi->GetStatiFileController_po()->service(request, response);

    }
    delete tmpObj;
    qDebug("Conroller: finished request");

   }
    catch(std::exception& e) {
      response.setStatus(500,"ERROR");
      response.write("error: " + QString(e.what()).toUtf8() + "\n\n");
      response.flush();
      qWarning(e.what());
    }
    // Clear the log buffer
    if (logger)
    {
       logger->clear();
    }
}
