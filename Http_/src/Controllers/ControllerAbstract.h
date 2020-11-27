#ifndef CONTROLLERABSTRACT_H
#define CONTROLLERABSTRACT_H

#include <QObject>
#include <QString>

#include "httprequesthandler.h"


using namespace stefanfrings;

  class ControllerAbstract : public stefanfrings::HttpRequestHandler
  {
    Q_OBJECT
    public:
      /**
       * @brief ControllerAbstract Основной конструктор
       * @param parent Родительский объект
       */
      ControllerAbstract(QObject * parent = Q_NULLPTR);
      /**
       * @brief ~ControllerAbstract Деструктор
       */
      virtual ~ControllerAbstract() override;
      /**
       * @brief GetControllerName_str Возвращает имя контроллера
       * @return Строка взятая из _ControllerName_str
       */
      QString GetControllerName_str() { return _ControllerName_str; }

  protected:
      QString _ControllerName_str = "AbstractController"; ///< @brief Имя класса контроллера (нужно для головного JSON)

      /**
       * @brief service Метод сервлета для контроллера
       * @param request Запрос
       * @param response  Ответ
       */
      virtual void service(stefanfrings::HttpRequest & request, stefanfrings::HttpResponse & response) override = 0;

      /**
       * @brief SetJsonPackageHead_v Устанавливает заголовок в Json объект
       * @param JsonObgect_ro Ссылка на QJsonObject
       * @param Operation_rc Описание действия
       * @param State_rc Состояние операции
       */
   };

#endif // CONTROLLERABSTRACT_H
