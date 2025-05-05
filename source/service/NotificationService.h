#ifndef _NOTIFICATION_SERVICE_H_
#define _NOTIFICATION_SERVICE_H_

#include <iostream>
#include <string>

/**
 * @file NotificationService.h
 * @brief Defines the NotificationService class for sending notifications.
 */

/**
 * @class NotificationService
 * @brief Provides functionality for sending notifications.
 * 
 * The NotificationService class contains a static method to send notifications
 * by displaying a message to the user.
 */
class NotificationService {
public:
    /**
     * @brief Sends a notification with the given message.
     * 
     * @param message The message to be displayed as a notification.
     */
    static void notify(const std::string& message);
};

#endif