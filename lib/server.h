#ifndef SERVER_H
#define SERVER_H

#include <WebServer.h>
#include "game.h"

class Server {
public:
    Server(Game* game, uint16_t port = 80);
    void begin();
    void handleClient();

private:
    WebServer webServer;
    Game* game;

    void handleRoot();
    void handleMove();
    void handleNotFound();
    String generateHTML();
};

#endif