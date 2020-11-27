/**
  @file
  @author Stefan Frings
*/

#ifndef REQUESTHANDLER_H
#define REQUESTHANDLER_H


#include <mutex>
#include "httprequesthandler.h"
#include "FactoryAbstract.h"
#include "benaphore.h"


using namespace stefanfrings;


namespace stefanfrings {
  class FileLogger;
  class HttpSessionStore;
  class StaticFileController;
}

/**
  The request handler receives incoming HTTP requests and generates responses.
*/

class RequestHandler : public HttpRequestHandler {
    Q_OBJECT
    Q_DISABLE_COPY(RequestHandler)


    FactoryAbstract* FactoryAbstractPtr;


    RecursiveBenaphore mutex_;

public:

    /**
      Constructor.
      @param parent Parent object
    */
    RequestHandler(QObject* parent=0);

    /**
      Process an incoming HTTP request.
      @param request The received HTTP request
      @param response Must be used to return the response
    */
    void service(HttpRequest& request, HttpResponse& response);


};

#endif // REQUESTHANDLER_H
