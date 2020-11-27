#ifndef CONTROLLERDEVICE_H
#define CONTROLLERDEVICE_H

#include <QObject>
#include "ControllerAbstract.h"


using namespace stefanfrings;



class ControllerDevice : public ControllerAbstract
{
    Q_OBJECT
    Q_DISABLE_COPY(ControllerDevice)

public:

    ControllerDevice(QObject * parent = Q_NULLPTR);
    /**
     * @brief ~ControllerAbstract Деструктор
     */
    virtual ~ControllerDevice() override;
    /**
     * @brief service Метод сервлета для контроллера
     * @param request Запрос
     * @param response  Ответ
     */
    virtual void service(stefanfrings::HttpRequest & request, stefanfrings::HttpResponse & response) override;

};



#endif // CONTROLLERDEVICE_H
