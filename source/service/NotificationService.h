#ifndef _NOTIFICATION_SERVICE_H_
#define _NOTIFICATION_SERVICE_H_

#include <iostream>
#include <string>

class NotificationService {
public:
    static void notify(const std::string& message);
};

#endif